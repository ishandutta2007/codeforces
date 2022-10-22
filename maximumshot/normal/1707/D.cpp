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
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

int mul(int x, int y, int p) {
    return (1ll * x * y) % p;
}

void inc(int& x, int y, int p) {
    if ((x += y) >= p)
        x -= p;
}

void dec(int& x, int y, int p) {
    if ((x -= y) < 0)
        x += p;
}

int sum(int x, int y, int p) {
    return x + y < p ? x + y : x + y - p;
}

struct input {
    int n, p;
    vector<pii> es;

    input() = default;

    void read() {
        cin >> n >> p;
        es.resize(n - 1);
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
        vector<vector<int>> g(n);
        for (auto [u, v] : es) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        function<void(int, int)> dfs = [&](int v, int par) {
            vector<int> sons;
            for (int to : g[v]) {
                if (to == par)
                    continue;
                dfs(to, v);
                sons.push_back(to);
            }
            if (sons.empty()) {
                for (int k = 1; k <= n; k++)
                    dp[v][k] = 1;
                return;
            }
            int sz = (int) sons.size();
            if (v != 0) {
                vector<int> F(sz), sm(sz), pref(sz), suff(sz);
                for (int k = 1; k <= n; k++) {
                    for (int i = 0; i < sz; i++) {
                        int to = sons[i];
                        inc(sm[i], dp[to][k], p);
                    }
                    pref = suff = sm;
                    for (int i = 1; i < sz; i++) pref[i] = mul(pref[i], pref[i - 1], p);
                    for (int i = sz - 2; i >= 0; i--) suff[i] = mul(suff[i], suff[i + 1], p);
                    for (int i = 0; i < sz; i++) {
                        int tmp = F[i];
                        int to = sons[i];
                        inc(dp[v][k], mul(tmp, dp[to][k], p), p);
                        int prod = 1;
                        if (i > 0) prod = mul(prod, pref[i - 1], p);
                        if (i + 1 < sz) prod = mul(prod, suff[i + 1], p);
                        inc(F[i], prod, p);
                    }
                }
            }
            {
                vector<int> sm(sz);
                for (int k = 1; k <= n; k++) {
                    int prod = 1;
                    for (int i = 0; i < sz; i++) {
                        int to = sons[i];
                        inc(sm[i], dp[to][k], p);
                        prod = mul(prod, sm[i], p);
                    }
                    inc(dp[v][k], prod, p);
                }
            }
            dp[v][0] = 0;
        };
        dfs(0, -1);
//        for (int v = 0; v < n; v++) {
//            cout << "v = " << v + 1 << "\n\t";
//            for (int k = 1; k <= n; k++) {
//                cout << dp[v][k] << " ";
//            }
//            cout << "\n";
//        }
        vector<int> f(n + 1);
        vector<vector<int>> C(n + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j], p);
            }
        }
        for (int k = 1; k <= n; k++) {
            f[k] = dp[0][k];
            for (int j = 1; j < k; j++) {
                dec(f[k], mul(f[j], C[k][j], p), p);
            }
        }
        vector<int> res(f.begin() + 1, f.begin() + n);
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