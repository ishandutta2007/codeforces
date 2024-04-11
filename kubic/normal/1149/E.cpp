#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define pb push_back
int n,m,a[N],vs[N],bl[N],mx[N],w[N];vector<int> e[N];
void dfs(int u)
{
	if(bl[u]) return;for(auto v:e[u]) dfs(v);
	for(auto v:e[u]) vs[bl[v]]=u;bl[u]=1;while(vs[bl[u]]==u) ++bl[u];
}
void slv(int x)
{
	int u;puts("WIN");
	for(int i=1;i<=n;++i) if(bl[i]==x && (a[i]^w[x])<a[i])
	{u=i;a[i]^=w[x];w[x]=0;break;}
	for(auto v:e[u]) if(w[bl[v]]) a[v]^=w[bl[v]],w[bl[v]]=0;
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
}
int main()
{
	scanf("%d %d",&n,&m);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,u,v;i<=m;++i) scanf("%d %d",&u,&v),e[u].pb(v);
	for(int i=1;i<=n;++i) if(!bl[i]) dfs(i);
	for(int i=1;i<=n;++i) w[bl[i]]^=a[i];
	for(int i=n;i;--i) if(w[i]) {slv(i);return 0;}puts("LOSE");return 0;
}