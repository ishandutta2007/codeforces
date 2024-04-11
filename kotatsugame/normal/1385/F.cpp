#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int T,N,K;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		vector<vector<int> >G(N);
		for(int i=0;i<N-1;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(K==1)
		{
			printf("%d\n",N-1);
			continue;
		}
		int ans=0;
		queue<int>Q;
		vector<int>rdeg(N);
		vector<int>deg(N);
		for(int i=0;i<N;i++)
		{
			for(int v:G[i])if(G[v].size()==1)rdeg[i]++;
			if(rdeg[i]>=K)Q.push(i);
			deg[i]=G[i].size();
		}
		while(!Q.empty())
		{
			int u=Q.front();Q.pop();
			ans++;
			rdeg[u]-=K;
			deg[u]-=K;
			if(rdeg[u]>=K)Q.push(u);
			else if(deg[u]==1&&rdeg[u]==0)
			{
				for(int v:G[u])
				{
					rdeg[v]++;
					if(rdeg[v]==K)Q.push(v);
				}
			}
		}
		printf("%d\n",ans);
	}
}