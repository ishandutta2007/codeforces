#include<cstdio>
#include<bitset>
using namespace std;
int A,B,M;
using bit=bitset<1000>;
bit OK[2000];
pair<int,int>G[2000][1000];
int ans[1<<17];
int mx=0;
void dfs(int u,int ei,int p,int c,int d)
{
	G[u][d].first=-1;
	if(G[u][c].first!=-1)
	{
		dfs(G[u][c].first,G[u][c].second,u,d,c);
		G[u][d]=G[u][c];
	}
	ans[ei]=c;
	G[u][c]=make_pair(p,ei);
}
int U[1<<17],V[1<<17];
int cnt[2000];
main()
{
	scanf("%d%d%d",&A,&B,&M);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;v+=A;
		U[i]=u;V[i]=v;
		cnt[u]++;cnt[v]++;
	}
	int mx=0;
	for(int i=0;i<A+B;i++)if(mx<cnt[i])mx=cnt[i];
	for(int i=0;i<A+B;i++)for(int j=0;j<mx;j++)G[i][j].first=-1;
	for(int i=0;i<M;i++)
	{
		int u=U[i],v=V[i];
		int col=-1,c1=-1,c2=-1;
		for(int i=0;i<mx;i++)
		{
			if(G[u][i].first<0)
			{
				if(G[v][i].first<0)
				{
					col=i;
					break;
				}
				else c2=i;
			}
			else if(G[v][i].first<0)
			{
				c1=i;
			}
		}
		if(col!=-1)
		{
			ans[i]=col;
			G[u][col]=make_pair(v,i);
			G[v][col]=make_pair(u,i);
			continue;
		}
		dfs(v,i,u,c2,c1);
		G[u][c2]=make_pair(v,i);
	}
	printf("%d\n",mx);
	for(int i=0;i<M;i++)printf("%d%c",ans[i]+1,i+1==M?10:32);
}