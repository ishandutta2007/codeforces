#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e5 + 10, mod = 998244353;
ll updiv(ll p, ll q) { return p / q + (p % q > 0); }
ll n,a[maxn],f[2][maxn];
vector <ll> v[2];
void work() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	ll ans = 0;
	for (ll i = n; i >= 1; --i) {
		ll p = i & 1, q = p ^ 1;
		v[p].push_back(a[i]);
		f[p][a[i]] = 1;
		for (ll x : v[q]) {
			(ans += (updiv(a[i], x) - 1) * f[q][x] % mod * i % mod) %= mod;
			(f[p][a[i] / updiv(a[i], x)] += f[q][x]) %= mod, f[q][x] = 0;
			if (a[i] / updiv(a[i], x) != v[p].back()) v[p].push_back(a[i] / updiv(a[i], x));
		}
		v[q].clear();
	}
	printf("%lld\n", ans);
	for (ll x : v[0]) f[0][x] = 0;
	for (ll x : v[1]) f[1][x] = 0;
	v[0].clear(), v[1].clear();
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}