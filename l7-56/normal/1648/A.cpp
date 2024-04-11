#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e5 + 10;
ll n,m;
struct node {
	ll x, y;
};
vector <node> a[maxn];

struct BIT {
	ll c[maxn];
	void add(ll pos, ll val) { for (; pos <= 100000; pos += pos & (-pos)) c[pos] += val; }
	ll ask(ll pos) {
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += c[pos];
		return res;
	}
	ll ask(ll l, ll r) {
		if (l > r) return 0;
		return ask(r) - ask(l - 1);
	}
	void clr(ll pos) { for (; pos <= 100000; pos += pos & (-pos)) c[pos] = 0; }
}T1,T2;

ll ans;
void solve(ll c) {
	if ((ll) a[c].size() <= 1) return;
	sort(a[c].begin(), a[c].end(), [] (node p, node q) { return p.x < q.x; });
	ll tot = a[c].size();
	for (ll i = 1, sumx = 0; i <= tot; ++i) {
		node nw = a[c][i - 1];
		ans += nw.x * (i - 1) - sumx;
		ans += T1.ask(1, nw.y) * nw.y - T2.ask(1, nw.y);
		ans += T2.ask(nw.y + 1, 100000) - T1.ask(nw.y + 1, 100000) * nw.y;
		sumx += nw.x;
		T1.add(nw.y, 1);
		T2.add(nw.y, nw.y);
	}
	for (node p : a[c]) T1.clr(p.y), T2.clr(p.y);
}

int main() {
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; ++i)
		for (ll j = 1; j <= m; ++j) {
			ll x; scanf("%lld", &x);
			a[x].push_back((node) {i, j});
		}
	for (ll i = 1; i <= 100000; ++i) solve(i);
	printf("%lld\n", ans);
	return 0;
}