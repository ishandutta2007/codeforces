#include <bits/stdc++.h>
using namespace std;
int n,m,dp[105][105];
vector<int> v[105];
int solve(int l,int r)
{
	if (r<l)
	return 0;
	if (dp[l][r]!=-1)
	return dp[l][r];
	int cum[m+2]={0};
	for (int i=1;i<=n;i++)
	{
		int a=*lower_bound(v[i].begin(),v[i].end(),l),b=*(upper_bound(v[i].begin(),v[i].end(),r+1)-1);
		if (a<b)
		{
			cum[a]++;
			cum[b]--;
		}
	}
	for (int i=1;i<=m;i++)
	cum[i]+=cum[i-1];
	int ans=0;
	for (int i=l;i<=r;i++)
	ans=max(ans,solve(l,i-1)+solve(i+1,r)+cum[i]*cum[i]);
	return dp[l][r]=ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		while (k--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			v[i].push_back(l);
		}
		v[i].push_back(m+1);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(1,m));
}