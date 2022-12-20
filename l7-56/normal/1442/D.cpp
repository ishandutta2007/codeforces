#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 3010;
ll n,m,dp[maxn],ans;
vector <ll> s[maxn];

void solve(ll l, ll r) {
	if (l == r) {
		for (ll j = 0; j < (int) s[l].size() && j <= m; ++j)
			ans = max(ans, dp[m - j] + s[l][j]);
		return;
	}
	ll mid = (l + r) >> 1;
	ll tmp[maxn];
	for (ll j = 0; j <= m; ++j) tmp[j] = dp[j];
	for (ll i = l; i <= mid; ++i) {
		ll v = s[i].size() - 1, w = s[i][v];
		for (ll j = m; j >= v; --j) dp[j] = max(dp[j], dp[j - v] + w);
	}
	solve(mid + 1, r);
	for (ll j = 0; j <= m; ++j) dp[j] = tmp[j];
	for (ll i = mid + 1; i <= r; ++i) {
		ll v = s[i].size() - 1, w = s[i][v];
		for (ll j = m; j >= v; --j) dp[j] = max(dp[j], dp[j - v] + w);
	}
	solve(l, mid);
	for (ll j = 0; j <= m; ++j) dp[j] = tmp[j];
}

int main() {
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; ++i) {
		ll t;
		scanf("%lld", &t);
		s[i].push_back(0);
		for (ll j = 1, x; j <= t; ++j)
			scanf("%lld", &x), s[i].push_back(s[i][j - 1] + x);
	}
	solve(1, n);
	printf("%lld\n", ans);
	return 0;
}