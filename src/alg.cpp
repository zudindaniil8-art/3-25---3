// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"
uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_val = num;
    uint64_t current = num;
    
    while (current != 1) {
        if (current % 2 == 0) {
            current = current / 2;
        } else {
            current = 3 * current + 1;
        }
        if (current > max_val) {
            max_val = current;
        }
    }
    return max_val;
}
unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    uint64_t current = num; 
    while (current != 1) {
        if (current % 2 == 0) {
            current = current / 2;
        } else {
            current = 3 * current + 1;
        }
        length++;
    }
    return length;
}
unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    uint64_t best_num = lbound;
    unsigned int best_len = collatzLen(lbound);
    
    for (uint64_t num = lbound + 1; num <= rbound; ++num) {
        unsigned int len = collatzLen(num);
        if (len > best_len) {
            best_len = len;
            best_num = num;
        }
    }
    *maxlen = best_len;
    return best_num;
}
