// =================================
//   author: memset0
//   date: 2019.02.09 21:25:29
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
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

const int N = 1e6 + 10, mod = 1e9 + 7;
int n, m, ans, f[N], prev[N], next[N], inv_fac[N];

inline int fpow(int a, int b) { int s = 1; for (; b; b >>= 1, a = (ll)a * a % mod) if (b & 1) s = (ll)s * a % mod; return s; }

void main() {
	read(n), read(m), inv_fac[0] = inv_fac[1] = prev[0] = next[m + 3] = 1;
	for (int i = 1; i <= m + 2; i++) f[i] = (f[i - 1] + fpow(i, m)) % mod;
	for (int i = 1; i <= m + 2; i++) prev[i] = (ll)prev[i - 1] * (n - i) % mod;
	for (int i = m + 2; i >= 1; i--) next[i] = (ll)next[i + 1] * (n - i) % mod;
	for (int i = 2; i <= m + 2; i++) inv_fac[i] = (ll)(mod - mod / i) * inv_fac[mod % i] % mod;
	for (int i = 2; i <= m + 2; i++) inv_fac[i] = (ll)inv_fac[i - 1] * inv_fac[i] % mod;
	for (int i = 1; i <= m + 2; i++) ans = (ans + (ll)f[i] * prev[i - 1] % mod * next[i + 1] % mod * inv_fac[i - 1] % mod * inv_fac[m + 2 - i] % mod * ((m - i) & 1 ? -1 : 1)) % mod;
	// for (int i = 1; i <= m + 2; i++) print((ll)f[i] * prev[i - 1] % mod * next[i + 1] % mod * inv_fac[i - 1] % mod * inv_fac[m + 2 - i] % mod * ((m - i) & 1 ? 1 : -1), '\n');
	// for (int i = 1; i <= m + 2; i++) print(f[i], " \n"[i == m + 2]);
	// for (int i = 1; i <= m + 2; i++) print(prev[i], " \n"[i == m + 2]);
	// for (int i = 1; i <= m + 2; i++) print(next[i], " \n"[i == m + 2]);
	// for (int i = 1; i <= m + 2; i++) print(inv_fac[i], " \n"[i == m + 2]);
	print((ans + mod) % mod, '\n');
}

} signed main() { return ringo::main(), 0; }