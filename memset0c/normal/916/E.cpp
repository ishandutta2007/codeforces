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

void parr(int *a, int n, string s) {
	cout << s << " ";
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	puts("");
}

const int maxn = 100010;
int n, m, u, v, x, opt, root;
int pos, id[maxn], wid[maxn], dep[maxn], fa[maxn], siz[maxn], son[maxn], top[maxn], wxw[maxn];
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
	id[u] = ++pos, wid[id[u]] = wxw[u], top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct node {
	int l, r, mid;
	ll sum, lazy;
} p[maxn << 2];

void pushup(int u, ll x) {
	p[u].sum += x * (p[u].r - p[u].l + 1);
	p[u].lazy += x;
}

void pushdown(int u) {
	if (p[u].lazy) {
		if (p[u].l != p[u].r) {
			pushup(u << 1, p[u].lazy);
			pushup(u << 1 | 1, p[u].lazy);
		}
		p[u].lazy = 0;
	}
}

void build(int l, int r, int u = 1) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) {
		p[u].sum = wid[l];
		return;
	}
	build(l, p[u].mid, u << 1);
	build(p[u].mid + 1, r, u << 1 | 1);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

void modify(int l, int r, ll x, int u = 1) {
	pushdown(u);
	// printf("modify %d %d %d %d\n", u, l, r, x);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, x);
		return;
	}
	if (r <= p[u].mid) modify(l, r, x, u << 1);
	else if (l > p[u].mid) modify(l, r, x, u << 1 | 1);
	else modify(l, p[u].mid, x, u << 1), modify(p[u].mid + 1, r, x, u << 1 | 1);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

ll query(int l, int r, int u = 1) {
	pushdown(u);
	// printf("query %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r)
		return p[u].sum;
	if (r <= p[u].mid) return query(l, r, u << 1);
	if (l > p[u].mid) return query(l, r, u << 1 | 1);
	return query(l, p[u].mid, u << 1) + query(p[u].mid + 1, r, u << 1 | 1);
}

int lca(int u, int v) {
	// printf("lca(%d, %d)", u, v);
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]])
			swap(u, v);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v])
		swap(u, v);
	// printf(" = %d\n", u);
	return u;
}

int getson(int u, int v) {
	// printf("getson(%d, %d)\n", u, v);
	while (top[u] != top[v]) {
		u = top[u];
		if (fa[u] == v) return u;
		u = fa[u];
	}
	return son[v];
}

// int exlca(int u, int v) {
// 	int lcauv = lca(u, v), lcaur = lca(u, root), lcavr = lca(v, root), lcauvr = lca(lcauv, root);
// 	if (lcauv == root || lcauvr != lcauv) {
// 		return lcauv;
// 	} else if (lcaur == root || lcavr == root) {
// 		return root;
// 	} else if (lcaur == u) {
// 		return u;
// 	} else if (lcavr == v) {
// 		return v;
// 	} else {
// 		return lcauv;
// 	}
// }

int deeper(int u, int v) {
	if (dep[u] > dep[v]) return u;
	else return v;
}

int exlca(int u, int v) {
	return deeper(lca(u, v), deeper(lca(u, root), lca(v, root)));
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		wxw[i] = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}

	dep[1] = 1;
	root = 1;
	dfs1(1);
	dfs2(1, 1);
	build(1, n);

	// parr(id, n, "id");
	// parr(dep, n, "dep");
	// parr(son, n, "son");

	for (int i = 1; i <= m; i++) {
		opt = read();
		// printf(">>> %d\n", opt);
		if (opt == 1) {
			root = read();
		} else if (opt == 2) {
			u= read(), v = read(), x = read();
			// printf("exlca(%d, %d) = %d root = %d\n", u, v, exlca(u, v), root);
			u = exlca(u, v);
			if (u == root) {
				modify(1, n, x);
			} else if (lca(u, root) != u) {
				modify(id[u], id[u] + siz[u] - 1, x);
			} else {
				v = getson(root, u);
				modify(1, n, x);
				modify(id[v], id[v] + siz[v] - 1, -x);
			}
		} else {
			u = read();
			if (u == root) {
				printf("%lld\n", query(1, n));
			} else if (lca(u, root) != u) {
				printf("%lld\n", query(id[u], id[u] + siz[u] - 1));
			} else {
				v = getson(root, u);
				printf("%lld\n", query(1, n) - query(id[v], id[v] + siz[v] - 1));
			}
		}
		// printf("]]] ");
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", query(id[i], id[i]));
		// puts("");
	}

	return 0;
}