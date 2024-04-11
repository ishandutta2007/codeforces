#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> freq(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        freq[a[i]].push_back(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int j = 0; j < n; j++)
        for (int i = j; i >= 0; i--) {
            dp[i][j] = i == j ? 1 : dp[i + 1][j] + 1;

            for (auto k : freq[a[i]])
                if (i < k && k <= j)
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
        }

    cout << dp[0][n - 1] - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}