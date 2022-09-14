#include<cstdio>
#include<vector>
using namespace std;
int T,N;
vector<int>G[2<<17];
int ans;
bool dfs(int u,int p)
{
	int cr=0;
	for(int v:G[u])if(v!=p)
	{
		bool now=dfs(v,u);
		if(now)cr++;
	}
	if(cr==0)return true;
	else
	{
		ans+=cr-1;
		return false;
	}
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans=1;
		dfs(0,-1);
		printf("%d\n",ans);
	}
}