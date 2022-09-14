#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
vector<pair<int,int> >G[2<<17];
int ans[2<<17];
int R;
void dfs(int u,int p,int col)
{
	int nxt=0;
	for(pair<int,int>e:G[u])if(e.first!=p)
	{
		if(nxt==col)nxt++;
		if(nxt>=R)nxt=R-1;
		ans[e.second]=nxt;
		dfs(e.first,u,nxt);
		nxt++;
	}
}
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N-1;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		G[u].push_back(make_pair(v,i));
		G[v].push_back(make_pair(u,i));
	}
	vector<int>vs(N);
	for(int i=0;i<N;i++)vs[i]=i;
	sort(vs.begin(),vs.end(),[](int i,int j){return G[i].size()>G[j].size();});
	R=G[vs[K]].size();
	dfs(0,-1,-1);
	printf("%d\n",R);
	for(int i=0;i<N-1;i++)printf("%d%c",ans[i]+1,i+2==N?10:32);
}