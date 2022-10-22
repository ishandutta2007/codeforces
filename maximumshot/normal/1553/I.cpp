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

template<int mod, int root, int LOG>
struct FFT {
//    const int mod = 998244353;
//    const int root = 31;
//    const int LOG = 23;
    vector<int> G[LOG + 1];
    vector<int> rev[LOG + 1];
    FFT() {
        for (int start = root, lvl = LOG; lvl >= 0; lvl--, start = mul(start, start)) {
            int tot = 1 << lvl;
            G[lvl].resize(tot);
            for (int cur = 1, i = 0; i < tot; i++, cur = mul(cur, start)) {
                G[lvl][i] = cur;
            }
        }
        for (int lvl = 1; lvl <= LOG; lvl++) {
            int tot = 1 << lvl;
            rev[lvl].resize(tot);
            for (int i = 1; i < tot; i++) {
                rev[lvl][i] = ((i & 1) << (lvl - 1)) | (rev[lvl][i >> 1] >> 1);
            }
        }
    }
    void fft(vector<int>& a, int sz, bool invert) {
        int n = 1 << sz;
        for (int j, i = 0; i < n; i++) {
            if ((j = rev[sz][i]) < i)
                swap(a[i], a[j]);
        }
        for (int f1, f2, lvl = 0, len = 1; len < n; len <<= 1, lvl++) {
            for (int i = 0; i < n; i+= (len << 1)) {
                for (int j = 0; j < len; j++) {
                    f1 = a[i + j];
                    f2 = mul(a[i + j + len], G[lvl + 1][j]);
                    a[i + j] = sum(f1, f2);
                    a[i + j + len] = sub(f1, f2);
                }
            }
        }
        if (invert) {
            reverse(a.begin() + 1, a.end());
            int rn = binpow(n, mod - 2);
            for (int i = 0; i < n; i++) {
                a[i] = mul(a[i], rn);
            }
        }
    }
    vector<int> multiply(const vector<int>& a, const vector<int>& b) {
        vector<int> fa(a.begin(), a.end());
        vector<int> fb(b.begin(), b.end());
        int n = (int) a.size();
        int m = (int) b.size();
        int maxnm = max(n, m), sz = 0;
        while ((1 << sz) < maxnm)
            sz++;
        sz++;
        fa.resize(1 << sz);
        fb.resize(1 << sz);
        fft(fa, sz, false);
        fft(fb, sz, false);
        int SZ = 1 << sz;
        for (int i = 0; i < SZ; i++) {
            fa[i] = mul(fa[i], fb[i]);
        }
        fft(fa, sz, true);
        return fa;
    }
    int sum(int x, int y) {
        return x + y < mod ? x + y : x + y - mod;
    }
    int sub(int x, int y) {
        return x >= y ? x - y : x - y + mod;
    }
    int mul(int x, int y) {
        return (1ll * x * y) % mod;
    }
    int mul(const vector<int>& a) {
        int res = 1;
        for (const auto& x : a)
            res = mul(res, x);
        return res;
    }
    void inc(int& x, int y) {
        if ((x += y) >= mod)
            x -= mod;
    }
    void dec(int& x, int y) {
        if ((x -= y) < 0)
            x += mod;
    }
    int binpow(int x, int pw) {
        int res = 1, tmp = x;
        while (pw > 0) {
            if (pw & 1) res = mul(res, tmp);
            tmp = mul(tmp, tmp);
            pw >>= 1;
        }
        return res;
    }
};

const int mod = 998244353;

FFT<mod, 31 * 31 * 31 * 31, 21> fft;

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
        return res == o.res;
    }
};

struct Polynom {
    vector<int> f = {0};

    static void normalize(vector<int>& a) {
        while ((int) a.size() > 1 && !a.back())
            a.pop_back();
    }

    Polynom operator + (const Polynom& o) const {
        vector<int> res(max(f.size(), o.f.size()));
        for (int i = 0; i < (int) f.size(); i++)
            inc_(res[i], f[i]);
        for (int i = 0; i < (int) o.f.size(); i++)
            inc_(res[i], o.f[i]);
        normalize(res);
        return Polynom{res};
    }

    Polynom operator * (const Polynom& o) const {
        auto res = fft.multiply(f, o.f);
//        vector<int> res(f.size() + o.f.size());
//        for (int i = 0; i < (int) f.size(); i++) {
//            for (int j = 0; j < (int) o.f.size(); j++)
//                inc_(res[i + j], mul_(f[i], o.f[j]));
//        }
        normalize(res);
        return Polynom{res};
    }

    Polynom& operator += (const Polynom& o) {
        if (f.size() < o.f.size()) f.resize(o.f.size());
        for (int i = 0; i < (int) o.f.size(); i++)
            inc_(f[i], o.f[i]);
        return *this;
    }
};

