#include <bits/stdc++.h>
using namespace std;
using llf = long double;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, d; cin >> n >> d;
    vector<int> v(n);
    for (int &vi : v) cin >> vi;
    if (d == 0) {
        bool found = false;
        for (int vi : v)
            found |= vi % 10 == 0;
        if (not found) {
            cout << "-1\n";
        } else {
            cout << n << '\n';
            for (int i = 0; i < n; ++i)
                cout << v[i] << " \n"[i + 1 == n];
        }
        return 0;
    }
    vector<array<pair<llf, int>, 10>> dp(n + 1);
    for (int i = 0; i < 10; ++i)
        dp[0][i] = {-1e100, -1e9};
    dp[0][1] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 10; ++j)
            dp[i][j] = dp[i - 1][j];
        for (int j = 0; j < 10; ++j) {
            int dd = j * v[i - 1] % 10;
            pair nv = {dp[i - 1][j].first + log(v[i - 1]), dp[i - 1][j].second + 1};
            dp[i][dd] = max(dp[i][dd], nv);
        }
    }
    if (dp[n][d].first < 0 or dp[n][d].second == 0) {
        cout << "-1\n";
        return 0;
    }
    vector<int> ans;
    for (int i = n; i >= 1; --i) {
        if (dp[i][d] != dp[i - 1][d]) {
            for (int j = 1; j < 10; ++j) {
                int dd = j * v[i - 1] % 10;
                if (dd != d) continue;
                pair nv = {dp[i - 1][j].first + log(v[i - 1]), dp[i - 1][j].second + 1};
                if (dp[i][d] == nv) {
                    ans.push_back(v[i - 1]);
                    d = j;
                    break;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    return 0;
}