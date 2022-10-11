#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> par;
    vector<int> sz;

    DSU() {}
    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    DSU dsu(n);
    int ans = 0;
    while (k--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        ans += !dsu.unite(v, u);
    }
    cout << ans << '\n';
}