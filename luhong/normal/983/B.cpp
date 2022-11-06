#include<iostream>
#include<cstdio>
using namespace std;
int dp[5100][5100],f[5100][5100];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&dp[i][i]),f[i][i]=dp[i][i];
	for(int len=2;len<=n;len++)
	for(int l=1;l+len-1<=n;l++)
	{
		int r=l+len-1;
		dp[l][r]=dp[l][r-1]^dp[l+1][r];
		f[l][r]=max(max(f[l][r-1],f[l+1][r]),dp[l][r]);
	}
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",f[l][r]);
	}
	return 0;
}