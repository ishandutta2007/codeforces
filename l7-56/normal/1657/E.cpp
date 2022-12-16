#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 300, mod = 998244353;
ll qpow(ll a, ll p) {
	ll ans = 1; a %= mod;
	while (p) {
		if (p & 1) ans = ans * a % mod;
		a = a * a % mod, p >>= 1;
	}
	return ans;
}
ll n,k,f[maxn][maxn],c[maxn][maxn];

int main() {
	scanf("%lld%lld", &n, &k);
	c[0][0] = 1;
	for (ll i = 1; i <= n; ++i)
		for (ll j = 0; j <= i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	f[0][0] = 1;
	for (ll j = 1; j <= k; ++j)
		for (ll i = 0; i < n; ++i)
			for (ll x = 0; x <= i; ++x)
				f[i][j] = (f[i][j] + f[i - x][j - 1] * c[i][x] % mod * qpow(k - j + 1, x * (x - 1) / 2 + x * (i - x)) % mod) % mod;
	printf("%lld\n", f[n - 1][k]);
	return 0;
}