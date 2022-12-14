#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[3333][3333],n,m,l,r,ans;
char s[3333],t[3333];
int main()
{
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s);m=strlen(t);
	for (int i=1;i<=n;i++) 
	{
		if (i<=m)
		{
			if (s[0]==t[i-1]) dp[i][i]=2;
			else dp[i][i]=0;
		} 
		else dp[i][i]=2;
	}
	for (int i=1;i<n;i++)
	{
		for (int j=1;i+j<=n;j++)
		{
			l=j;r=i+j;
			if (l>m || t[l-1]==s[i]) dp[l][r]=(dp[l][r]+dp[l+1][r])%mod;
			if (r>m || t[r-1]==s[i]) dp[l][r]=(dp[l][r]+dp[l][r-1])%mod;
		}
	}
	for (int i=m;i<=n;i++) ans=(ans+dp[1][i])%mod;
	printf("%d\n",ans);
	return 0;
}