#include <bits/stdc++.h>
using namespace std;
long long dp[5005];
int tag[5005],s[5005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		scanf("%d",&tag[i]);
		for (int i=1;i<=n;i++)
		scanf("%d",&s[i]);
		for (int i=1;i<=n;i++)
		{
			dp[i]=0;
			for (int j=i-1;j>0;j--)
			{
				if (tag[i]==tag[j])
				continue;
				long long tmp=dp[i]+abs(s[i]-s[j]);
				dp[i]=max(dp[i],dp[j]+abs(s[i]-s[j]));
				dp[j]=max(dp[j],tmp);
			}
		}
		printf("%I64d\n",*max_element(dp+1,dp+n+1));
	}
}