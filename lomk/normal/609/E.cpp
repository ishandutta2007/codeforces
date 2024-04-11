/*input
8 10
8 7 11
3 5 23
2 1 23
7 2 13
6 4 18
1 4 20
8 4 17
2 8 8
3 2 9
5 6 29
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define bit(x, k) (1ll&(x >> k))

using ll = long long;
const int N = 2e5 + 5;
const ll INF = 1e18;

struct Edge {
    int u, v, c, id;
    Edge(int _u, int _v, int _c, int _id): u(_u), v(_v), c(_c), id(_id) {};
};

struct Data {
    int par; ll maxc = -INF;
    Data() = default;
};

struct Dsu {
    vector<int> par;

    void init(int n) {
        par.resize(n + 5, 0);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;

int n, m; ll mstWeight = 0;
int h[N]; ll res[N];
vector <Edge> edges;
vector <pair <int, int>> g[N];
Data up[N][21];

void dfs(int u, int p) {
    up[u][0].par = p;
    for (auto &e : g[u]) {
        int v = e.fi; int c = e.se;
        if (v == p) continue;
        h[v] = h[u] + 1;
        up[v][0].maxc = c;
        dfs(v, u);
    }
}

// tm cnh c trng s ln nht trn ng i u, v nh bi LUBENICA
ll lca(int u, int v) {
    ll ret = -INF;
    if (h[u] < h[v]) swap(u, v);
    int depth = h[u] - h[v];
    for (int i = 0; i <= 20; i++) {
        if (bit(depth, i)) {
            ret = max(ret, up[u][i].maxc);
            u = up[u][i].par;
        }
    }

    if (u == v) return ret;

    for (int i = 20; i >= 0; i--) {
        if (up[u][i].par != up[v][i].par) {
            ret = max({ret, up[u][i].maxc, up[v][i].maxc});
            u = up[u][i].par; v = up[v][i].par;
        }
    }
    ret = max({ret, up[u][0].maxc, up[v][0].maxc});
    return ret;
}

void buildMST() {
    dsu.init(n);
    sort(edges.begin(), edges.end(), [](Edge & x, Edge & y) {
        return x.c < y.c;
    });

    for (auto &e : edges) {
        if (!dsu.join(e.u, e.v)) continue;
        g[e.u].push_back({e.v, e.c});
        g[e.v].push_back({e.u, e.c});
        res[e.id] = -1; // nh du l cnh ny thuc cy khung nh nht
        mstWeight += e.c;
    }
}

void buildLCA() {
    dfs(1, 1);
    for (int i = 1; i <= 20; i++) {
        for (int u = 1; u <= n; u++) {
            up[u][i].par = up[up[u][i - 1].par][i - 1].par;
            up[u][i].maxc = max(up[u][i - 1].maxc, up[up[u][i - 1].par][i - 1].maxc);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c, i});
    }

    // dng cy khung nh nht
    buildMST();

    // dng LCA
    buildLCA();

    // tm cy khung nh nht cho tng cnh
    for (auto &e : edges) {
        if (res[e.id] == -1) res[e.id] = mstWeight;
        else res[e.id] = mstWeight - lca(e.u, e.v) + e.c;
    }

    // in ra kt qu
    for (int i = 1; i <= m; i++) cout << res[i] << "\n";
    return 0;
}