#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e6 + 10, mod = 1e9 + 7;
ll qpow(ll a, ll p) {
	ll ans = 1; a %= mod;
	while (p) {
		if (p & 1) ans = ans * a % mod;
		a = a * a % mod, p >>= 1;
	}
	return ans;
}
ll n,fact[maxn],inv[maxn],ans;
ll c(ll n, ll m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return fact[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
	scanf("%lld", &n);
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % mod, inv[i] = qpow(fact[i], mod - 2);
	for (ll i = 0; i <= n; ++i)
	 	if ((n - i) % 2 == 0) ans = (ans + 2 * fact[n - i] % mod * (c(n - i - 1, i - 1) + c(n - i, i)) % mod) % mod;
	printf("%lld\n", ans);
	return 0;
}