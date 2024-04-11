#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
pair<int,int>diameter_dfs(const vector<vector<int> >&G,int u,int p)
{
	pair<int,int>ans(0,u);
	for(const int v:G[u])
	{
		if(v!=p)
		{
			pair<int,int>q=diameter_dfs(G,v,u);
			q.first+=1;
			ans=max(ans,q);
		}
	}
	return ans;
}
int diameter(const vector<vector<int> >&G)
{
	pair<int,int>p=diameter_dfs(G,0,-1);
	pair<int,int>q=diameter_dfs(G,p.second,-1);
	return q.first;
}
int T,N,a,b,da,db;
int dist[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d%d%d",&N,&a,&b,&da,&db);
		a--,b--;
		vector<vector<int> >G(N);
		for(int i=1;i<N;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int diam=diameter(G);
		for(int i=0;i<N;i++)dist[i]=1e9;
		queue<int>P;
		P.push(a);
		dist[a]=0;
		while(!P.empty())
		{
			int u=P.front();P.pop();
			for(int v:G[u])
			{
				if(dist[v]>dist[u]+1)
				{
					dist[v]=dist[u]+1;
					P.push(v);
				}
			}
		}
		puts(dist[b]<=da||2*da>=diam||2*da>=db?"Alice":"Bob");
	}
}