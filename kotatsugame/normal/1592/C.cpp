#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,K;
int A[1<<17];
vector<int>G[1<<17];
int ch[1<<17];
int dfs(int u,int p)
{
	ch[u]=A[u];
	for(int v:G[u])if(v!=p)ch[u]^=dfs(v,u);
	return ch[u];
}
int dfs2(int u,int p,int X)
{
	int cnt=0;
	for(int v:G[u])if(v!=p)
	{
		int now=dfs2(v,u,X);
		if(now==2)return 2;
		else if(now==1)
		{
			cnt++;
			if(cnt>=2)return 2;
		}
	}
	if(cnt>=1&&ch[u]==0)return 2;
	if(ch[u]==X||cnt>=1)return 1;
	return 0;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(0,-1);
		if(ch[0]==0)
		{
			puts("YES");
		}
		else if(K==2)
		{
			puts("NO");
		}
		else
		{
			int X=ch[0];
			int t=dfs2(0,-1,X);
			puts(t==2?"YES":"NO");
		}
	}
}