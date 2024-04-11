#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2e5 + 10, mod = 998244353;
struct node {
	ll x,y;
}a[maxn];
ll n,m,k,q,fx[maxn],fy[maxn];
void work() {
	scanf("%lld%lld%lld%lld", &n, &m, &k, &q);
	for (ll i = 1; i <= q; ++i) scanf("%lld%lld", &a[i].x, &a[i].y);
	ll ans = 1, cntx = 0, cnty = 0;
	for (ll i = q; i >= 1; --i) {
		if ((!fx[a[i].x] && !fy[a[i].y]) || (!fx[a[i].x] && cnty != m) || (!fy[a[i].y] && cntx != n)) ans = ans * k % mod;
		cntx += !(fx[a[i].x]), cnty += !(fy[a[i].y]);
		fx[a[i].x] = 1, fy[a[i].y] = 1;
	}
	for (int i = 1; i <= q; ++i) fx[a[i].x] = fy[a[i].y] = 0;
	printf("%lld\n", ans);
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}