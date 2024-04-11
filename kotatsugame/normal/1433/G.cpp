#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,K;
int A[1000],B[1000];
int U[1000],V[1000];
vector<pair<int,int> >G[1000];
vector<int>dijkstra(int st)
{
	vector<int>res(N,(int)1e9);
	res[st]=0;
	priority_queue<pair<int,int> >P;
	P.push(make_pair(0,st));
	while(!P.empty())
	{
		int cost=-P.top().first;
		int u=P.top().second;
		P.pop();
		if(res[u]<cost)continue;
		for(pair<int,int>e:G[u])
		{
			int v=e.first;
			if(res[v]>res[u]+e.second)
			{
				res[v]=res[u]+e.second;
				P.push(make_pair(-res[v],v));
			}
		}
	}
	return res;
}
main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++)
	{
		int W;
		scanf("%d%d%d",&U[i],&V[i],&W);
		U[i]--,V[i]--;
		G[U[i]].push_back(make_pair(V[i],W));
		G[V[i]].push_back(make_pair(U[i],W));
	}
	vector<vector<int> >dist(N);
	for(int i=0;i<N;i++)
	{
		dist[i]=dijkstra(i);
	}
	long long ans=0;
	for(int i=0;i<K;i++)
	{
		scanf("%d%d",&A[i],&B[i]);
		A[i]--,B[i]--;
		ans+=dist[A[i]][B[i]];
	}
	for(int i=0;i<M;i++)
	{
		long long now=0;
		for(int j=0;j<K;j++)
		{
			now+=min(dist[A[j]][B[j]],
				min(dist[A[j]][U[i]]+dist[V[i]][B[j]],dist[A[j]][V[i]]+dist[U[i]][B[j]]));
		}
		ans=min(ans,now);
	}
	printf("%lld\n",ans);
}