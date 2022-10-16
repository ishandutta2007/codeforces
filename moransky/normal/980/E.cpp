#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1000005;
int n, K, fa[N], dep[N], dfn[N], sz[N];
int head[N], tot, cnt = 1, numE = 0;
int c[N];
void inline add(int x, int k) {
	for (; x <= n; x += x & - x) c[x] += k;
}
int inline ask (int x) {
	int res = 0;
	for (; x; x -= x & -x) res += c[x];
	return res;
}
struct E{
	int next, v;
}e[N << 1];
bool ans[N];
void inline addE(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}
void dfs(int u) {
	sz[u] = 1; dfn[u] = ++tot;
	for(int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
		sz[u] += sz[v];
		
	}
}
void inline work(int x) {
	if(cnt + (dep[x] - ask(dfn[x])) > n - K) return;
	for (; x != n && !ans[x]; x = fa[x]) {
		ans[x] = true, add(dfn[x], 1), add(dfn[x] + sz[x], -1), cnt++;
	}
}
int main(){
	scanf("%d%d", &n, &K);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v), addE(u, v), addE(v, u);
	}
	ans[n] = true;
	dfs(n);
	
	for (int i = n - 1; i; i--)
		if(!ans[i]) work(i);
	
	for (int i = 1; i <= n; i++)
		if(!ans[i]) printf("%d ", i);
	return 0;
}