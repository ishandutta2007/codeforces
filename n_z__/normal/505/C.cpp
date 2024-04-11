#include<bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
int o[40001],dp[40001][600];
int dfs(int s,int l)
{
	if(dp[s][l]!=-1)return dp[s][l];
	int ans=0;
	for(int i=-1;i<=1;i++)if(s+i+l<=30001&&i+l>0)ans=max(ans,dfs(s+i+l,l+i));
	dp[s][l]=ans+o[s];
	return dp[s][l];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin>>n>>k;
	for(int x=1,y;x<=n;x++)cin>>y,o[y]++;
	cout<<dfs(k,k);
}//