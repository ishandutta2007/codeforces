#include<iostream>
#include<cstdio>
using namespace std;
int n,dp[5555][5555],mx[5555][5555],a[5555],l,r,q;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) dp[i][i]=mx[i][i]=a[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n-i;j++)
		{
			l=j;r=j+i;
			dp[l][r]=dp[l+1][r]^dp[l][r-1];
			mx[l][r]=max(max(mx[l+1][r],mx[l][r-1]),dp[l][r]);
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",mx[l][r]);
	}
	return 0;
}