#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=200000;
const ll INF=1e15;
ll dp[2][N+5],c[N+5];
ll t,n,a,b;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&a,&b);
		for(ll i=0;i<=n;i++) dp[0][i]=dp[1][i]=INF;
		for(ll i=1;i<=n;i++) scanf("%1d",&c[i]);
		dp[0][0]=b;
		dp[1][0]=INF;
		for(ll i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				dp[0][i]=min(dp[0][i],dp[0][i-1]);
				dp[0][i]=min(dp[0][i],dp[1][i-1]+a);
				dp[0][i]+=b;
				dp[1][i]=min(dp[1][i],dp[0][i-1]+a);
				dp[1][i]=min(dp[1][i],dp[1][i-1]);
				dp[1][i]+=2*b;
			}
			else
			{
				dp[0][i]=INF;
				dp[1][i]=min(dp[1][i],dp[1][i-1]);
				dp[1][i]+=2*b;				
			}
		}
		printf("%lld\n",dp[0][n]+a*n);
	}
	return 0;
}