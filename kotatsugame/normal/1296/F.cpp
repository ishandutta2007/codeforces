#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<pair<int,int> >G[5050];
int ans[5050];
int pr[13][5050];
int pe[5050];
int dep[5050];
void dfs(int u,int p,int d,int eid)
{
	pe[u]=eid;
	dep[u]=d;
	pr[0][u]=p;
	for(pair<int,int>e:G[u])if(e.first!=p)dfs(e.first,u,d+1,e.second);
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	for(int k=0;k<13;k++)if(dep[v]-dep[u]>>k&1)v=pr[k][v];
	if(u==v)return u;
	for(int k=13;k--;)if(pr[k][u]!=pr[k][v])u=pr[k][u],v=pr[k][v];
	return pr[0][u];
}
void mk(int u,int to,int f)
{
	if(u==to)return;
	if(ans[pe[u]]<f)ans[pe[u]]=f;
	mk(pr[0][u],to,f);
}
int ch(int u,int to)
{
	if(u==to)return 1000000;
	return min(ans[pe[u]],ch(pr[0][u],to));
}
int Qa[5050],Qb[5050],Qf[5050];
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(make_pair(v,i-1));
		G[v].push_back(make_pair(u,i-1));
	}
	dfs(0,-1,0,-1);
	for(int k=1;k<13;k++)for(int i=0;i<N;i++)
	{
		if(pr[k-1][i]==-1)pr[k][i]=-1;
		else pr[k][i]=pr[k-1][pr[k-1][i]];
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int a,b,f;
		scanf("%d%d%d",&a,&b,&f);
		a--,b--;
		Qa[i]=a,Qb[i]=b,Qf[i]=f;
		int c=lca(a,b);
		mk(a,c,f);
		mk(b,c,f);
	}
	for(int i=0;i<N-1;i++)if(ans[i]==0)ans[i]=1000000;
	for(int i=0;i<M;i++)
	{
		int c=lca(Qa[i],Qb[i]);
		int t=min(ch(Qa[i],c),ch(Qb[i],c));
		if(t!=Qf[i])
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=0;i<N-1;i++)printf("%d%c",ans[i],i+2==N?10:32);
}