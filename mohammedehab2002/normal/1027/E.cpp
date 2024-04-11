#include <iostream>
#include <string.h>
using namespace std;
#define mod 998244353
bool ret;
int dp[505][505][2],N,K;
int go(int n,int k,bool flag)
{
	if (n==N)
	return (flag || ret);
	if (dp[n][k][flag]!=-1)
	return dp[n][k][flag];
	int ans=go(n+1,1,flag);
	if (k!=K)
	ans=(ans+go(n+1,k+1,(flag || (k+1)==K)))%mod;
	return dp[n][k][flag]=ans;
}
int main()
{
	int k;
	scanf("%d%d",&N,&k);
	k--;
	long long ans=0;
	for (int mx=1;mx<=min(N,k);mx++)
	{
		memset(dp,-1,sizeof(dp));
		K=mx;
		ret=0;
		long long tmp=go(1,1,K==1);
		memset(dp,-1,sizeof(dp));
		K=k/mx;
		ret=1;
		tmp=(tmp*go(1,1,K==1)*2LL)%mod;
		if (K)
		ans=(ans+tmp)%mod;
	}
	printf("%I64d",ans);
}