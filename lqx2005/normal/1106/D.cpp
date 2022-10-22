#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
int n,m;
vector<int> g[N+5];
vector<int> ans;
bool vis[N+5];
void bfs()
{
	priority_queue<int,vector<int>,greater<int> > q;
	q.push(1);
	ans.push_back(1);
	vis[1]=1;
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		ans.push_back(u);
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(vis[v]) continue;
			vis[v]=1;
			q.push(v);
		}
	}
	return;
}
int main()
{
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}