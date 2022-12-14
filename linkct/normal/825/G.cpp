#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005, LOG = 21;

int n, q, dep[MAXN], pre[MAXN][LOG], val[MAXN][LOG];
int g[MAXN], to[MAXN << 1], nxt[MAXN << 1], edgeSize;
int ans, fa[MAXN]; bool col[MAXN];

void addEdge(int u, int v){
	nxt[++ edgeSize] = g[u];
	to[g[u] = edgeSize] = v;
}
void dfs(int x){
	int p;
	for(p = 1; (1 << p) < dep[x]; ++ p){
		pre[x][p] = pre[pre[x][p - 1]][p - 1];
		val[x][p] = min(val[x][p - 1], val[pre[x][p - 1]][p - 1]);
	}
	for(p = g[x]; p; p = nxt[p]){
		if(dep[to[p]]) continue;
		dep[to[p]] = dep[x] + 1;
		pre[to[p]][0] = fa[to[p]] = x;
		val[to[p]][0] = to[p];
		dfs(to[p]);
	}
}
inline void color(int x){ans = min(ans, x), col[x] = true;}
int main(){
	int i, u, v, x, op, p, cur, lastans = 0;
	scanf("%d%d", &n, &q);
	for(i = 1; i < n; ++ i){
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
	} scanf("%*d %d", &x);
	x = (x + lastans) % n + 1;
	dep[x] = 1, dfs(x);
	ans = x, color(x), -- q;
	for(i = 1; i <= q; ++ i){
		scanf("%d%d", &op, &x);
		x = (x + lastans) % n + 1;
		if(op == 1){
			for(; !col[x]; x = fa[x])
				color(x);
		}else{
			for(p = 19, cur = ans; p >= 0; -- p)
				if(dep[x] > (1 << p) && !col[pre[x][p]]){
					cur = min(cur, val[x][p]);
					x = pre[x][p];
				}
			printf("%d\n", lastans = min(cur, x));
		}
	} return 0;
}