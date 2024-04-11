#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

struct DSU {
    vector<int> par;
    vector<int> sz;

    DSU() {}
    DSU(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    inline int getPar(int v) {
        return par[v] == v ? v : par[v] = getPar(par[v]);
    }

    inline bool unite(int v, int u) {
        v = getPar(v);
        u = getPar(u);
        if (v == u) return false;
        if (sz[v] < sz[u]) swap(v, u);
        par[u] = v;
        sz[v] += sz[u];
        return true;
    }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> m >> n;
    vector<int> a(m);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> b(n);
    for (auto &x : b) {
        cin >> x;
    }

    vector<array<int, 3>> edges;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int v;
            cin >> v;
            v--;
            ans += a[i] + b[v];
            edges.push_back({i + n, v, a[i] + b[v]});
        }
    }
    sort(all(edges), [](array<int, 3> &a, array<int, 3> &b) {
        return a[2] > b[2];
    });
    dbg(edges);

    DSU dsu(n + m);
//    dbg(ans);
    for (auto [u, v, cost] : edges) {
//        dbg(u, v, cost, ans);
        ans -= cost * dsu.unite(u, v);
//        dbg(ans);
    }
    cout << ans << '\n';
}