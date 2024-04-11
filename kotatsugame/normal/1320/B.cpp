#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int N,M,K;
int p[2<<17];
vector<int>G[2<<17],rG[2<<17];
int dist[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[v].push_back(u);
		rG[u].push_back(v);
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d",&p[i]);
		p[i]--;
	}
	for(int i=0;i<N;i++)dist[i]=1e9;
	{
		int goal=p[K-1];
		dist[goal]=0;
		queue<int>P;
		P.push(goal);
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
	}
	int cm=0,cM=0;
	for(int i=0;i+1<K;i++)
	{
		if(dist[p[i]]-1!=dist[p[i+1]])cm++;
		for(int v:rG[p[i]])
		{
			if(v!=p[i+1]&&dist[p[i]]-1==dist[v])
			{
				cM++;
				break;
			}
		}
	}
	printf("%d %d\n",cm,cM);
}