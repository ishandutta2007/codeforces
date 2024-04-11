#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pll;

const ll maxn = 60, maxm = 310;
ll n,m;
struct Edge {
	ll u,v,w;
}e[maxm],e1[maxm];
vector <ll> pos;
vector <pll> f;

ll fa[maxn];
ll get(ll x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }

void calc(ll i) {
	ll x = pos[i];
	for (ll i = 1; i <= n; ++i) fa[i] = i;
	for (ll i = 1; i <= m; ++i) e1[i] = e[i], e1[i].w -= x;
	sort(e1 + 1, e1 + m + 1, [] (Edge a, Edge b) {
		return abs(a.w) < abs(b.w) || (abs(a.w) == abs(b.w) && a.w > b.w);
	});
	pll res = make_pair(0, 0);
	for (ll i = 1; i <= m; ++i) {
		ll u = e1[i].u, v = e1[i].v, w = e1[i].w;
		u = get(u), v = get(v);
		if (u == v) continue;
		fa[u] = v;
		if (w <= 0) res.first++, res.second -= w + x;
		else res.first--, res.second += w + x;
	}
	f[i] = res;
}

ll query(ll x) {
	ll i = upper_bound(pos.begin(), pos.end(), x) - pos.begin() - 1;
	return f[i].first * x + f[i].second;
}

int main() {
	scanf("%lld%lld", &n, &m);
	pos.push_back(0); pos.push_back(100000001);
	for (ll i = 1; i <= m; ++i) {
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
		pos.push_back(e[i].w);
		for (ll j = 1; j < i; ++j)
			pos.push_back((e[i].w + e[j].w + 1) / 2);
	}
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	ll len = pos.size();
	f.resize(len + 10);
	for (ll i = 0; i < len; ++i) calc(i);

	ll p,k,a,b,c,q,ans = 0;
	scanf("%lld%lld%lld%lld%lld", &p, &k, &a, &b, &c);
	a %= c, b %= c;
	for (ll i = 1; i <= p; ++i) {
		scanf("%lld", &q);
		ans ^= query(q);
	}
	for (ll i = p + 1; i <= k; ++i)
		q = (q * a % c + b) % c, ans ^= query(q);
	printf("%lld\n", ans);
	return 0;
}