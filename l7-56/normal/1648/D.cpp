#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pii;

const ll maxn = 5e5 + 10, inf = 4e18;
ll n,q,a[4][maxn],s[4][maxn],f[maxn],g[maxn];
struct node {
	ll x, y, z;
	friend node operator + (node p, node q) { return {max(p.x, q.x), max(p.y, q.y), max(max(p.z, q.z), p.x + q.y)}; }
};
struct SegTree {
	node val[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(ll rt) { val[rt] = val[ls] + val[rs]; }
	void build(ll rt, ll l, ll r) {
		if (l == r) return val[rt] = {f[l], g[l], f[l] + g[l]}, void();
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void upd(ll rt, ll l, ll r, ll pos, ll v) {
		if (l == r) return val[rt].x = max(val[rt].x, v), val[rt].z = max(val[rt].z, val[rt].x + val[rt].y), void();
		pos <= mid ? upd(ls, l, mid, pos, v) : upd(rs, mid + 1, r, pos, v); push_up(rt);
	}
	node query(ll rt, ll l, ll r, ll L, ll R) {
		if (L <= l && r <= R) return val[rt];
		if (L > mid) return query(rs, mid + 1, r, L, R);
		if (R <= mid) return query(ls, l, mid, L, R);
		return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
	}
	#undef ls
	#undef rs
	#undef mid
}T;

vector <pii> t[maxn];

int main() {
	scanf("%lld%lld", &n, &q);
	for (ll i = 1; i <= 3; ++i)
		for (ll j = 1; j <= n; ++j)
			scanf("%lld", &a[i][j]), s[i][j] = s[i][j - 1] + a[i][j];
	for (ll i = 1; i <= q; ++i) {
		ll l, r, k; scanf("%lld%lld%lld", &l, &r, &k);
		t[r].push_back(make_pair(l, k));
	}
	for (ll i = 1; i <= n; ++i) f[i] = s[1][i] - s[2][i - 1], g[i] = s[2][i] - s[3][i - 1] + s[3][n];
	T.build(1, 1, n);
	ll ans = -inf;
	for (ll i = 1; i <= n; ++i) {
		for (pii p : t[i]) {
			ll l = p.first, k = p.second;
			node res = T.query(1, 1, n, l, i);
			ans = max(ans, res.z - k);
			if (i < n) T.upd(1, 1, n, i + 1, res.x - k);
		}
	}
	printf("%lld\n", ans);
	return 0;
}