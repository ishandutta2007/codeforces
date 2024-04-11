#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v;
int dp[5005][5005];
int solve(int l,int r)
{
	if (l==r)
	return 0;
	if (dp[l][r]!=-1)
	return dp[l][r];
	int ans=min(solve(l+1,r),solve(l,r-1));
	if (v[l]==v[r])
	ans=min(ans,solve(l+1,r-1));
	return dp[l][r]=ans+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		if (v.empty() || v.back()!=a)
		v.push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(0,v.size()-1));
}