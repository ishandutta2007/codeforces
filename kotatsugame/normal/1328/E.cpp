#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int>G[2<<17];
int dep[2<<17];
int pr[20][2<<17];
void dfs(int u,int p,int d)
{
	dep[u]=d;
	pr[0][u]=p;
	for(int v:G[u])
	{
		if(v!=p)dfs(v,u,d+1);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int k=0;k<20;k++)
	{
		if(dep[u]-dep[v]>>k&1)u=pr[k][u];
	}
	if(u==v)return u;
	for(int k=20;k--;)
	{
		if(pr[k][u]!=pr[k][v])
		{
			u=pr[k][u];
			v=pr[k][v];
		}
	}
	return pr[0][u];
}
main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1,0);
	for(int k=1;k<20;k++)
	{
		for(int i=0;i<N;i++)
		{
			if(pr[k-1][i]!=-1)pr[k][i]=pr[k-1][pr[k-1][i]];
		}
	}
	for(int i=0;i<M;i++)
	{
		int k;scanf("%d",&k);
		vector<int>id(k);
		for(int j=0;j<k;j++)scanf("%d",&id[j]),id[j]--;
		sort(id.begin(),id.end(),[](const int a,const int b){return dep[a]<dep[b];});
		bool ok=true;
		for(int j=1;j<k;j++)
		{
			int u=id[j-1],v=id[j];
			int w=lca(u,v);
			if(w!=u&&w!=v&&w!=pr[0][u]&&w!=pr[0][v])
			{
				ok=false;
				break;
			}
		}
		puts(ok?"YES":"NO");
	}
}