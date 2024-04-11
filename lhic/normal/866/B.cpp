#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n;
const int MX = 120000;
ll s;

ll nd[MX];
ll a[MX];
ll b[MX];
vector<pair<ll, ll> > g[2];
ll bs = 0;
ll sum = 0;
vector<pair<ll, ll> > vv;


int main() {
	scanf("%d%lld", &n, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld%lld", nd + i, a + i, b + i);
		bs += min(a[i], b[i]) * nd[i];
		sum += nd[i];
		if (a[i] > b[i]) {
			g[0].push_back(make_pair(a[i] - b[i], nd[i]));
		}
		else {
			g[1].push_back(make_pair(b[i] - a[i], nd[i]));
		}
	}
	sort(g[0].rbegin(), g[0].rend());
	sort(g[1].rbegin(), g[1].rend());
	ll ndp = (sum + s - 1) / s;
	ll sh = 0;
	int i = 0;
	while (i < g[0].size()) {
		ll go = (g[0][i].second - sh) / s;
		if (go)
			vv.push_back(make_pair(g[0][i].first * s, go));
		sh += go * s;
		ll cur = (g[0][i].second - sh) * g[0][i].first;
		sh = s - (g[0][i].second - sh);
		++i;
		while (i < g[0].size() && g[0][i].second <= sh) {
			cur += g[0][i].second * g[0][i].first;
			sh -= g[0][i].second;
			++i;
		}
		if (i < g[0].size())
			cur += sh * g[0][i].first;
		vv.push_back(make_pair(cur, 1));
	}
	sh = 0;
	i = 0;
	while (i < g[1].size()) {
		ll go = (g[1][i].second - sh) / s;
		if (go)
			vv.push_back(make_pair(g[1][i].first * s, go));
		sh += go * s;
		ll cur = (g[1][i].second - sh) * g[1][i].first;
		sh = s - (g[1][i].second - sh);
		++i;
		while (i < g[1].size() && g[1][i].second <= sh) {
			cur += g[1][i].second * g[1][i].first;
			sh -= g[1][i].second;
			++i;
		}
		if (i < g[1].size())
			cur += sh * g[1][i].first;
		vv.push_back(make_pair(cur, 1));
	}
	sort(vv.rbegin(), vv.rend());
	ll ans = bs;
	for (int i = 0; i < vv.size(); ++i) {
		ll go = min(ndp, vv[i].second);
		ans += go * vv[i].first;
		ndp -= go;
	}
	cout << ans << "\n";
	return 0;
}