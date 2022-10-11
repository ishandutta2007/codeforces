#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(2));
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(2));
        for (int i = 0; i < n; i++) {
            cin >> a[i][1]; a[i][0] = -a[i][1];
            if (i == 0) {
                dp[i][0] = dp[i][1] = {-n - 1, 0};
            } else {
                for (int j = 0; j < 2; j++) {
                    dp[i][j] = {n + 1, 0};
                    for (int k = 0; k < 2; k++) {
                        if (a[i - 1][k] < a[i][j]) {
                            dp[i][j] = min(dp[i][j], {dp[i - 1][k].first, k});
                        }
                        if (dp[i - 1][k].first < a[i][j]) {
                            dp[i][j] = min(dp[i][j], {a[i - 1][k], k});
                        }
                    }
                }
            }
        }
        for (int cur = 0; cur < 2; cur++) {
            if (dp[n - 1][cur].first <= n) {
                cout << "YES\n";
                for (int i = n - 1; i >= 0; i--) {
                    a[i][0] = a[i][cur];
                    cur = dp[i][cur].second;
                }
                for (int i = 0; i < n; i++) {
                    cout << a[i][0] << " \n"[i == n - 1];
                }
                goto hell;
            }
        }
        cout << "NO\n";
    hell:
        continue;
    }
}