#include<bits/stdc++.h>
using namespace std;
int cnt[33],n,m,k,test;
long long ans;
char s[333333];
bool dp[33333];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&m,&k);
		scanf("%s",s);
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<k;i++) cnt[s[i]-'A']++;
		ans=1e18;
		for (int i=0;i<26;i++)
		{
			for (int j=0;j<=n;j++) dp[j]=0;
			dp[0]=1;
			for (int j=0;j<26;j++)
			{
				if (i==j) continue;
				for (int h=n;h>=cnt[j];h--)
				{
					dp[h]|=dp[h-cnt[j]];
				}
			}
			for (int j=0;j<=n;j++)
			{
				if (dp[j])
				{
					if (n-j<=cnt[i])
					{
						ans=min(ans,1ll*(n-j)*(cnt[i]-n+j));
						if (k-cnt[i]-j>=m) ans=0;
						else ans=min(ans,1ll*(n-j)*(m-(k-cnt[i]-j)));
					}
				}
			}
			if (dp[n]) ans=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}