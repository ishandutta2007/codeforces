#include <bits/stdc++.h>
using namespace std;
bool vis[100005][130];
long long dp[100005][130];
int n,p,k,a[100005],o[100005],mat[100005][10];
bool cmp(int i,int j)
{
	return a[i]>a[j];
}
long long solve(int idx,int mask)
{
	if (idx==n)
	{
		if (mask==(1<<p)-1)
		return 0;
		return -1e18;
	}
	if (vis[idx][mask])
	return dp[idx][mask];
	vis[idx][mask]=1;
	int cnt=__builtin_popcount(mask);
	long long ans=solve(idx+1,mask);
	if (idx-cnt<k)
	ans+=a[o[idx]];
	for (int i=0;i<p;i++)
	{
		if (!(mask&(1<<i)))
		ans=max(ans,solve(idx+1,(mask|(1<<i)))+mat[o[idx]][i]);
	}
	return dp[idx][mask]=ans;
}
int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		o[i]=i;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<p;j++)
		scanf("%d",&mat[i][j]);
	}
	sort(o,o+n,cmp);
	printf("%I64d",solve(0,0));
}