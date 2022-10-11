#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <iostream>
#include <numeric>
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

int n;
vector<vector<int>> g;

int dfs(int v, int par, int dep, int k) {
    vector<int> vals;
    for (auto u : g[v]) {
        if (u == par) continue;
        vals.emplace_back(dfs(u, v, dep + 1, k));
    }
    if (vals.empty()) return dep;

    vector<int> bad;
    for (auto x : vals) {
        if (x - dep + 1 > k) bad.emplace_back(x);
    }
    if (len(bad) > 1) return n;
    if (len(bad) == 1) return bad[0];
    return *min_element(all(vals));
}

bool can(int k) {
    int dep = dfs(0, 0, 0, k);
    return dep <= k;
}

void solve() {
    g.clear();
    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].emplace_back(u);
        g[u].emplace_back(v);
    }

    int l = 0, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (can(mid)) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}