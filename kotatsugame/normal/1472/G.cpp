#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int T,N,M;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		vector<vector<int> >G(N);
		for(int i=0;i<M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
		}
		vector<int>dist(N,1e9);
		{
			dist[0]=0;
			queue<int>P;
			P.push(0);
			while(!P.empty())
			{
				int u=P.front();P.pop();
				for(int v:G[u])if(dist[v]>dist[u]+1)
				{
					dist[v]=dist[u]+1;
					P.push(v);
				}
			}
		}
		vector<pair<int,int> >ui(N);
		for(int i=0;i<N;i++)ui[i]=make_pair(-dist[i],i);
		sort(ui.begin(),ui.end());
		vector<int>ans=dist;
		for(int i=0;i<N;i++)
		{
			int u=ui[i].second;
			for(int v:G[u])
			{
				if(dist[v]>dist[u])ans[u]=min(ans[u],ans[v]);
				else ans[u]=min(ans[u],dist[v]);
			}
		}
		for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
	}
}