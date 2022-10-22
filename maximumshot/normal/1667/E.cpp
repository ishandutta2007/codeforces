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
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {
        cout << n << "\n";
    }

    void gen() {

    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> fact(n + 1), rfact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = mul_(fact[i - 1], i);
        rfact[n] = binpow_(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) rfact[i] = mul_(rfact[i + 1], i + 1);
        auto CNK = [&](int nn, int kk) -> int {
            if (nn < kk || kk < 0) return 0;
            return mul_(fact[nn], mul_(rfact[kk], rfact[nn - kk]));
        };
        vector<int> rev(n + 1);
        for (int i = 1; i <= n; i++)
            rev[i] = mul_(rfact[i], fact[i - 1]);
        vector<int> f(n + 1);
        f[1] = fact[n - 1];
        int T = (n - 1) / 2;
        for (int i = 2; i <= n; i++) {
            if (T <= n - i) {
                inc_(f[i], CNK(n - T - 1, i - 1));
//                for (int x = 0; x <= n - T - 2; x++) {
//                    inc_(f[i], CNK(x, i - 2));
//                }
                if (i - 3 >= 0) {
//                    for (int x = 0; x <= i - 3; x++) {
//                        dec_(f[i], CNK(x, i - 2));
//                    }
                    dec_(f[i], CNK(i - 2, i - 1));
                }
            }
            f[i] = mul_(f[i], fact[i - 2]);
            f[i] = mul_(f[i], fact[n - i]);
            f[i] = mul_(f[i], i - 1);
        }
        vector<int> dp(n + 1);
        for (int sm = 0, i = n; i >= 1; i--) {
            dp[i] = f[i];
            dec_(dp[i], mul_(sm, rev[i]));
            inc_(sm, dp[i]);
//            for (int j = i + 1; j <= n; j++) {
//                dec_(dp[i], mul_(dp[j], rev[i]));
//            }
        }
        dp.erase(dp.begin());
        return output{dp};
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