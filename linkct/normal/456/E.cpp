#include <cstdio>
#define MAXN 300005

struct edge{
	int n, p;
	void var(int _n, int _p){
		n = _n, p = _p;
	}
}edges[MAXN << 1];
int f[MAXN], n, m, q, far, length, g[MAXN], edgeSize, ext[MAXN];
bool vis[MAXN];

void dfs(int x, int fa, int len){
	if(len > length){
		far = x;
		length = len;
	}
	for(int p = g[x]; p; p = edges[p].p)
		if(edges[p].n != fa) dfs(edges[p].n, x, len + 1);
}
inline int max(int a, int b){return a > b ? a : b;}
int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
void unite(int a, int b){f[find(a)] = find(f[b]);}
void addEdge(int s, int t){
	edges[++ edgeSize].var(t, g[s]);
	g[s] = edgeSize;
	edges[++ edgeSize].var(s, g[t]);
	g[t] = edgeSize;
}
int main(){
	int i, s, t, type, temp;
	scanf("%d%d%d", &n, &m, &q);
	for(i = 1; i <= n; ++ i) f[i] = i;
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &s, &t);
		addEdge(s, t);
		unite(s, t);
	}
	for(i = 1; i <= n; ++ i)
		if(!vis[find(i)]){
			length = 0, far = i;
			vis[find(i)] = true;
			dfs(i, -1, 0);
			length = 0;
			dfs(far, -1, 0);
			ext[find(i)] = length;
		}
	for(i = 1; i <= q; ++ i){
		scanf("%d", &type);
		if(type == 1){
			scanf("%d", &s);
			printf("%d\n", ext[find(s)]);
		}else{
			scanf("%d%d", &s, &t);
			if(find(s) != find(t)){
				temp = max(((ext[find(s)] + 1) >> 1) + ((ext[find(t)] + 1) >> 1) + 1, max(ext[find(s)], ext[find(t)]));
				unite(s, t);
				ext[find(s)] = temp;
			}
		}
	}
	return 0;
}