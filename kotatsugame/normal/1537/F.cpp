#include<cstdio>
#include<vector>
using namespace std;
int T,N,M;
vector<vector<int> >G;
long long A[2<<17],B[2<<17];
int vis[2<<17];
long long X=0;
long long dfs(int u,int c)
{
	vis[u]=c;
	X+=A[u]*c;
	for(int v:G[u])
	{
		if(vis[v]==0)
		{
			if(dfs(v,-c))return true;
		}
		else if(vis[v]!=-c)return true;
	}
	return false;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		G=vector<vector<int> >(N);
		for(int i=0;i<N;i++)scanf("%lld",&A[i]);
		for(int i=0;i<N;i++)scanf("%lld",&B[i]);
		for(int i=0;i<M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int flag=0;
		for(int i=0;i<N;i++)
		{
			vis[i]=0;
			A[i]=B[i]-A[i];
			flag+=A[i]%2;
		}
		if(flag%2!=0)puts("NO");
		else
		{
			X=0;
			if(dfs(0,1))puts("YES");
			else puts(X==0?"YES":"NO");
		}
	}
}