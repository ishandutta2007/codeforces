#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int k,f[11],q,n;
long long cur,ans,dp[7][1111111];
long long calc(int sum,int f)
{
	if (sum<=(k-1)*9+2) return 1ll*(sum/3)*f;
	if (sum%3==0) return 1ll*(sum/3)*f;
	sum-=(sum%9);
	return 1ll*(sum/3)*f;
}
long long dfs(int i,int n)
{
	if (~dp[i][n]) return dp[i][n];
	if (i==6)
	{
		return dp[i][n]=0;
	}
	int lst=n%10;long long res=0;
	for (int j=0;j<1000;j++)
	{
		if (lst+10*j<=min(n,9*k))
		{
			res=max(dfs(i+1,(n-lst)/10-j)+calc(lst+10*j,f[i]),res);
		}
	}
	int lpp=min(n,9*k);
	lpp=(lpp/10-1)*10+lst;
	if (lpp+10<=min(n,9*k)) lpp+=10;
	for (int j=0;j<1000;j++)
	{
		if (lpp-10*j>=0)
		{
			res=max(dfs(i+1,(n-lpp)/10+j)+calc(lpp-10*j,f[i]),res);
		}
	}
	return dp[i][n]=res;
}
long long solve(int n,int k)
{
	return dfs(0,n);
}
int main()
{
	scanf("%d",&k);
	for (int i=0;i<6;i++) scanf("%d",&f[i]);
	scanf("%d",&q);
	memset(dp,-1,sizeof(dp));
	while(q--)
	{
		scanf("%d",&n);
		printf("%lld\n",solve(n,k));
	}
	return Accepted;
}