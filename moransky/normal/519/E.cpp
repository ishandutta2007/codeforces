#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100005, L = 17;
int n, m, a, b, dep[N], sz[N], tot[N], fa[N][L];
int head[N], numE = 0;
struct E{
	int next, v;
}e[N << 1];
void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}
void dfs(int u) {
	sz[u] = 1;
	for (int i = 1; i < L && fa[u][i - 1]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1]; 
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == fa[u][0]) continue;
		dep[v] = dep[u] + 1;
		fa[v][0] = u;
		dfs(v);
		sz[u] += sz[v];
	}
	
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == fa[u][0]) continue;
		tot[v] = sz[u] - 1 - sz[v];
	}
} 
int inline lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for (int i = L - 1; ~i; i--)
		if(dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
 	if(x == y) return x;
	for (int i = L - 1; ~i; i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	a = x, b = y;
	return fa[x][0];
}
int main(){
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	dfs(1);
	scanf("%d", &m);
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y);
		if(dep[x] < dep[y]) swap(x, y);
		int p = lca(x, y); 
		if(x == y) printf("%d\n", n);
		else if(p == y) {
			if((dep[x] - dep[y]) & 1) puts("0");
			else {
				int d = dep[x] - (dep[x] - dep[y]) / 2 + 1;
				int z = x;
				for (int i = L - 1; ~i; i--)
					if(dep[z] - (1 << i) >= d) z = fa[z][i];
				printf("%d\n", tot[z] + 1);
			}
		} else {
			if((dep[x] + dep[y]) & 1) puts("0");
			else{
				
				int d = dep[x] - (dep[x] + dep[y] - 2 * dep[p]) / 2; 
				if(d == dep[p]) {
					printf("%d\n", (tot[a] + tot[b] - sz[a] - sz[b]) / 2 + 1 + n - sz[p]);
				} else {
					int z = x; d++;
					for (int i = L - 1; ~i; i--)
						if(dep[z] - (1 << i) >= d) z = fa[z][i];

					printf("%d\n", tot[z] + 1);
				}
			}
		}
	}
	return 0;
}