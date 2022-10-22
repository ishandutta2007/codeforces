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
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n;
    vector<int> a;
    vector<vector<int>> g;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        g.resize(n);
        for (auto& x : a) cin >> x;
        for (int u, v, i = 1; i < n; i++) {
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
        for (int v = 0; v < n; v++) {
            for (int to : g[v]) {
                if (v < to) {
                    cout << v + 1 << " " << to + 1 << "\n";
                }
            }
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        const int MAX_BIT = 10;
        n = rnd() % MAXN + 1;
        a.resize(n);
        g.resize(n);
        for (auto& x : a)
            x = rnd() % (1 << MAX_BIT);
        for (int i = 1; i < n; i++) {
            int j = max(0, i - 1 - int(rnd() % 3));
            g[j].push_back(i);
            g[i].push_back(j);
        }
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> A(n);
        function<void(int, int)> go = [&](int v, int par) {
            A[v] = a[v] ^ (par == -1 ? 0 : A[par]);
            for (int to : g[v]) {
                if (to == par)
                    continue;
                go(to, v);
            }
        };
        go(0, -1);
        vector<map<int, int>> dp(n);
        int res = 0;
        function<void(int, int)> dfs = [&](int v, int par) {
            int any = 0;
            if (a[v] == 0) any = 1;
            for (int to : g[v]) {
                if (to == par)
                    continue;
                dfs(to, v);
                {
                    int y = A[v] ^ a[v];
                    if (dp[to].count(y))
                        any = 1;
                }
                if (dp[to].size() > dp[v].size())
                    swap(dp[v], dp[to]);
                for (auto [x, cn] : dp[to]) {
                    int y = x ^ a[v];
                    if (dp[v].count(y)) any = 1;
                }
                for (auto [x, cn] : dp[to])
                    dp[v][x] += cn;
            }
            if (!any) dp[v][A[v]]++;
            else res++, dp[v].clear();
        };
        dfs(0, -1);
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        auto get_path = [&](int s, int t) -> vector<int> {
            vector<int> dist(n, inf), from(n, -1);
            dist[s] = 0;
            queue<int> que;
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (int to : g[v]) {
                    if (dist[to] > dist[v] + 1) {
                        dist[to] = dist[v] + 1;
                        from[to] = v;
                        que.push(to);
                    }
                }
            }
            vector<int> path;
            for (int x = t; x != -1; x = from[x]) {
                path.push_back(x);
            }
            reverse(path.begin(), path.end());
            return path;
        };
        int res = n;
        for (int mask = 0; mask < (1 << n); mask++) {
            int tmp = __builtin_popcount(mask);
            int ok = 1;
            for (int s = 0; s < n; s++) {
                for (int t = s; t < n; t++) {
                    auto P = get_path(s, t);
                    int xr = 0;
                    for (int v : P) {
                        if ((1 << v) & mask) {
                            xr = -1;
                            break;
                        } else {
                            xr ^= a[v];
                        }
                    }
                    if (xr == 0) ok = 0;
                }
            }
            if (ok) res = min(res, tmp);
        }
        return output{res};
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