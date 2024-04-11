#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2e5 + 10, mod = 998244353;
ll qpow(ll a, ll p) {
	ll ans = 1; a %= mod;
	while (p) {
		if (p & 1) ans = ans * a % mod;
		a = a * a % mod, p >>= 1;
	}
	return ans;
}
ll inv(ll x) { return qpow(x, mod - 2); }
ll v[maxn],p[maxn],cntp;
struct Edge {
	ll v,x,y;
};
vector <Edge> e[maxn];
ll n,r[maxn],ans,cnt[maxn],lcnt[maxn];
void dfs(ll u, ll pre) {
	ans = (ans + r[u]) % mod;
	for (Edge o : e[u]) {
		ll nx = o.v, x = o.x, y = o.y;
		if (nx == pre) continue;
		r[nx] = r[u] * y % mod * inv(x) % mod;
		for (ll t = x; t > 1; ) cnt[v[t]]++, t /= v[t];
		for (ll t = y; t > 1; ) cnt[v[t]]--, t /= v[t];
		for (ll t = x; t > 1; ) lcnt[v[t]] = max(lcnt[v[t]], cnt[v[t]]), t /= v[t];
		dfs(nx, u);
		for (ll t = x; t > 1; ) cnt[v[t]]--, t /= v[t];
		for (ll t = y; t > 1; ) cnt[v[t]]++, t /= v[t];
	}
}
void work() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) e[i].clear(), cnt[i] = lcnt[i] = 0;
	for (ll i = 1; i < n; ++i) {
		ll a, b, x, y; scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
		e[a].push_back((Edge) {b, x, y});
		e[b].push_back((Edge) {a, y, x});
	}
	ans = 0, r[1] = 1, dfs(1, 0);
	for (ll i = 1; i <= n; ++i) if (lcnt[i]) ans = ans * qpow(i, lcnt[i]) % mod;
	printf("%lld\n", ans);
}

int main() {
	v[1] = 1;
	for (ll i = 2; i <= 200000; ++i) {
		if (!v[i]) v[i] = i, p[++cntp] = i;
		for (ll j = 1; j <= cntp; ++j) {
			if (i * p[j] > 200000 || p[j] > v[i]) continue;
			v[i * p[j]] = p[j];
		}
	}
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}