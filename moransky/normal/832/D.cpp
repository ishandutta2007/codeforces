#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100005, L = 18;
int n, Q, fa[N][L], dep[N];
int head[N], numE = 0;
struct E{
	int next, v;
}e[N << 1];
void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE; 
}
void dfs(int u) {
	for (int i = 1; i < L && fa[u][i - 1]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == fa[u][0]) continue;
		dep[v] = dep[u] + 1;
		fa[v][0] = u;
		dfs(v);
	}
}
int inline lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for (int i = L - 1; ~i; i--)
		if(dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if(x == y) return x;
	for (int i = L - 1; ~i; i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int main(){
	scanf("%d%d", &n, &Q);
	for (int i = 2, p; i <= n; i++) {
		scanf("%d", &p);
		add(p, i); add(i, p);
	}
	dfs(1);
	for (int i = 1, a, b, c; i <= Q; i++) {
		scanf("%d%d%d", &a, &b, &c);
		int p1 = lca(a, b), p2 = lca(a, c), p3 = lca(b, c);
		if(p1 != p2) { 
			if(p1 == p3) swap(p2, p3), swap(a, b);
			else swap(p1, p3), swap(a, c);
		} 
		int ans = max(dep[b] - dep[p3], dep[c] - dep[p3]);
		if(dep[p3] < dep[p1]) swap(p3, p1);
		ans = max(ans, dep[p3] + dep[a] - 2 * dep[p1]);
		printf("%d\n", ans + 1);
	}
	return 0;
}