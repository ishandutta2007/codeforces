#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,rt,mn,mx,dg[N],dep[N];bool vs[2],lf[N];vector<int> e[N];
void dfs(int u,int f)
{
	int cnt=0;lf[u]=1;dep[u]=dep[f]+1;
	for(int i=0,v;i<e[u].size();++i)
	{
		v=e[u][i];
		if(v!=f) lf[u]=0,dfs(v,u),cnt+=lf[v];
	}if(cnt) mx-=cnt-1;
}
int main()
{
	scanf("%d",&n);mn=1;mx=n-1;
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);e[v].push_back(u);
		++dg[u];++dg[v];
	}for(int i=1;i<=n;++i) if(dg[i]>dg[rt]) rt=i;dfs(rt,0);
	for(int i=1;i<=n;++i) if(lf[i]) vs[dep[i]&1]=1;
	if(vs[0] && vs[1]) mn=3;printf("%d %d\n",mn,mx);return 0;
}