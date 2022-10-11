#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    for (auto &x : c) {
        cin >> x;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[u].emplace_back(v);
    }

    map<vector<int>, ll> sums;
    for (int i = 0; i < n; i++) {
        if (g[i].empty()) continue;
        sort(all(g[i]));
        sums[g[i]] += c[i];
    }

    ll ans = 0;
    for (auto [_, sum] : sums) {
        ans = gcd(ans, sum);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}