#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 100005, L = 17;
int n, q, fa[N][L], dep[N];
int head[N], numE = 0;
struct E{
	int next, v;
} e[N << 1];
void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}
void dfs(int u) {
	for (int i = 1; i < L && fa[u][i - 1]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa[u][0]) continue;
		dep[v] = dep[u] + 1;
		fa[v][0] = u;
		dfs(v); 
	}
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = L - 1; ~i; i--)
		if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = L - 1; ~i; i--)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int d(int a, int b, int p) {
	return dep[a] + dep[b] - 2 * dep[p];
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++)
		scanf("%d%d", &u, &v), add(u, v), add(v, u);
	dfs(1);
	scanf("%d", &q);
	while (q--) {
		int x, y, a, b, k; scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
		int p1 = lca(a, b), d1 = d(a, b, p1);
		int p2 = lca(a, x), p3 = lca(a, y);
		int p4 = lca(b, x), p5 = lca(b, y);
		int d2 = d(a, x, p2) + 1 + d(y, b, p5);
		int d3 = d(a, y, p3) + 1 + d(x, b, p4);
		int p6 = lca(x, y), d4 = d(x, y, p6) + 1;
		if ((d1 <= k && (k - d1) % 2 == 0) || (d2 <= k && (k - d2) % 2 == 0) || (d3 <= k && (k - d3) % 2 == 0)) puts("YES");
		else if((d2 + d4 <= k && (k - d2 - d4) % 2 == 0) || (d3 + d4 <= k && (k - d3 - d4) % 2 == 0)) puts("YES");
		else puts("NO");
	}
	return 0;
}