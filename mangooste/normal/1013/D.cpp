#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> par, sz;
    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    inline int get_par(int v) {
        return par[v] == v ? v : par[v] = get_par(par[v]);
    }

    inline bool uni(int v, int u) {
        v = get_par(v);
        u = get_par(u);
        if (v == u)
            return false;
        if (sz[v] < sz[u])
            swap(v, u);
        par[u] = v;
        sz[v] += sz[u];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    DSU dsu(n + m);
    int ans = n + m - 1;
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        ans -= dsu.uni(i, n + j);
    }
    cout << ans << '\n';
}