#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 1e5 + 10, inf = 3e18;
ll n,m,k,x[maxn],f[maxn];
struct Ladder {
	ll sx,sy,ex,ey,h;
}a[maxn];
struct node {
	ll x,id;
	friend bool operator < (node a, node b) { return a.x < b.x; }
};
vector <ll> q[maxn],o[maxn];
void work() {
	scanf("%lld%lld%lld", &n, &m, &k);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &x[i]), q[i].clear(), o[i].clear();
	for (ll i = 1; i <= k; ++i)
		scanf("%lld%lld%lld%lld%lld", &a[i].sx, &a[i].sy, &a[i].ex, &a[i].ey, &a[i].h),
		q[a[i].sx].push_back(i), o[a[i].ex].push_back(i), f[i] = inf;
	o[1].push_back(0);
	a[0].sx = 0, a[0].ey = 1;
	q[n].push_back(k + 1);
	a[k + 1].h = 0, a[k + 1].sx = n, a[k + 1].sy = m, f[k + 1] = inf;
	for (ll i = 1; i <= n; ++i) {
		vector <node> v;
		for (ll p : q[i]) v.push_back({a[p].sy, p});
		for (ll p : o[i]) v.push_back({a[p].ey, p});
		sort(v.begin(), v.end());
		ll mn = inf;
		for (node p : v) {
			ll g = p.id;
			if (a[g].sx == i) f[g] = min(f[g], mn + x[i] * a[g].sy - a[g].h);
			else mn = min(mn, f[g] - x[i] * a[g].ey);
		}
		reverse(v.begin(), v.end());
		mn = inf;
		for (node p : v) {
			ll g = p.id;
			if (a[g].sx == i) f[g] = min(f[g], mn - x[i] * a[g].sy - a[g].h);
			else mn = min(mn, f[g] + x[i] * a[g].ey);
		}
	}
	if (f[k + 1] < 1e18) printf("%lld\n", f[k + 1]);
	else printf("NO ESCAPE\n");
}

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) work();
	return 0;
}