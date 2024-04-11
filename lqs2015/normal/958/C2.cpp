#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,p;
int dp[111][555555],cur[111],a[555555],ld[111];
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		a[i]%=p;
	}
	for (int i=1;i<=n;i++) dp[0][i]=-1e9;
	for (int i=1;i<=k;i++)
	{
		for (int j=0;j<p;j++) cur[j]=-1e9;
		for (int j=1;j<=n;j++)
		{
			for (int h=0;h<p;h++) ld[(h+a[j])%p]=cur[h];
			for (int h=0;h<p;h++) cur[h]=ld[h];
			cur[a[j]]=max(cur[a[j]],dp[i-1][j-1]);
			for (int h=0;h<p;h++) dp[i][j]=max(dp[i][j],cur[h]+h);
		}
	}
	cout<<dp[k][n]<<endl;
	return 0;
}