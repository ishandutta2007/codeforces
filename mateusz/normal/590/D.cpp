#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 155, INF = 1e9;

int N, K, S;
int tab[MAX_N];
int dp[2][MAX_N][MAX_N*MAX_N];

int main() {

    scanf("%d %d %d", &N, &K, &S);
    S = min(S, N * (N - 1));

    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
    }

    for (int k = K; k >= 1; k--) {

        for (int n = N; n >= 1; n--) {
            for (int s = 0; s <= S; s++) {
                if (n == N) {
                    if (s >= n - k && k == K) {
                        dp[0][n][s] = tab[n];
                    } else {
                        dp[0][n][s] = INF;
                    }
                    continue;
                }
                dp[0][n][s] = min(s >= n - k ? tab[n] + dp[1][n + 1][s - (n - k)] : INF,
                                  dp[0][n + 1][s]);
            }
        }
        for (int n = 1; n <= N; n++) {
            for (int s = 0; s <= S; s++) {
                dp[1][n][s] = dp[0][n][s];
            }
        }
    }

    printf("%d\n", dp[1][1][S]);
    return 0;
}