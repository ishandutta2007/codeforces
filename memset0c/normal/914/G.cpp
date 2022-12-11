// =================================
//   author: memset0
//   date: 2019.06.20 14:21:31
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
    x = 0; char c = getchar(); bool f = 0;
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
template <class T> inline void print(T a, int l, int r, std::string s = "") {
    if (s != "") std::cout << s << ": ";
    for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 2e6 + 10, K = 18, mod = 1e9 + 7;
int n, L, ans, lim = 1;
int a[N], F[N], G[N], H[N], fib[N], cnt[N], tmp[N], dp[K][N];

inline int half(int x) { return x & 1 ? (x + mod) >> 1 : x >> 1; }
inline int dec(int a, int b) { a -= b; return a < 0 ? a + mod : a; }
inline int inc(int a, int b) { a += b; return a >= mod ? a - mod : a; }
inline int mul(int a, int b) { return (ll)a * b - (ll)a * b / mod * mod; }

inline void fwt_or(int &a, int &b) { b = inc(b, a); }
inline void ifwt_or(int &a, int &b) { b = dec(b, a); }
inline void fwt_and(int &a, int &b) { a = inc(a, b); }
inline void ifwt_and(int &a, int &b) { a = dec(a, b); }
inline void fwt_xor(int &a, int &b) { int x = a, y = b; a = inc(x, y), b = dec(x, y); }
inline void ifwt_xor(int &a, int &b) { int x = a, y = b; a = half(inc(x, y)), b = half(dec(x, y)); }

inline void fwt(int *a, void oper(int&, int&)) {
    for (int len = 1; len < lim; len <<= 1)
        for (int i = 0; i < lim; i += (len << 1))
            for (int j = 0; j < len; j++)
                oper(a[i + j], a[i + j + len]);
}

void main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]), ++G[a[i]], ++H[a[i]];;
        while (lim <= a[i]) lim <<= 1, ++L;
    }
    fib[1] = 1;
    for (int i = 2; i < lim; i++) fib[i] = inc(fib[i - 1], fib[i - 2]);
    for (int i = 1; i < lim; i++) cnt[i] = cnt[i >> 1] + (i & 1);
    for (int i = 1; i <= n; i++) ++dp[cnt[a[i]]][a[i]];
    for (int i = 0; i <= L; i++) fwt(dp[i], fwt_or);
    for (int i = 0; i <= L; i++) {
        memset(tmp, 0, lim << 2);
        for (int j = 0; j <= i; j++)
            for (int k = 0; k < lim; k++)
                tmp[k] = inc(tmp[k], mul(dp[j][k], dp[i - j][k]));
        fwt(tmp, ifwt_or);
        for (int k = 0; k < lim; k++) if (cnt[k] == i) F[k] = tmp[k];
    }
    fwt(G, fwt_xor);
    for (int i = 0; i < lim; i++) G[i] = mul(G[i], G[i]);
    fwt(G, ifwt_xor);
    for (int i = 0; i < lim; i++) F[i] = mul(F[i], fib[i]), G[i] = mul(G[i], fib[i]), H[i] = mul(H[i], fib[i]);
    fwt(F, fwt_and), fwt(G, fwt_and), fwt(H, fwt_and);
    for (int i = 0; i < lim; i++) F[i] = mul(F[i], mul(G[i], H[i]));
    fwt(F, ifwt_and);
    for (int i = 0; i < L; i++) ans = inc(ans, F[1 << i]);
    print(ans, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
    freopen("1.in", "r", stdin);
#endif
    return ringo::main(), 0;
}