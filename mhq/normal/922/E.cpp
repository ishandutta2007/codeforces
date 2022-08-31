#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e4 + 10;
int n;
long long w, b, x;
long long dp[1005][maxN];
int c[maxN];
long long cost[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> w >> b >> x;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];
    memset(dp, -1, sizeof dp);
    dp[0][0] = w;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < maxN; j++) {
            long long cur_bal = dp[i - 1][j];
            if (cur_bal == -1) continue;
            for (int k = 0; k <= c[i]; k++) {
                if (cost[i] * k > cur_bal) continue;
                dp[i][j + k] = max(min(cur_bal - (k * cost[i]) + x, w + (b * (j + k))), dp[i][j + k]);
            }
        }
    }
    for (int i = maxN - 1; i >= 0; i--) {
        if (dp[n][i] != -1) {
            cout << i;
            return 0;
        }
    }
    return 0;
}