#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N,M;
vector<pair<int,int> >G[2<<17];
vector<long long>dijkstra(vector<long long>d)
{
	priority_queue<pair<long long,int> >P;
	for(int i=0;i<N;i++)if(d[i]<(long long)1e18)P.push(make_pair(-d[i],i));
	while(!P.empty())
	{
		long long cost=-P.top().first;
		int u=P.top().second;
		P.pop();
		if(d[u]<cost)continue;
		for(pair<int,int>e:G[u])
		{
			int v=e.first;
			if(d[v]>cost+e.second)
			{
				d[v]=cost+e.second;
				P.push(make_pair(-d[v],v));
			}
		}
	}
	return d;
}
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		u--,v--;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	vector<long long>d(N,(long long)1e18);
	d[0]=0;
	d=dijkstra(d);
	vector<long long>E(N,(long long)1e18),F(N,(long long)1e18);
	for(int u=0;u<N;u++)
	{
		for(pair<int,int>e:G[u])
		{
			int v=e.first;
			E[v]=min(E[v],d[u]+e.second*2);
			F[v]=min(F[v],d[u]);
		}
	}
	E=dijkstra(E);
	F=dijkstra(F);
	vector<long long>EE(N,(long long)1e18),FF(N,(long long)1e18);
	for(int u=0;u<N;u++)
	{
		for(pair<int,int>e:G[u])
		{
			int v=e.first;
			EE[v]=min(EE[v],E[u]);
			FF[v]=min(FF[v],F[u]+e.second*2);
		}
	}
	EE=dijkstra(EE);
	FF=dijkstra(FF);
	for(int i=1;i<N;i++)printf("%lld%c",min(d[i],min(EE[i],FF[i])),i+1==N?10:32);
}