#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

const int N = 300005, M = 300005, S = 19;

int n, m, w[N], L[N], R[N], dfn[N << 1], dfncnt;
int dep[N], fa[N][S], ans[M], cnt[N], d[N], res, pos[N << 1], t, sum[N];

int L1[N], R1[N];

int pos2[N];

bool vis[N];

int head[N], numE = 0;

set<int> s;

struct E{
	int next, v;
} e[N << 1];

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

void dfs(int u) {
	dfn[L[u] = ++dfncnt] = u;
	for (int i = 1; i < S && fa[u][i - 1]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa[u][0]) continue;
		fa[v][0] = u, dep[v] = dep[u] + 1;
		dfs(v);
	}
	dfn[R[u] = ++dfncnt] = u;
}

int inline lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = S - 1; ~i; i--)
		if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = S - 1; ~i; i--)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

struct Q{
	int l, r, x, y, p, id;
	bool operator < (const Q &b) const {
		if (pos[l] != pos[b.l]) return l < b.l;
		return (pos[l] & 1) ? r < b.r : r > b.r;
	}
} q[M];

void inline ins(int x) {
	cnt[w[x]] ^= 1;
	if (cnt[w[x]]) sum[pos2[w[x]]]++;
	else sum[pos2[w[x]]]--;
}

int inline query(int l, int r) {
	int p = pos2[l], q = pos2[r];
	if (p == q) {
		for (int i = l; i <= r; i++)
			if (cnt[i]) return i;
	} else {
		for (int i = l; i <= R1[p]; i++)
			if (cnt[i]) return i;
		for (int i = L1[q]; i <= r; i++)
			if (cnt[i]) return i;
		for (int i = p + 1; i <= q - 1; i++) {
			if (sum[i]) {
				for (int j = L1[i]; j <= R1[i]; j++)
					if (cnt[j]) return j;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &n, &m); t = 2 * sqrt(n);
	int rr = sqrt(n);
	for (int i = 1; i <= n; i++) scanf("%d", w + i);
	for (int i = 1; i <= 2 * n; i++) pos[i] = (i - 1) / t + 1;
	for (int i = 1; i <= n; i++) {
		pos2[i] = (i - 1) / rr + 1;
		if (!L1[pos2[i]]) L1[pos2[i]] = i;
		R1[pos2[i]] = i;
	}
	for (int i = 1, u, v; i < n; i++)
		scanf("%d%d", &u, &v), add(u, v), add(v, u);
	dfs(1);
	for (int i = 1, u, v; i <= m; i++) {
		int x, y;
		scanf("%d%d%d%d", &u, &v, &x, &y);
		if (L[u] > L[v]) swap(u, v);
		int p = lca(u, v);
		if (p == u) q[i] = (Q) { L[u], L[v], x, y, 0, i };
		else q[i] = (Q) { R[u], L[v], x, y, p, i };
	}
	sort(q + 1, q + 1 + m);
	int l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		while (l < q[i].l) ins(dfn[l++]);
		while (l > q[i].l) ins(dfn[--l]);
		while (r < q[i].r) ins(dfn[++r]);
		while (r > q[i].r) ins(dfn[r--]);
		if (q[i].p) ins(q[i].p);
		ans[q[i].id] = query(q[i].x, q[i].y);
		if (q[i].p) ins(q[i].p);
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}