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

struct DSU {
    int n = 0; // [0, n)
    vector<int> p;

    DSU(int nn) {
        n = nn;
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        p[y] = x;
    }
};

struct output {
    string res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct Tree {
    int n = 0; // [0, n)
    vector<vector<int>> g;
    vector<int> tin, tout, depth, f;
    vector<vector<int>> p;
    int LOG;
    int timer = 0;

    Tree() = default;

    Tree(vector<pii> es) {
        n = (int) es.size() + 1;
        g.resize(n);
        for (auto [u, v] : es) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        LOG = 0;
        while ((1 << LOG) <= n) LOG++; LOG++;
        p.assign(LOG, vector<int>(n, -1));
        depth.resize(n);
        tin.resize(n);
        tout.resize(n);
        f.assign(n, 0);
        dfs(0);
        for (int j = 1; j < LOG; j++) {
            for (int v = 0; v < n; v++) {
                int pv = p[j - 1][v];
                if (pv == -1) {
                    p[j][v] = -1;
                } else {
                    p[j][v] = p[j - 1][pv];
                }
            }
        }
    }

    void dfs(int v, int par = -1) {
        depth[v] = par == -1 ? 0 : depth[par] + 1;
        tin[v] = timer++;
        p[0][v] = par;
        for (int to : g[v]) {
            if (to == par)
                continue;
            dfs(to, v);
        }
        tout[v] = timer;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int j = LOG - 1; j >= 0; j--) {
            int pu = p[j][u];
            if (pu == -1 || depth[pu] < depth[v]) continue;
            u = pu;
        }
        for (int j = LOG - 1; j >= 0; j--) {
            int pu = p[j][u];
            int pv = p[j][v];
            if (pu == -1 || pv == -1 || pu == pv) continue;
            u = pu;
            v = pv;
        }
        if (u != v) u = p[0][u];
        return u;
    }

    void update_subtree(int v, int dx, int inclusive) {
        int l, r;
        if (inclusive) {
            l = tin[v], r = tout[v] - 1;
        } else {
            l = tin[v] + 1, r = tout[v] - 1;
        }
//        for (int i = l; i <= r; i++)
//            f[i] += dx;
        update_f(l, r, dx);
    }

    void update_uptree(int v, int dx) {
        update_f(0, tin[v] - 1, dx);
        update_f(tout[v], n - 1, dx);
    }

    void update_f(int l, int r, int dx) {
        if (l > r) return;
        for (int cur = l; cur < n; cur |= (cur + 1)) f[cur] += dx;
        for (int cur = r + 1; cur < n; cur |= (cur + 1)) f[cur] -= dx;
    }

    int jump(int son, int par) {
        for (int j = LOG - 1; j >= 0; j--) {
            int nson = p[j][son];
            if (nson == -1 || depth[nson] <= depth[par]) continue;
            son = nson;
        }
        return son;
    }

    int get(int v) {
        int res = 0;
        for (int cur = tin[v]; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res += f[cur];
        return res;
//        return f[tin[v]];
    }
};

struct input {
    int n, m;
    vector<pii> es;

    input() = default;

    void read() {
        cin >> n >> m;
        es.resize(m);
        for (auto& [u, v] : es) {
            cin >> u >> v;
            u--, v--;
        }
    }

    void print() {
        cout << n << " " << m << "\n";
    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> in(m);
        DSU dsu(n);
        vector<pii> tr_es;
        for (int i = 0; i < m; i++) {
            auto [u, v] = es[i];
            if (dsu.find(u) != dsu.find(v)) {
                dsu.merge(u, v);
                in[i] = 1;
                tr_es.emplace_back(u, v);
            }
        }
        Tree tr(tr_es);
        int total = 0;
        for (int i = 0; i < m; i++) {
            if (!in[i]) {
                total++;
                auto [u, v] = es[i];
                int w = tr.get_lca(u, v);
                if (tr.depth[u] > tr.depth[v]) swap(u, v);
                if (u == w) {
                    tr.update_subtree(v, +1, 1);

                    tr.update_subtree(u, +1, 1);
                    int z = tr.jump(v, u);
                    tr.update_subtree(z, -1, 1);

                    tr.update_uptree(u, +1);
                } else {
                    tr.update_subtree(u, +1, 1);
                    tr.update_subtree(v, +1, 1);
                }
            }
        }
        string res(n, '0');
        for (int i = 0; i < n; i++) {
            if (tr.get(i) == total)
                res[i] = '1';
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return output();
    }
#endif
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

#ifdef DEBUG
void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
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
#endif

#ifdef DEBUG
void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}
#endif

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