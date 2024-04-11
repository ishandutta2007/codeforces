#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int>G[2<<17];
int cnt[2];
void dfs(int u,int p,int c)
{
	cnt[c]++;
	for(int v:G[u])
	{
		if(v!=p)
		{
			dfs(v,u,1-c);
		}
	}
}
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1,0);
	printf("%d\n",min(cnt[0],cnt[1])-1);
}