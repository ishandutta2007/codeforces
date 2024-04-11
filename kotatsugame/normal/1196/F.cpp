#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,K;
vector<pair<int,int> >G[2<<17];
main()
{
	scanf("%d%d%d",&N,&M,&K);
	vector<pair<int,pair<int,int> > >Es(M);
	for(int i=0;i<M;i++)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		u--,v--;
		Es[i]=make_pair(w,make_pair(u,v));
	}
	sort(Es.begin(),Es.end());
	vector<int>vs;
	for(int i=0;i<M&&i<K;i++)
	{
		vs.push_back(Es[i].second.first);
		vs.push_back(Es[i].second.second);
	}
	sort(vs.begin(),vs.end());
	vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=0;i<M&&i<K;i++)
	{
		int u=Es[i].second.first,v=Es[i].second.second;
		int w=Es[i].first;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	vector<long long>ans;
	for(int u:vs)
	{
		vector<long long>dist(N,(long long)1e18);
		dist[u]=0;
		priority_queue<pair<long long,int> >P;
		P.push(make_pair(0,u));
		while(!P.empty())
		{
			int u=P.top().second;
			long long cost=-P.top().first;
			P.pop();
			if(dist[u]<cost)continue;
			for(pair<int,int>e:G[u])
			{
				int v=e.first;
				long long nxt=e.second+cost;
				if(dist[v]>nxt)
				{
					dist[v]=nxt;
					P.push(make_pair(-nxt,v));
				}
			}
		}
		for(int v:vs)if(dist[v]<(long long)1e18&&u<v)ans.push_back(dist[v]);
	}
	sort(ans.begin(),ans.end());
	printf("%lld\n",ans[K-1]);
}