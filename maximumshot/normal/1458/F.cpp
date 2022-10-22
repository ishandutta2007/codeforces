#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

ll slow(int n, vector<pii> edges) {
    vector<vector<int>> g(n + 1, vector<int>(n + 1, inf));
    for (auto [u, v] : edges)
        g[u][v] = g[v][u] = 1;
    for (int v = 1; v <= n; v++)
        g[v][v] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    ll res = 0;
    for (int l = 1; l <= n; l++) {
        int mx = 0;
        for (int r = l; r <= n; r++) {
            for (int j = l; j <= r; j++)
                mx = max(mx, g[j][r]);
            res += mx;
        }
    }
    return res;
}

struct Circle {
    int c = 0;
    int r = 0;
};

struct CentroidDecomposition {
    int n = 0;
    vector<vector<int>> g, cn;
    vector<vector<ll>> sm;
    vector<pii> parent;
    vector<int> sz;
    vector<int> used;
    vector<ll> total_sm;
    vector<int> total_cn;
    vector<vector<int>> dist;
    vector<int> level;

    CentroidDecomposition() = default;

    CentroidDecomposition(int nn, const vector<vector<int>>& gg) {
        n = nn;
        g = gg;

        parent.resize(n + 1, {-1, -1});
        sm.resize(n + 1);
        cn.resize(n + 1);
        for (int v = 1; v <= n; v++) {
            sm[v].resize(g[v].size());
            cn[v].resize(g[v].size());
        }

        sz.resize(n + 1);
        used.resize(n + 1);
        total_sm.resize(n + 1);
        total_cn.resize(n + 1);
        level.resize(n + 1);

        rec(1);
    }

    void dfs(int v, int par = -1) {
        sz[v] = 1;
        for (int to : g[v]) {
            if (to == par || used[to])
                continue;
            dfs(to, v);
            sz[v] += sz[to];
        }
    }

    void go(int v, int par, int Size, int& centroid) {
        int mx = Size - sz[v];
        for (int to : g[v]) {
            if (to == par || used[to])
                continue;
            go(to, v, Size, centroid);
            if (centroid != -1)
                return;
            mx = max(mx, sz[to]);
        }
        if (mx <= Size / 2)
            centroid = v;
    }

    void set_dist(int v, int par, int lvl) {
        dist[lvl][v] = par == -1 ? 0 : dist[lvl][par] + 1;
        for (int to : g[v]) {
            if (to == par || used[to])
                continue;
            set_dist(to, v, lvl);
        }
    }

    void rec(int v, int lvl = 0, int from_c = -1, int from_id = -1) {
        dfs(v);
        int Size = sz[v];
        int centroid = -1;
        go(v, -1, Size, centroid);
        parent[centroid] = {from_c, from_id};
        used[centroid] = 1;
        level[centroid] = lvl;
        while ((int) dist.size() <= lvl)
            dist.emplace_back(n + 1);
        set_dist(centroid, -1, lvl);
        for (int i = 0; i < (int) g[centroid].size(); i++) {
            int to = g[centroid][i];
            if (used[to])
                continue;
            rec(to, lvl + 1, centroid, i);
        }
    }

    void update_vertex(int v, int type) {
//        cout << "update(" << v << ", " << type << ")\n";
        for (int id = -1, c = v; c != -1; tie(c, id) = parent[c]) {
            total_sm[c] += type * dist[level[c]][v];
            total_cn[c] += type;
            sm[c][id] += type * dist[level[c]][v];
            cn[c][id] += type;
        }
    }

    ll query(int v) {
        ll res = 0;
        for (int id = -1, c = v; c != -1; tie(c, id) = parent[c]) {
            ll hlp_sm = total_sm[c];
            int hlp_cn = total_cn[c];
            if (id != -1) {
                hlp_sm -= sm[c][id];
                hlp_cn -= cn[c][id];
            }
            res += hlp_sm + 1ll * hlp_cn * dist[level[c]][v];
        }
//        cout << "query(" << v << ") = " << res << "\n";
        return res;
    }
};

struct Tree {
    vector<vector<int>> g;
    int n = 0, LOG = 0;
    vector<int> depth;
    vector<vector<int>> parent;
    CentroidDecomposition cd;

    void dfs(int v, int par = -1) {
        depth[v] = par == -1 ? 0 : depth[par] + 1;
        parent[0][v] = par;
        for (int to : g[v]) {
            if (to == par)
                continue;
            dfs(to, v);
        }
    }

