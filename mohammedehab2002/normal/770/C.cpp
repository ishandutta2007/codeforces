#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[100005],rev[100005];
int arr[100005],scc[100005],sz[100005],cur;
bool vis[100005],must[100005];
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
	sz[cur]++;
	for (int u:rev[node])
	{
		if (!vis[u])
		dfs2(u);
	}
}
void dfs3(int node)
{
	must[node]=1;
	for (int u:rev[node])
	{
		if (!must[u])
		dfs3(u);
	}
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<k;i++)
	scanf("%d",&arr[i]);
	for (int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		while (t--)
		{
			int a;
			scanf("%d",&a);
			v[a].push_back(i);
			rev[i].push_back(a);
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		dfs(i);
	}
	memset(vis,0,sizeof(vis));
	while (!st.empty())
	{
		if (!vis[st.top()])
		{
			dfs2(st.top());
			cur++;
		}
		st.pop();
	}
	for (int i=0;i<k;i++)
	dfs3(arr[i]);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (must[i])
		{
			if (sz[scc[i]]>1)
			{
				printf("-1");
				return 0;
			}
			ans++;
		}
	}
	printf("%d\n",ans);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		dfs(i);
	}
	while (!st.empty())
	{
		if (must[st.top()])
		printf("%d ",st.top());
		st.pop();
	}
}