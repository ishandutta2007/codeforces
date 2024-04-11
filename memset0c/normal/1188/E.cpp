// =================================
//   author: memset0
//   date: 2019.07.25 19:31:17
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for (int i = (l), i##ed = (r); i <= i##ed; ++i)
#define for_each(i, a) for (size_t i = 0, i##ed = a.size(); i < i##ed; ++i)
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

const int N = 2e6 + 10, mod = 998244353;
int n, m, ans, cnt, used;
int a[N], b[N], mrk[N], inv[N], fac[N], ifac[N];

inline int dec(int a, int b) { a -= b; return a < 0 ? a + mod : a; }
inline int inc(int a, int b) { a += b; return a >= mod ? a - mod : a; }
inline int mul(int a, int b) { return (ll)a * b - (ll)a * b / mod * mod; }
inline int binom(int n, int m) { return n < m ? 0 : mul(fac[n], mul(ifac[m], ifac[n - m])); }

void init_fac(int n) {
	fac[0] = fac[1] = inv[0] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= n; i++) fac[i] = mul(fac[i - 1], i);
	for (int i = 2; i <= n; i++) inv[i] = mul(mod - mod / i, inv[mod % i]);
	for (int i = 2; i <= n; i++) ifac[i] = mul(ifac[i - 1], inv[i]);
}

int calc(int s, int m) {
	return dec(binom(s + n - 1, n - 1), binom(s + m - 1, n - 1));
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		m += a[i], b[i] = a[i];
	}
	init_fac(n + m);
	ans = 1; // for zero operations
	for (int i = 1; i <= m; i++) {
		// for %i operations
		for (int i = 1; i <= n; i++) {
			--b[i];
			if (b[i] < 0) {
				++used, b[i] += n;
				if (!mrk[i]) ++cnt, mrk[i] = 1;
			}
		}
		if (used > i || cnt == n) break;
		ans = inc(ans, calc(i - used, cnt));
	}
	print(ans, '\n');
}

} signed main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}