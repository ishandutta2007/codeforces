#include <bits/stdc++.h>
using namespace std;
stack<int> s;
bool vis[5005];
vector<int> v[5005];
vector<pair<int,int> > e;
int pos[5005];
void dfs(int node)
{
	vis[node]=1;
	for (int u:v[node])
	{
		if (!vis[u])
		dfs(u);
	}
	s.push(node);
}
int main()
{
	int n,m,cur=0,ans=1;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		e.push_back({a,b});
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		dfs(i);
	}
	while (!s.empty())
	{
		pos[s.top()]=cur++;
		s.pop();
	}
	for (auto p:e)
	{
		if (pos[p.first]>pos[p.second])
		ans=2;
	}
	printf("%d\n",ans);
	for (auto p:e)
	printf("%d ",(pos[p.first]>pos[p.second])+1);
}