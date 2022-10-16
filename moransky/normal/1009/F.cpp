#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1000005;

int n, dep[N], ans[N], rt[N];

struct E{
	int next, v;
} e[N << 1];

int head[N], numE = 0;

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

int idx = 0;

struct T {
	int l, r, v;
} t[N * 21];

void inline pushup(int p) {
	t[p].v = max(t[t[p].l].v, t[t[p].r].v);
}

void build(int &p, int l, int r, int x) {
	p = ++idx;
	if (l == r) { t[p].v = 1; return; }
	int mid = (l + r) >> 1;
	if (x <= mid) build(t[p].l, l, mid, x);
	else build(t[p].r, mid + 1, r, x);
	pushup(p);
}

void merge(int &p, int q, int l, int r) {
	if (!q) return;
	if (!p) { p = q; return; }
	if (l == r) { t[p].v += t[q].v; return; }
	int mid = (l + r) >> 1;
	merge(t[p].l, t[q].l, l, mid);
	merge(t[p].r, t[q].r, mid + 1, r);
	pushup(p);
}

int query(int p, int l, int r) {
	if (l == r) return r;
	int mid = (l + r) >> 1;
	if (t[t[p].l].v >= t[t[p].r].v) return query(t[p].l, l, mid);
	else return query(t[p].r, mid + 1, r);
}

void dfs(int u, int last) {
	dep[u] = dep[last] + 1;
	build(rt[u], 1, n, dep[u]);
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == last) continue;
		dfs(v, u);
		merge(rt[u], rt[v], 1, n);
	}
	ans[u] = query(rt[u], 1, n) - dep[u];
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}