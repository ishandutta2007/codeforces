#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    for (int &x: a) --x;
    vector<vector<bool>> hasMajor(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < n; ++i) {
        vector<int> count(n);
        int maxCount = 0;
        for (int j = i; j <= n; ++j) {
            hasMajor[i][j] = maxCount * 2 > j - i;
            if (j != n) maxCount = max(maxCount, ++count[a[j]]);
        }
    }
    vector<int> d = a;
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    int ans = -1e9;
    for (int x: d) {
        vector<int> dp(n + 1, -1e9);
        vector<int> ind{0};
        for (int i = 0; i < n; ++i) if (a[i] == x) ind.push_back(i + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i - 1] == x) dp[i] = dp[i - 1] + 1;
            if (i == n || a[i] == x) {
                for (int j: ind) {
                    if (i % 2 == j % 2 && !hasMajor[j][i]) dp[i] = max(dp[i], dp[j]);
                }
            }
        }
        ans = max(ans, dp[n]);
    }
    cout << ans << '\n';
}