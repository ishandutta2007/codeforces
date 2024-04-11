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

const int mod = 998244353;

inline int sum_(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int mul_(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int sub_(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void inc_(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void dec_(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int binpow_(int x, int pw) {
    if (x == 0)
        return 0;
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = mul_(res, tmp);
        }
        tmp = mul_(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int div_(int a, int b) {
    return mul_(a, binpow_(b, mod - 2));
}

struct output {
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct Value {
    int rem = 0;
    int big = 0;

    Value operator + (const Value& o) const {
        return Value{sum_(rem, o.rem), big | o.big | int(rem + o.rem >= mod)};
    }
};

struct input {
    int n, m;
    vector<int> a;
    vector<pii> es;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a) cin >> x;
        es.resize(m);
        for (auto& [u, v] : es)
            cin >> u >> v, u--, v--;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }
    output fast() {
        vector<vector<int>> g(n), gr(n);
        for (auto [u, v] : es) {
            g[u].push_back(v);
            gr[v].push_back(u);
        }
        vector<int> used(n);
        vector<vector<Value>> dp(n, vector<Value>(n + 1));
        function<void(int)> dfs = [&](int v) {
            if (used[v])
                return;
            used[v] = 1;
            dp[v][0] = {a[v] % mod, a[v] >= mod};
            for (int to : gr[v]) {
                dfs(to);
                dp[to].insert(dp[to].begin(), Value{0, 0});
                for (int j = 0; j <= n; j++)
                    dp[v][j] = dp[v][j] + dp[to][j];
                dp[to].erase(dp[to].begin());
            }
        };
        int root = 0;
        while (!g[root].empty()) root++;
        dfs(root);
//        for (int v = 0; v < n; v++) {
//            cout << v + 1 << " : "; for (int j = 0; j <= n; j++) cout << dp[v][j].rem << " "; cout << "\n";
//        }
        Value res;
        for (int j = 0; j <= n; j++) {
            if (res.big || res.rem >= j) {
                res = res + dp[root][j];
            } else if (dp[root][j].big || dp[root][j].rem) {
                Value tmp = {j, 0};
                res = dp[root][j] + tmp;
            }
        }
        return output{res.rem};
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
    int t;
    cin >> t;
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