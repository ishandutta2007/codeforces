#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

struct output {
    vector<pii> res;

    output() = default;

    void print() {
        for (auto [max_e, need_cost] : res)
            cout << max_e << " " << need_cost << "\n";
    }

    bool operator == (const output& o) const {
        return true;
    }
};

struct Tree {
    int n = 0; // [1, n]
    vector<int> depth;
    vector<vector<pii>> g;
    int LOG;
    vector<vector<int>> p, w;

    Tree() = default;

    Tree(vector<tuple<int, int, int>> edges) {
        n = (int) edges.size() + 1;

        LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        p.resize(LOG, vector<int>(n + 1, -1));
        w.resize(LOG, vector<int>(n + 1, 0));
        g.resize(n + 1);
        depth.resize(n + 1);

        for (auto [u, v, cost] : edges) {
            g[u].emplace_back(v, cost);
            g[v].emplace_back(u, cost);
        }

        dfs(1);

        for (int j = 1; j < LOG; j++) {
            for (int v = 1; v <= n; v++) {
                int pv = p[j - 1][v];
                if (pv != -1) {
                    p[j][v] = p[j - 1][pv];
                    w[j][v] = max(w[j - 1][v], w[j - 1][pv]);
                }
            }
        }
    }

    void dfs(int v, int par = -1) {
        p[0][v] = par;
        depth[v] = par == -1 ? 0 : depth[par] + 1;
        for (auto [to, cost] : g[v]) {
            if (to == par)
                continue;
            w[0][to] = cost;
            dfs(to, v);
        }
    }

    int get_lca(int x, int y) {
        if (depth[x] < depth[y]) swap(x, y);
        for (int j = LOG - 1; j >= 0; j--) {
            int px = p[j][x];
            if (px == -1 || depth[px] < depth[y])
                continue;
            x = px;
        }
        for (int j = LOG - 1; j >= 0; j--) {
            int px = p[j][x];
            int py = p[j][y];
            if (px == -1 || py == -1 || px == py)
                continue;
            x = px;
            y = py;
        }
        if (x != y)
            x = p[0][x];
        return x;
    }

    int get_max_ver(int S, int P) {
        int res = 0;
        for (int j = LOG - 1; j >= 0; j--) {
            int pS = p[j][S];
            if (pS == -1 || depth[pS] < depth[P])
                continue;
            res = max(res, w[j][S]);
            S = pS;
        }
        return res;
    }

    int get_max(int s, int t) {
        int z = get_lca(s, t);
        return max(get_max_ver(s, z), get_max_ver(t, z));
    }
};

struct DSU {
    int n = 0; // [1, n]
    Tree T;
    vector<int> e;
    vector<int> crd;
    vector<int> p;
    vector<pii> mx;
    vector<map<int, tuple<int, int, int>>> info;

    DSU() = default;

    DSU(Tree T_, vector<int> e_) {
        T = T_;
        e = e_;
        n = T.n;

        crd = e_;
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());

        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        mx.resize(n + 1);
        info.resize(n + 1);
        for (int v = 1; v <= n; v++) {
            mx[v] = {lower_bound(crd.begin(), crd.end(), e[v]) - crd.begin(), v};
            info[v][mx[v].first] = {0, v, v};
        }
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;

        if (info[v].size() > info[u].size())
            swap(u, v);

        p[v] = u;
        mx[u] = max(mx[u], mx[v]);

        for (auto item : info[v]) {
            int eid = item.first;
            auto [mxe1, front1, back1] = item.second;
            auto [mxe2, front2, back2] = info[u][eid];
            int mxe, front, back;
            if (front2) {
                mxe = max({mxe1, mxe2, T.get_max(back1, front2), T.get_max(back2, front1)});
                front = front1;
                back = back2;
            } else {
                mxe = mxe1, front = front1, back = back1;
            }
            info[u][eid] = {mxe, front, back};
        }
    }

    pii query(int v) {
        int pv = find(v);
        auto [eid, u] = mx[pv];
        int max_e = crd[eid];
        int need_cost = max({T.get_max(v, u), get<0>(info[pv][eid])});
        return {max_e, need_cost};
    }
};

struct input {
    int n, q;
    vector<int> e;

    struct Edge {
        int u;
        int v;
        int cap;
        int cost;
    };

    vector<Edge> edges;

    struct Query {
        int v;
        int x;
        int id;
    };

    vector<Query> queries;

    input() = default;

    void read() {
        cin >> n >> q;
        e.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> e[i];
        edges.resize(n - 1);
        for (auto& edge : edges)
            cin >> edge.u >> edge.v >> edge.cap >> edge.cost;
        queries.resize(q);
        for (auto& query : queries)
            cin >> query.v >> query.x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) {
            return e1.cap > e2.cap;
        });
        for (int i = 0; i < q; i++)
            queries[i].id = i;
        sort(queries.begin(), queries.end(), [](Query q1, Query q2) {
            return q1.v > q2.v;
        });
        vector<tuple<int, int, int>> cost_edges;
        for (auto edge : edges)
            cost_edges.emplace_back(edge.u, edge.v, edge.cost);
        Tree T(cost_edges);
        DSU dsu(T, e);
        output res;
        res.res.resize(q);
        for (int edges_it = 0, it = 0; it < q; it++) {
            Query query = queries[it];
            while (edges_it < (int) edges.size() && edges[edges_it].cap >= query.v) {
                Edge edge = edges[edges_it++];
                dsu.merge(edge.u, edge.v);
            }
            res.res[query.id] = dsu.query(query.x);
        }
        return res;
    }

    output slow() {
        return output();
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

void test() {
    while (1) {
        input in;
        in.gen();
        output fs = in.fast();
        output sl = in.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
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