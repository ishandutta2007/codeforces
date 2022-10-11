#include <iostream>
#include <string.h>
using namespace std;
#define mod 998244353
long long dp[505][505];
int p[505];
long long solve(int l,int r)
{
	if (r<=l)
	return 1;
	if (dp[l][r]!=-1)
	return dp[l][r];
	int idx=l;
	for (int i=l;i<=r;i++)
	{
		if (p[i]<p[idx])
		idx=i;
	}
	long long a1=0,a2=0;
	for (int i=l;i<=idx;i++)
	a1=(a1+solve(l,i-1)*solve(i,idx-1))%mod;
	for (int i=idx;i<=r;i++)
	a2=(a2+solve(idx+1,i)*solve(i+1,r))%mod;
	return dp[l][r]=(a1*a2)%mod;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	memset(dp,-1,sizeof(dp));
	printf("%I64d",solve(1,n));
}