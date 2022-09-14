#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,Q;
vector<int>G[2<<17];
vector<int>vs;
int L[2<<17],R[2<<17];
void dfs(int u)
{
	L[u]=vs.size();
	vs.push_back(u);
	for(int v:G[u])dfs(v);
	R[u]=vs.size();
}
main()
{
	scanf("%d%d",&N,&Q);
	for(int i=1;i<N;i++)
	{
		int p;
		scanf("%d",&p);
		p--;
		G[p].push_back(i);
	}
	dfs(0);
	for(;Q--;)
	{
		int u,k;
		scanf("%d%d",&u,&k);
		u--;
		k--;
		int id=L[u]+k;
		printf("%d\n",id<R[u]?vs[id]+1:-1);
	}
}