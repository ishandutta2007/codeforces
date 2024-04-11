#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[1005];
int pos[5][1005],dp[1005];
bool vis[1005];
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
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<k;i++)
	{
		for (int x=1;x<=n;x++)
		{
			int a;
			scanf("%d",&a);
			pos[i][a]=x;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			bool ok=1;
			for (int x=0;x<k;x++)
			ok&=(pos[x][i]<pos[x][j]);
			if (ok)
			v[i].push_back(j);
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		dfs(i);
	}
	int ans=0;
	while (!st.empty())
	{
		int node=st.top();
		st.pop();
		dp[node]++;
		for (int u:v[node])
		dp[u]=max(dp[u],dp[node]);
		ans=max(ans,dp[node]);
	}
	printf("%d",ans);
}