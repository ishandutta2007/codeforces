#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[111111],n,ans,cnt;
char s[111111];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	dp[0]=1;
	for (int i=1;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
	ans=1;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='m' || s[i]=='w') 
		{
			ans=0;
		}
		if (s[i]==s[i-1] || i==0) cnt++;
		else 
		{
			if (s[i-1]=='n' || s[i-1]=='u') ans=1ll*ans*dp[cnt]%mod;
			cnt=1;
		}
	}
	if (s[n-1]=='n' || s[n-1]=='u') ans=1ll*ans*dp[cnt]%mod;
	printf("%d\n",ans);
	return 0;
}