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

const int MAXN = 5e5 + 5;

int fact[MAXN];
int rfact[MAXN];

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = mul_(fact[i - 1], i);
    rfact[MAXN - 1] = binpow_(fact[MAXN - 1], mod - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        rfact[i] = mul_(rfact[i + 1], i + 1);
}

int CNK(int n, int k) {
    if (n < k || k < 0) return 0;
    return mul_(fact[n], mul_(rfact[k], rfact[n - k]));
}

struct output {
    int res = 0;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        n++;
        a.resize(n);
        for (auto& x : a) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
//        int N = 20;
//        vector<vector<int>> dp(N, vector<int>(N));
//        dp[0][0] = 1;
        int res = 0;
//        for (int x = 0; x < N; x++) {
//            for (int y = 0; y < N; y++) {
//                if (y < (x < n ? a[x] : 0)) {
//                    inc_(res, dp[x][y]);
//                    inc_(dp[x + 1][y], dp[x][y]);
//                    inc_(dp[x][y + 1], dp[x][y]);
//                }
//            }
//        }
        for (int i = 0; i < n; i++) {
            int x = i + 1;
            int y = a[i] - 1;
            inc_(res, CNK(x + y, x));
//            for (int j = 0; j < a[i]; j++) {
//                inc_(res, CNK(i + j, j));
//            }
        }
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

    precalc();
    work();
//    test();
//    max_test();

    return 0;
}