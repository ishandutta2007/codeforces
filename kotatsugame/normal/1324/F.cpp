#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int>G[2<<17];
int a[2<<17];
int d1[2<<17];
int dfs(int u,int p)
{
	int cnt=a[u]==1?1:-1;
	for(int v:G[u])
	{
		if(v!=p)
		{
			int t=dfs(v,u);
			if(t>0)cnt+=t;
		}
	}
	d1[u]=cnt;
	return cnt;
}
int d2[2<<17];
void dfs2(int u,int p,int pd)
{
	d2[u]=d1[u]+max(pd,0);
	for(int v:G[u])
	{
		if(v!=p)
		{
			dfs2(v,u,d2[u]-max(d1[v],0));
		}
	}
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	dfs2(0,-1,0);
	for(int i=0;i<N;i++)printf("%d%c",d2[i],i+1==N?'\n':' ');
}