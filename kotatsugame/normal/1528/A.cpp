#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
vector<vector<int> >G;
int L[1<<17],R[1<<17];
pair<long long,long long>dfs(int u,int p)
{
	pair<long long,long long>ret=make_pair(0LL,0LL);
	for(int v:G[u])if(v!=p)
	{
		pair<long long,long long>q=dfs(v,u);
		ret.first+=max(q.first+abs(L[u]-L[v]),q.second+abs(L[u]-R[v]));
		ret.second+=max(q.first+abs(R[u]-L[v]),q.second+abs(R[u]-R[v]));
	}
	return ret;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		G=vector<vector<int> >(N);
		for(int i=0;i<N;i++)scanf("%d%d",&L[i],&R[i]);
		for(int i=1;i<N;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		pair<long long,long long>p=dfs(0,-1);
		printf("%lld\n",max(p.first,p.second));
	}
}