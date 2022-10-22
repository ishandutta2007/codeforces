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
        if (n == m)
            return output{mul_(n, k)};
        int r2 = binpow_(2, mod - 2);
        vector<int> fact(n + 1), rfact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = mul_(fact[i - 1], i);
        rfact[n] = binpow_(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--)
            rfact[i] = mul_(rfact[i + 1], i + 1);
        auto CNK = [&](int nn, int kk) -> int {
            if (nn < kk)
                return 0;
            return mul_(fact[nn], mul_(rfact[kk], rfact[nn - kk]));
        };
        int res = 0;
        vector<int> pw_r2(n + 1);
        pw_r2[0] = 1;
        for (int i = 1; i <= n; i++)
            pw_r2[i] = mul_(pw_r2[i - 1], r2);
        for (int i = 1; i <= m; i++) {
            int w = n - m;
            int h = m - i + 1;
            int prob = mul_(CNK(w + h - 2, w - 1), pw_r2[w + h - 1]);
            inc_(res, mul_(prob, i));
        }
        res = mul_(res, k);
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