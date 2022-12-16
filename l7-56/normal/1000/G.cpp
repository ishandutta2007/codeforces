#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 3e5 + 10;
struct Edge {
	ll v, w, nxt;
} e[maxn << 1];
ll h[maxn], cnt_e;
void add(ll x, ll y, ll z) { e[++cnt_e] = {y, z, h[x]}, h[x] = cnt_e; }
ll n,q,a[maxn],val[maxn],f[maxn],g[maxn],d[maxn];
ll sa[maxn],sv[maxn],sf[maxn],sd[maxn];
ll dep[maxn],fa[maxn],son[maxn],siz[maxn],top[maxn];
void dfs1(ll u) {
	siz[u] = 1;
	dep[u] = dep[fa[u]] + 1;
	sa[u] = sa[fa[u]] + a[u];
	sv[u] = sv[fa[u]] + val[u];
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v, w = e[j].w;
		if (v == fa[u]) continue;
		val[v] = w, fa[v] = u;
		dfs1(v);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
		f[u] += d[v];
	}
	d[u] = max(f[u] - val[u] * 2 + a[u], 0ll);
}

void dfs2(ll u, ll tp, ll up) {
	g[u] = up;
	sf[u] = sf[fa[u]] + f[u];
	sd[u] = sd[fa[u]] + d[u];
	top[u] = tp;
	if (son[u]) dfs2(son[u], tp, max(0ll, g[u] + f[u] - d[son[u]] + a[u] - 2 * val[son[u]]));
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == fa[u] || v == son[u]) continue;
		dfs2(v, v, max(0ll, up + f[u] - d[v] + a[u] - 2 * val[v]));
	}
}

ll lca(ll x, ll y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] < dep[y]) swap(x, y);
	return y;
}

ll query(ll x, ll y) {
	ll z = lca(x, y);
	return (sf[x] + sf[y] - sf[z] - sf[fa[z]]) - (sd[x] + sd[y] - 2 * sd[z]) + g[z]
	- (sv[x] + sv[y] - 2 * sv[z]) + (sa[x] + sa[y] - sa[z] - sa[fa[z]]);
}

signed main() {
	read(n, q);
	for (ll i = 1; i <= n; ++i) read(a[i]);
	for (ll i = 1; i < n; ++i) {
		ll x, y, z; read(x, y, z);
		add(x, y, z), add(y, x, z);
	}
	dfs1(1), dfs2(1, 1, 0);
	while (q--) {
		ll x, y; read(x, y);
		write(query(x, y), '\n');
	}
	return 0;
}