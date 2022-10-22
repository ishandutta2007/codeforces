#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dep[100010],a[100010];vector<int> e[100010];
void dfs(int x,int f)
{
	int s=0;
	for (auto g:e[x]) if (g!=f)
	{
		dep[g]=dep[x]+1;dfs(g,x);s+=(dep[g]%2)*2-1;
	}
	if (f) a[x]=(dep[x]%2)*2-1-s;
	else a[x]=-s;
}
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i;cin>>n;
		for (i=1;i<=n;i++) e[i].clear();
		for (i=1;i<n;i++)
		{
			int u,v;cin>>u>>v;
			e[u].push_back(v);e[v].push_back(u);
		}
		dfs(1,0);
		for (i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
	}
}