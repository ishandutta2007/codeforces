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
    void add_edge(int fr, int to, int cp, int id) {
        g[fr].push_back((int)es.size());
        es.push_back({fr, to, cp, id, 0});
        g[to].push_back((int)es.size());
        es.push_back({to, fr, 0, -1, 0});
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
};

struct output {
    int can;
    vector<int> h;
    int p1, p2;

    void print() {
        if (can) {
            int mn = 2 * inf + 10;
            mn = min({mn, p1, p2});
            for (auto x : h) mn = min(mn, x);
            cout << "YES\n";
            for (auto x : h)
                cout << x - mn << " ";
            cout << "\n";
            cout << p1 - mn << " " << p2 - mn << "\n";
        } else {
            cout << "NO\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

bool check(vector<int> h, int p1, int p2, vector<int> d1, vector<int> d2) {
    vector<int> a1, a2;
    for (auto x : h) {
        a1.push_back(abs(p1 - x));
        a2.push_back(abs(p2 - x));
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    return a1 == d1 && a2 == d2;
}

optional<vector<int>> try_solve(int p1, int p2, vector<int> d1, vector<int> d2) {
    unordered_map<int, int> c1, c2;
    for (auto x : d1) c1[x]++;
    for (auto x : d2) c2[x]++;
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    d1.erase(unique(d1.begin(), d1.end()), d1.end());
    d2.erase(unique(d2.begin(), d2.end()), d2.end());
    int n = (int) d1.size();
    int m = (int) d2.size();
    int N = 3 * n + 3 * m + 2;
    int S = N - 1, T = N - 2;
    Dinic dinic(N, S, T);
    for (int i = 0; i < n; i++) {
        int x = c1[d1[i]];
        dinic.add_edge(S, 3 * i, x, -1);
        dinic.add_edge(3 * i, 3 * i + 1, x, -1);
        dinic.add_edge(3 * i, 3 * i + 2, x, -1);
    }
    for (int j = 0; j < m; j++) {
        int x = c2[d2[j]];
        dinic.add_edge(3 * n + 3 * j, T, x, -1);
        dinic.add_edge(3 * n + 3 * j + 1, 3 * n + 3 * j, x, -1);
        dinic.add_edge(3 * n + 3 * j + 2, 3 * n + 3 * j, x, -1);
    }
    vector<int> hs;
    for (int i = 0; i < n; i++) {
        for (int si = 1; si <= 2; si++) {
            int val = si == 1 ? p1 - d1[i] : p1 + d1[i];
            int need_val = abs(val - p2);
            int need_sj = val >= p2 ? 1 : 2;
            int j = lower_bound(d2.begin(), d2.end(), need_val) - d2.begin();
            if (j == m || d2[j] != need_val) continue;
            int id = (int) hs.size();
            hs.push_back(val);
            dinic.add_edge(3 * i + si, 3 * n + 3 * j + need_sj, inf, id);
        }
    }
    int need_F = 0;
    for (auto [k, v] : c1) need_F += v;
    int F = dinic.find_max_flow();
    if (F != need_F) return {nullopt};
    dinic.assign_result();
    vector<int> res;
    for (int i = 0; i < (int) hs.size(); i++) {
        int x = dinic.get_flow(i);
        for (int j = 0; j < x; j++)
            res.push_back(hs[i]);
    }
    return res;
}

struct input {
    int n;
    vector<int> d1, d2;

    input() = default;

    void read() {
        cin >> n;
        d1.resize(n);
        d2.resize(n);
        for (auto& x : d1) cin >> x;
        for (auto& x : d2) cin >> x;
    }

    void print() {
        cout << n << "\n";
        for (auto x : d1) cout << x << " ";
        cout << "\n";
        for (auto x : d2) cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
        const int MAXX = 10;
    }

    void gen_max_test() {
    }

    output fast() {
        sort(d1.rbegin(), d1.rend());
        sort(d2.rbegin(), d2.rend());
        for (int it = 0; it < 2; it++, swap(d1, d2)) {
            int p1 = 0;
            vector<int> h = d1;
            sort(h.begin(), h.end());
            for (int x : d2) {
                for (int sign = -1; sign <= 1; sign += 2) {
                    int p2 = d1[0] + sign * x;
                    if (check(h, p1, p2, d1, d2)) {
                        if (it) swap(p1, p2);
                        return output{1, h, p1, p2};
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            int L = d1[i];
            int R = d1[0];
            int p1 = L;
            int M = L + R;
            {
                int p2 = d2[0];
                for (int j = 1; j < n; j++) {
                    if (d2[0] + d2[j] == L + R) {
                        vector<int> dd1, dd2;
                        dd1.reserve(n - 2);
                        dd2.reserve(n - 2);
                        for (int q = 0; q < n; q++) {
                            if (q == 0 || q == i) continue;
                            dd1.push_back(d1[q]);
                        }
                        for (int q = 0; q < n; q++) {
                            if (q == 0 || q == j) continue;
                            dd2.push_back(d2[q]);
                        }
                        // p1, p1, dd1, dd2, M
                        auto tmp = try_solve(p1, p2, dd1, dd2);
                        if (tmp.has_value()) {
                            vector<int> h = tmp.value();
                            h.push_back(0);
                            h.push_back(M);
                            sort(h.begin(), h.end());
                            return output{1, h, p1, p2};
                        }
                        break;
                    }
                }
            }
            {
                int p2 = L + R - d2[0];
                for (int j = 1; j < n; j++) {
                    if (d2[0] + d2[j] == L + R) {
                        vector<int> dd1, dd2;
                        dd1.reserve(n - 2);
                        dd2.reserve(n - 2);
                        for (int q = 0; q < n; q++) {
                            if (q == 0 || q == i) continue;
                            dd1.push_back(d1[q]);
                        }
                        for (int q = 0; q < n; q++) {
                            if (q == 0 || q == j) continue;
                            dd2.push_back(d2[q]);
                        }
                        auto tmp = try_solve(p1, p2, dd1, dd2);
                        if (tmp.has_value()) {
                            vector<int> h = tmp.value();
                            h.push_back(0);
                            h.push_back(M);
                            sort(h.begin(), h.end());
                            return output{1, h, p1, p2};
                        }
                        break;
                    }
                }
            }
        }
        return output{0, {}, 0, 0};
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
//#ifdef DEBUG
    cin >> t;
//#endif
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