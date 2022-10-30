#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s[100005],dp[100005];
signed main()
{
	scanf("%lld",&n),memset(s,0,sizeof(s));
	for(int i=1,x;i<=n;i++) scanf("%lld",&x),s[x]++;
	dp[1]=s[1],dp[0]=0;
	for(int i=2;i<=100000;i++) dp[i]=max(dp[i-1],s[i]*i+dp[i-2]);
	return printf("%lld\n",dp[100000]),0;
}