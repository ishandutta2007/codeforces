#include<cstdio>
#include<vector>
using namespace std;
int T,N;
vector<int>G[1<<17];
int ch[1<<17];
vector<int>center;
void dfs(int u,int p)
{
	int nch=1;
	bool isc=true;
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		nch+=ch[v];
		if(ch[v]>N/2)isc=false;
	}
	ch[u]=nch;
	if(N-nch>N/2)isc=false;
	if(isc)center.push_back(u);
}
pair<int,int>dfs2(int u,int p)
{
	pair<int,int>ans=make_pair(p,u);
	for(int v:G[u])if(v!=p)
	{
		ans=dfs2(v,u);
		break;
	}
	return ans;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)G[i].clear();
		center.clear();
		for(int i=1;i<N;i++)
		{
			int a,b;scanf("%d%d",&a,&b);
			a--,b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(0,-1);
		if(center.size()==1)
		{
			int u=0,v=G[0][0];
			printf("%d %d\n",u+1,v+1);
			printf("%d %d\n",u+1,v+1);
		}
		else
		{
			int u=center[0],v=center[1];
			pair<int,int>e=dfs2(v,u);
			printf("%d %d\n",e.first+1,e.second+1);
			printf("%d %d\n",u+1,e.second+1);
		}
	}
}