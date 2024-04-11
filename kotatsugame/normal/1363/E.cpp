#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int>G[2<<17];
int A[2<<17],B[2<<17];
long long ans;
int C[2<<17];
void pre(int u,int p)
{
	C[u]=B[u];
	for(int v:G[u])if(v!=p)
	{
		pre(v,u);
		C[u]+=C[v];
	}
}
void dfs(int u,int p,int ca)
{
	if(A[u]>ca)A[u]=ca;
	long long cnt=0;
	if(B[u]!=0)cnt++;
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u,A[u]);
		if(C[v]>0)cnt+=C[v];
		else cnt-=C[v];
	}
	cnt-=abs(C[u]);
	ans+=cnt*A[u];
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int u,v;
		scanf("%d%d%d",&A[i],&u,&v);
		if(u!=v)
		{
			if(u==1)B[i]=1;
			else B[i]=-1;
		}
	}
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	pre(0,-1);
	if(C[0]!=0)
	{
		puts("-1");
		return 0;
	}
	dfs(0,-1,(int)2e9);
	printf("%lld\n",ans);
}