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

struct Dinic {
    struct Edge {
        int fr, to, cp, id, fl;
    };
    int n, S, T;
    vector<Edge> es;
    vector<vector<int>> g;
    vector<int> dist, res, ptr;
    Dinic(int n_, int S_, int T_)
            : n(n_), S(S_), T(T_) {
        g.resize(n);
    }
    int add_edge(int fr, int to, int cp, int id) {
        int eid = (int) es.size();
        g[fr].push_back((int)es.size());
        es.push_back({fr, to, cp, id, 0});
        g[to].push_back((int)es.size());
        es.push_back({to, fr, 0, -1, 0});
        return eid;
    }
    bool bfs(int K) {
        dist.assign(n, inf);
        dist[S] = 0;
        queue<int> q;
        q.push(S);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int ps : g[v]) {
                Edge& e = es[ps];
                if (e.fl + K > e.cp) continue;
                if (dist[e.to] > dist[e.fr] + 1) {
                    dist[e.to] = dist[e.fr] + 1;
                    q.push(e.to);
                }
            }
        }
        return dist[T] < inf;
    }
    int dfs(int v, int _push = INT_MAX) {
        if (v == T || !_push) return _push;
        for (int& iter = ptr[v];
             iter < (int)g[v].size(); iter++) {
            int ps = g[v][ptr[v]];
            Edge& e = es[ps];
            if (dist[e.to] != dist[e.fr] + 1) continue;
            int tmp =
                    dfs(e.to, min(_push, e.cp - e.fl));
            if (tmp) {
                e.fl += tmp;
                es[ps ^ 1].fl -= tmp;
                return tmp;
            }
        }
        return 0;
    }
    ll find_max_flow() {
        ptr.resize(n);
        ll max_flow = 0, add_flow;
        for (int K = 1 << 30; K > 0; K >>= 1) {
            while (bfs(K)) {
                ptr.assign(n, 0);
                while ((add_flow = dfs(S))) {
                    max_flow += add_flow;
                }
            }
        }
        return max_flow;
    }
    void assign_result() {
        res.resize(es.size());
        for (Edge e : es)
            if (e.id != -1) res[e.id] = e.fl;
    }
    int get_flow(int id) { return res[id]; }
    bool go(int v, vector<int>& F,
            vector<int>& path) {
        if (v == T) return 1;
        for (int ps : g[v]) {
            if (F[ps] <= 0) continue;
            if (go(es[ps].to, F, path)) {
                path.push_back(ps);
                return 1;
            }
        }
        return 0;
    }
    vector<pair<int, vector<int>>> decomposition() {
        find_max_flow();
        vector<int> F((int)es.size()), path, add;
        vector<pair<int, vector<int>>> dcmp;
        for (int i = 0; i < (int)es.size(); i++)
            F[i] = es[i].fl;
        while (go(S, F, path)) {
            int mn = INT_MAX;
            for (int ps : path)
                mn = min(mn, F[ps]);
            for (int ps : path)
                F[ps] -= mn;
            for (int ps : path)
                add.push_back(es[ps].id);
            reverse(add.begin(), add.end());
            dcmp.push_back({mn, add});
            add.clear();
            path.clear();
        }
        return dcmp;
    }
};

struct output {
    int can;
    vector<pii> res;

    void print() {
        if (can) {
            cout << "YES\n";
            for (auto [u, v] : res)
                cout << u + 1 << " " << v + 1 << "\n";
        } else {
            cout << "NO\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    vector<int> a, s;
    vector<pii> es;

    input() = default;

    void read() {
        cin >> n >> m;
        s.resize(n);
        for (auto& x : s) cin >> x;
        a.resize(n);
        for (auto& x : a) cin >> x;
        es.resize(m);
        for (auto& [u, v] : es) {
            cin >> u >> v;
            u--, v--;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> deg(n);
        for (auto [u, v] : es)
            deg[u]++, deg[v]++;
        vector<int> din(n, inf);
        for (int i = 0; i < n; i++) {
            if (s[i] == 0) continue;
            auto& x = din[i];
            x = a[i] + deg[i];
            if (x % 2) return output{0, {}};
            x /= 2;
        }
        int N = n + m + 2;
        int S = N - 1, T = N - 2;
        Dinic dinic(N, S, T);
        vector<int> mem(n);
        for (int v = 0; v < n; v++) {
            mem[v] = dinic.add_edge(m + v, T, s[v] ? din[v] : 0, -1);
        }
        for (int e = 0; e < m; e++) {
            dinic.add_edge(S, e, 1, -1);
        }
        vector<vector<pii>> g(n);
        for (int e = 0; e < m; e++) {
            auto [u, v] = es[e];
            {
                int eid = dinic.add_edge(e, m + u, 1, -1);
                g[u].emplace_back(eid, v);
            }
            {
                int eid = dinic.add_edge(e, m + v, 1, -1);
                g[v].emplace_back(eid, u);
            }
        }
        int need = 0;
        for (int v = 0; v < n; v++) {
            if (s[v]) {
                need += din[v];
//                cout << v << " : " << din[v] << "\n";
            }
        }
        int F = dinic.find_max_flow();
        for (int v = 0; v < n; v++) {
            if (!s[v])
                dinic.es[mem[v]].cp = inf;
        }
        dinic.find_max_flow();
//        if (F != need) return output{0, {}};
        vector<pii> res;
        for (int v = 0; v < n; v++) {
            if (!s[v]) continue;
            for (auto [eid, to] : g[v]) {
                if (dinic.es[eid].fl == 1) {
                    res.emplace_back(to, v);
                } else if (!s[to]) {
                    res.emplace_back(v, to);
                }
            }
        }
        set<pii> Q;
        for (auto [u, v] : res) {
            if (u > v) swap(u, v);
            Q.insert({u, v});
        }
        vector<int> aa(n);
        for (auto [u, v] : es) {
            if (u > v) swap(u, v);
            if (!Q.count({u, v}))
                res.emplace_back(u, v);
        }
        for (auto [u, v] : res) {
            aa[u]--;
            aa[v]++;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] && aa[i] != a[i])
                return output{0, {}};
        }
        return output{1, res};
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