//#define _GLIBCXX_DEBUG
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
int n, m;
const int maxN = 12;
const int maxM = 2005;
int a[maxN][maxM];
int dp[(1 << maxN) + 2];
int ndp[(1 << maxN) + 2];
int buf[(1 << maxN) + 2];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<int,int>> all;
    for (int j = 0; j < m; j++) {
        int mx = 0;
        for (int i = 0; i < n; i++) mx = max(mx, a[i][j]);
        all.emplace_back(mx, j);
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    if (all.size() > n) all.resize(n);
    for (int i = 0; i < (1 << n); i++) {
        dp[i] = ndp[i] = -1e9;
    }
    dp[0] = 0;
    for (auto& it : all) {
        int col = it.second;
        for (int shift = 0; shift < n; shift++) {
            memcpy(buf, dp, sizeof(buf));
            for (int who = 0; who < n; who++) {
                int pos = (who + shift) % n;
                for (int mask = 0; mask < (1 << n); mask++) {
                    if (!(mask & (1 << pos))) {
                        buf[mask | (1 << pos)] = max(buf[mask | (1 << pos)], buf[mask] + a[who][col]);
                    }
                }
            }
            for (int mask = 0; mask < (1 << n); mask++) ndp[mask] = max(ndp[mask], buf[mask]);
        }
        for (int i = 0; i < (1 << n); i++) {
            dp[i] = ndp[i];
            ndp[i] = -1e9;
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  //  freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}