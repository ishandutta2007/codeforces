#include<bits/stdc++.h>
using namespace std;
int n,k,r=0,a[505],dp[505][505];
int main()
{
	scanf("%d%d",&n,&k),memset(dp,0,sizeof(dp)),dp[0][0]=1;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) for(int j=k;j>=a[i];j--) for(int l=500;l>=0;l--) {if(l>=a[i]) dp[j][l]|=dp[j-a[i]][l-a[i]];dp[j][l]|=dp[j-a[i]][l];}
	for(int i=0;i<=k;i++) if(dp[k][i]) r++;printf("%d\n",r);
	for(int i=0;i<=k;i++) if(dp[k][i]) printf("%d ",i);
	return puts(""),0;
}