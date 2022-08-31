/*
    author:  Maksim1744
    created: 13.11.2020 17:35:50
*/

#include <stdio.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

void test_case() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", 1);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test_case();
    }
    return 0;
}