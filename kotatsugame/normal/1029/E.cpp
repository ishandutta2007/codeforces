#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int>G[2<<17];
int A[2<<17],B[2<<17],C[2<<17];
void dfs(int u,int p)
{
	A[u]=1;
	int mn=1e6;
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		A[u]+=min(A[v],min(B[v],C[v]));
		int T=min(A[v],B[v]);
		mn=min(mn,A[v]-T);
		B[u]+=T;
		C[u]+=T;
	}
	B[u]+=mn;
}
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=0;
	for(int u:G[0])
	{
		dfs(u,0);
		ans+=A[u]-1;
	}
	printf("%d\n",ans);
}