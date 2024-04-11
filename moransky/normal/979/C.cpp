#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 300005, L = 19;
int n, x, y, dep[N], fa[N][L], sz[N];
int head[N], numE = 0;
LL res = 0;
struct E{
	int next, v;
}e[N << 1];
void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v};
	head[u] = numE;
} 
void dfs(int u) {
	sz[u] = 1;
	for (int i = 1; i < L && fa[u][i - 1]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == fa[u][0]) continue;
		fa[v][0] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
		sz[u] += sz[v];
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
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v); 
		add(u, v); add(v, u);
	}
	
	dfs(1);
	
	if(dep[x] < dep[y]) swap(x, y);
	int p = lca(x, y);
	if(p == y) {
		res = (LL)(n - sz[y] + 1) * sz[x];
		for (int i = head[y]; i; i = e[i].next) {
			int v = e[i].v;
			if(v == fa[y][0]) continue;
			if(lca(v, x) != v) res += (LL)sz[v] * sz[x];
		}
	} else {
		res = (LL)sz[x] * sz[y];
	}
	printf("%lld\n", (LL)(n - 1) * n - res);
	return 0;
}