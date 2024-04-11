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
        ll fr, to, cp, id, fl;
    };
    int n, S, T;
    vector<Edge> es;
    vector<vector<int>> g;
    vector<int> dist, res, ptr;

    Dinic(int n_, int S_, int T_): n(n_), S(S_), T(T_) {
        g.resize(n);
    }

    void add_edge(int fr, int to, ll cp, int id) {
        g[fr].push_back((int) es.size());
        es.push_back({fr, to, cp, id, 0});
        g[to].push_back((int) es.size());
        es.push_back({to, fr, cp, -1, 0});
//        cout << "add edge " << fr << " " << to << " " << cp << "\n";
    }

    bool bfs(ll K) {
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

    ll dfs(int v, ll push_ = inf64) {
        if (v == T || !push_) return push_;
        for (int& iter = ptr[v]; iter < (int) g[v].size(); iter++) {
            int ps = g[v][ptr[v]];
            Edge& e = es[ps];
            if (dist[e.to] != dist[e.fr] + 1) continue;
            ll tmp = dfs(e.to, min(push_, e.cp - e.fl));
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
        for (ll K = 1ll << 60; K > 0; K >>= 1) {
            while (bfs(K)) {
                ptr.assign(n, 0);
                while ((add_flow = dfs(S))) {
                    max_flow += add_flow;
                }
            }
        }
        return max_flow;
    }

    vector<int> walk() {
        vector<int> used(n);
        used[S] = 1;
        queue<int> q;
        q.push(S);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int eid : g[v]) {
                auto e = es[eid];
                if (!used[e.to] && e.fl < e.cp) {
                    used[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
        return used;
    }
};

struct output {
    ll res;
    string s;

    void print() {
        cout << res << "\n" << s << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    int a, b;
    vector<tuple<int, int, int>> es;

    input() = default;

    void read() {
        cin >> n >> m;
        cin >> a >> b;
        a--, b--;
        es.resize(m);
        for (auto& [u, v, l] : es)
            cin >> u >> v >> l, u--, v--;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int N = 2 * n + 2, S = N - 1, T = N - 2;
        Dinic dinic(N, S, T);
        dinic.add_edge(S, a, inf64, -1);
        dinic.add_edge(a + n, T, inf64, -1);
        dinic.add_edge(b, T, inf64, -1);
        dinic.add_edge(S, b + n, inf64, -1);
        for (auto [u, v, l] : es) {
            dinic.add_edge(u, v + n, l, -1);
            dinic.add_edge(v, u + n, l, -1);
        }
        ll fl = dinic.find_max_flow();
        vector<int> used = dinic.walk();
        string res(n, '?');
        for (int i = 0; i < n; i++) {
            if (used[i] && !used[i + n]) res[i] = 'A';
            else if (!used[i] && used[i + n]) res[i] = 'B';
            else res[i] = 'C';
        }
//        cout << "used = ";
//        for (int x : used)
//            cout << x;
//        cout << "\n";
//        ll cost = 0;
//        for (auto [u, v, l] : es) {
//            if (res[u] > res[v]) swap(u, v);
//            int cf = 0;
//            if (res[u] == 'A' && res[v] == 'A') cf = 2;
//            if (res[u] == 'A' && res[v] == 'C') cf = 1;
//            if (res[u] == 'B' && res[v] == 'B') cf = 2;
//            if (res[u] == 'B' && res[v] == 'C') cf = 1;
//            cost += cf * l;
//        }
//        cout << "cost = " << cost << "\n";
        return output{fl, res};
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

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
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