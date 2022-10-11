#include <iostream>
#include <vector>
using namespace std;
bool vis[100005];
vector <int> v[100005];
int dfs(int node,int pnode)
{
	if (vis[node])
	return 0;
	vis[node]=true;
	int mn=1;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		mn=min(dfs(v[node][i],node),mn);
	}
	return mn;
}
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans=0;
	for (int i=1;i<n;i++)
	{
		if (vis[i])
		continue;
		ans+=dfs(i,0);
	}
	cout << ans;
}