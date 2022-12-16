#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 1e6 + 10, mod = 998244353;
ll qpow(ll a, int p) {
	ll ans = 1; a %= mod;
	while (p) {
		if (p & 1) ans = ans * a % mod;
		a = a * a % mod, p >>= 1;
	}
	return ans;
}
ll inv(ll x) { return qpow(x, mod - 2); }
int rk[maxn];
void calcrk(int n) {
	int lg = 0; for (int t = n; t >>= 1; ) lg++;
	for (int i = 0; i < n; ++i) rk[i] = ((rk[i >> 1] >> 1) | ((i & 1) << (lg - 1)));
}
void NTT(ll *f, int n, int flg) {
	for (int i = 0; i < n; ++i) if (i < rk[i]) swap(f[i], f[rk[i]]);
	for (int len = 2; len <= n; len <<= 1) {
		int hlf = len >> 1;
		ll w = qpow(3, (mod - 1) / len);
		for (int l = 0, r = len - 1; r < n; l += len, r += len) {
			ll wk = 1;
			for (int k = l; k < l + hlf; ++k) {
				ll fk = (f[k] + wk * f[k + hlf] % mod) % mod, fkk = (f[k] - wk * f[k + hlf] % mod + mod) % mod;
				f[k] = fk, f[k + hlf] = fkk, wk = wk * w % mod;
			}
		}
	}
	if (flg == -1) {
		reverse(f + 1, f + n);
		int in = inv(n);
		for (int i = 0; i < n; ++i) f[i] = f[i] * in % mod;
	}
}
ll f[maxn],g[maxn];

int n,s;
ll fact[maxn],invf[maxn],dp[maxn],ans[maxn];

void prework() {
	fact[0] = invf[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % mod, invf[i] = inv(fact[i]);
	int N = 1;
	while (N <= s + s - 2) N <<= 1;
	calcrk(N);
	for (int i = 0; i < s - 1; ++i) f[i] = fact[i], g[i] = invf[s - 2 - i];
	NTT(f, N, 1), NTT(g, N, 1);
	for (int i = 0; i < N; ++i) f[i] = f[i] * g[i] % mod;
	NTT(f, N, -1);
	dp[1] = fact[n - 1];
	for (int i = 2; i <= s; ++i) dp[i] = fact[n - i] * (i - 1) % mod * f[s + i - 4] % mod;
}

int main() {
	read(n);
	s = (n + 1) >> 1;
	prework();
	ll sum = 0;
	for (int i = s; i >= 1; --i) {
		ans[i] = (dp[i] - sum * inv(i) % mod + mod) % mod;
		sum = (sum + ans[i]) % mod;
	}
	for (int i = 1; i <= n; ++i)
		write(ans[i], " \n"[i == n]);
	return 0;
}