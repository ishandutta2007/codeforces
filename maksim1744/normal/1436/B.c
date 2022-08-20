/*
    author:  Maksim1744
    created: 24.10.2020 17:08:19
*/

#include <stdio.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

int a[105][105];

int is_prime(int k) {
    if (k == 1) return 0;
    for (int j = 2; j * j <= k; ++j)
        if (k % j == 0)
            return 0;
    return 1;
}

void test_case() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 1;
        }
    }
    int k = 1;
    while (is_prime(k) || !is_prime(k + n - 1)) ++k;
    for (int i = 0; i < n; ++i) {
        a[i][i] = k;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test_case();
    }
    return 0;
}