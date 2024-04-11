#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000000;
const int mod=998244353;
int n;
int a[maxn+5];
int dp[maxn+5];
int qpow(int a,int b)
{
	int res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		b/=2;
		a=a*a%mod;
	}
	return res;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int ans=0;
	for(int i=1;i<=n-1;i++)
	{
		int p2=n-i+1;
		p2=(p2+1)*qpow(2,p2-2)%mod;
		ans=(ans+p2*a[i]%mod)%mod;
	}
	ans=(ans+a[n])%mod;
	printf("%lld\n",ans);	
	return 0;
}