#include<iostream>
#include<vector>
using namespace std;
int n,c[10101],ans;
vector<int>G[10101];
void dfs(int u,int col)
{
	ans+=c[u]!=col;
	for(int i=0;i<G[u].size();i++)dfs(G[u][i],c[u]);
}
main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a;cin>>a;a--;
		G[a].push_back(i);
	}
	for(int i=0;i<n;i++)cin>>c[i];
	dfs(0,0);
	cout<<ans<<endl;
}