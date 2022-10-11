#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[100005],dp[505][505][2];
int solve(int l,int r,bool keep)
{
	if (l>=r)
	return !keep;
	if (dp[l][r][keep]!=-1)
	return dp[l][r][keep];
	int ans=(1<<30);
	for (int x=l;x<r;x++)
	{
		if (!keep)
		ans=min(ans,solve(l,x,0)+solve(x+1,r,0));
		else
		ans=min(ans,min(solve(l,x,0)+solve(x+1,r,1),solve(l,x,1)+solve(x+1,r,0)));
	}
	if (!keep)
	ans=min(ans,solve(l,r,1)+1);
	if (arr[l]==arr[r])
	{
		if (keep)
		ans=min(ans,solve(l+1,r-1,1));
		else
		ans=min(ans,solve(l+1,r-1,0));
	}
	return dp[l][r][keep]=ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(0,n-1,0));
}