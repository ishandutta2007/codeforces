#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N,M;
vector<int>G[2<<17];
bool vis[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=0;
	for(int i=0;i<N;i++)if(!vis[i])
	{
		bool ok=true;
		vis[i]=true;
		queue<int>P;
		P.push(i);
		while(!P.empty())
		{
			int u=P.front();
			P.pop();
			if(G[u].size()!=2)ok=false;
			for(int v:G[u])if(!vis[v])
			{
				vis[v]=true;
				P.push(v);
			}
		}
		if(ok)ans++;
	}
	printf("%d\n",ans);
}