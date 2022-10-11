#include <bits/stdc++.h>
using namespace std;

const int N = 1005, MOD = 998244353;

int n, m;
long long ans = 0, dp[N][N][4];
char x[N], y[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (x + 1) >> (y + 1);
    n = strlen(x + 1); m = strlen(y + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0) {
                dp[i][j][2] = 1;
                if (j > 0 && x[i] != y[j]) {
                    (dp[i][j][0] += dp[i - 1][j][3] + dp[i - 1][j][1]) %= MOD;
                }
                if (i > 1 && x[i] != x[i - 1]) {
                    (dp[i][j][0] += dp[i - 1][j][0]) %= MOD;
                    (dp[i][j][2] += dp[i - 1][j][2]) %= MOD;
                }
            }
            if (j > 0) {
                dp[i][j][3] = 1;
                if (i > 0 && x[i] != y[j]) {
                    (dp[i][j][1] += dp[i][j - 1][2] + dp[i][j - 1][0]) %= MOD;
                }
                if (j > 1 && y[j] != y[j - 1]) {
                    (dp[i][j][1] += dp[i][j - 1][1]) %= MOD;
                    (dp[i][j][3] += dp[i][j - 1][3]) %= MOD;
                }
            }
            (ans += dp[i][j][0] + dp[i][j][1]) %= MOD;
        }
    }
    cout << ans;
}