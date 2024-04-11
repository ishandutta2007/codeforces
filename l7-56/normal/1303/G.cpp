#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pll;

const ll maxn = 2e5 + 10;
ll n,a[maxn];
struct Edge {
	ll v,nxt;
}e[maxn << 1];
ll h[maxn],cnt_e;
void add(ll x, ll y) {
	e[++cnt_e] = {y, h[x]};
	h[x] = cnt_e;
}

ll siz[maxn];
bitset <maxn> vis;
pll getg(ll u, ll pre, ll tot) {
	siz[u] = 1;
	pll nw = {0, u}, nx = {n, 0};
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre || vis[v]) continue;
		nx = min(nx, getg(v, u, tot));
		siz[u] += siz[v];
		nw.first = max(nw.first, siz[v]);
	}
	nw.first = max(nw.first, tot - siz[u]);
	return min(nw, nx);
}

struct node {
	ll k,b;
	ll calc(ll x) { return k * x + b; }
}b[maxn];
ll cnt_line;
struct SegTree {
	ll tr[maxn << 2], clr[maxn << 2];
	void push_down(ll rt) {
		if (!clr[rt]) return;
		clr[rt << 1] = clr[rt << 1 | 1] = 1;
		tr[rt << 1] = tr[rt << 1 | 1] = 0;
		clr[rt] = 0;
	}
	void update(ll rt, ll l, ll r, ll u) {
		ll mid = (l + r) >> 1, &v = tr[rt];
		push_down(rt);
		if (b[u].calc(mid) > b[v].calc(mid)) swap(u, v);
		if (b[u].calc(l) > b[v].calc(l)) update(rt << 1, l, mid, u);
		if (b[u].calc(r) > b[v].calc(r)) update(rt << 1 | 1, mid + 1, r, u);
	}
	void add(ll _k, ll _b) {
		b[++cnt_line] = (node) {_k, _b};
		update(1, 1, n, cnt_line);
	}
	ll query(ll rt, ll l, ll r, ll pos) {
		if (l == r) return tr[rt];
		ll mid = (l + r) >> 1, u = tr[rt], v;
		push_down(rt);
		if (pos <= mid) v = query(rt << 1, l, mid, pos);
		else v = query(rt << 1 | 1, mid + 1, r, pos);
		return b[u].calc(pos) > b[v].calc(pos) ? u : v;
	}
	void clear() { clr[1] = 1, tr[1] = cnt_line = 0; }
}T;

ll ans;
void dfs1(ll u, ll pre, ll sum, ll res, ll len) {
	ll pos = T.query(1, 1, n, len);
	ans = max(ans, b[pos].calc(len) + res);
	siz[u] = 1;
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre || vis[v]) continue;
		dfs1(v, u, sum + a[v], res + sum + a[v], len + 1);
		siz[u] += siz[v];
	}
}

void dfs2(ll u, ll pre, ll sum, ll res, ll len) {
	T.add(sum, res);
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre || vis[v]) continue;
		dfs2(v, u, sum + a[v], res + (len + 1) * a[v], len + 1);
	}
}

void solve(ll u, ll tot) {
	u = getg(u, 0, tot).second;
	// printf("%lld\n", u);
	T.clear();
	T.add(a[u], a[u]);
	stack <ll> t;
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (vis[v]) continue;
		dfs1(v, u, a[v], a[v], 1);
		dfs2(v, u, a[u] + a[v], a[u] + a[v] * 2, 2);
		t.push(v);
	}
	T.clear();
	while (!t.empty()) {
		ll v = t.top(); t.pop();
		dfs1(v, u, a[v], a[v], 1);
		dfs2(v, u, a[u] + a[v], a[u] + a[v] * 2, 2);
	}
	ll pos = T.query(1, 1, n, 1);
	ans = max(ans, b[pos].calc(0));
	vis[u] = 1;
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (vis[v]) continue;
		solve(v, siz[v]);
	}
}

int main() {
	scanf("%lld", &n);
	for (ll i = 1, x, y; i < n; ++i) scanf("%lld%lld", &x, &y), add(x, y), add(y, x);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	solve(1, n);
	printf("%lld\n", ans);
	return 0;
}