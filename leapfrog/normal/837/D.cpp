#include<bits/stdc++.h>
using namespace std;
int n,k,a[205],b[205],dp[205][6005];long long t;
int main()
{
	scanf("%d%d",&n,&k),memset(dp,~0x3f,sizeof(dp)),dp[0][0]=0;int tot=0,res=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t),a[i]=b[i]=0;
		while(t%2==0) ++a[i],t/=2;
		while(t%5==0) ++b[i],++tot,t/=5;
	}
	for(int i=1;i<=n;i++) for(int j=k;j>=1;j--) for(int k=tot;k>=b[i];k--) dp[j][k]=max(dp[j][k],dp[j-1][k-b[i]]+a[i]);
	for(int i=0;i<=tot;i++) res=max(res,min(dp[k][i],i));
	return printf("%d\n",res),0;
}