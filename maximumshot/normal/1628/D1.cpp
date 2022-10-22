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

const int mod = inf + 7;

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

struct input {
    int n, m, k;

    input() = default;

    void read() {
        cin >> n >> m >> k;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<vector<ld>> dp(n + 1, vector<ld>(m + 1));
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        const ld eps = 1e-9;
        int r2 = binpow_(2, mod - 2);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i && j <= m; j++) {
                if (i == j) {
                    dp[i][j] = ld(i) * ld(k);
                    f[i][j] = mul_(i, k);
                } else if (j == 0) {
                } else {
                    ld sep = (dp[i - 1][j] - dp[i - 1][j - 1]) * 0.5;
                    int x = sub_(f[i - 1][j], f[i - 1][j - 1]);
                    x = mul_(x, r2);
                    ld val1 = dp[i - 1][j] - sep;
                    ld val2 = dp[i - 1][j - 1] + sep;
                    if (val1 < val2) {
                        if (dp[i][j] < val1) {
                            dp[i][j] = val1;
                            f[i][j] = sub_(f[i - 1][j], x);
                        }
                    } else {
                        if (dp[i][j] < val2) {
                            dp[i][j] = val2;
                            f[i][j] = sum_(f[i - 1][j - 1], x);
                        }
                    }
                }
            }
        }
        return output{f[n][m]};
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