#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
char s[1111111];
int n,dp[1111111],msk,ans;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)
	{
		msk=0;
		for (int j=i;j<n;j++)
		{
			if (msk&(1<<(s[j]-'a'))) break;
			msk|=(1<<(s[j]-'a'));
			dp[msk]=__builtin_popcount(msk);
		}
	}
	for (int i=0;i<(1<<maxn);i++)
	{
		for (int j=0;j<maxn;j++)
		{
			if (i&(1<<j)) dp[i]=max(dp[i],dp[i^(1<<j)]);
		}
	}
	for (int i=0;i<(1<<maxn);i++)
	{
		if (dp[i]==__builtin_popcount(i))
		{
			ans=max(ans,dp[i]+dp[(1<<maxn)-1-i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}