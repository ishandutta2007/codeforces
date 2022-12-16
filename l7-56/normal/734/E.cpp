#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 2e5 + 10;
int n,f[maxn];

struct Edge{
	int v,w,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add(int x, int y, int z){
	e[++cnt_e] = (Edge){y, z, h[x]};
	h[x] = cnt_e; return;
}

int dis[maxn],ans,ansi;
void dfs(int u, int pre){
	for(int i = h[u]; i; i = e[i].nxt){
		int v = e[i].v, w = e[i].w;
		if(v == pre) continue;
		dis[v] = dis[u] + w;
		dfs(v, u);
	}
	if(ans < dis[u]) ans = dis[u], ansi = u;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &f[i]);
	for(int i = 1; i < n; ++i){
		int a,b;
		scanf("%d%d", &a, &b);
		if(f[a] == f[b]) add(a, b, 0), add(b, a, 0);
		else add(a, b, 1), add(b, a, 1);
	}
	dis[1] = ans = 0;
	dfs(1, 0);
	dis[ansi] = ans = 0;
	dfs(ansi, 0);
	printf("%d", (ans + 1) / 2);
	return 0;
}
//CF734E