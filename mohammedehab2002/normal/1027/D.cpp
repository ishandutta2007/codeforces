#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[200005],rev[200005],scc;
bool vis[200005],in[200005];
int arr[200005];
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
	scc.push_back(node);
	for (int u:rev[node])
	{
		if (!vis[u])
		dfs2(u);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		v[i].push_back(a);
		rev[a].push_back(i);
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		dfs(i);
	}
	long long ans=0;
	memset(vis,0,sizeof(vis));
	while (!st.empty())
	{
		int node=st.top();
		st.pop();
		if (!vis[node])
		{
			scc.clear();
			dfs2(node);
			for (int i:scc)
			in[i]=1;
			bool ok=1;
			for (int i:scc)
			{
				for (int u:v[i])
				{
					if (!in[u])
					ok=0;
				}
			}
			if (ok)
			{
				int mn=(1<<30);
				for (int i:scc)
				mn=min(mn,arr[i]);
				ans+=mn;
			}
			for (int i:scc)
			in[i]=0;
		}
	}
	printf("%I64d",ans);
}