#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 1e6 + 10, mod = 1e9 + 7, inv2 = 500000004;
ll qpow(ll a, ll p) {
	a %= mod;
	ll ans = 1;
	while (p) {
		if (p & 1) ans = ans * a % mod;
		a = a * a % mod, p >>= 1;
	}
	return ans;
}
ll fact[maxn],inv[maxn];
ll c(ll n, ll m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return fact[n] * inv[m] % mod * inv[n - m] % mod;
}

void work() {
	ll n,m,k;
	scanf("%lld%lld%lld", &n, &m, &k);
	if (m == 0) return printf("0\n"), void();
	if (n == m) return printf("%lld\n", k * n % mod), void();
	ll ans = 0;
	for (ll i = 1; i <= n; ++i)
		ans = (ans + k * i % mod * c(n - i - 1, m - i) % mod * qpow(inv2, n - i) % mod) % mod;
	printf("%lld\n", ans);
}

int main() {
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= 1000000; ++i)
		fact[i] = fact[i - 1] * i % mod, inv[i] = qpow(fact[i], mod - 2);
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}