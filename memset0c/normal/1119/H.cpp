// =================================
//   author: memset0
//   date: 2019.04.07 18:24:19
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

const int N = 2e5 + 10, mod = 998244353;
int n, m, p, q, r, lim, tot;
int a[N], b[N], c[N], f[N], g[N], h[N];

inline int dec(int a, int b) { a -= b; return a < 0 ? a + mod : a; }
inline int sub(int a, int b) { a += b; return a >= mod ? a - mod : a; }
inline int mul(int a, int b) { return (ll)a * b - (ll)a * b / mod * mod; }
inline int inv(int x) { return x < 2 ? 1 : mul(mod - mod / x, inv(mod % x)); }
inline int fpow(int a, int b) { int s = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) s = mul(s, a); return s; }

void fwt(int *a) {
	for (int len = 1; len < lim; len <<= 1)	
		for (int i = 0; i < lim; i += (len << 1))
			for (int j = 0; j < len; j++) {
				int x = a[i + j], y = a[i + j + len];
				a[i + j] = sub(x, y), a[i + j + len] = dec(x, y);
			}
}

void ifwt(int *a) {
	for (int len = 1; len < lim; len <<= 1)
		for (int i = 0; i < lim; i += (len << 1))
			for (int j = 0; j < len; j++) {
				int x = a[i + j], y = a[i + j + len];
				a[i + j] = mul(sub(x, y), inv(2)), a[i + j + len] = mul(dec(x, y), inv(2));
			}
}

void main() {
	read(n), read(m), read(p), read(q), read(r);
	for (int i = 1; i <= n; i++) read(a[i]), read(b[i]), read(c[i]);
	for (int i = 1; i <= n; i++) tot ^= a[i], ++f[a[i] ^ b[i]], ++g[a[i] ^ c[i]], ++h[b[i] ^ c[i]];
	lim = 1 << m;
	fwt(f), fwt(g), fwt(h);
	int t0 = sub(sub(p, q), r), t1 = dec(sub(p, q), r), t2 = sub(dec(p, q), r), t3 = dec(dec(p, q), r);
	for (int i = 0; i < lim; i++) {
		int x = mul(sub(n, sub(f[i], sub(g[i], h[i]))), inv(4)),
			y = dec(mul(sub(n, f[i]), inv(2)), x),
			z = dec(mul(sub(n, g[i]), inv(2)), x),
			w = dec(mul(sub(n, h[i]), inv(2)), x);
		f[i] = mul(fpow(t0, x), mul(fpow(t1, y), mul(fpow(t2, z), fpow(t3, w))));
	}
	ifwt(f);
	for (int i = 0; i < lim; i++) print(f[i ^ tot], ' ');	
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}