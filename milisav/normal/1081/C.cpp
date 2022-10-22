#include<bits/stdc++.h>
using namespace std;
int n,k;
long long m;
long long mod=998244353;
long long dp[2500][2500];
long long sum[2500];
int main()
{
	scanf("%d %lld %d",&n,&m,&k);
	k++;
	dp[1][1]=m;
	sum[1]=m;
	for(int i=2;i<=n;i++) {
		dp[i][1]=m;
		for(int j=2;j<=k;j++) {
			dp[i][j]=((m-1)*sum[j-1])%mod;
		}
		for(int j=1;j<=k;j++) sum[j]=(sum[j]+dp[i][j])%mod;
	}
	printf("%lld",dp[n][k]);
	return 0;
}