template <class T>
vector<vector<T>> multiply_matrix(const vector<vector<T>>& a, const vector<vector<T>>& b) {
    int n = (int) a.size();
    int m = (int) a[0].size();
    int k = (int) b[0].size();
    vector<vector<T>> res(n, vector<T>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int t = 0; t < m; t++)
                res[i][j] += a[i][t] * b[t][j];
        }
    }
    return res;
}

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a) cin >> x;
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        n = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % n + 1;
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> b;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (i + x > n) return output{0};
            for (int j = 0; j < x; j++) {
                if (a[i + j] != x)
                    return output{0};
            }
            b.push_back(x);
            i = i + x - 1;
        }
        vector<int> fact(n + 1), rfact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = mul_(fact[i - 1], i);
        rfact[n] = binpow_(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--)
            rfact[i] = mul_(rfact[i + 1], i + 1);
        vector<int> pw2(n + 1), pw_r2(n + 1);
        pw2[0] = 1;
        for (int i = 1; i <= n; i++)
            pw2[i] = mul_(pw2[i - 1], 2);
        int r2 = binpow_(2, mod - 2);
        pw_r2[0] = 1;
        for (int i = 1; i <= n; i++)
            pw_r2[i] = mul_(pw_r2[i - 1], r2);
        int k = (int) b.size();
        int res = 0;

//        vector<vector<int>> dp(k + 1, vector<int>(k + 1));
//        dp[0][0] = 1;
//        dp[1][1] = b[0] == 1 ? r2 : 1;
//        for (int i = 2; i <= k; i++) {
//            for (int j = 1; j <= k; j++) {
//                dp[i][j] = sum_(
//                        mul_(dp[i - 1][j - 1], b[i - 1] == 1 ? r2 : 1),
//                        dp[i - 1][j]
//                );
//                if (b[i - 2] == 1)
//                    inc_(dp[i][j], mul_(dp[i - 2][j - 1], r2));
//            }
//        }

        vector<int> f(k + 1);
//        vector<Polynom> dp(k + 1);
//        dp[0] = Polynom{{1}};
//        dp[1] = Polynom{{0, b[0] == 1 ? r2 : 1}};

        vector<vector<Polynom>> start = {
            {Polynom{{1}}},
            {Polynom{{0, b[0] == 1 ? r2 : 1}}}
        };

        vector<int> cf(k + 1);
        for (int i = 1; i <= k; i++)
            cf[i] = b[i - 1] == 1 ? r2 : 1;
        b.insert(b.begin(), 0);
        b.insert(b.begin(), 0);
        for (auto& t : b) t = mul_(int(t == 1), r2);

        vector<vector<vector<Polynom>>> A;
        vector<vector<Polynom>> eye = {
                {Polynom{{1}}, Polynom{{0}}},
                {Polynom{{0}}, Polynom{{1}}}
        }, ml = eye;
        for (int i = 2; i <= k; i++) {
            vector<vector<Polynom>> cur = {
                {Polynom{{0}}, Polynom{{1}}},
                {Polynom{{0, b[i]}}, Polynom{{1, cf[i]}}}
            };
//            ml = multiply_matrix(cur, ml);
//            cout << "i = " << i << "\n";
//            auto dp_i = multiply_matrix(ml, start);
//            cout << "\thave = "; for (auto x : dp_i[1][0].f) cout << x << " "; cout << "\n";
//            cout << "\tneed = "; for (auto x : dp[i]) cout << x << " "; cout << "\n";
            A.push_back(cur);
        }
        reverse(A.begin(), A.end());

//        for (int i = 2; i <= k; i++) {
//            dp[i] = (dp[i - 1] * Polynom{{1, cf[i]}}) + (dp[i - 2] * Polynom{{0, b[i]}});
//        }

        function<vector<vector<Polynom>>(int, int)> rec =
                [&](int l, int r) -> vector<vector<Polynom>> {
            if (l > r) return eye;
            if (l == r) return A[l];
            int m = (l + r) / 2;
            auto le = rec(l, m);
            auto ri = rec(m + 1, r);
            return multiply_matrix(le, ri);
        };

        auto ML = rec(0, (int) A.size() - 1);
        start = multiply_matrix(ML, start);

        f = start[1][0].f;
//        f = dp[k];
        f.resize(k + 1);

        for (int i = 0; i < k; i++) {
            int sign = i % 2 == 0 ? 1 : mod - 1;
            int coef = mul_(mul_(sign, f[k - i]), mul_(fact[k - i], pw2[k - i]));
            inc_(res, coef);
        }

        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        int res = 0;
        do {
            vector<int> b(n);
            for (int i = 0; i < n; i++) {
                int l = i, r = i;
                while (l > 0 && p[l - 1] + 1 == p[l]) l--;
                while (r + 1 < n && p[r + 1] == p[r] + 1) r++;
                b[i] = r - l + 1;
            }
            for (int i = 0; i < n; i++) {
                int l = i, r = i;
                while (l > 0 && p[l - 1] - 1 == p[l]) l--;
                while (r + 1 < n && p[r + 1] == p[r] - 1) r++;
                b[i] = max(b[i], r - l + 1);
            }
            if (a == b) res++;
        } while (next_permutation(p.begin(), p.end()));
        return output{res};
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