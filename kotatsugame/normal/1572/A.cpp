#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<vector<int> >G(N);
		vector<int>dist(N,-1),indeg(N,0);
		for(int i=0;i<N;i++)
		{
			int k;scanf("%d",&k);
			indeg[i]=k;
			for(;k--;)
			{
				int a;scanf("%d",&a);
				a--;
				G[a].push_back(i);
			}
		}
		queue<int>P;
		for(int i=0;i<N;i++)if(!indeg[i])P.push(i),dist[i]=1;
		int cnt=0;
		while(!P.empty())
		{
			int u=P.front();P.pop();
			cnt++;
			for(int v:G[u])
			{
				int nd=dist[u];
				if(v<u)nd++;
				if(dist[v]<nd)dist[v]=nd;
				if(!--indeg[v])P.push(v);
			}
		}
		int ans=0;
		for(int i=0;i<N;i++)
		{
			if(ans<dist[i])ans=dist[i];
		}
		printf("%d\n",cnt<N?-1:ans);
	}
}