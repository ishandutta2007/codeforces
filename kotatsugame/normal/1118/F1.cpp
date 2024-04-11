#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int> >E;
vector<int>G[3<<17];
int n,ans;
int col[3<<17],dp1[2][3<<17],dp2[3<<17];
int dfs1(int u,int p)
{
	if(col[u]==1)dp1[0][u]++;
	if(col[u]==2)dp1[1][u]++;
	for(int i=0;i<G[u].size();i++)
	{
		if(G[u][i]==p)continue;
		int t=dfs1(G[u][i],u);
		if(t&1)dp1[0][u]++;
		if(t&2)dp1[1][u]++;
	}
	return (dp1[1][u]?2:0)+(dp1[0][u]?1:0);
}
void dfs2(int u,int p,int top)
{
	for(int i=0;i<G[u].size();i++)
	{
		if(G[u][i]==p)continue;
		int n1=!!dp1[0][G[u][i]],n2=!!dp1[1][G[u][i]];
		int t=top|(dp1[1][u]-n2>0?2:0)|(dp1[0][u]-n1>0?1:0);
		int v=n2*2+n1;
		ans+=v!=3&&t!=3;
		dfs2(G[u][i],u,t);
	}
}
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&col[i]);
	for(int i=1;i<n;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		a--,b--;
		E.push_back(make_pair(a,b));
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs1(0,-1);
	dfs2(0,-1,0);
	cout<<ans<<endl;
}