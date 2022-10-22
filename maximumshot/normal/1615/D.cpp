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
    int can;
    vector<tuple<int, int, int>> res;

    void print() {
        if (can) {
            cout << "YES\n";
            for (auto [u, v, x] : res)
                cout << u << " " << v << " " << x << "\n";
        } else {
            cout << "NO\n";
        }
    }

    bool operator == (const output& o) const {
        return can == o.can;
    }
};

struct input {
    int n, m;
    vector<tuple<int, int, int>> edges, info;
    vector<vector<pii>> tr, g;
    vector<int> f, used;

    input() = default;

    void read() {
        cin >> n >> m;
        edges.resize(n - 1);
        for (auto& [u, v, x] : edges)
            cin >> u >> v >> x;
        info.resize(m);
        for (auto& [u, v, x] : info)
            cin >> u >> v >> x;
    }

    void print() {
        cout << n << " " << m << "\n";
        for (auto [u, v, x] : edges) {
            cout << u << " " << v << " " << x << "\n";
        }
        for (auto [u, v, x] : info) {
            cout << u << " " << v << " " << x << "\n";
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 16;
        n = rnd() % MAXN + 1;
        m = rnd() % MAXN + 1;
        for (int i = 2; i <= n; i++) {
            int j = rnd() % (i - 1) + 1;
            int x = rnd() % 3 - 1;
            edges.emplace_back(j, i, x);
        }
        for (int i = 0; i < m; i++) {
            int u = rnd() % n + 1;
            int v = rnd() % n + 1;
            int x = rnd() % 2;
            info.emplace_back(u, v, x);
        }
    }

    void dfs(int v, int par = -1) {
        for (auto [to, x] : tr[v]) {
            if (to == par)
                continue;
            if (x == -1) {
                f[to] = -1;
            } else {
                f[to] = f[v] ^ x;
                dfs(to, v);
            }
        }
    }

    void go(int v) {
        used[v] = 1;
        for (auto [to, x] : g[v]) {
            if (used[to] || f[to] != -1)
                continue;
            f[to] = f[v] ^ x;
            go(to);
        }
    }

    output fast() {
        tr.resize(n + 1);
        for (auto [u, v, x] : edges) {
            tr[u].emplace_back(v, x);
            tr[v].emplace_back(u, x);
        }
        f.assign(n + 1, -1);
        f[1] = 0;
        dfs(1, -1);
        g.resize(n + 1);
        for (int v = 1; v <= n; v++) {
            if (f[v] != -1)
                f[v] = __builtin_popcount(f[v]) % 2;
        }
        for (auto [u, v, x] : info) {
            if (f[u] != -1 && f[v] != -1 && (f[v] ^ f[u]) != x)
                return output{0, {}};
            if (f[u] == -1 || f[v] == -1) {
//                cout << u << " " << v << " " << x << " ??\n";
                g[u].emplace_back(v, x);
                g[v].emplace_back(u, x);
            }
        }
        for (auto [u, v, x] : edges) {
            if (x == -1)
                continue;
            x = __builtin_popcount(x) % 2;
            g[u].emplace_back(v, x);
            g[v].emplace_back(u, x);
        }
        used.assign(n + 1, 0);
        for (int v = 1; v <= n; v++) {
            if (used[v] || f[v] == -1)
                continue;
            go(v);
        }
        for (int v = 1; v <= n; v++) {
            if (used[v])
                continue;
            assert(f[v] == -1);
            f[v] = 0;
            go(v);
        }
        for (auto [u, v, x] : info) {
            if ((f[u] ^ f[v]) != x)
                return output{0, {}};
        }
        for (auto [u, v, x] : edges) {
            if (x == -1)
                continue;
            if ((f[u] ^ f[v]) != __builtin_popcount(x) % 2)
                return output{0, {}};
        }
        vector<tuple<int, int, int>> res;
        for (auto [u, v, x] : edges) {
            if (x == -1)
                x = f[u] ^ f[v];
            res.emplace_back(u, v, x);
        }
        return output{1, res};
    }

    output slow() {
        vector<int> ids;
        vector<vector<int>> G(n + 1, vector<int>(n + 1, -1)), g;
        for (int i = 0; i < n - 1; i++) {
            auto [u, v, x] = edges[i];
            if (x == -1)
                ids.push_back(i);
            else
                G[u][v] = G[v][u] = __builtin_popcount(x) % 2;
        }
        int sz = (int) ids.size();
        for (int mask = 0; mask < (1 << sz); mask++) {
            g = G;
            for (int i = 0; i < sz; i++) {
                int x = (mask >> i) & 1;
                auto [u, v, _] = edges[ids[i]];
                g[u][v] = g[v][u] = x;
            }
            vector<int> F(n + 1, -1);
            F[1] = 0;
            queue<int> q;
            q.push(1);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int to = 1; to <= n; to++) {
                    if (g[v][to] != -1 && F[to] == -1) {
                        F[to] = F[v] ^ g[v][to];
                        q.push(to);
                    }
                }
            }
            int ok = 1;
            for (auto [u, v, x] : info) {
                if ((F[u] ^ F[v]) != x)
                    ok = 0;
            }
            if (ok) {
                vector<tuple<int, int, int>> res;
                for (auto [u, v, x] : edges) {
                    if (x == -1)
                        x = g[u][v];
                    res.emplace_back(u, v, x);
                }
                return output{1, res};
            }
        }
        return output{0, {}};
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

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