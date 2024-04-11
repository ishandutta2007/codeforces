#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 1e5 + 10;
ll n,col[maxn];
struct Edge {
	ll v,nxt;
}e[maxn << 1];
ll h[maxn],cnt_e;
void add_e(ll x, ll y) {
	e[++cnt_e] = {y, h[x]};
	h[x] = cnt_e;
}

struct LA {
	ll l[maxn],r[maxn],sum[maxn];
	void init() {
		l[r[0] = 100001] = 0;
		sum[0] = sum[100001] = 0;
	}
	void del(ll pos) { l[r[pos]] = l[pos], r[l[pos]] = r[pos]; }
	void ins(ll pos, ll id, ll val) { l[r[pos]] = id, r[id] = r[pos], r[pos] = id, l[id] = pos, sum[id] = val; }
	void movr(ll pos, ll val) {
		if (r[pos] == pos + 1) sum[r[pos]] += val;
		else ins(pos, pos + 1, val);
		if (pos) {
			sum[pos] -= val;
			if (sum[pos] <= 0) del(pos);
		}
	}
	void movl(ll pos, ll val) {
		sum[pos] -= val;
		if (pos > 1) {
			if (l[pos] == pos - 1) sum[l[pos]] += val;
			else ins(l[pos], pos - 1, val);
		}
		if (sum[pos] <= 0) del(pos);
	}
	ll ask() { return sum[l[100001]]; }
}cc;

ll cnt[maxn];
void add(ll c) { cc.movr(cnt[c]++, c); }
void del(ll c) { cc.movl(cnt[c]--, c); }

ll st[maxn],ed[maxn],idx,id[maxn],siz[maxn],son[maxn];
void dfs1(ll u, ll pre) {
	siz[u] = 1;
	st[u] = ++idx;
	id[idx] = u;
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
	}
	ed[u] = idx;
}

ll ans[maxn];
void dfs2(ll u, ll pre, bool clr) {
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre || v == son[u]) continue;
		dfs2(v, u, 1);
	}
	if (son[u]) dfs2(son[u], u, 0);
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre || v == son[u]) continue;
		for (ll x = st[v]; x <= ed[v]; ++x) add(col[id[x]]);
	}
	add(col[u]);
	ans[u] = cc.ask();
	if (clr) { for (ll x = st[u]; x <= ed[u]; ++x) del(col[id[x]]); }
}

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &col[i]);
	for (ll i = 1; i < n; ++i) {
		ll x,y;
		scanf("%lld%lld", &x, &y);
		add_e(x, y), add_e(y, x);
	}
	dfs1(1, 0);
	cc.init();
	dfs2(1, 0, 1);
	for (ll i = 1; i <= n; ++i) printf("%lld%c", ans[i], " \n"[i == n]);
	return 0;
}