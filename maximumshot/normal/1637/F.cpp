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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n;
    vector<int> h;
    vector<vector<int>> g;

    input() = default;

    void read() {
        cin >> n;
        h.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        g.resize(n + 1);
        for (int u, v, i = 0; i < n - 1; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
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
        vector<int> mx(n + 1);
        vector<ll> dp(n + 1, inf64);
        ll res = inf64;
        function<void(int, int)> dfs = [&](int v, int par) {
            mx[v] = 0;
            dp[v] = 0;
            for (int to : g[v]) {
                if (to == par)
                    continue;
                dfs(to, v);
                mx[v] = max(mx[v], mx[to]);
                dp[v] += dp[to];
            }
            if (mx[v] < h[v]) {
                dp[v] += h[v] - mx[v];
                mx[v] = h[v];
            }
        };
        function<void(int, int, int, ll)> go = [&](int v, int par, int par_mx, ll par_dp) {
            {
                ll DP = par_dp;
                int MX = par_mx;
                for (int to : g[v]) {
                    if (to == par)
                        continue;
                    MX = max(MX, mx[to]);
                    DP += dp[to];
                }
                if (MX < h[v]) {
                    DP += h[v] - MX;
                    MX = h[v];
                }
                res = min(res, DP + MX);
            }
            int sz = (int) g[v].size();
            vector<int> pref_mx(sz), suff_mx(sz);
            for (int i = 0; i < sz; i++) {
                if (i) pref_mx[i] = pref_mx[i - 1];
                int to = g[v][i];
                if (to != par)
                    pref_mx[i] = max(pref_mx[i], mx[to]);
            }
            for (int i = sz - 1; i >= 0; i--) {
                if (i + 1 < sz) suff_mx[i] = suff_mx[i + 1];
                int to = g[v][i];
                if (to != par)
                    suff_mx[i] = max(suff_mx[i], mx[to]);
            }
            ll sm = par_dp;
            for (int to : g[v]) {
                if (to == par)
                    continue;
                sm += dp[to];
            }
            for (int i = 0; i < sz; i++) {
                int to = g[v][i];
                if (to == par)
                    continue;
                int to_mx = par_mx;
                if (i > 0) to_mx = max(to_mx, pref_mx[i - 1]);
                if (i + 1 < sz) to_mx = max(to_mx, suff_mx[i + 1]);
                ll to_dp = sm - dp[to];
                if (to_mx < h[v]) {
                    to_dp += h[v] - to_mx;
                    to_mx = h[v];
                }
                go(to, v, to_mx, to_dp);
            }
        };
        dfs(1, -1);
        go(1, -1, 0, 0);
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
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