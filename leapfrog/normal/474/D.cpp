#include<bits/stdc++.h>
using namespace std;
int t,k;long long dp[100005],s[100005];
int main()
{
	scanf("%d%d",&t,&k),dp[0]=1,s[0]=1;
	for(int i=1;i<=100000;i++) dp[i]+=dp[i-1],dp[i]%=1000000007,dp[i]+=(i>=k?dp[i-k]:0),dp[i]%=1000000007;
	for(int i=1;i<=100000;i++) s[i]=s[i-1]+dp[i],s[i]%=1000000007;
	for(int i=1,a,b;i<=t;i++) scanf("%d%d",&a,&b),printf("%lld\n",(s[b]-s[a-1]+1000000007)%1000000007);
	return 0;
}