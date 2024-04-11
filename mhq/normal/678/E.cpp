#include <bits/stdc++.h>
using namespace std;
const int maxN = 20;
double p[maxN][maxN];
double dp[1 << 18][maxN];
int n;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    for (int mask = (1 << n) - 1; mask > 0; mask--) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = -1;
        }
    }
    for (int mask = (1 << n) - 1; mask > 0; mask--) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            if (mask == (1 << n) - 1) {
                dp[mask][i] = double((i == 0));
                continue;
            }
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) != 0) continue;
                dp[mask][i] = max(dp[mask][i], dp[mask | (1 << j)][i] * p[i][j] + dp[mask | (1 << j)][j] * p[j][i]);
            }
        }
    }
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[1 << i][i]);
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}