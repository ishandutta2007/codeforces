// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 500010;
int n, m, u, v, opt;
int pos, id[maxn], siz[maxn], dep[maxn], fa[maxn], top[maxn], son[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
}

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			fa[to[i]] = u;
			dep[to[i]] = dep[u] + 1;
			dfs1(to[i]);
			siz[u] += siz[to[i]];
			if (siz[to[i]] > siz[son[u]])
				son[u] = to[i];
		}
}

void dfs2(int u, int toppoint) {
	id[u] = ++pos, top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct node {
	int l, r, mid;
	int val, lazy;
} p[maxn << 2];

void pushup(int val, int u) {
	p[u].val = p[u].lazy = val;
}

void pushdown(int u) {
	if (p[u].lazy != -1) {
		if (p[u].l != p[u].r) {
			pushup(p[u].lazy, u << 1);
			pushup(p[u].lazy, u << 1 | 1);
		}
		p[u].lazy = -1;
	}
}

void build(int l, int r, int u = 1) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].val = 0, p[u].lazy = -1;
	if (l == r) return;
	build(l, p[u].mid, u << 1);
	build(p[u].mid + 1, r, u << 1 | 1);
}

void modify(int l, int r, int x, int u = 1) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(x, u);
		return;
	}
	if (r <= p[u].mid) return (void) modify(l, r, x, u << 1);
	if (l > p[u].mid) return (void) modify(l, r, x, u << 1 | 1);
	modify(l, p[u].mid, x, u << 1);
	modify(p[u].mid + 1, r, x, u << 1 | 1);
}

int query(int k, int u = 1) {
	pushdown(u);
	if (p[u].l == p[u].r)
		return p[u].val;
	if (k <= p[u].mid) return query(k, u << 1);
	else return query(k, u << 1 | 1);
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}

	dfs1(1);
	dfs2(1, 1);
	build(1, n);

	m = read();
	for (int i = 1; i <= m; i++) {
		opt = read();
		// printf(">>> %d\n", opt);
		if (opt == 1) {
			u = read();
			modify(id[u], id[u] + siz[u] - 1, 1);
		} else if (opt == 2) {
			u = read();
			while (top[u] != 1) {
				modify(id[top[u]], id[u], 0);
				u = fa[top[u]];
			}
			modify(1, id[u], 0);
		} else if (opt == 3) {
			u = read();
			printf("%d\n", query(id[u]));
		}
	}

	return 0;
}