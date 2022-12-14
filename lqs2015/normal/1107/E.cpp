#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
long long ans,f[111][111],a[111],dp[111][111];
int l,r,n;
string s;
int main()
{
	scanf("%d",&n);
	cin>>s;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) f[i][i]=a[1];
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<=n-i;j++)
		{
			l=j;r=j+i;
			for (int k=l;k<=r;k++)
			{
				for (int h=1;h<=n;h++)
				dp[k][h]=-1e9;
			}
			dp[l][1]=0;
			for (int k=l+1;k<=r;k++)
			{
				if (s[k-1]!=s[l-1]) continue;
				for (int h=2;h<=r-l+1;h++)
				{
					for (int p=l;p<k;p++)
					{
						dp[k][h]=max(dp[k][h],dp[p][h-1]+f[p+1][k-1]);
					}
				}
			}
			for (int k=l;k<=r;k++)
			{
				for (int h=1;h<=r-l+1;h++)
				{
					f[l][r]=max(f[l][r],dp[k][h]+a[h]+f[k+1][r]);
				}
			}
		}
	}
	printf("%lld\n",f[1][n]);
	return Accepted;
}