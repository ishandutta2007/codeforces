#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2010, mod = 1e9 + 7;
ll n,m,cnt;
char mp[maxn][maxn];
ll qpow(ll a, ll p) {
	ll ans = 1; a %= mod;
	while (p) {
		if (p & 1) ans = ans * a % mod;
		a = a * a % mod, p >>= 1;
	}
	return ans;
}

void work() {
	scanf("%lld%lld", &n, &m);
	cnt = 0;
	for (ll i = 1; i <= n; ++i) {
		scanf("%s", mp[i] + 1);
		for (ll j = 1; j <= m; ++j)
			cnt += (mp[i][j] == '#');
	}
	printf("%lld\n", (qpow(2, cnt) - (cnt == n * m) + mod) % mod);
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}