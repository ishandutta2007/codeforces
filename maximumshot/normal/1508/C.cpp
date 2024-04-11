#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Edge {
    int u = 0;
    int v = 0;
    int w = 0;

    int get_to(int x) {
        return u == x ? v : u;
    }
};

struct DSU {
    int n = 0; // [1, n]
    vector<int> p, sz;

    DSU(int nn) {
        n = nn;
        p.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

ll slow(int n, int m, vector<Edge> edges) {
    vector<vector<ll>> G(n + 1, vector<ll>(n + 1)), H;
    ll xr = 0;
    for (auto e : edges) {
        G[e.u][e.v] = G[e.v][e.u] = e.w;
        xr ^= e.w;
    }
    auto calc_mst = [&]() -> ll {
        ll W = 0;
        vector<pii> es;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++)
                es.emplace_back(j, i);
        }
        sort(es.begin(), es.end(), [&](pii e1, pii e2){
            return H[e1.first][e1.second] < H[e2.first][e2.second];
        });
        DSU dsu(n);
        for (auto [u, v] : es) {
            if (dsu.merge(u, v))
                W += H[u][v];
        }
        return W;
    };
    ll res = inf64;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (G[i][j])
                continue;
            H = G;
            H[i][j] = H[j][i] = xr;
            res = min(res, calc_mst());
        }
    }
    return res;
}

const int LOG = 21;
struct Tree {
    int n = 0;
    vector<vector<pii>> g;
    vector<int> depth, parent[LOG], zeros;

    Tree(int nn, vector<vector<pii>> gg) {
        n = nn;
        g = gg;
        depth.resize(n + 1);
        for (int j = 0; j < LOG; j++)
            parent[j].resize(n + 1, -1);
        zeros.resize(n + 1);
        dfs(1, -1);
        for (int j = 1; j < LOG; j++) {
            for (int v = 1; v <= n; v++) {
                int pv = parent[j - 1][v];
                if (pv == -1) {
                    parent[j][v] = -1;
                } else {
                    parent[j][v] = parent[j - 1][pv];
                }
            }
        }
    }

    void dfs(int v, int par) {
        parent[0][v] = par;
        depth[v] = par == -1 ? 0 : depth[par] + 1;
        for (auto [to, w] : g[v]) {
            if (to == par)
                continue;
            zeros[to] = zeros[v] + (w == 0);
            dfs(to, v);
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        for (int j = LOG - 1; j >= 0; j--) {
            int pu = parent[j][u];
            if (pu == -1 || depth[pu] < depth[v])
                continue;
            u = pu;
        }
        for (int j = LOG - 1; j >= 0; j--) {
            int pu = parent[j][u];
            int pv = parent[j][v];
            if (pu == -1 || pv == -1 || pu == pv)
                continue;
            u = pu;
            v = pv;
        }
        if (u != v)
            u = parent[0][u];
        return u;
    }

    int query(int u, int v) {
        int w = get_lca(u, v);
        return zeros[u] + zeros[v] - 2 * zeros[w];
    }
};

ll fast(int n, int m, vector<Edge> edges) {
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        auto e = edges[i];
        g[e.u].push_back(i);
        g[e.v].push_back(i);
    }
    for (int v = 1; v <= n; v++) {
        sort(g[v].begin(), g[v].end(), [&](int e1, int e2) {
            return edges[e1].get_to(v) < edges[e2].get_to(v);
        });
    }

    set<int> Q;
    for (int v = 1; v <= n; v++)
        Q.insert(v);
    vector<int> color(n + 1);
    int cc = 0;
    function<void(int)> dfs = [&](int v) {
        color[v] = cc;
        Q.erase(v);
        int last = 0;
        for (int it = 0; it <= (int) g[v].size(); it++) {
            int to = n + 1;
            if (it < (int) g[v].size()) {
                int eid = g[v][it];
                auto e = edges[eid];
                to = e.get_to(v);
            }
            while (1) {
                auto it = Q.upper_bound(last);
                if (it == Q.end() || *it >= to)
                    break;
                dfs(*it);
            }
            last = to;
        }
    };
    for (int s = 1; s <= n; s++) {
        if (!Q.count(s))
            continue;
        cc++;
        dfs(s);
    }
    vector<int> for_mst;
    for (int i = 0; i < m; i++) {
        auto e = edges[i];
        if (color[e.u] != color[e.v])
            for_mst.push_back(i);
    }
    sort(for_mst.begin(), for_mst.end(), [&](int e1, int e2) {
        return edges[e1].w < edges[e2].w;
    });
    ll res = 0;
    DSU dsu(cc);
    vector<int> in_mst(m);
    for (int it : for_mst) {
        auto e = edges[it];
        if (dsu.merge(color[e.u], color[e.v])) {
            in_mst[it] = 1;
            res += e.w;
        }
    }
    vector<ll> cnt_v(cc + 1);
    for (int v = 1; v <= n; v++)
        cnt_v[color[v]]++;
    vector<ll> cnt_e(cc + 1);
    for (int c = 1; c <= cc; c++)
        cnt_e[c] = 1ll * cnt_v[c] * (cnt_v[c] - 1) / 2;
    for (auto e : edges) {
        int cu = color[e.u];
        int cv = color[e.v];
        if (cu != cv)
            continue;
        cnt_e[cu]--;
    }
    int E = 0;
    for (int c = 1; c <= cc; c++) {
        if (cnt_e[c] > cnt_v[c] - 1)
            return res;
        E += cnt_e[c];
    }
    ll xr = 0, mn = inf64;
    for (int it = 0; it < m; it++) {
        auto e = edges[it];
        xr ^= e.w;
    }
    // n <= sqrt(2e5)

    ll glob = res + xr;

    vector<vector<pii>> tree(n + 1);
    for (int i = 0; i < m; i++) {
        if (in_mst[i]) {
            auto e = edges[i];
            tree[e.u].emplace_back(e.v, e.w);
            tree[e.v].emplace_back(e.u, e.w);
        }
    }

    vector<vector<int>> G(n + 1, vector<int>(n + 1));
    for (auto e : edges)
        G[e.u][e.v] = G[e.v][e.u] = e.w;

    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (color[u] == color[v] && G[u][v] == 0) {
                tree[u].emplace_back(v, 0);
                tree[v].emplace_back(u, 0);
            }
        }
    }

    Tree tr(n, tree);

    for (int i = 0; i < m; i++) {
        if (in_mst[i])
            continue;
        auto e = edges[i];
        if (tr.query(e.u, e.v) > 0)
            glob = min(glob, res + e.w);
    }

    return glob;
}

void work() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& e : edges)
        cin >> e.u >> e.v >> e.w;
    ll fs = fast(n, m, edges);
    cout << fs << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 10;
    const int MAXW = 127;
    while (1) {
        int n = rnd() % MAXN + 2;
        int m = rnd() % ((n * (n - 1) / 2));
        vector<pii> es;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++)
                es.emplace_back(i, j);
        }
        shuffle(es.begin(), es.end(), rnd);
        vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            auto& e = edges[i];
            tie(e.u, e.v) = es[i];
            e.w = rnd() % MAXW + 1;
        }
        auto fs = fast(n, m, edges);
        auto sl = slow(n, m, edges);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << " " << m << "\n";
            for (auto e : edges)
                cout << e.u << " " << e.v << " " << e.w << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}