    void build() {
        LOG = 0;
        while ((1 << LOG) <= n)
            LOG++;

        depth.resize(n + 1);
        parent.resize(LOG, vector<int>(n + 1, -1));

        dfs(1);

        for (int j = 1; j < LOG; j++) {
            for (int v = 1; v <= n; v++) {
                int pv = parent[j - 1][v];
                if (pv == -1) {
                    parent[j][v] = pv;
                } else {
                    parent[j][v] = parent[j - 1][pv];
                }
            }
        }
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    Tree(int nn, vector<pii> edges) {
        n = nn;
        g.resize(2 * n);
        for (auto [u, v] : edges) {
            int x = ++n;
            add_edge(u, x);
            add_edge(x, v);
        }
        build();
        cd = CentroidDecomposition(n, g);
    }

    vector<int> get_path(int s, int t) {
        vector<int> dist(n + 1, inf), from(n + 1, -1);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    from[to] = v;
                    q.push(to);
                }
            }
        }
        vector<int> path;
        for (int v = t;; v = from[v]) {
            path.push_back(v);
            if (v == s)
                break;
        }
        reverse(path.begin(), path.end());
        return path;
    }

    Circle get_union_slow(Circle w1, Circle w2) {
        vector<int> path = get_path(w1.c, w2.c);
        int D = (int) path.size() - 1;
        if (w1.r > D + w2.r)
            return w1;
        if (w2.r > D + w1.r)
            return w2;
        int R = (w1.r + w2.r + D) / 2;
        return Circle{path[R - w1.r], R};
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

    int get_dist(int u, int v, int w) {
        return depth[u] + depth[v] - 2 * depth[w];
    }

    int jump_to(int fr, int to, int len, int w) {
        int d1 = depth[fr] - depth[w];
        int d2 = depth[to] - depth[w];
        if (len > d1) {
            len = d1 + d2 - len;
            swap(fr, to);
        }
        for (int j = LOG - 1; j >= 0; j--) {
            if ((1 << j) & len)
                fr = parent[j][fr];
        }
        return fr;
    }

    Circle get_union(Circle w1, Circle w2) {
        int w = get_lca(w1.c, w2.c);
        int D = get_dist(w1.c, w2.c, w);
        if (w1.r > D + w2.r)
            return w1;
        if (w2.r > D + w1.r)
            return w2;
        int R = (w1.r + w2.r + D) / 2;
        return Circle{jump_to(w1.c, w2.c, R - w1.r, w), R};
    }

    void update_vertex(int v, int type) {
        cd.update_vertex(v, type);
    }

    ll query(int v) {
        return cd.query(v);
    }
};

ll fast(int n, vector<pii> edges) {
    ll res = 0;
    vector<Circle> ws(n + 1);
    Tree tree(n, edges);
    vector<ll> suff_r(n + 1);
    function<void(int, int)> rec = [&](int l, int r) {
        if (l == r)
            return;
        int m = (l + r) / 2;
        rec(l, m);
        rec(m + 1, r);
        for (int i = m; i >= l; i--) {
            ws[i] = Circle{i, 0};
            if (i < m)
                ws[i] = tree.get_union(ws[i], ws[i + 1]);
        }
        for (int i = m + 1; i <= r; i++) {
            ws[i] = Circle{i, 0};
            if (i > m + 1)
                ws[i] = tree.get_union(ws[i], ws[i - 1]);
        }
        for (int i = r; i > m; i--) {
            suff_r[i] = ws[i].r;
            if (i < r)
                suff_r[i] += suff_r[i + 1];
        }
        ll hlp = 0;
        int ql = m + 1, qr = m + 1;
        for (int i = m; i >= l; i--) {
            const auto& w1 = ws[i];
            while (ql <= r) {
                const auto& w2 = ws[ql];
                int lca = tree.get_lca(w1.c, w2.c);
                int D = tree.get_dist(w1.c, w2.c, lca);
                if (w1.r <= w2.r + D)
                    break;
                tree.update_vertex(w2.c, -1);
                ql++;
            }
            while (qr < ql)
                tree.update_vertex(ws[qr++].c, +1);
            while (qr <= r) {
                const auto& w2 = ws[qr];
                int lca = tree.get_lca(w1.c, w2.c);
                int D = tree.get_dist(w1.c, w2.c, lca);
                if (w2.r > w1.r + D)
                    break;
                tree.update_vertex(w2.c, +1);
                qr++;
            }
            res += 1ll * max(0, ql - (m + 1)) * ws[i].r;
            if (qr <= r)
                res += suff_r[qr];
            hlp += 1ll * ws[i].r * (qr - ql);
            hlp += (ql <= r ? suff_r[ql] : 0) - (qr <= r ? suff_r[qr] : 0);
            hlp += tree.query(w1.c);
        }
        while (ql < qr)
            tree.update_vertex(ws[ql++].c, -1);
        res += hlp / 2;
    };
    rec(1, n);
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<pii> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i].first >> edges[i].second;
    ll fs = fast(n, edges);
    cout << fs << "\n";
}

void test() {
    mt19937 rnd(42);
    const int N = 150;
    while (1) {
        int n = rnd() % N + 1;
        vector<pii> edges(n - 1);
        for (int i = 0; i < n - 1; i++) {
            edges[i].second = i + 2;
            edges[i].first = rnd() % (edges[i].second - 1) + 1;
        }
        ll fs = fast(n, edges);
        ll sl = slow(n, edges);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << "\n";
            cout << n << "\n";
            for (auto [u, v] : edges)
                cout << u << " " << v << "\n";
            break;
        }
    }
}

void max_test() {
    mt19937 rnd(42);
    double st = clock();
    while (1) {
        int n = 1e5;
        vector<pii> edges(n - 1);
        for (int i = 0; i < n - 1; i++) {
            edges[i].second = i + 2;
            int k = min(4000, edges[i].second - 1); // [1, k]
            edges[i].first = edges[i].second - (rnd() % k + 1);
        }
        ll fs = fast(n, edges);
        cout << fs << "\n";
        break;
    }
    cout << (clock() - st) / CLOCKS_PER_SEC << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}