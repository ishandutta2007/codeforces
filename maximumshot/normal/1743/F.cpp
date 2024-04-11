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

struct Matrix {
    int a[2][2];

    Matrix() {
        a[0][0] = a[1][1] = 1;
        a[0][1] = a[1][0] = 0;
    }

    Matrix operator * (const Matrix& o) const {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ll sm = 0;
                for (int k = 0; k < 2; k++) {
                    sm += 1ll * a[i][k] * o.a[k][j];
                }
                res.a[i][j] = sm % mod;
            }
        }
        return res;
    }

    bool is_eye() const {
        return a[0][0] == 1 && a[1][1] == 1 && a[0][1] == 0 && a[1][0] == 0;
    }
};

struct RangeTree {
    int n = 0; // [0, )
    vector<Matrix> t;
    vector<int> where;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        t.resize(4 * n);
    }

    void push(int v) {
        if (!t[v].is_eye()) {
            t[v << 1] = t[v] * t[v << 1];
            t[v << 1 | 1] = t[v] * t[v << 1 | 1];
            t[v] = Matrix();
        }
    }

    void update(int v, int tl, int tr, int l, int r, const Matrix& x) {
        if (l <= tl && tr <= r) {
            t[v] = x * t[v];
        } else {
            int tm = tl + (tr - tl) / 2;
            push(v);
            if (l <= tm) update(v << 1, tl, tm, l, r, x);
            if (r > tm) update(v << 1 | 1, tm + 1, tr, l, r, x);
        }
    }

    void update(int l, int r, const Matrix& x) {
        update(1, 0, n - 1, l, r, x);
    }

    void build(int v, int tl, int tr) {
        if (tl < tr) {
            int tm = tl + (tr - tl) / 2;
            push(v);
            build(v << 1, tl, tm);
            build(v << 1 | 1, tm + 1, tr);
        } else {
            where[tl] = v;
        }
    }

    void build() {
        where.resize(n);
        build(1, 0, n - 1);
    }

    Matrix get(int pos) {
        return t[where[pos]];
    }
};

struct input {
    int n;
    vector<pii> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& [l, r] : a)
            cin >> l >> r;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int X = 0;
        for (auto [l, r] : a) X = max(X, r);
        X++;
        // [0, X)
        vector<vector<int>> dp(X, vector<int>(2)), nx;
        int init = 1;
        RangeTree rt(X);
        Matrix A, B;
        {
            A.a[0][0] = A.a[0][1] = 1;
            A.a[1][0] = A.a[1][1] = 2;
        }
        {
            B.a[0][0] = 3;
            B.a[0][1] = 1;
            B.a[1][0] = 0;
            B.a[1][1] = 2;
        }
        for (auto [l, r] : a) {
            if (init) {
                init = 0;
                for (int x = 0; x < X; x++) {
                    if (l <= x && x <= r) {
                        dp[x][0] = 0;
                        dp[x][1] = 1;
                    } else {
                        dp[x][0] = 1;
                        dp[x][1] = 0;
                    }
                }
            } else {
                rt.update(l, r, A);
                if (l > 0) rt.update(0, l - 1, B);
                if (r + 1 < X) rt.update(r + 1, X - 1, B);
//                nx.assign(X, vector<int>(2, 0));
//                for (int x = 0; x < X; x++) {
//                    if (l <= x && x <= r) {
////                        nx[x][0] = sum_(dp[x][0], dp[x][1]);
////                        nx[x][1] = mul_(2, sum_(dp[x][0], dp[x][1]));
//                        nx[x] = MUL(A, dp[x]);
//                    } else {
////                        nx[x][0] = sum_(mul_(3, dp[x][0]), dp[x][1]);
////                        nx[x][1] = sum_(dp[x][1], dp[x][1]);
//                        nx[x] = MUL(B, dp[x]);
//                    }
//                }
//                swap(dp, nx);
            }
        }
        int res = 0;
        rt.build();
        for (int x = 0; x < X; x++) {
//            inc_(res, dp[x][1]);
            auto mat = rt.get(x);
            for (int j = 0; j < 2; j++)
                inc_(res, mul_(mat.a[1][j], dp[x][j]));
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
#ifdef DEBUG
    cin >> t;
#endif
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