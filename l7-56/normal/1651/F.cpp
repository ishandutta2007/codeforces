#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef tuple <ll, ll, ll> plll;

const ll maxn = 2e5 + 10, K = 100, inf = 1e9;
ll n,C[maxn],R[maxn];
struct SegTree {
	ll sum[600000];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(ll rt) { sum[rt] = sum[ls] + sum[rs]; }
	void build(ll rt, ll l, ll r, ll tim) {
		if (l == r) return sum[rt] = min(C[l], R[l] * tim), void();
		build(ls, l, mid, tim), build(rs, mid + 1, r, tim), push_up(rt);
	}
	ll query_sum(ll rt, ll l, ll r, ll L, ll R) {
		if (L > r || R < l) return 0;
		if (L <= l && r <= R) return sum[rt];
		return query_sum(ls, l, mid, L, R) + query_sum(rs, mid + 1, r, L, R);
	}
	ll query_pos(ll rt, ll l, ll r, ll L, ll R, ll val) {
		if (L > r || R < l) return -1;
		if (l == r) return sum[rt] >= val ? l : -1;
		if (sum[ls] >= val) {
			ll res = query_pos(ls, l, mid, L, R, val);
			if (res != -1) return res;
		}
		return query_pos(rs, mid + 1, r, L, R, val - sum[ls]);
	}
	#undef ls
	#undef rs
	#undef mid
}T[K];

set <plll> events;

int main() {
	// printf("%lld\n", (sizeof T) / 1024 / 1024);
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld%lld", &C[i], &R[i]);
	for (ll t = 0; t < K; ++t) T[t].build(1, 1, n, t);
	for (ll i = 1; i <= n; ++i) events.insert(make_tuple(i, -inf, C[i]));
	ll q, ans = 0; scanf("%lld", &q);
	while (q--) {
		ll t, h, nw = 1; scanf("%lld%lld", &t, &h);
		bool alive = 1;
		while (!events.empty()) {
			ll x, dlt, rst; tie(x, dlt, rst) = *events.begin();
			dlt = t - dlt;
			if (nw < x) {
				if (dlt >= K) {
					for (ll i = nw; i < x; ++i) {
						ll val = min(R[i] * dlt, C[i]);
						if (val >= h) {
							events.insert(make_tuple(i, t, val - h));
							h = alive = 0; break;
						}
						h -= val;
					}
					if (!h) break;
				}
				else {
					ll pos = T[dlt].query_pos(1, 1, n, nw, x - 1, h + T[dlt].query_sum(1, 1, n, 1, nw - 1));
					if (pos == -1) h -= T[dlt].query_sum(1, 1, n, nw, x - 1);
					else {
						h -= T[dlt].query_sum(1, 1, n, nw, pos - 1);
						events.insert(make_tuple(pos, t, min(C[pos], R[pos] * dlt) - h));
						h = alive = 0; break;
					}
				}
			}
			ll val = min(C[x], R[x] * dlt + rst);
			events.erase(events.begin());
			if (val >= h) {
				events.insert(make_tuple(x, t, val - h));
				h = alive = 0; break;
			}
			h -= val, nw = x + 1;
		}
		ans += h;
		// printf("%lld\n", h);
		if (alive) events.insert(make_tuple(n, t, 0));
	}
	printf("%lld\n", ans);
	return 0;
}