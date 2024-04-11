#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
bool vis[100005];
int arr[100005];
int dfs(int node)
{
	if (vis[node])
	return arr[node];
	vis[node]=1;
	int ans=arr[node];
	for (int i=0;i<v[node].size();i++)
	ans=min(ans,dfs(v[node][i]));
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		ans+=dfs(i);
	}
	printf("%I64d",ans);
}