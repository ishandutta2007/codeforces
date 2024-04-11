/*
    author:  Maksim1744
    created: 23.10.2020 01:44:07
*/

#include <stdio.h>
#include <inttypes.h>

#define N 100

#define inf 1000000

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int a[N][N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int dp[N][N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                dp[i][j][k] = -inf;
            }
        }
        dp[i][0][0] = 0;
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            for (int cnt = N - 2; cnt >= 0; --cnt) {
                for (int rem = 0; rem < k; ++rem) {
                    if (dp[r][cnt + 1][(rem + a[r][c]) % k] < dp[r][cnt][rem] + a[r][c]) {
                        dp[r][cnt + 1][(rem + a[r][c]) % k] = dp[r][cnt][rem] + a[r][c];
                    }
                }
            }
        }
    }

    int dp2[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp2[i][j] = -inf;
        }
    }
    dp2[0][0] = 0;
    for (int r = 0; r < n; ++r) {
        for (int rem1 = 0; rem1 < k; ++rem1) {
            for (int cnt = 0; cnt <= m / 2; ++cnt) {
                for (int rem2 = 0; rem2 < k; ++rem2) {
                    if (dp2[r + 1][(rem1 + rem2) % k] < dp2[r][rem1] + dp[r][cnt][rem2]) {
                        dp2[r + 1][(rem1 + rem2) % k] = dp2[r][rem1] + dp[r][cnt][rem2];
                    }
                }
            }
        }
    }

    printf("%d\n", dp2[n][0]);

    return 0;
}