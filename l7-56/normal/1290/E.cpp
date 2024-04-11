#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll maxn = 2e5 + 10, inf = 3e18;
struct SegTree {
	struct node {
		ll sum,mx,smx,cnt,scnt,add,sadd;
	}tr[maxn << 2];
	#define sum(x) tr[x].sum
	#define mx(x) tr[x].mx
	#define smx(x) tr[x].smx
	#define cnt(x) tr[x].cnt
	#define scnt(x) tr[x].scnt
	#define add(x) tr[x].add
	#define sadd(x) tr[x].sadd
	void init(ll rt) {
		sum(rt) = cnt(rt) = scnt(rt) = add(rt) = sadd(rt) = mx(rt) = smx(rt) = 0;
	}
	void push_up(ll rt) {
		ll ls = rt << 1, rs = rt << 1 | 1;
		sum(rt) = sum(ls) + sum(rs);
		if (mx(ls) > mx(rs)) {
			mx(rt) = mx(ls), cnt(rt) = cnt(ls);
			smx(rt) = max(smx(ls), mx(rs)), scnt(rt) = scnt(ls) + cnt(rs) + scnt(rs);
		}
		else if (mx(ls) < mx(rs)) {
			mx(rt) = mx(rs), cnt(rt) = cnt(rs);
			smx(rt) = max(mx(ls), smx(rs)), scnt(rt) = cnt(ls) + scnt(ls) + scnt(rs);
		}
		else {
			mx(rt) = mx(ls), cnt(rt) = cnt(ls) + cnt(rs);
			smx(rt) = max(smx(ls), smx(rs)), scnt(rt) = scnt(ls) + scnt(rs);
		}
	}
	void build(ll rt, ll l, ll r) {
		if (l == r) return init(rt);
		ll mid = (l + r) >> 1;
		build(rt << 1, l, mid);
		build(rt << 1 | 1, mid + 1, r);
		push_up(rt);
	}
	void tag(ll rt, ll val1, ll val2, ll Mx) {
		// printf("TAG(%lld %lld %lld %d)\n", rt, val1, val2, flag);
		if (Mx > mx(rt)) val1 = val2;
		mx(rt) += val1, smx(rt) += val2;
		sum(rt) += val1 * cnt(rt) + val2 * scnt(rt);
		add(rt) += val1, sadd(rt) += val2;
		// printf("%lld\n", sum(rt));
	}
	void push_down(ll rt) {
		ll ls = rt << 1, rs = rt << 1 | 1, Mx = max(mx(ls), mx(rs));
		tag(ls, add(rt), sadd(rt), Mx);
		tag(rs, add(rt), sadd(rt), Mx);
		add(rt) = sadd(rt) = 0;
	}
	void update(ll rt, ll l, ll r, ll pos, ll val) {
		if (l == r) {
			cnt(rt) = 1;
			mx(rt) = sum(rt) = val;
			return;
		}
		push_down(rt);
		ll mid = (l + r) >> 1;
		if (pos <= mid) update(rt << 1, l, mid, pos, val);
		else update(rt << 1 | 1, mid + 1, r, pos, val);
		push_up(rt);
		// printf("UPD(%lld %lld %lld %lld %lld) %lld\n", rt, l, r, pos, val, sum(rt));
	}
	void add_seg(ll rt, ll l, ll r, ll L, ll R) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt, 1, 1, mx(rt));
		push_down(rt);
		ll mid = (l + r) >> 1;
		add_seg(rt << 1, l, mid, L, R);
		add_seg(rt << 1 | 1, mid + 1, r, L, R);
		push_up(rt);
		// printf("ADD(%lld %lld %lld %lld %lld %lld) %lld\n", rt, l, r, L, R, val, sum(rt));
	}
	void seg_min(ll rt, ll l, ll r, ll L, ll R, ll val) {
		if (L > r || R < l || mx(rt) <= val) return;
		if (L <= l && r <= R && smx(rt) < val) return tag(rt, val - mx(rt), 0, mx(rt));
		push_down(rt);
		ll mid = (l + r) >> 1;
		seg_min(rt << 1, l, mid, L, R, val);
		seg_min(rt << 1 | 1, mid + 1, r, L, R, val);
		push_up(rt);
		// printf("MIN(%lld %lld %lld %lld %lld %lld) %lld\n", rt, l, r, L, R, val, sum(rt));
	}
	ll query_sum() { return sum(1); }
	ll query_cnt(ll rt, ll l, ll r, ll L, ll R) {
		if (L > r || R < l) return 0;
		if (L <= l && r <= R) return cnt(rt) + scnt(rt);
		push_down(rt);
		ll mid = (l + r) >> 1, res = query_cnt(rt << 1, l, mid, L, R) + query_cnt(rt << 1 | 1, mid + 1, r, L, R);
		return res;
	}
	#undef sum
	#undef mx
	#undef smx
	#undef cnt
	#undef scnt
	#undef add
	#undef sadd
}L,R;
ll n,a[maxn],pos[maxn],ans[maxn];

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]), pos[a[i]] = i;
	R.build(1, 1, n);
	for (ll i = 1; i <= n; ++i) {
		R.update(1, 1, n, pos[i], i + 1);
		R.seg_min(1, 1, n, 1, pos[i] - 1, R.query_cnt(1, 1, n, 1, pos[i]));
		R.add_seg(1, 1, n, pos[i] + 1, n);
		ans[i] += R.query_sum();
	}
	for (ll i = 1; i <= n; ++i) pos[i] = n - pos[i] + 1;
	L.build(1, 1, n);
	for (ll i = 1; i <= n; ++i) {
		L.update(1, 1, n, pos[i], i + 1);
		L.seg_min(1, 1, n, 1, pos[i] - 1, L.query_cnt(1, 1, n, 1, pos[i]));
		L.add_seg(1, 1, n, pos[i] + 1, n);
		ans[i] += L.query_sum() - i * (i + 2);
	}
	for (ll i = 1; i <= n; ++i) printf("%lld\n", ans[i]);
	return 0;
}