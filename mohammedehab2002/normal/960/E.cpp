#include <iostream>
#include <vector>
using namespace std;
long long mod=1000000007;
int n,cnt[200005][2],out[200005][2],dp[200005][2];
vector<int> v[200005];
void pre(int node,int pnode)
{
	cnt[node][0]=1;
	for (int u:v[node])
	{
		if (u!=pnode)
		{
			pre(u,node);
			cnt[node][0]+=cnt[u][1];
			cnt[node][1]+=cnt[u][0];
		}
	}
	for (int u:v[node])
	{
		if (u!=pnode)
		{
			out[u][0]=cnt[node][1]-cnt[u][0];
			out[u][1]=cnt[node][0]-cnt[u][1];
		}
	}
}
void pre2(int node,int pnode)
{
	for (int u:v[node])
	{
		if (u!=pnode)
		{
			dp[u][0]=out[u][0]+dp[node][1];
			dp[u][1]=out[u][1]+dp[node][0];
			pre2(u,node);
		}
	}
}
long long m(long long x)
{
	if (x<0)
	x+=5LL*mod*mod;
	return x%mod;
}
long long ans=0,arr[200005];
void dfs(int node,int pnode)
{
	int sz=cnt[node][0]+cnt[node][1];
	ans=m(ans+arr[node]*(dp[node][0]-dp[node][1]+1)*sz);
	ans=m(ans+arr[node]*(cnt[node][0]-cnt[node][1])*(n-sz+1));
	for (int u:v[node])
	{
		if (u!=pnode)
		{
			ans=m(ans+arr[node]*(cnt[u][1]-cnt[u][0])*(sz-(cnt[u][0]+cnt[u][1])-1));
			dfs(u,node);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%I64d",&arr[i]);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	pre(1,0);
	pre2(1,0);
	dfs(1,0);
	for (int i=1;i<=n;i++)
	ans=m(ans-arr[i]);
	printf("%I64d",ans);
}