// =================================
//   author: memset0
//   date: 2019.05.18 22:16:19
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

const int N = 5e3 + 10, mod = 1e9 + 7;
int n, m, ans, s[N], inv[N], fac[N], ifac[N];

inline int dec(int a, int b) { a -= b; return a < 0 ? a + mod : a; }
inline int inc(int a, int b) { a += b; return a >= mod ? a - mod : a; }
inline int mul(int a, int b) { return (ll)a * b - (ll)a * b / mod * mod; }
inline int fpow(int a, int b) { int s = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) s = mul(s, a); return s; }

inline int C(int n, int m) {
	int res = 1;
	for (int i = 1; i <= m; i++)
		res = mul(res, mul(inv[i], n - i + 1));
	return res;
}

void getFactorial(int n, int *f, int *g) {
	f[0] = f[1] = g[0] = g[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = mul(mod - mod / i, inv[mod % i]);
	for (int i = 2; i <= n; i++) f[i] = mul(f[i - 1], i);
	for (int i = 2; i <= n; i++) g[i] = mul(g[i - 1], inv[i]);
}

void getStrlingNumber(int n, int *res) {
	static int s[N][N];
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j < i; j++) s[i][j] = inc(s[i - 1][j - 1], mul(j, s[i - 1][j]));
		s[i][i] = 1;
	}
	for (int i = 0; i <= n; i++) res[i] = s[n][i];
}

void main() {
	read(n), read(m);
	getFactorial(m, fac, ifac);
	getStrlingNumber(m, s);
	// print(fac, 0, m, "fac"), print(ifac, 0, m, "ifac"), print(s, 0, m, "strling");
	for (int i = 0; i <= m; i++) if (n >= i)
		ans = inc(ans, mul(fac[i], mul(s[i], mul(C(n, i), fpow(2, n - i)))));
	print(ans, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	ringo::main();
	std::cerr << clock() / (double)CLOCKS_PER_SEC << std::endl;
	return 0;
}