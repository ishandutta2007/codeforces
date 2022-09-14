#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
vector<int>G[2<<17];
int ans;
int dfs(int u,int p)
{
	vector<int>A;
	for(int v:G[u])if(v!=p)
	{
		A.push_back(1+dfs(v,u));
	}
	sort(A.begin(),A.end());
	if(p==-1)
	{
		ans=max(ans,A.back());
		if(A.size()>=2)ans=max(ans,A[A.size()-2]+1);
		return 0;
	}
	if(A.empty())return 0;
	if(A.size()>=2)ans=max(ans,A.back()+1);
	return A[0];
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
		ans=0;
		dfs(0,-1);
		printf("%d\n",ans);
	}
}