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
    vector<ll> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n;
    vector<vector<pii>> g;
    int k;
    vector<int> z;
    vector<int> pass, fine;
    vector<vector<int>> masks;
    int T;
    int q;

    struct Query {
        int t, c, u;
        char i;
    };

    vector<Query> queries;
    vector<int> p, up;
    vector<ll> W;

    input() = default;

    void read() {
        cin >> n;
        g.resize(n + 1);
        for (int u, v, t, i = 0; i < n - 1; i++) {
            cin >> u >> v >> t;
            g[u].emplace_back(v, t);
            g[v].emplace_back(u, t);
        }
        cin >> k;
        z.resize(n + 1);
        string sz;
        cin >> sz;
        for (int i = 1; i <= n; i++)
            z[i] = sz[i - 1] - 'A';
        pass.resize(k);
        for (int i = 0; i < k; i++)
            cin >> pass[i];
        fine.resize(k);
        for (int i = 0; i < k; i++)
            cin >> fine[i];
        cin >> T;
        cin >> q;
        queries.resize(q);
        for (auto& query : queries) {
            cin >> query.t;
            if (query.t == 1 || query.t == 2) {
                cin >> query.i >> query.c;
            } else {
                cin >> query.u;
            }
        }
    }

    void init() {
        p.resize(n + 1);
        up.resize(n + 1);
        W.resize(n + 1);
        masks.resize(n + 1);
    }

    void print() {
        cout << n << "\n";
        for (int v = 1; v <= n; v++) {
            for (auto [to, t] : g[v]) {
                if (v < to) {
                    cout << v << " " << to << " " << t << "\n";
                }
            }
        }
        cout << k << "\n";
        for (int i = 1; i <= n; i++)
            cout << char(z[i] + 'A');
        cout << "\n";
        for (int i = 0; i < k; i++)
            cout << pass[i] << " ";
        cout << "\n";
        for (int i = 0; i < k; i++)
            cout << fine[i] << " ";
        cout << "\n";
        cout << T << "\n";
        cout << q << "\n";
        for (auto query : queries) {
            cout << query.t << " ";
            if (query.t == 3) {
                cout << query.u << "\n";
            } else {
                cout << query.i << " " << query.c << "\n";
            }
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 100;
        const int MAXK = 5;
        const int MAXT = 1000;
        n = rnd() % MAXN + 2;
        g.resize(n + 1);
        k = rnd() % MAXK + 1;
        z.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            int j = max(1, i - 1 - int(rnd() % 10));
            int t = rnd() % MAXT + 1;
            g[i].emplace_back(j, t);
            g[j].emplace_back(i, t);
            z[i] = min(k - 1, z[j] + int(rnd() % MAXK));
        }
        pass.resize(k);
        fine.resize(k);
        for (int i = 0; i < k; i++) {
            pass[i] = rnd() % MAXT + 1;
            fine[i] = rnd() % MAXT + 1;
        }
        T = rnd() % MAXT + 1;
        q = rnd() % MAXN + 1;
        queries.resize(q);
        for (auto& query : queries) {
            query.t = rnd() % 3 + 1;
            query.t = 3;
            if (query.t == 3) {
                query.u = rnd() % n + 1;
            } else {
                query.i = rnd() % k + 'A';
                query.c = rnd() % MAXT + 1;
            }
        }
    }

    void gen_max_test() {
        static mt19937 rnd(42);
        n = 2e5;
        g.resize(n + 1);
        k = 26;
        const int MAXT = 1e9;
        const int MAXK = 26;
        z.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            int j = max(1, i - 1 - int(rnd() % 3));
            int t = rnd() % MAXT + 1;
            g[i].emplace_back(j, t);
            g[j].emplace_back(i, t);
            z[i] = min(k - 1, z[j] + int(rnd() % 2));
        }
        pass.resize(k);
        fine.resize(k);
        for (int i = 0; i < k; i++) {
            pass[i] = rnd() % MAXT + 1;
            fine[i] = rnd() % MAXT + 1;
        }
        T = rnd() % MAXT + 1;
        q = 2e5;
        queries.resize(q);
        int cur = 0;
        int IT = 0;
        for (auto& query : queries) {
            IT++;
            query.t = IT <= q / 2 ? rnd() % 2 + 1 : 3;
            query.t = 3;
            if (query.t == 3) {
                query.u = ++cur;
            } else {
                query.i = rnd() % k + 'A';
                query.c = rnd() % MAXT + 1;
            }
        }
    }

    void dfs(int v, int par) {
        {
            int x = up[v];
            ll dist = W[v] - W[x];
            int mask = 0;
            while (x > 1) {
                int y = up[x];
                ll len = W[x] - W[y];
                int color = z[x];
                ll mn = len / T;
                ll lk = (dist + T - 1) / T;
                ll rk = (dist + len - 1) / T;
                ll have = max(0ll, rk - lk + 1);
                if (have > mn)
                    mask |= 1 << color;
                x = y;
                dist += len;
            }
            masks[v] = {mask};
        }
        p[v] = par;
        for (auto [to, t] : g[v]) {
            if (to == par)
                continue;
            W[to] = W[v] + t;
            if (z[v] != z[to]) up[to] = v;
            else up[to] = up[v];
            dfs(to, v);
            if (z[v] != z[to])
                continue;
            for (auto mask : masks[to])
                masks[v].push_back(mask);
            sort(masks[v].begin(), masks[v].end());
            masks[v].erase(unique(masks[v].begin(), masks[v].end()), masks[v].end());
        }
    }

    output fast() {
        init();
        vector<ll> res;
        up[1] = 0;
        W[1] = 0;
        dfs(1, -1);

        for (auto query : queries) {
            if (query.t == 1) {
                pass[query.i - 'A'] = query.c;
            } else if (query.t == 2) {
                fine[query.i - 'A'] = query.c;
            } else {
                int v = query.u;
                ll best_cost = inf64;
                for (int mask : masks[v]) {
                    ll cost = 0;
                    int x = up[v];
                    while (x > 1) {
                        int y = up[x];
                        ll len = W[x] - W[y];
                        int color = z[x];
                        ll have = len / T;
                        if ((1 << color) & mask)
                            have++;
                        if (pass[color] / fine[color] >= have) cost += have * fine[color];
                        else cost += pass[color];
                        x = y;
                    }
                    best_cost = min(best_cost, cost);
                }
                res.push_back(best_cost);
            }
        }
        return output{res};
    }

    void DFS(int v, int par, int color, ll& res) {
        if (z[v] != color)
            return;
        for (auto [to, t] : g[v]) {
            if (to == par)
                continue;
            DFS(to, v, color, res);
        }
        int x = up[v];
        ll dist = (W[v] - W[x]) % T;
        ll cost = 0;
        while (x > 1) {
            int y = up[x];
            ll len = W[x] - W[y];
            // dist <= k * T < dist + len
            // k >= dist / T
            // dist / T <= k <= (dist + len - 1) / T
            ll lk = (dist + T - 1) / T;
            ll rk = (dist + len - 1) / T;
            ll cnt = 0;
            if (lk <= rk)
                cnt += rk - lk + 1;
            cost += min(cnt * fine[z[x]], pass[z[x]] + 0ll);
            dist += len;
            x = y;
        }
        res = min(res, cost);
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        init();
        vector<ll> res;
        up[1] = 0;
        W[1] = 0;
        dfs(1, -1);
        for (auto query : queries) {
            if (query.t == 1) {
                pass[query.i - 'A'] = query.c;
            } else if (query.t == 2) {
                fine[query.i - 'A'] = query.c;
            } else {
                if (query.u == 1) {
                    res.push_back(0);
                    continue;
                }
                ll cost = inf64;
                DFS(query.u, p[query.u], z[query.u], cost);
                res.push_back(cost);
            }
        }
        return output{res};

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