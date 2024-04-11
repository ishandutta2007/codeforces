#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll maxn = 110, maxm = 1e5 + 10;
ll n,m,q,a[maxn],b[maxm],ans;
struct SegTree {
	struct node {
		ll mx,sum,add;
	}tr[maxm << 2];
	#define mx(x) tr[x].mx
	#define sum(x) tr[x].sum
	#define add(x) tr[x].add
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	void push_up(ll rt) {
		sum(rt) = sum(ls) + sum(rs);
		mx(rt) = max(mx(ls), mx(rs));
	}
	void build(ll rt, ll l, ll r) {
		if (l == r) {
			mx(rt) = sum(rt) = b[l];
			return;
		}
		ll mid = (l + r) >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		push_up(rt);
	}
	void push_down(ll rt, ll l, ll r) {
		if (add(rt)) {
			ll mid = (l + r) >> 1;
			sum(ls) += add(rt) * (mid - l + 1);
			sum(rs) += add(rt) * (r - mid);
			mx(ls) += add(rt), mx(rs) += add(rt);
			add(ls) += add(rt), add(rs) += add(rt);
			add(rt) = 0;
		}
	}
	void add_seg(ll rt, ll l, ll r, ll L, ll R, ll val) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) {
			sum(rt) += (r - l + 1) * val;
			add(rt) += val, mx(rt) += val;
			return;
		}
		ll mid = (l + r) >> 1; push_down(rt, l, r);
		add_seg(ls, l, mid, L, R, val), add_seg(rs, mid + 1, r, L, R, val); push_up(rt);
	}
	ll query_pos(ll rt, ll l, ll r, ll val) {
		if (mx(rt) < val) return r + 1;
		if (l == r) return l;
		ll mid = (l + r) >> 1; push_down(rt, l, r);
		if (mx(ls) >= val) return query_pos(ls, l, mid, val);
		else return query_pos(rs, mid + 1, r, val);
	}
	ll query_sum(ll rt, ll l, ll r, ll L, ll R) {
		if (L > r || R < l) return 0;
		if (L <= l && r <= R) return sum(rt);
		ll mid = (l + r) >> 1; push_down(rt, l, r);
		return query_sum(ls, l, mid, L, R) + query_sum(rs, mid + 1, r, L, R);
	}
	#undef mx
	#undef sum
	#undef add
	#undef ls
	#undef rs
}B;

ll query() {
	ll ret = ans;
	for (ll i = 2; i <= n; ++i) {
		ll pos = B.query_pos(1, 2, m, a[i]);
		ret += B.query_sum(1, 2, m, 2, pos - 1) + a[i] * (n + m - pos - i + 2);
	}
	return ret;
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &q);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (ll i = 1; i <= m; ++i) scanf("%lld", &b[i]);
	ans = (a[1] + b[1]) * (n + m - 1);
	for (ll i = n; i >= 2; --i) a[i] -= a[i - 1];
	for (ll i = m; i >= 2; --i) b[i] -= b[i - 1], ans += (m - i + 1) * b[i];
	B.build(1, 2, m);
	while (q--) {
		ll op, d, k;
		scanf("%lld%lld%lld", &op, &k, &d);
		if (op == 1) {
			if (k == n) ans += d * (n + m - 1), --k;
			for (ll i = n; i >= n - k + 1; --i) a[i] += d;
		}
		else {
			if (k == m) ans += d * (n + m - 1), --k;
			B.add_seg(1, 2, m, m - k + 1, m, d);
			ans += k * (k + 1) / 2 * d;
		}
		printf("%lld\n", query());
	}
	return 0;
}