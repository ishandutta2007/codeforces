#include<iostream>
#include<cstdio>
#define inv 499122177
#define mod 998244353
using namespace std;
int a[1001000],dp[1001000],f[1000100],g[1010000],mi[1010000];
int main()
{
	int n;scanf("%d",&n);
	mi[0]=1;for(int i=1;i<=n;i++)mi[i]=1ll*mi[i-1]*inv%mod;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=(a[i]+a[i-1])%mod;
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		g[i]=1ll*(g[i-1]+dp[i-1])*inv%mod;
		f[i]=(f[i-1]+1ll*a[i-1]*mi[i-1])%mod;
		dp[i]=((f[i]+g[i])%mod+1ll*a[i]*mi[i-1])%mod;
	}
	for(int i=1;i<n;i++)dp[n]=dp[n]*2%mod;
	printf("%d\n",dp[n]);
	return 0;
}
/*
dp[i]i 
dp[i]=((dp[j]+a[1]+...+a[i-j])*(1/2)^(i-j)  (1<=j<i)   )  +(a[1]+...+a[i])*(1/2)^(i-1)
a 
dp[i]=(  (dp[j]+a[i-j])*(1/2)^(i-j)  (1<=j<i)   )   +a[i]*(1/2)^(i-1)

dp[i]=(a[j]*(1/2)^j+dp[i-j]*(1/2)^j   (1<=j<i)   )  +a[i]*(1/2)^(i-1)

f[i]=a[j]*(1/2)^j  (1<=j<i)
f[i]=f[i-1]+a[i-1]*(1/2)^(i-1)

g[i]=dp[j]*(1/2)^(i-j)   (1<=j<i)
g[i]=(g[i-1]+dp[i-1])*(1/2)

dp[i]=f[i]+g[i]+a[i]*(1/2)^(i-1)
*/