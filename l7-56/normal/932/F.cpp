#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll maxn = 1e6 + 10;
const ld inf = LLONG_MAX;
ll n,a[maxn],b[maxn],f[maxn],vis[maxn];
struct Edge {
	ll v,nxt;
}e[maxn << 1];
ll h[maxn],cnt_e;
void add(ll x, ll y) {
	e[++cnt_e] = {y, h[x]};
	h[x] = cnt_e;
}

ll siz[maxn],son[maxn],st[maxn],ed[maxn],id[maxn],idx;
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

struct node {
	ll id,u;
}t[maxn];
ll tot,q[maxn],tp;
#define X(i) (b[i])
#define Y(i) (f[i])
#define slope(x, y) ((Y(x) - Y(y)) / (ld) (X(x) - X(y)))
void solve(ll l, ll r) {
	if (l == r) return;
	ll mid = (l + r) >> 1;
	solve(l, mid);
	sort(t + l, t + mid + 1, [](node x, node y) { return X(x.u) != X(y.u) ? X(x.u) < X(y.u) : Y(x.u) < Y(y.u); });
	sort(t + mid + 1, t + r + 1, [](node x, node y) { return a[x.u] < a[y.u]; });
	tp = 0;
	for (ll i = l; i <= mid; ++i) {
		if (i > l && X(t[i].u) == X(t[i - 1].u)) continue;
		while (tp > 1 && slope(t[q[tp - 1]].u, t[q[tp]].u) > slope(t[q[tp]].u, t[i].u)) --tp;
		q[++tp] = i;
	}
	for (ll i = mid + 1; i <= r; ++i) {
		if (vis[t[i].u]) continue;
		while (tp > 1 && slope(t[q[tp - 1]].u, t[q[tp]].u) > -a[t[i].u]) --tp;
		ll u = t[i].u, v = t[q[tp]].u;
		f[u] = min(f[u], f[v] + a[u] * b[v]);
	}
	sort(t + mid + 1, t + r + 1, [](node x, node y) { return x.id < y.id; });
	solve(mid + 1, r);
}

void dfs2(ll u, ll pre, bool clr) {
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre || v == son[u]) continue;
		dfs2(v, u, 1);
	}
	if (son[u]) dfs2(son[u], u, 0);
	else f[u] = 0, vis[u] = 1;
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre || v == son[u]) continue;
		for (ll x = st[v]; x <= ed[v]; ++x)
			t[++tot] = {tot, id[x]}, vis[id[x]] = 1;
	}
	t[++tot] = {tot, u};
	if (clr) { solve(1, tot); tot = 0; }
}

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &b[i]);
	for (ll i = 1; i < n; ++i) {
		ll x,y;
		scanf("%lld%lld", &x, &y);
		add(x, y), add(y, x);
	}
	memset(f, 0x3f, sizeof f);
	dfs1(1, 0);
	dfs2(1, 0, 1);
	for (ll i = 1; i <= n; ++i) printf("%lld%c", f[i], " \n"[i == n]);
	return 0;
}