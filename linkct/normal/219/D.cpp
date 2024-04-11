#include <cstdio>
#define MAX 200005

struct edge{
	int n, p, c;
	void var(int _n, int _p, int _c)
	{n = _n; p = _p; c = _c;}
}edges[MAX << 1];
int g[MAX], n, edgeSize, ans = 1 << 30, answer[MAX], up[MAX], down[MAX];

void addEdge(int f, int t){
	edges[++ edgeSize].var(t, g[f], 0);
	g[f] = edgeSize;
	edges[++ edgeSize].var(f, g[t], 1);
	g[t] = edgeSize;
}
void dfs1(int x, int fa){
	int p, v;
	for(p = g[x]; p; p = edges[p].p){
		v = edges[p].n;
		if(v != fa){
			dfs1(v, x);
			down[x] += down[v] + edges[p].c;
		}
	}
}
void dfs2(int x, int fa, int cost){
	if(x != 1)
		up[x] = up[fa] + down[fa] - down[x] - cost + (cost ? 0 : 1);
	int p, v;
	for(p = g[x]; p; p = edges[p].p){
		v = edges[p].n;
		if(v != fa)
			dfs2(v, x, edges[p].c);
	}
}
int main(){
	int i, s, t;
	scanf("%d", &n);
	for(i = 1; i < n; ++ i){
		scanf("%d%d", &s, &t);
		addEdge(s, t);
	}
	dfs1(1, -1);
	dfs2(1, -1, 0);
	for(i = 1; i <= n; ++ i)
		if(up[i] + down[i] < ans)
			ans = up[i] + down[i], answer[answer[0] = 1] = i;
		else if(up[i] + down[i] == ans)
			answer[++ answer[0]] = i;
	printf("%d\n", ans);
	for(i = 1; i < answer[0]; ++ i)
		printf("%d ", answer[i]);
	printf("%d\n", answer[answer[0]]);
	return 0;
}