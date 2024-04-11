#include <bits/stdc++.h>

using namespace std;

const int N = 18;
const long long INF = 1e18;

int n, m, k, a, b, c;
int satisfaction[N];
int gain[N][N];
long long dp[1 << N][N];

int main() {

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &satisfaction[i]);
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        gain[a][b] = c;
    }

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -INF;
            if ((i & (1 << j)) == 0) {
                continue;
            }
            int u = i - (1 << j);
            if (u == 0) {
                dp[i][j] = satisfaction[j];
                continue;
            }

            for (int l = 0; l < n; l++) {
                if ((u & (1 << l)) == 0) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[u][l] + satisfaction[j] + gain[l][j]);
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        if (__builtin_popcount(i) == m) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
    }
    printf("%I64d\n", ans);

    return 0;
}