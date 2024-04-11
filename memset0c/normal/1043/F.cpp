// =================================
//   author: memset0
//   date: 2019.01.27 11:20:11
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

const int N = 3e5 + 10, mod = 998244353;
int n, a[N], cnt[N], f[N], inv[N], fac[N];

inline void decd(int &a, int b) { a -= b; if (a < 0) a += mod; }
inline void sumd(int &a, int b) { a += b; if (a >= mod) a -= mod; }
inline int C(int n, int m) { return n < m ? 0 : (ll)fac[n] * inv[m] % mod * inv[n - m] % mod; }

void main() {
	read(n), fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= n; i++) read(a[i]), ++cnt[a[i]];
	for (int i = 2; i < N; i++) fac[i] = (ll)fac[i - 1] * i % mod;
	for (int i = 2; i < N; i++) inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i < N; i++) inv[i] = (ll)inv[i - 1] * inv[i] % mod;
	for (int i = 1; i < N; i++)
		for (int j = i << 1; j < N; j += i)
			sumd(cnt[i], cnt[j]);
	// for (int i = 1; i < N; i++) print(cnt[i], " \n"[i == max]);
	for (int ans = 1; ans <= 7; ans++) {
		for (int i = N - 1; i >= 1; i--) {
			f[i] = C(cnt[i], ans);
			for (int j = i << 1; j < N; j += i)
				decd(f[i], f[j]);
		}
		// for (int i = 1; i < N; i++) print(f[i], " \n"[i == max]);
		if (f[1]) return print(ans, '\n');
	} puts("-1");
}

} signed main() { return ringo::main(), 0; }