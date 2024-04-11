#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int>G[3<<17];
int C[3<<17];
bool ok[3<<17];
int ch[3<<17];
int dfs1(int u,int p)
{
	ch[u]=C[u];
	if(C[u])ok[u]=true;
	for(int v:G[u])if(v!=p)
	{
		int t=dfs1(v,u);
		if(t>=2&&ok[v]||C[v])ok[u]=true;
		ch[u]+=t;
	}
	return ch[u];
}
void dfs2(int u,int p,int pc)
{
	if(pc>=2&&ok[p]||C[p])ok[u]=true;
	for(int v:G[u])if(v!=p)
	{
		dfs2(v,u,ch[u]+pc-ch[v]);
	}
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)cin>>C[i];
	for(int i=1;i<N;i++)
	{
		int u,v;cin>>u>>v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(0,-1);
	for(int u:G[0])
	{
		dfs2(u,0,ch[0]-ch[u]);
	}
	for(int i=0;i<N;i++)cout<<(ok[i]?1:0)<<(i+1==N?"\n":" ");
}