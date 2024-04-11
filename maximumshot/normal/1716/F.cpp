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
        return res == o.res;
    }
};

const int MAXK = 2005;
int dp[MAXK][MAXK];

void precalc() {
    dp[0][0] = 1;
    for (int i = 1; i < MAXK; i++) {
        for (int j = 0; j < MAXK; j++) {
            dp[i][j] = mul_(j, dp[i - 1][j]);
            if (j) inc_(dp[i][j], mul_(dp[i - 1][j - 1], 1));
        }
    }
}

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
        int U = (m + 1) / 2;
        int D = m / 2;
        if (n <= k + 3) {
            int res = 0;
            vector<int> fact(n + 1), rfact(n + 1);
            fact[0] = 1;
            for (int i = 1; i <= n; i++) {
                fact[i] = mul_(fact[i - 1], i);
            }
            rfact[n] = binpow_(fact[n], mod - 2);
            for (int i = n - 1; i >= 0; i--)
                rfact[i] = mul_(rfact[i + 1], i + 1);
            for (int i = 0; i <= n; i++) {
                int coef = mul_(fact[n], mul_(rfact[i], rfact[n - i]));
                coef = mul_(coef, binpow_(U, i));
                coef = mul_(coef, binpow_(D, n - i));
                coef = mul_(coef, binpow_(i, k));
                inc_(res, coef);
            }
            return output{res};
        }
        vector<int> cur = {1};
        vector<int> a(k + 1), b(k + 1);
        for (int i = 0; i <= k; i++) {
            a[i] = i;
            b[i] = mul_(U, n - i + 1);
        }
        int res = 0;
        int x = binpow_(m, mod - 2);
        vector<int> B = b;
        B[0] = 1;
        for (int j = 1; j <= k; j++)
            B[j] = mul_(B[j], B[j - 1]);
        for (int i = 0; i <= k; i++) {
            int coef = mul_(dp[k][i], binpow_(x, i));
            coef = mul_(coef, B[i]);
            inc_(res, coef);
        }
        res = mul_(res, binpow_(m, n));
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

    precalc();
    work();
//    test();
//    max_test();

    return 0;
}