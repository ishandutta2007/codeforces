#include <cstdio>
const int MAXN = 300005, LOG = 15, SIGMA = 26, MAXM = 600005;

int n, target, val[MAXN], dif[MAXN], fa[MAXN], size[MAXN], nodeSize;
int ch[MAXN * LOG][SIGMA], g[MAXN], nxt[MAXM], to[MAXM], edgeSize, son[MAXN];
int root[MAXN], ans, ansc;
char str[MAXN];

inline int idx(char x){return x - 'a';}
void addEdge(int u, int v){
	nxt[++ edgeSize] = g[u];
	to[g[u] = edgeSize] = v;
}
void dfsCalc(int x){
	size[x] = 1;
	for(int p = g[x]; p; p = nxt[p])
		if(to[p] != fa[x]){
			fa[to[p]] = x;
			dfsCalc(to[p]);
			size[x] += size[to[p]];
			if(size[son[x]] < size[to[p]]) son[x] = to[p];
		}
}
void dfsGet(int x, int cur){
	if(!ch[cur][idx(str[x])]){
		ch[cur][idx(str[x])] = ++ nodeSize;
		++ dif[target];
	} cur = ch[cur][idx(str[x])];
	for(int p = g[x]; p; p = nxt[p])
		if(to[p] != fa[x]) dfsGet(to[p], cur);
}
void dfsLink(int x){
	int p;
	for(p = g[x]; p; p = nxt[p])
		if(to[p] != fa[x])
			dfsLink(to[p]);
	root[x] = ++ nodeSize;
	if(son[x]) ch[root[x]][idx(str[x])] = root[son[x]];
	else ch[root[x]][idx(str[x])] = ++ nodeSize;
	dif[x] = dif[son[x]] + 1; target = x;
	for(p = g[x]; p; p = nxt[p])
		if(to[p] != fa[x] && to[p] != son[x])
			dfsGet(to[p], ch[root[x]][idx(str[x])]);
	if(dif[x] + val[x] > ans) ans = dif[x] + val[x], ansc = 1;
	else if(dif[x] + val[x] == ans) ++ ansc;
}
int main(){
	int i, u, v;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i) scanf("%d", &val[i]);
	scanf("%s", str + 1);
	for(i = 1; i < n; ++ i){
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
	}
	dfsCalc(1);
	dfsLink(1);
	printf("%d\n%d\n", ans, ansc);
	return 0;
}