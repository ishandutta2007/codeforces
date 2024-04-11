#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005][12][2];
int n, m, k;
string s, t;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    cin >> s >> t;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int sz = 0; sz <= k; sz++) {
                for (int t = 1; t < 2; t++){
                    dp[i][j][sz][t] = -1005;
                }
            }
        }
    }
    //dp[0][0][0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int sz = 0; sz <= k; sz++) {
                dp[i + 1][j][sz][0] = max(dp[i + 1][j][sz][0], dp[i][j][sz][1]);
                dp[i + 1][j][sz][0] = max(dp[i + 1][j][sz][0], dp[i][j][sz][0]);
                dp[i][j + 1][sz][0] = max(dp[i][j + 1][sz][0], dp[i][j][sz][1]);
                dp[i][j + 1][sz][0] = max(dp[i][j + 1][sz][0], dp[i][j][sz][0]);
                if ((i < n) && (j < m) && s[i] == t[j]) {
                    dp[i + 1][j + 1][sz][1] = max(dp[i + 1][j + 1][sz][1], dp[i][j][sz][1] + 1);
                    if (sz + 1 <= k) dp[i + 1][j + 1][sz + 1][1] = max(dp[i + 1][j + 1][sz + 1][1], dp[i][j][sz][0] + 1);
                }
            }
        }
    }
    cout << max(dp[n][m][k][0], dp[n][m][k][1]);
    return 0;
}