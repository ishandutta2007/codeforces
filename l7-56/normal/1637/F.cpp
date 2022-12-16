#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2e5 + 10;
ll n,a[maxn];
struct Edge {
	ll v,nxt;
}e[maxn << 1];
ll h[maxn],cnt_e;
void add(ll x, ll y) { e[++cnt_e] = {y, h[x]}; h[x] = cnt_e; }

ll ans = 0;
ll dfs(ll u, ll pre) {
	ll mx = 0, smx = 0;
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre) continue;
		ll val = dfs(v, u);
		if (val > mx) smx = mx, mx = val;
		else if (val > smx) smx = val;
	}
	if (pre == 0) ans += a[u] * 2 - mx - smx;
	else ans += max(a[u] - mx, 0ll);
	return max(a[u], mx);
}

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (ll i = 1; i < n; ++i) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		add(u, v), add(v, u);
	}
	ll mxi = 1;
	for (ll i = 2; i <= n; ++i)
		if (a[mxi] < a[i]) mxi = i;
	dfs(mxi, 0);
	printf("%lld\n", ans);
	return 0;
}