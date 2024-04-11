#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1 << 20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int n, k, p;
const int maxN = 1e5 + 10;
int a[maxN];


namespace ntt {

    const int md = 998244353;

    inline void add(int &x, int y) {
        x += y;
        if (x >= md) {
            x -= md;
        }
    }

    inline void sub(int &x, int y) {
        x -= y;
        if (x < 0) {
            x += md;
        }
    }

    inline int mul(int x, int y) {
        return (long long) x * y % md;
    }

    inline int power(int x, int y) {
        int res = 1;
        for (; y; y >>= 1, x = mul(x, x)) {
            if (y & 1) {
                res = mul(res, x);
            }
        }
        return res;
    }

    inline int inv(int a) {
        a %= md;
        if (a < 0) {
            a += md;
        }
        int b = md, u = 0, v = 1;
        while (a) {
            int t = b / a;
            b -= t * a;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0) {
            u += md;
        }
        return u;
    }

    int base = 1, root = -1, max_base = -1;
    vector<int> rev = {0, 1}, roots = {0, 1};

    void init() {
        int temp = md - 1;
        max_base = 0;
        while (temp % 2 == 0) {
            temp >>= 1;
            ++max_base;
        }
        root = 2;
        while (true) {
            if (power(root, 1 << max_base) == 1 && power(root, 1 << max_base - 1) != 1) {
                break;
            }
            ++root;
        }
    }

