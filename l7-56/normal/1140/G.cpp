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

const ll maxn = 3e5 + 10, inf = 4e18;
ll n,q,a[maxn],f[maxn][20],dep[maxn];
struct node {
	ll val[2][2];
	friend node merge(node p, node q, ll u) {
		node ret;
		for (ll i = 0; i < 2; ++i)
			for (ll j = 0; j < 2; ++j) {
				ret.val[i][j] = inf;
				for (ll k = 0; k < 2; ++k)
					for (ll l = 0; l < 2; ++l)
						ret.val[i][j] = min(ret.val[i][j], p.val[i][k] + q.val[l][j] + (k != l) * a[u]);
			}
		return ret;
	}
} g[maxn][20];
struct Edge {
	ll v, w1, w2, nxt;
} e[maxn << 1];
ll h[maxn], cnt_e = 1;
void add(ll x, ll y, ll w1, ll w2) { e[++cnt_e] = {y, w1, w2, h[x]}, h[x] = cnt_e; }

void dfs1(ll u, ll pre) {
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v, w1 = e[j].w1, w2 = e[j].w2;
		if (v == pre) continue;
		dfs1(v, u), a[u] = min(a[u], a[v] + w1 + w2);
	}
}
void dfs2(ll u, ll pre) {
	dep[u] = dep[pre] + 1;
	for (ll i = 1; i <= 19; ++i)
		f[u][i] = f[f[u][i - 1]][i - 1],
		g[u][i] = merge(g[u][i - 1], g[f[u][i - 1]][i - 1], f[u][i - 1]);
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v, w1 = e[j].w1, w2 = e[j].w2;
		if (v == pre) continue;
		a[v] = min(a[v], a[u] + w1 + w2);
		f[v][0] = u;
		g[v][0].val[0][0] = min(w1, a[u] + w2 + a[v]);
		g[v][0].val[0][1] = min(a[u] + w1, a[v] + w2);
		g[v][0].val[1][0] = min(w2 + a[u], w1 + a[v]);
		g[v][0].val[1][1] = min(a[u] + w1 + a[v], w2);
		dfs2(v, u);
	}
}

ll query(ll x, ll y) {
	ll f1 = (x & 1) ^ 1, f2 = (y & 1) ^ 1; x = (x + 1) >> 1, y = (y + 1) >> 1;
	if (dep[x] < dep[y]) swap(x, y), swap(f1, f2);
	node gx, gy;
	gx.val[0][0] = gx.val[1][1] = gy.val[0][0] = gy.val[1][1] = 0;
	gx.val[0][1] = gx.val[1][0] = a[x], gy.val[0][1] = gy.val[1][0] = a[y];
	for (ll i = 19; i >= 0; --i)
		if (dep[x] - dep[y] >= (1 << i))
			gx = merge(gx, g[x][i], x), x = f[x][i];
	if (x == y) return gx.val[f1][f2];
	for (ll i = 19; i >= 0; --i)
		if (f[x][i] != f[y][i]) {
			gx = merge(gx, g[x][i], x), gy = merge(gy, g[y][i], y);
			x = f[x][i], y = f[y][i];
		}
	gx = merge(gx, g[x][0], x), gy = merge(gy, g[y][0], y);
	x = f[x][0], y = f[x][0];
	swap(gy.val[0][1], gy.val[1][0]);
	gx = merge(gx, gy, x);
	return gx.val[f1][f2];
}

int main() {
	read(n);
	for (ll i = 1; i <= n; ++i) read(a[i]);
	for (ll i = 1; i < n; ++i) {
		ll x, y, w1, w2; read(x, y, w1, w2);
		add(x, y, w1, w2), add(y, x, w1, w2);
	}
	dfs1(1, 0), dfs2(1, 0);
	read(q);
	while (q--) {
		ll x, y; read(x, y);
		write(query(x, y), '\n');
	}
	return 0;
}