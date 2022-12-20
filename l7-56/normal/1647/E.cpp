#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e5 + 10;
ll n,a[maxn],ind[maxn],f[maxn][31],c[maxn],mx,cnt,stp,b[maxn],vis[maxn];

struct SegTree {
	ll sum[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(ll rt) { sum[rt] = sum[ls] + sum[rs]; }
	void build(ll rt, ll l, ll r) {
		if (l == r) return sum[rt] = 1, void();
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void upd(ll rt, ll l, ll r, ll pos) {
		if (l == r) return sum[rt] = 0, void();
		pos <= mid ? upd(ls, l, mid, pos) : upd(rs, mid + 1, r, pos); push_up(rt);
	}
	ll query_sum(ll rt, ll l, ll r, ll L, ll R) {
		if (L > r || R < l) return 0;
		if (L <= l && r <= R) return sum[rt];
		return query_sum(ls, l, mid, L, R) + query_sum(rs, mid + 1, r, L, R);
	}
	ll query_pos(ll rt, ll l, ll r, ll val) {
		if (l == r) return l;
		if (sum[ls] >= val) return query_pos(ls, l, mid, val);
		return query_pos(rs, mid + 1, r, val - sum[ls]);
	}
	#undef ls
	#undef rs
	#undef mid
}T;

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &f[i][0]), ind[f[i][0]]++;
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]), mx = max(mx, a[i]), cnt += (ind[i] == 0);
	stp = (mx - n) / cnt;
	for (ll j = 1; j <= 30; ++j)
		for (ll i = 1; i <= n; ++i)
			f[i][j] = f[f[i][j - 1]][j - 1];
	T.build(1, 1, n);
	for (ll i = 1; i <= n; ++i) {
		c[i] = i;
		for (ll j = 30; j >= 0; --j)
			if (stp & (1ll << j)) c[i] = f[c[i]][j];
		if (vis[c[i]]) continue;
		vis[c[i]] = 1, b[i] = a[c[i]];
		T.upd(1, 1, n, b[i]);
	}
	for (ll i = 1; i <= n; ++i) {
		if (b[i]) continue;
		b[i] = T.query_pos(1, 1, n, T.query_sum(1, 1, n, 1, a[c[i]] - 1) + 1);
		T.upd(1, 1, n, b[i]);
	}
	for (ll i = 1; i <= n; ++i) printf("%lld%c", b[i], " \n"[i == n]);
	return 0;
}