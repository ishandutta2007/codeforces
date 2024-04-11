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

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

int lcm(int x, int y) {
    return (x / gcd(x, y)) * y;
}

struct input {
    int n, a0, x, y, k, M;

    input() = default;

    void read() {
        cin >> n >> a0 >> x >> y >> k >> M;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int L = 1;
        for (int i = 1; i <= k; i++)
            L = lcm(L, i);
        int res = 0;
        vector<int> dp(L), nx(L);
        for (int i = 0; i < n; i++) {
            dp[a0 % L]++;
            inc_(res, a0 / L);
            a0 = (1ll * a0 * x + y) % M;
        }
        res = mul_(res, L);
        res = mul_(res, mul_(k, binpow_(n, k - 1)));
        for (int j = 1; j <= k; j++) {
            int add = 0;
            for (int i = 0; i < L; i++) {
                inc_(add, mul_(dp[i], i));
            }
            inc_(res, mul_(add, binpow_(n, k - j)));
            nx.assign(L, 0);
            for (int i = 0; i < L; i++) {
                inc_(nx[i], mul_(dp[i], n - 1));
                inc_(nx[i - i % j], dp[i]);
            }
            swap(dp, nx);
        }
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