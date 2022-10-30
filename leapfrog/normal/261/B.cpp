#include<bits/stdc++.h>
using namespace std;
int n,p,a[55],sum;long long dp[55][55];double fac[55],ans;
int main()
{
	scanf("%d",&n),fac[0]=1,sum=0,ans=0;
	for(int i=1;i<=n;i++) scanf("%d",a+i),sum+=a[i],fac[i]=fac[i-1]*i;
	scanf("%d",&p);if(sum<=p) return printf("%.5lf\n",1.0*n),0;else dp[0][0]=1;
	for(int i=1;i<=n;i++) for(int j=i;j>=1;j--) for(int k=p;k>=a[i];k--) dp[j][k]+=dp[j-1][k-a[i]];
	for(int i=1;i<=n;i++) for(int j=0;j<=p;j++) ans+=1.0*dp[i][j]*fac[i]*fac[n-i];
	return printf("%.5lf\n",ans/fac[n]),0;
}