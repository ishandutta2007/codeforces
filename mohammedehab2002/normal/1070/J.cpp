#include <iostream>
#include <string.h>
using namespace std;
int cnt[26],dp[30005];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m,k;
		string s;
		cin >> n >> m >> k >> s;
		memset(cnt,0,sizeof(cnt));
		for (char i:s)
		cnt[i-'A']++;
		int ans=(1<<30);
		for (int i=0;i<26;i++)
		{
			for (int j=0;j<=n;j++)
			dp[j]=(1<<30);
			dp[n]=m;
			for (int j=0;j<26;j++)
			{
				if (i==j)
				continue;
				for (int k=0;k<=n;k++)
				{
					dp[k]=max(0,dp[k]-cnt[j]);
					if (k+cnt[j]<=n)
					dp[k]=min(dp[k],dp[k+cnt[j]]);
				}
			}
			for (int j=0;j<=n;j++)
			{
				if (j+dp[j]<=cnt[i])
				ans=min(ans,j*dp[j]);
			}
		}
		printf("%d\n",ans);
	}
}