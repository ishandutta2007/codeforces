#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e6 + 10;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll n,m,sum[21];
bitset <maxn * 21> vis;

int main() {
	scanf("%lld%lld", &n, &m);
	ll ans = 1;
	for (ll i = 1; i <= 20; ++i) {
		for (ll j = 1; j <= m; ++j) vis.set(i * j, 1);
		sum[i] = vis.count();
	}
	vis.reset();
	for (ll i = 2; i <= n; ++i) {
		if (vis[i]) continue;
		ll x = i, cnt = 0;
		while (x <= n) vis[x] = 1, x *= i, cnt++;
		ans += sum[cnt];
	}
	printf("%lld\n", ans);
	return 0;
}