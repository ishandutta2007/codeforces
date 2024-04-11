#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
#define mod 1000000007
vector<int> v[100005],rev[100005];
int arr[100005],mn,c;
bool vis[100005];
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
	if (arr[node]<mn)
	{
		mn=arr[node];
		c=1;
	}
	else if (arr[node]==mn)
	c++;
	for (int u:rev[node])
	{
		if (!vis[u])
		dfs2(u);
	}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	scanf("%d",&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		rev[b].push_back(a);
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		dfs(i);
	}
	memset(vis,0,sizeof(vis));
	long long ans=0,cnt=1;
	while (!st.empty())
	{
		int node=st.top();
		st.pop();
		if (!vis[node])
		{
			mn=(1<<30);
			dfs2(node);
			ans+=mn;
			cnt=(cnt*c)%mod;
		}
	}
	printf("%I64d %I64d",ans,cnt);
}