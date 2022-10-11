#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &xs : a)
        for (auto &x : xs)
            cin >> x;

    vector<int> mx(m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mx[i] = max(mx[i], a[j][i]);
    vector<int> cols(m);
    iota(cols.begin(), cols.end(), 0);
    sort(cols.begin(), cols.end(), [&](int a, int b) {
        return mx[a] > mx[b];
    });
    cols.resize(min(n, m));

    const int MASK = (1 << n);
    vector<vector<int>> bits(MASK);
    for (int mask = 0; mask < MASK; mask++)
        for (int i = 0; i < n; i++)
            if ((mask >> i) % 2)
                bits[mask].push_back(i);

    vector<vector<int>> submasks(MASK);
    for (int mask = 0; mask < MASK; mask++) {
        int cur = (1 << int(bits[mask].size()));
        submasks[mask].resize(cur);
        for (int i = 1; i < cur; i++) {
            int j = bits[i][0];
            submasks[mask][i] = submasks[mask][i ^ (1 << j)] + (1 << bits[mask][j]);
        }
    }

    vector<int> dp(MASK);
    for (auto col : cols) {
        vector<int> best(MASK);
        vector<int> sum(MASK);
        for (int rep = 0; rep < n; rep++)
            for (int mask = 1; mask < MASK; mask++) {
                int i = bits[mask][0];
                sum[mask] = sum[mask ^ (1 << i)] + a[(i + rep) % n][col];
                best[mask] = max(best[mask], sum[mask]);
            }

        auto ndp = dp;
        for (int mask = 1; mask < MASK; mask++)
            for (int submask : submasks[mask])
                ndp[mask] = max(ndp[mask], best[submask] + dp[mask ^ submask]);
        dp = ndp;
    }
    cout << dp.back() << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}