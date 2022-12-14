#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[111111],dp[222][2],pdp[222][2],pre[222][2],ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	pdp[0][1]=1;
	for (int i=0;i<=201;i++) pre[i][1]=1;
	for (int i=1;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
		for (int j=1;j<=200;j++)
		{
			if (a[i]!=-1 && a[i]!=j) continue;
			dp[j][0]=(pre[j-1][0]+pre[j-1][1])%mod;
			dp[j][1]=(1ll*pre[201][1]-pre[j-1][1]+pdp[j][0])%mod;
 		}
 		pre[0][0]=pre[0][1]=0;
 		for (int j=1;j<=201;j++)
 		{
 			for (int k=0;k<2;k++)
 			{
 				pdp[j][k]=dp[j][k];
 				pre[j][k]=(pre[j-1][k]+dp[j][k])%mod;
			}
		}
	}
	for (int j=1;j<=200;j++)
	{
		ans=(ans+dp[j][1])%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}