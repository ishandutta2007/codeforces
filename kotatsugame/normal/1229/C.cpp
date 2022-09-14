#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int N,M;
vector<int>G[1<<17];
long long cnt[1<<17];
long long L[1<<17],R[1<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);u--,v--;
		cnt[u]++;
		cnt[v]++;
		if(u<v)
		{
			G[u].push_back(v);
			L[v]++;
			R[u]++;
		}
		else
		{
			G[v].push_back(u);
			L[u]++;
			R[v]++;
		}
	}
	long long all=0;
	for(int i=0;i<N;i++)
	{
		for(int v:G[i])
		{
			all+=R[v];
		}
	}
	printf("%lld\n",all);
	int Q;scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		int u;scanf("%d",&u);u--;
		all-=L[u]*R[u];
		L[u]=cnt[u];R[u]=0;
		for(int v:G[u])
		{
			all+=--L[v];
			all-=R[v]++;
			G[v].push_back(u);
		}
		G[u].clear();
		printf("%lld\n",all);
	}
}