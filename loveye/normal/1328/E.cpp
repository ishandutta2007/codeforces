#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m,f[N][20],k,a[N],ok,dep[N],p;
int fir[N],to[N << 1],nxt[N << 1],cnt;
inline void addedge(int u,int v) {
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	fir[u] = cnt;
}
void dfs(int u) {
	for(int k = 1;k < 20;++k)
		f[u][k] = f[f[u][k-1]][k-1];
	for(int i = fir[u],v;v = to[i],i;i = nxt[i])
		if(v != f[u][0]) {
			f[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
		}
}
inline int LCA(int u,int v) {
	if(dep[u] < dep[v]) swap(u,v);
	for(int i = 19;i >= 0;--i)
		if(dep[f[u][i]] >= dep[v])
			u = f[u][i];
	if(u == v) return u;
	for(int i = 19;i >= 0;--i)
		if(f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1,u,v;i < n;++i)
		scanf("%d%d",&u,&v),addedge(u,v),addedge(v,u);
	dep[1] = 1;
	dfs(1);
	while(m--) {
		scanf("%d",&k);
		p = 0;
		for(int i = 1;i <= k;++i) {
			scanf("%d",a+i);
			if(dep[p] < dep[a[i]]) p = a[i];
		}
		ok = 0;
		for(int i = 1;i <= k;++i) {
			int lca = LCA(p,a[i]);
			if(lca != a[i] && f[a[i]][0] != lca) ok = 1;
		}
		puts(!ok ? "YES" : "NO");
	}
	return 0;
}