#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],dp[5005],ans;double tp;
signed main()
{
	scanf("%d%d",&n,&m),ans=0;
	for(int i=1;i<=n;i++) scanf("%d%lf",a+i,&tp),dp[i]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) if(a[j]<=a[i]) dp[i]=max(dp[i],dp[j]+1);
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	return printf("%d\n",n-ans),0;
}