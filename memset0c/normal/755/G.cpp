// =================================
//   author: memset0
//   date: 2019.05.13 23:09:15
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

const int N = 1 << 17, mod = 998244353;
int n, m, k, lim = 1, inv_lim, w[N], rev[N];
struct matrix {
	int a[2][2][N >> 1];
} s, t, a;

inline int dec(int a, int b) { a -= b; return a < 0 ? a + mod : a; }
inline int inc(int a, int b) { a += b; return a >= mod ? a - mod : a; }
inline int mul(int a, int b) { return (ll)a * b - (ll)a * b / mod * mod; }
inline int inv(int x) { return x < 2 ? 1 : mul(mod - mod / x, inv(mod % x)); }
inline int fpow(int a, int b) { int s = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) s = mul(s, a); return s; }

inline void ntt(int *a) {
	for (int i = 0; i < lim; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int len = 1; len < lim; len <<= 1)
		for (int i = 0; i < lim; i += (len << 1))
			for (int j = 0; j < len; j++) {
				int x = a[i + j], y = mul(w[j + len], a[i + j + len]);
				a[i + j] = inc(x, y), a[i + j + len] = dec(x, y);
			}
}

inline matrix mul(matrix a, matrix b) {
	static matrix c;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) { ntt(a.a[i][j]), ntt(b.a[i][j]); }
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < lim; k++)
		c.a[i][j][k] = ((ll)a.a[i][0][k] * b.a[0][j][k] + (ll)a.a[i][1][k] * b.a[1][j][k]) % mod;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		std::reverse(c.a[i][j] + 1, c.a[i][j] + lim), ntt(c.a[i][j]);
		memset(c.a[i][j] + (lim >> 1), 0, lim << 1);
		for (int k = 0; k < (lim >> 1); k++) c.a[i][j][k] = mul(c.a[i][j][k], inv_lim);
	}
	return c;
}

void main() {
	read(n), read(m);
	while (lim < ((m + 1) << 1)) lim <<= 1, ++k; inv_lim = inv(lim);
	for (int i = 0; i < lim; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	for (int wn, len = 1; len < lim; len <<= 1) {
		wn = fpow(3, (mod - 1) / (len << 1)), w[len] = 1;
		for (int i = 1; i < len; i++) w[i + len] = mul(w[i + len - 1], wn);
	}
	t.a[0][0][0] = s.a[0][0][0] = s.a[1][1][0] = a.a[0][0][0] = a.a[0][0][1] = a.a[0][1][1] = a.a[1][0][0] = 1;
	for (int b = n; b; b >>= 1, a = mul(a, a)) if (b & 1) s = mul(s, a); s = mul(s, t);
	print(s.a[0][0], 1, m);
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	ringo::main();
	std::cerr << clock() / (double)CLOCKS_PER_SEC << std::endl;
	return 0;
}