#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e6 + 10, inf = 9e18;
ll n,q,x[maxn],w[maxn],s[maxn],ans[maxn],tp;
struct node {
	ll l, r, val, id;
}a[maxn];
ll tot;

struct BIT {
	ll c[maxn];
	BIT() { memset(c, 0x7f, sizeof c); }
	void upd(ll pos, ll val) { for (; pos <= n; pos += pos & (-pos)) c[pos] = min(c[pos], val); }
	ll ask(ll pos) {
		ll res = inf;
		for (; pos > 0; pos &= pos - 1) res = min(res, c[pos]);
		return res;
	}
}T;

int main() {
	scanf("%lld%lld", &n, &q);
	for (ll i = 1; i <= n; ++i) {
		scanf("%lld%lld", &x[i], &w[i]);
		while (tp && w[s[tp]] > w[i]) --tp;
		if (tp) a[++tot] = {s[tp], i, (x[i] - x[s[tp]]) * (w[s[tp]] + w[i]), 0};
		s[++tp] = i;
	}
	tp = 0;
	for (ll i = n; i >= 1; --i) {
		while (tp && w[s[tp]] > w[i]) --tp;
		if (tp) a[++tot] = {i, s[tp], (x[s[tp]] - x[i]) * (w[s[tp]] + w[i]), 0};
		s[++tp] = i;
	}
	for (ll i = 1; i <= q; ++i) {
		a[++tot].id = i;
		scanf("%lld%lld", &a[tot].l, &a[tot].r);
	}
	sort(a + 1, a + tot + 1, [] (node p, node q) {
		if (p.l != q.l) return p.l > q.l;
		if (p.r != q.r) return p.r < q.r;
		return p.id < q.id;
	});
	for (ll i = 1; i <= tot; ++i) {
		if (a[i].id) ans[a[i].id] = T.ask(a[i].r);
		else T.upd(a[i].r, a[i].val);
	}
	for (ll i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
	return 0;
}