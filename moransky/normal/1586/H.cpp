// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5, L = 18;

typedef pair<int, int> PII;

int n, q, a[N], r1[N], r2[N], pre[N], dep[N], dfn[N], dfncnt, fa[N][L], mx[N][L], sz[N];

struct E{
	int v, c, t;
};

struct Ed{
	int u, v, w;
	bool operator < (const Ed &b) const {
		return w < b.w;
	}
} ed[N];

vector<E> g[N];

struct Q{
	int v, x, id;
	bool operator < (const Q &b) const {
		return v < b.v;
	}
} e[N];



void dfs(int u) {
	dep[u] = dep[fa[u][0]] + 1;
	dfn[u] = ++dfncnt;
	pre[dfn[u]] = u;
	for (int i = 1; i < L; i++) {
		mx[u][i] = max(mx[u][i - 1], mx[fa[u][i - 1]][i - 1]);
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	sz[u] = 1;
	for (E t: g[u]) {
		int v = t.v;
		if (v == fa[u][0]) continue;
		mx[v][0] = t.t;
		fa[v][0] = u;
		dfs(v);
		sz[u] += sz[v];
	}
}

int inline lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = L - 1; ~i; i--)
		if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = L - 1; ~i; i--)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return x;
}

int inline qv(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int res = 0;
	for (int i = L - 1; ~i; i--)
		if (dep[x] - (1 << i) >= dep[y]) chkMax(res, mx[x][i]), x = fa[x][i];
	if (x == y) return res;
	for (int i = L - 1; ~i; i--)
		if (fa[x][i] != fa[y][i]) chkMax(res, mx[x][i]), chkMax(res, mx[y][i]), x = fa[x][i], y = fa[y][i];
	chkMax(res, mx[x][0]), chkMax(res, mx[y][0]);
	return res;
}

int w[N], d[N], f[N], p[N];

set<int> s[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

typedef set<int>::iterator SIT;

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (sz[x] > sz[y]) swap(x, y);
	f[x] = y, sz[y] += sz[x];
	if (w[y] > w[x]) return;
	if (w[x] > w[y]) {
		w[y] = w[x];
		swap(s[x], s[y]);
		p[y] = p[x];
		d[y] = d[x];
		return;
	}
	p[y] = lca(p[y], p[x]);
	for (int p: s[x]) {
		SIT it = s[y].lower_bound(p);
		if (it != s[y].end()) chkMax(d[y], qv(pre[*it], pre[p]));
		if (it != s[y].begin()) {
			--it;
			chkMax(d[y], qv(pre[*it], pre[p]));
		}
	}
	for (int p: s[x]) {
		s[y].insert(p);
	}
}

bool inline find(int p, int l, int r) {
	SIT it = s[p].lower_bound(l);
	return it != s[p].end() && *it <= r;
}

void query(int i) {
	int id = e[i].id;
	int x = e[i].x;
	int y = find(x);
	r1[id] = w[y];
	r2[id] = d[y];
	chkMax(r2[id], qv(p[y], x));
}

int main() {
	read(n), read(q);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	for (int i = 1, u, v, c, t; i < n; i++) {
		read(u), read(v), read(c), read(t);
		g[u].pb((E) { v, c, t });
		g[v].pb((E) { u, c, t });
		ed[i] = (Ed) { u, v, c };
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		f[i] = p[i] = i, w[i] = a[i], sz[i] = 1;
		s[i].insert(dfn[i]); 
	}
	for (int i = 1; i <= q; i++) read(e[i].v), read(e[i].x), e[i].id = i;
	sort(e + 1, e + 1 + q);
	sort(ed + 1, ed + n);
	for (int i = q, j = n - 1; i; i--) {
		while (j && ed[j].w >= e[i].v) {
			merge(ed[j].u, ed[j].v), --j;
		}
		query(i);
	}
	for (int i = 1; i <= q; i++)
		printf("%d %d\n", r1[i], r2[i]);
    return 0;
}