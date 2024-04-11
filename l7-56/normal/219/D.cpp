#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n;
struct Edge{
	int v,w,nxt;
}e[maxn * 2];
int h[maxn],cnt_e;
void add(int u, int v, int w){
	e[++cnt_e] = (Edge){v, w, h[u]};
	h[u] = cnt_e; return;
}

int to_leaves,to_root[maxn],dep[maxn],k,ans[maxn],top;
void dfs(int u, int pre, int sum){
	to_root[u] = sum;
	for(int i = h[u]; i; i = e[i].nxt){
		int v = e[i].v, w = e[i].w;
		if(v == pre) continue;
		to_leaves += w; dep[v] = dep[u] + 1;
		dfs(v, u, sum + (w ^ 1));
	}
}

int main(){
	while(~scanf("%d", &n)){
		to_leaves = cnt_e = 0;
		memset(h, 0, sizeof h);
		for(int i = 1; i < n; ++i){
			int a,b;
			scanf("%d%d", &a, &b);
			add(a,b,0); add(b,a,1);
		}
		dfs(1, 0, 0);
		k = n;
		for(int i = 1; i <= n; ++i) k = min(k, to_leaves - dep[i] + to_root[i] * 2);
		top = 0;
		for(int i = 1; i <= n; ++i) if(k == to_leaves - dep[i] + to_root[i] * 2) ans[++top] = i;
		sort(ans + 1, ans + top + 1);
		printf("%d\n", k);
		for(int i = 1; i <= top; ++i) printf("%d ", ans[i]);
		putchar('\n'); 
	}
	return 0;
}