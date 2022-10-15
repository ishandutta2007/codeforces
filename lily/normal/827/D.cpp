/* Never Say Die */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double D;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
int ch = 0;
template <class T> inline void read(T &a) {
	bool f = 0; a = 0;
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
	if (f) a = -a;
}

#define MAXN 200005
#define INF 0x3f3f3f3f

struct edge {
	int nxt, v, w;
} e[MAXN * 2];

int head[MAXN], ecnt = 1;

void add(int u, int v, int w) {
	e[++ecnt] = (edge) {head[u], v, w}; head[u] = ecnt;
	e[++ecnt] = (edge) {head[v], u, w}; head[v] = ecnt;
}

int n, m;
int dep[MAXN], fa[MAXN], son[MAXN], siz[MAXN], top[MAXN], L[MAXN], R[MAXN], rev[MAXN], val[MAXN], tid;

void dfs(int x) {
	siz[x] = 1;
	for (int o = head[x]; o; o = e[o].nxt) {
		int v = e[o].v;
		if (v != fa[x]) {
			fa[v] = x;
			dep[v] = dep[x] + 1;
			val[v] = e[o].w;
			dfs(v);
			siz[x] += siz[v];
			if (siz[v] > siz[son[x]]) son[x] = v;
		}
	}
}

void lnk(int x, int anc) {
	L[x] = ++tid; rev[tid] = x;
	top[x] = anc;
	if (son[x]) {
		lnk(son[x], anc);
		for (int o = head[x]; o; o = e[o].nxt) {
			int v = e[o].v;
			if (v != fa[x] && v != son[x]) lnk(v, v);
		}
	}
	R[x] = tid;
}

struct Node {
	int l, r, v;
} t[MAXN * 2];

int tcnt = 0;

int build(int l, int r) {
	int x = ++tcnt;
	if (l < r) {
		int mid = (l + r) >> 1;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r);
		t[x].v = -1;
	}
	t[x].v = INF;
	return x;
}

void b2(int x, int l, int r) {
	if (l < r) {
		int mid = (l + r) >> 1;
		b2(t[x].l, l, mid);
		b2(t[x].r, mid + 1, r);
		t[x].v = max(t[t[x].l].v, t[t[x].r].v);
	}
	else t[x].v = val[rev[l]];
}

void pd(int x) {
	t[t[x].l].v = t[x].v;
	t[t[x].r].v = t[x].v;
	t[x].v = -1;
}

void upd(int x, int l, int r, int ql, int qr, int v) {
	if (l == ql && r == qr) {
		t[x].v = v;
		return;
	}
	if (~t[x].v) pd(x);
	int mid = (l + r) >> 1;
	if (ql <= mid) upd(t[x].l, l, mid, ql, min(mid, qr), v);
	if (qr >  mid) upd(t[x].r, mid + 1, r, max(mid + 1, ql), qr, v);
}

void upd_t(int u, int v, int w) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		upd(1, 1, n, L[top[u]], L[u], w);
		u = fa[top[u]];
	}
	if (L[u] > L[v]) swap(u, v);
	if (u == v) return;
	upd(1, 1, n, L[u] + 1, L[v], w);
}

int qry(int x, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) return t[x].v;
	int mid = (l + r) >> 1, ret = 0;
	if (ql <= mid) ret = qry(t[x].l, l, mid, ql, min(mid, qr));
	if (qr >  mid) ret = max(ret, qry(t[x].r, mid + 1, r, max(mid + 1, ql), qr));
	return ret;
}

int qry_t(int u, int v) {
	int ret = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		ret = max(ret, qry(1, 1, n, L[top[u]], L[u]));
		u = fa[top[u]];
	}
	if (L[u] > L[v]) swap(u, v);
	if (u == v) return ret;
	return max(ret, qry(1, 1, n, L[u] + 1, L[v]));
}

int q[MAXN];

void get(int x, int l, int r) {
	if (l < r) {
		if (~t[x].v) pd(x);
		int mid = (l + r) >> 1;
		get(t[x].l, l, mid);
		get(t[x].r, mid + 1, r);
	}
	else q[l] = t[x].v;
}

struct E {
	int u, v, w, id;
	bool operator < (const E &a) const {return w < a.w;}
} ee[MAXN];


int f[MAXN]; bool vis[MAXN];

int getf(int x) {
	static int sta[MAXN]; int tt = 0;
	while (f[x] > 0) sta[++tt] = x, x = f[x];
	while (tt) f[sta[tt--]] = x; 
	return x;
}

int ans[MAXN];

int main() {
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		read(ee[i].u); read(ee[i].v); read(ee[i].w); ee[i].id = i;
	}
	sort(ee + 1, ee + m + 1);
	for (int i = 1; i <= n; i++) f[i] = -1;
	for (int i = 1; i <= m; i++) {
		int u = getf(ee[i].u), v = getf(ee[i].v);		
		if (u != v) {
			vis[i] = 1;
			if (f[u] > f[v]) swap(u, v);
			f[u] += f[v];
			f[v] = u;
			add(ee[i].u, ee[i].v, ee[i].w);
		}
	}
	dfs(1);
	lnk(1, 1);
	build(1, n);
	for (int i = m; i; i--) {
		if (!vis[i]) upd_t(ee[i].u, ee[i].v, ee[i].w);
	}
	get(1, 1, n);
	for (int i = 1; i <= m; i++) {
		if (vis[i]) {
			int u = ee[i].u, v = ee[i].v;
			if (v == fa[u]) swap(u, v);
			ans[ee[i].id] = q[L[v]];
		}
	}
	b2(1, 1, n);
	for (int i = 1; i <= m; i++) {
		if (!vis[i]) {
			ans[ee[i].id] = qry_t(ee[i].u, ee[i].v);
		}
	}
	for (int i = 1; i <= m; i++) printf("%d ", (ans[i] == INF ? 0 : ans[i]) - 1);
	return 0;
}