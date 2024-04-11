#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int dp[3005][3005],dp2[3005][3005];
string a,b;
int solve2(int x,int y)
{
	if (y==b.size())
	return (int)a.size()-x+1;
	if (x==a.size())
	return 0;
	if (dp2[x][y]!=-1)
	return dp2[x][y];
	return dp2[x][y]=((solve2(x+1,y)+((y<b.size() && a[x]==b[b.size()-y-1])? solve2(x+1,y+1):0))%mod);
}
int solve(int l,int r)
{
	int idx=r-l+1;
	if (r==b.size()-1)
	return solve2(idx,idx);
	if (dp[l][r]!=-1)
	return dp[l][r];
	return dp[l][r]=((((l && a[idx]==b[l-1])? solve(l-1,r):0)+((a[idx]==b[r+1])? solve(l,r+1):0))%mod);
}
int main()
{
	cin >> a >> b;
	int ans=0,pw=1;
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	for (int i=0;i<b.size();i++)
	{
		if (b[i]==a[0])
		ans=(ans+2LL*solve(i,i))%mod;
	}
	for (int i=1;i<a.size();i++)
	{
		pw=(2*pw)%mod;
		if (a[i]==b[b.size()-1])
		ans=(ans+1LL*pw*solve2(i+1,1))%mod;
	}
	cout << ans;
}