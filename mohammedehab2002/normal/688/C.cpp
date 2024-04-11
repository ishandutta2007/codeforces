#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005],a[2];
int c[100005],vis[100005],b=1;
void dfs(int node,int col)
{
	if (vis[node] && c[node]!=col)
	b=0;
	if (vis[node])
	return;
	c[node]=col;
	vis[node]=1;
	a[col].push_back(node);
	for (int i=0;i<v[node].size();i++)
	dfs(v[node][i],!col);
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
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		dfs(i,0);
	}
	if (!b)
	cout << -1;
	else
	{
		for (int i=0;i<2;i++)
		{
			cout << a[i].size() << endl;
			for (int x=0;x<a[i].size();x++)
			cout << a[i][x] << ' ';
			cout << endl;
		}
	}
}