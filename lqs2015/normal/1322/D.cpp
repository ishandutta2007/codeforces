#include<bits/stdc++.h>
using namespace std;
int n,m,l[2222],s[2222],c[5555],dp[5555][2222],mx;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&l[i]);
	for (int i=1;i<=n;i++) scanf("%d",&s[i]);
	for (int i=1;i<=n+m;i++) scanf("%d",&c[i]);
	for (int i=0;i<=n+m;i++)
	{
		for (int j=0;j<=n;j++)
		{
			dp[i][j]=-1e9;
		}
	}
	for (int i=0;i<=n+m;i++) dp[i][0]=0;
	for (int i=n;i>=1;i--)
	{
		for (int j=n;j>=1;j--) dp[l[i]][j]=max(dp[l[i]][j],dp[l[i]][j-1]+c[l[i]]-s[i]);
		mx=n;
		for (int j=l[i];j<=n+m;j++)
		{
			for (int k=0;k<=mx;k++)
			{
				dp[j+1][k/2]=max(dp[j+1][k/2],dp[j][k]+(k/2)*c[j+1]);
			}
			mx>>=1;
		}
	}
	printf("%d\n",dp[n+m][0]);
	return 0;
}