#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pll;

const ll maxn = 1e5 + 10, inf = 4e18;
ll n,a[maxn],m;
struct node {
	ll t, p, id;
};
vector <node> b[maxn];
ll f[110], pre[maxn][110];

void work() {
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]), b[i].clear();
	for (ll i = 1; i <= m; ++i) {
		ll e, t, p; scanf("%lld%lld%lld", &e, &t, &p);
		b[e].push_back((node) {t, p, i});
	}
	vector <ll> ans;
	for (ll i = 1, tim = 0; i <= n; ++i) {
		for (ll i = 1; i <= 100; ++i) f[i] = inf;
		ll idx = 0;
		for (node x : b[i]) {
			++idx;
			for (ll j = 0; j <= 100; ++j) pre[idx][j] = j;
			for (ll j = 100; j >= 0; --j)
				if (f[min(j + x.p, 100ll)] > f[j] + x.t) {
					f[min(j + x.p, 100ll)] = f[j] + x.t;
					pre[idx][min(j + x.p, 100ll)] = j;
				}
		}
		if (tim + f[100] > a[i]) return printf("-1\n"), void();
		for (ll nw = 100; idx >= 0; nw = pre[idx--][nw])
			if (pre[idx][nw] < nw) ans.push_back(b[i][idx - 1].id);
		tim += f[100];
	}
	printf("%lld\n", (ll) ans.size());
	for (ll x : ans) printf("%lld ", x);
	printf("\n");
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}