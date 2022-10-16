#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200005, L = 18, M = N << 1;
LL res = 0;
int n, m, f[N], fa[N][L], Max[N][L], dep[N]; 
int head[N], numE = 0;
LL ans[N];
struct E{
	int u, v, w, id;
	bool operator < (const E &x) const {
		return w < x.w;
	}
}e[M];
int get(int x) {
	return x == f[x] ? x : f[x] = get(f[x]);
} 
struct Edge{
	int next, v, w;
}g[M];
void add(int u, int v, int w) {
	g[++numE] = (Edge) { head[u], v, w };
	head[u] = numE;
}
void dfs(int u, int last) {
	fa[u][0] = last;
	dep[u] = dep[last] + 1;
	for (int i = 1; i < L && fa[u][i - 1]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1], Max[u][i] = max(Max[u][i - 1], Max[fa[u][i - 1]][i - 1]);
	for (int i = head[u]; i; i = g[i].next) {
		int v = g[i].v;
		if(v == last) continue;
		Max[v][0] = g[i].w;
		dfs(v, u); 
	}
}
int inline getMax(int x, int y) {
	int res = 0;
	if(dep[x] < dep[y]) swap(x, y);
	for (int i = L - 1; ~i; i--)
		if(dep[x] - (1 << i) >= dep[y]) {
			res = max(res, Max[x][i]);
			x = fa[x][i];
		}
	if(x == y) return res;
	for (int i = L - 1; ~i; i--) {
		if(fa[x][i] != fa[y][i]) {
			res = max(res, max(Max[x][i], Max[y][i]));
			x = fa[x][i], y = fa[y][i];
		}
	}
	return max(res, max(Max[x][0], Max[y][0]));
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w), e[i].id = i;
		
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		u = get(u), v = get(v);
		if(u != v) {
			add(u, v, w);
			add(v, u, w);
			res += w;
			f[u] = v; 
		}
	}
	
	dfs(1, 0);
	
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		ans[e[i].id] = res - getMax(u, v) + w;
	}
	for (int i = 1; i <= m; i++)
		printf("%lld\n", ans[i]);
	return 0;
}