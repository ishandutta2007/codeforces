// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2019.02.16 16:16:14
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define poly std::vector <int>
#define for_each(i, a) for (int i = 0, __lim = a.size(); i < __lim; ++i)
namespace ringo {
template <class T> inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}
template <class T> inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
inline void print(const poly &a) { for_each(i, a) print(a[i], " \n"[i == __lim - 1]); }
inline void read(poly &a, int n) { for (int i = 0, x; i < n; i++) read(x), a.push_back(x); }

const int N = 1e5 + 10, M = N << 3, mod = 998244353;
int n, m, a[N], b[N], w[M << 3], rev[M << 3];

inline poly resize(poly f, int n) { return f.resize(n), f; }
inline int dec(int a, int b) { a -= b; return a < 0 ? a + mod : a; }
inline int sub(int a, int b) { a += b; return a >= mod ? a - mod : a; }
inline int inv(int x) { return x < 2 ? 1 : (ll)(mod - mod / x) * inv(mod % x) % mod; }
inline int fpow(int a, int b) { int s = 1; for (; b; b >>= 1, a = (ll)a * a % mod) if (b & 1) s = (ll)s * a % mod; return s; }

void ntt(poly &a) {
    int lim = a.size();
    for_each(i, a) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
    for (int len = 1; len < lim; len <<= 1)
        for (int i = 0; i < lim; i += (len << 1))
            for (int j = 0; j < len; j++) {
                int x = a[i + j], y = (ll)w[j + len] * a[i + j + len] % mod;
                a[i + j] = sub(x, y), a[i + j + len] = dec(x, y);
            }
}

int init(int len) {
    int lim = 1, k = 0; while (lim < len) lim <<= 1, ++k;
    for (int i = 0; i < lim; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    // for (int len = 1, wn; len < lim; len <<= 1) {
    //     wn = fpow(3, (mod - 1) / (len << 1)), w[len] = 1;
    //     for (int i = 1; i < len; i++) w[i + len] = (ll)w[i + len - 1] * wn % mod;
    // }
    return lim;
}

void main_init(int lim) {
    for (int len = 1, wn, __lim = std::min(lim + 100, M); len < __lim; len <<= 1) {
        wn = fpow(3, (mod - 1) / (len << 1)), w[len] = 1;
        for (int i = 1; i < len; i++) w[i + len] = (ll)w[i + len - 1] * wn % mod;
    }
}

inline poly operator + (poly f, int a) { f[0] = sub(f[0], a); return f; }
inline poly operator + (int a, poly f) { f[0] = sub(a, f[0]); return f; }
inline poly operator - (poly f, int a) { f[0] = dec(f[0], a); return f; }
inline poly operator - (int a, poly f) { for_each(i, f) f[i] = dec(0, f[i]); f[0] = sub(a, f[0]); return f; }
inline poly operator * (poly f, int a) { for_each(i, f) f[i] = (ll)f[i] * a % mod; return f; }
inline poly operator * (int a, poly f) { for_each(i, f) f[i] = (ll)f[i] * a % mod; return f; }

inline poly operator + (poly f, const poly &g) {
    f.resize(std::max(f.size(), g.size()));
    for_each(i, f) f[i] = sub(i < f.size() ? f[i] : 0, i < g.size() ? g[i] : 0);
    return f;
}

inline poly operator - (poly f, const poly &g) {
    f.resize(std::max(f.size(), g.size()));
    for_each(i, f) f[i] = dec(i < f.size() ? f[i] : 0, i < g.size() ? g[i] : 0);
    return f;
}

inline poly operator * (const poly &f, const poly &g) {
    poly a = f, b = g;
    int lim = init(a.size() + b.size() - 1), inv_lim = inv(lim);
    a.resize(lim), b.resize(lim), ntt(a), ntt(b);
    for_each(i, a) a[i] = (ll)a[i] * b[i] % mod;
    std::reverse(a.begin() + 1, a.end()), ntt(a), a.resize(f.size() + g.size() - 1);
    for_each(i, a) a[i] = (ll)a[i] * inv_lim % mod;
    return a;
}

inline poly inv(const poly &f) {
    poly g(1, inv(f[0]));
    for (int len = 2; (len >> 1) < f.size(); len <<= 1) {
        int lim = init(len << 1), inv_lim = inv(lim);
        poly a = resize(f, len), b = g;
        a.resize(lim), b.resize(lim), ntt(a), ntt(b);
        for_each(i, a) a[i] = (ll)a[i] * b[i] % mod * b[i] % mod;
        std::reverse(a.begin() + 1, a.end()), ntt(a), g.resize(len);
        for_each(i, g) g[i] = dec(sub(g[i], g[i]), (ll)a[i] * inv_lim % mod);
    } return g.resize(f.size()), g;
}

inline poly sqrt(const poly &f) {
    poly g(1, 1);
    for (int len = 2; (len >> 1) < f.size(); len <<= 1)
        g = resize(resize(resize(g * g, len) + f, len) * inv(resize(2 * g, len)), len);
    return g.resize(f.size()), g;
}

void main() {
    poly A, F; read(m), read(n); main_init(n << 2), ++n;
    for (int i = 1; i <= m; i++) read(a[i]), b[a[i]] = 1;
    for (int i = 0; i < n; i++) A.push_back(b[i]);
    F = resize(2 * inv(1 + sqrt(1 - 4 * A)), n);
    for (int i = 1; i < n; i++) print(F[i], '\n');
}

} signed main() { return ringo::main(), 0; }