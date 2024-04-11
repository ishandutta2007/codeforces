/*
    author:  Maksim1744
    created: 27.10.2020 17:44:31
*/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

int dp[225][450];
int t[225];

int inf = 1000000000;

int abs(int k) {
    if (k < 0) return -k;
    return k;
}

int comp (const int *a, const int *b) {
    return *a - *b;
}

void test_case() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n + 5; ++i) {
        for (int j = 0; j < (n + 5) * 2; ++j) {
            dp[i][j] = inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    qsort(t, n, sizeof(int), (int(*) (const void *, const void *)) comp);
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", t[i]);
    // }
    // printf("\n");
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int tlast = 0; tlast < n * 2 + 5; ++tlast) {
            for (int tnext = tlast + 1; tnext < n * 2 + 5; ++tnext) {
                dp[i + 1][tnext] = min(dp[i + 1][tnext], dp[i][tlast] + abs(tnext - t[i]));
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n * 2 + 5; ++i) {
        ans = min(ans, dp[n][i]);
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        test_case();
    }
    return 0;
}