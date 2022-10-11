#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[200005];
bool vis[200005];
int scc[100005],cur;
stack<int> st;
void dfs(int node)
{
	vis[node]=1;
	for (int u:v[node])
	{
		if (!vis[u])
		dfs(u);
	}
	st.push(node);
}
void dfs2(int node)
{
	vis[node]=1;
	scc[node]=cur;
	for (int u:v[node])
	{
		if (!vis[u])
		dfs2(u);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (c)
		{
			v[a].push_back(b);
			v[b].push_back(a);
			v[a+n].push_back(b+n);
			v[b+n].push_back(a+n);
		}
		else
		{
			v[a].push_back(b+n);
			v[b].push_back(a+n);
			v[a+n].push_back(b);
			v[b+n].push_back(a);
		}
	}
	for (int i=1;i<=2*n;i++)
	{
		if (!vis[i])
		dfs(i);
	}
	vector<int> ans;
	memset(vis,0,sizeof(vis));
	while (!st.empty())
	{
		if (!vis[st.top()])
		{
			dfs2(st.top());
			cur++;
		}
		if (st.top()>n && !vis[st.top()-n])
		ans.push_back(st.top()-n);
		st.pop();
	}
	for (int i=1;i<=n;i++)
	{
		if (scc[i]==scc[i+n])
		{
			printf("Impossible");
			return 0;
		}
	}
	printf("%d\n",ans.size());
	for (int i:ans)
	printf("%d ",i);
}