    void ensure_base(int nbase) {
        if (max_base == -1) {
            init();
        }
        if (nbase <= base) {
            return;
        }
        assert(nbase <= max_base);
        rev.resize(1 << nbase);
        for (int i = 0; i < 1 << nbase; ++i) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << nbase - 1;
        }
        roots.resize(1 << nbase);
        while (base < nbase) {
            int z = power(root, 1 << max_base - 1 - base);
            for (int i = 1 << base - 1; i < 1 << base; ++i) {
                roots[i << 1] = roots[i];
                roots[i << 1 | 1] = mul(roots[i], z);
            }
            ++base;
        }
    }

    void dft(vector<int> &a) {
        int n = a.size(), zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for (int i = 0; i < n; ++i) {
            if (i < rev[i] >> shift) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j += i << 1) {
                for (int k = 0; k < i; ++k) {
                    int x = a[j + k], y = mul(a[j + k + i], roots[i + k]);
                    a[j + k] = (x + y) % md;
                    a[j + k + i] = (x + md - y) % md;
                }
            }
        }
    }

    vector<int> multiply(vector<int> a, vector<int> b) {
        int need = a.size() + b.size() - 1, nbase = 0;
        while (1 << nbase < need) {
            ++nbase;
        }
        ensure_base(nbase);
        int sz = 1 << nbase;
        a.resize(sz);
        b.resize(sz);
        bool equal = a == b;
        dft(a);
        if (equal) {
            b = a;
        } else {
            dft(b);
        }
        int inv_sz = inv(sz);
        for (int i = 0; i < sz; ++i) {
            a[i] = mul(mul(a[i], b[i]), inv_sz);
        }
        reverse(a.begin() + 1, a.end());
        dft(a);
        a.resize(need);
        return a;
    }

    vector<int> inverse(vector<int> a) {
        int n = a.size(), m = n + 1 >> 1;
        if (n == 1) {
            return vector<int>(1, inv(a[0]));
        } else {
            vector<int> b = inverse(vector<int>(a.begin(), a.begin() + m));
            int need = n << 1, nbase = 0;
            while (1 << nbase < need) {
                ++nbase;
            }
            ensure_base(nbase);
            int sz = 1 << nbase;
            a.resize(sz);
            b.resize(sz);
            dft(a);
            dft(b);
            int inv_sz = inv(sz);
            for (int i = 0; i < sz; ++i) {
                a[i] = mul(mul(md + 2 - mul(a[i], b[i]), b[i]), inv_sz);
            }
            reverse(a.begin() + 1, a.end());
            dft(a);
            a.resize(n);
            return a;
        }
    }

    using ntt::multiply;
    using ntt::inverse;

    vector<int> &operator+=(vector<int> &a, const vector<int> &b) {
        if (a.size() < b.size()) {
            a.resize(b.size());
        }
        for (int i = 0; i < b.size(); ++i) {
            add(a[i], b[i]);
        }
        return a;
    }

    vector<int> operator+(const vector<int> &a, const vector<int> &b) {
        vector<int> c = a;
        return c += b;
    }

    vector<int> &operator-=(vector<int> &a, const vector<int> &b) {
        if (a.size() < b.size()) {
            a.resize(b.size());
        }
        for (int i = 0; i < b.size(); ++i) {
            sub(a[i], b[i]);
        }
        return a;
    }

    vector<int> operator-(const vector<int> &a, const vector<int> &b) {
        vector<int> c = a;
        return c -= b;
    }

    vector<int> &operator*=(vector<int> &a, const vector<int> &b) {
        if (min(a.size(), b.size()) < 128) {
            vector<int> c = a;
            a.assign(a.size() + b.size() - 1, 0);
            for (int i = 0; i < c.size(); ++i) {
                for (int j = 0; j < b.size(); ++j) {
                    add(a[i + j], mul(c[i], b[j]));
                }
            }
        } else {
            a = multiply(a, b);
        }
        return a;
    }

    vector<int> operator*(const vector<int> &a, const vector<int> &b) {
        vector<int> c = a;
        return c *= b;
    }

    vector<int> &operator/=(vector<int> &a, const vector<int> &b) {
        int n = a.size(), m = b.size();
        if (n < m) {
            a.clear();
        } else {
            vector<int> c = b;
            reverse(a.begin(), a.end());
            reverse(c.begin(), c.end());
            c.resize(n - m + 1);
            a *= inverse(c);
            a.erase(a.begin() + n - m + 1, a.end());
            reverse(a.begin(), a.end());
        }
        return a;
    }

    vector<int> operator/(const vector<int> &a, const vector<int> &b) {
        vector<int> c = a;
        return c /= b;
    }

    vector<int> &operator%=(vector<int> &a, const vector<int> &b) {
        int n = a.size(), m = b.size();
        if (n >= m) {
            vector<int> c = (a / b) * b;
            a.resize(m - 1);
            for (int i = 0; i < m - 1; ++i) {
                sub(a[i], c[i]);
            }
        }
        return a;
    }

    vector<int> operator%(const vector<int> &a, const vector<int> &b) {
        vector<int> c = a;
        return c %= b;
    }

    vector<int> derivative(const vector<int> &a) {
        int n = a.size();
        vector<int> b(n - 1);
        for (int i = 1; i < n; ++i) {
            b[i - 1] = mul(a[i], i);
        }
        return b;
    }

    vector<int> primitive(const vector<int> &a) {
        int n = a.size();
        vector<int> b(n + 1), invs(n + 1);
        for (int i = 1; i <= n; ++i) {
            invs[i] = i == 1 ? 1 : mul(md - md / i, invs[md % i]);
            b[i] = mul(a[i - 1], invs[i]);
        }
        return b;
    }

    vector<int> logarithm(const vector<int> &a) {
        vector<int> b = primitive(derivative(a) * inverse(a));
        b.resize(a.size());
        return b;
    }

    vector<int> exponent(const vector<int> &a) {
        vector<int> b(1, 1);
        while (b.size() < a.size()) {
            vector<int> c(a.begin(), a.begin() + min(a.size(), b.size() << 1));
            add(c[0], 1);
            vector<int> old_b = b;
            b.resize(b.size() << 1);
            c -= logarithm(b);
            c *= old_b;
            for (int i = b.size() >> 1; i < b.size(); ++i) {
                b[i] = c[i];
            }
        }
        b.resize(a.size());
        return b;
    }

    vector<int> power(const vector<int> &a, int m) {
        int n = a.size(), p = -1;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                p = i;
                break;
            }
        }
        if (p == -1) {
            b[0] = !m;
            return b;
        }
        if ((long long) m * p >= n) {
            return b;
        }
        int mu = power(a[p], m), di = inv(a[p]);
        vector<int> c(n - m * p);
        for (int i = 0; i < n - m * p; ++i) {
            c[i] = mul(a[i + p], di);
        }
        c = logarithm(c);
        for (int i = 0; i < n - m * p; ++i) {
            c[i] = mul(c[i], m);
        }
        c = exponent(c);
        for (int i = 0; i < n - m * p; ++i) {
            b[i + m * p] = mul(c[i], mu);
        }
        return b;
    }

    vector<int> sqrt(const vector<int> &a) {
        vector<int> b(1, 1);
        while (b.size() < a.size()) {
            vector<int> c(a.begin(), a.begin() + min(a.size(), b.size() << 1));
            vector<int> old_b = b;
            b.resize(b.size() << 1);
            c *= inverse(b);
            for (int i = b.size() >> 1; i < b.size(); ++i) {
                b[i] = mul(c[i], md + 1 >> 1);
            }
        }
        b.resize(a.size());
        return b;
    }

    vector<int> multiply_all(int l, int r, vector<vector<int>> &all) {
        if (l > r) {
            return vector<int>();
        } else if (l == r) {
            return all[l];
        } else {
            int y = l + r >> 1;
            return multiply_all(l, y, all) * multiply_all(y + 1, r, all);
        }
    }

    vector<int> evaluate(const vector<int> &f, const vector<int> &x) {
        int n = x.size();
        if (!n) {
            return vector<int>();
        }
        vector<vector<int>> up(n * 2);
        for (int i = 0; i < n; ++i) {
            up[i + n] = vector<int>{(md - x[i]) % md, 1};
        }
        for (int i = n - 1; i; --i) {
            up[i] = up[i << 1] * up[i << 1 | 1];
        }
        vector<vector<int>> down(n * 2);
        down[1] = f % up[1];
        for (int i = 2; i < n * 2; ++i) {
            down[i] = down[i >> 1] % up[i];
        }
        vector<int> y(n);
        for (int i = 0; i < n; ++i) {
            y[i] = down[i + n][0];
        }
        return y;
    }

    vector<int> interpolate(const vector<int> &x, const vector<int> &y) {
        int n = x.size();
        vector<vector<int>> up(n * 2);
        for (int i = 0; i < n; ++i) {
            up[i + n] = vector<int>{(md - x[i]) % md, 1};
        }
        for (int i = n - 1; i; --i) {
            up[i] = up[i << 1] * up[i << 1 | 1];
        }
        vector<int> a = evaluate(derivative(up[1]), x);
        for (int i = 0; i < n; ++i) {
            a[i] = mul(y[i], inv(a[i]));
        }
        vector<vector<int>> down(n * 2);
        for (int i = 0; i < n; ++i) {
            down[i + n] = vector<int>(1, a[i]);
        }
        for (int i = n - 1; i; --i) {
            down[i] = down[i << 1] * up[i << 1 | 1] + down[i << 1 | 1] * up[i << 1];
        }
        return down[1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int d = k;
    vector<int> add(d + 2), coef(d + 2);
    add[0] = 0;
    coef[0] = 1;
    int invr = pw(p, mod - 2);
    for (int i = 0; i <= d; i++) {
        coef[i + 1] = mult(coef[i], invr);
        add[i + 1] = mult(invr, sum(pw(i, d), add[i]));
    }
    vector<int> inv(d + 2);
    inv[1] = 1;
    for (int i = 2; i <= d + 1; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
    }
    //calc_in_(d + 1)
    vector<int> invfact(d + 2);
    invfact[0] = 1;
    for (int i = 1; i <= d + 1; i++) {
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    int tot_fact = 1;
    for (int i = 1; i <= d + 1; i++) tot_fact = mult(tot_fact, i);
    int tot_coef = 0;
    int tot_add = 0;
    for (int i = 0; i <= d + 1; i++) {
        int cnk = mult(tot_fact, mult(invfact[i], invfact[d + 1 - i]));
        if (i & 1) cnk = sub(0, cnk);
        tot_coef = sum(tot_coef, mult(cnk, coef[i]));
        tot_add = sum(tot_add, mult(cnk, add[i]));
    }
    int g0 = 0;
    if (tot_coef == 0) {
        assert(p == 1);
        g0 = 0;
    } else {
        g0 = mult(pw(tot_coef, mod - 2), sub(0, tot_add));
    }

    assert(sum(mult(g0, tot_coef), tot_add) == 0);
    invfact.clear();
    inv.clear();
    vector<int> vals(d + 1);
    vector<int> res(d + 1);
    for (int i = 0; i <= d; i++) {
        vals[i] = sum(mult(g0, coef[i]), add[i]);
        res[i] = i;
    }
    auto g_poly = ntt::interpolate(res, vals);
    vector<int> all;
    for (int i = 0; i < n; i++) {
        all.emplace_back(a[i] + 1);
    }
    auto res_vals = ntt::evaluate(g_poly, all);
    for (int i = 0; i < n; i++) {
        res_vals[i] = sub(mult(pw(p, a[i] + 1), res_vals[i]), g0);
    }
    vector<int> suf_sum(n), pref_sum(n);
    vector<int> dp_pref(n), dp_suf(n);
    pref_sum[0] = 1;
    for (int i = 0; i + 1 < n; i++) {
        pref_sum[i + 1] = sum(mult(pref_sum[i], a[i] + 1), 1);
        dp_pref[i + 1] = sum(mult(a[i] + 1, dp_pref[i]), mult(a[i], pref_sum[i]));
    }
    suf_sum[n - 1] = 1;
    for (int i = n - 1; i > 0; i--) {
        suf_sum[i - 1] = sum(mult(suf_sum[i], a[i] + 1), 1);
        dp_suf[i - 1] = sum(mult(a[i] + 1, dp_suf[i]), mult(a[i], suf_sum[i]));
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = sum(ans, mult(res_vals[i], mult(suf_sum[i], pref_sum[i])));
        ans = sum(ans, mult(res_vals[i], mult(dp_pref[i], suf_sum[i])));
        ans = sum(ans, mult(res_vals[i], mult(dp_suf[i], pref_sum[i])));
    }
    cout << ans << '\n';
    return 0;
}