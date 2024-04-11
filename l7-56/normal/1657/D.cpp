#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pii;

const ll maxn = 3e5 + 10;
ll n,m,C,ans[maxn];
map <ll, ll> mp;
pii b[maxn];

struct node {
	ll a,c,y,cost;
	bool operator < (const node &p) const { return cost > p.cost; }
};
priority_queue <node> pq;

int main() {
	scanf("%lld%lld", &n, &C);
	for (ll i = 1; i <= n; ++i) {
		ll c, d, h; scanf("%lld%lld%lld", &c, &d, &h);
		mp[c] = max(mp[c], d * h);
	}
	for (pii p : mp) pq.push((node){p.second, p.first, 0, 0});
	scanf("%lld", &m);
	for (ll i = 1; i <= m; ++i) {
		ll d, h; scanf("%lld%lld", &d, &h);
		b[i] = make_pair(d * h, i);
	}
	sort(b + 1, b + m + 1);
	for (ll i = 1; i <= m; ++i) {
		ll A = b[i].first;
		while (!pq.empty()) {
			node nw = pq.top();
			if (nw.y > A) break;
			pq.pop();
			ll x = A / nw.a + 1;
			if (x > C / nw.c) continue;
			nw.cost = x * nw.c;
			nw.y = x * nw.a;
			pq.push(nw);
		}
		if (pq.empty()) {
			while (i <= m) ans[b[i++].second] = -1;
			break;
		}
		ans[b[i].second] = pq.top().cost;
	}
	for (ll i = 1; i <= m; ++i) printf("%lld%c", ans[i], " \n"[i == m]);
	return 0;
}