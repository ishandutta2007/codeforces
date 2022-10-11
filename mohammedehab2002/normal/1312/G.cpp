#include <bits/stdc++.h>
using namespace std;
int cnt[1000005],dp[1000005],sp[1000005],ans[1000005];
vector<pair<char,int> > v[1000005];
int pre(int node)
{
	cnt[node]=min(sp[node],1);
	for (auto u:v[node])
	cnt[node]+=pre(u.second);
	return cnt[node];
}
void dfs(int node,int var)
{
	int tot=min(sp[node],1);
	if (sp[node])
	{
		dp[node]=min(dp[node],var+1);
		ans[sp[node]]=dp[node];
	}
	for (auto u:v[node])
	{
		dp[u.second]=min(dp[u.second],dp[node]+1);
		dfs(u.second,min(var,dp[node])+tot);
		tot+=cnt[u.second];
	}
}
int main()
{
	int n,k;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		int p;
		char c;
		cin >> p >> c;
		v[p].push_back({c,i});
		dp[i]=1e9;
	}
	for (int i=0;i<=n;i++)
	sort(v[i].begin(),v[i].end());
	cin >> k;
	for (int i=1;i<=k;i++)
	{
		int a;
		cin >> a;
		sp[a]=i;
	}
	pre(0);
	dfs(0,1e9);
	for (int i=1;i<=k;i++)
	printf("%d ",ans[i]);
}