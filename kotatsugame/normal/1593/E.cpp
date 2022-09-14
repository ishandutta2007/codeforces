#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int T,N,K;
vector<int>G[4<<17];
int deg[4<<17];
int dist[4<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;scanf("%d%d",&u,&v);u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		queue<int>P;
		for(int i=0;i<N;i++)
		{
			dist[i]=1e9;
			deg[i]=G[i].size();
			if(deg[i]<=1)
			{
				dist[i]=0;
				P.push(i);
			}
		}
		while(!P.empty())
		{
			int u=P.front();P.pop();
			for(int v:G[u])if(--deg[v]==1)
			{
				dist[v]=dist[u]+1;
				P.push(v);
			}
		}
		int ans=0;
		for(int i=0;i<N;i++)if(dist[i]>=K)ans++;
		printf("%d\n",ans);
	}
}