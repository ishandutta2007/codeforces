#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 2e5 + 10;
ll n,q,a[maxn],b[maxn],mu[maxn],c[maxn],ans[maxn];
struct Query {
	ll id, x;
	bool operator < (const Query &p) const { return x < p.x; }
}qu[maxn];

ll sum0,sumc,idx;
pair <ll, ll> cx[maxn];
void prework() {
	mu[1] = 1;
	for(ll i = 1; i <= n; ++i) {
		c[i] += b[i] - a[i];
		if(mu[i] == 0) sum0 += abs(c[i]);
		else cx[++idx].first = -c[i] / mu[i], cx[idx].second = mu[i] * c[i];
		for(ll j = 2; j * i <= n; ++j)
			mu[j * i] -= mu[i],
			c[j * i] -= c[i];
	}
	sort(cx + 1, cx + idx + 1);
	for(ll i = 1; i <= idx; ++i) sumc += cx[i].second;
}

int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(ll i = 1; i <= n; ++i) scanf("%lld", &b[i]);
	scanf("%lld", &q);
	for(ll i = 1; i <= q; ++i)
		scanf("%lld", &qu[i].x), qu[i].id = i;
	sort(qu + 1, qu + q + 1);
	prework();
	for(ll i = 1, p = 1, sum = 0, cnt = 0; i <= q; ++i) {
		ll x = qu[i].x + 1;
		while(p <= idx && x >= cx[p].first) sum += cx[p++].second, cnt++;
		ans[qu[i].id] = sum + cnt * x - ((sumc - sum) + (idx - cnt) * x) + sum0;
	}
	for(ll i = 1; i <= q; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}