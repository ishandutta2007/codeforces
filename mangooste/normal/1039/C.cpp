#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

const int MOD = int(1e9) + 7;

vector<int> p2;

void init(int n) {
    p2.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2;
        if (p2[i] >= MOD) p2[i] -= MOD;
    }
}

struct DSU {
    int cnt;
    vector<int> par;
    vector<int> sz;
    vector<pair<int, int>> changes;

    DSU(int n) : cnt(n) {
        par.resize(n);
        iota(all(par), 0);
        sz.resize(n, 1);
    }

    int getPar(int v) {
        return par[v] == v ? v : par[v] = getPar(par[v]);
    }

    void unite(int v, int u) {
        v = getPar(v);
        u = getPar(u);
        if (v == u) {
            changes.emplace_back(-1, -1);
            return;
        }

        if (sz[v] < sz[u]) swap(v, u);
        cnt--;
        sz[v] += sz[u];
        par[u] = v;
        changes.emplace_back(v, u);
    }

    void back() {
        auto [v, u] = changes.back();
        changes.pop_back();
        if (v == -1 || u == -1) return;

        cnt++;
        sz[v] -= sz[u];
        par[u] = u;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> c(n);
    for (auto &x : c) {
        cin >> x;
    }
    map<ll, vector<pair<int, int>>> mp;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        mp[c[v] ^ c[u]].emplace_back(v, u);
    }
    init(n);

    int ans = 0;
    DSU dsu(n);
    for (auto &[_, edges] : mp) {
        for (auto [u, v] : edges) {
            dsu.unite(u, v);
        }
        ans += p2[dsu.cnt];
        if (ans >= MOD) ans -= MOD;
        for (int i = 0; i < len(edges); i++) {
            dsu.back();
        }
    }

    ans += ll((1ll << k) - len(mp)) % MOD * p2[n] % MOD;
    if (ans >= MOD) ans -= MOD;
    cout << ans << '\n';
}