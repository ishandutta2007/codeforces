#include<bits/stdc++.h>
using namespace std;
const int nax = 2048;
int a[nax >> 1][nax >> 1];
int n;

struct DSU {
    vector <int> par;
    vector <int> sz;
    int n;

    DSU(int n) : n(n), par(n + 1), sz(n + 1) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

};


void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= n ; ++ j)
            cin >> a[i][j];
    }
    DSU ds(2 * n);

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = i + 1 ; j <= n ; ++ j) {
            if (a[i][j] > a[j][i]) {
                /**
                    it means that we must swap, in other words,
                    i ^ j or i and j is in different component
                */
                if (!ds.same(i, j) || !ds.same(i + n, j + n)) {
                    swap(a[i][j], a[j][i]);
                    ds.unite(i, j + n);
                    ds.unite(j, i + n);
                }
            } else if (a[i][j] < a[j][i]) {
                /**
                    it means that we must not swap this, or
                    i and j is in the same component
                */
                if (ds.same(i, j + n) || ds.same(i + n, j)) {
                    swap(a[i][j], a[j][i]);
                } else {
                    ds.unite(i, j);
                    ds.unite(i + n, j + n);;
                }
            }
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= n ; ++ j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}