#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int N;
vector<pair<int,int> >G[3030];
int U[3030],V[3030];
int dfs(int u,int p)
{
	int c=1;
	for(pair<int,int>e:G[u])if(e.first!=p)
	{
		c+=dfs(e.first,u);
	}
	return c;
}
long long dp[3030][3030];
int up[3030][3030];
int vp[3030][3030];
bool vis[3030][3030];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		scanf("%d%d",&U[i],&V[i]);
		U[i]--,V[i]--;
		G[U[i]].push_back(make_pair(V[i],0));
		G[V[i]].push_back(make_pair(U[i],0));
	}
	queue<pair<int,int> >P;
	for(int i=0;i<N;i++)for(pair<int,int>&e:G[i])
	{
		int c=dfs(e.first,i);
		e.second=c;
		P.push(make_pair(i,e.first));
		dp[i][e.first]=c*(N-c);
		up[i][e.first]=e.first;
		vp[i][e.first]=i;
		vis[i][e.first]=true;
	}
	long long ans=0;
	while(!P.empty())
	{
		int u=P.front().first;
		int v=P.front().second;
		long long tdp=dp[u][v];
		P.pop();
		if(ans<tdp)ans=tdp;
		int chu,chv;
		for(pair<int,int>e:G[u])if(e.first==up[u][v])chu=N-e.second;
		for(pair<int,int>e:G[v])if(e.first==vp[u][v])chv=N-e.second;
		for(pair<int,int>e:G[u])if(e.first!=up[u][v])
		{
			int r=e.first;
			long long t=tdp+e.second*chv;
			if(dp[r][v]<t)
			{
				dp[r][v]=t;
				if(!vis[r][v])
				{
					vis[r][v]=true;
					up[r][v]=u;
					vp[r][v]=vp[u][v];
					P.push(make_pair(r,v));
				}
			}
		}
		for(pair<int,int>e:G[v])if(e.first!=vp[u][v])
		{
			int r=e.first;
			long long t=tdp+chu*e.second;
			if(dp[u][r]<t)
			{
				dp[u][r]=t;
				if(!vis[u][r])
				{
					vis[u][r]=true;
					up[u][r]=up[u][v];
					vp[u][r]=v;
					P.push(make_pair(u,r));
				}
			}
		}
	}
	printf("%lld\n",ans);
}