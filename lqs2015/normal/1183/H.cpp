#include<bits/stdc++.h>
using namespace std;
const long long inf=1e13;
void add(long long &a,long long b)
{
	a+=b;
	if (a>inf) a=inf;
}
int n;long long K;
long long dp[111][26][111],DP[111][111],lst,ans,fuck[111];
char s[111];
int main()
{
	scanf("%d%lld",&n,&K);
	scanf("%s",s);
	DP[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<26;j++)
		{
			for (int k=1;k<=n;k++)
			{
				if (j==s[i-1]-'a') dp[i][j][k]=DP[i-1][k-1];
				else dp[i][j][k]=dp[i-1][j][k];
			}
		}
		DP[i][0]=1;
		for (int k=1;k<=n;k++)
		{
			DP[i][k]=DP[i-1][k]+DP[i-1][k-1]-dp[i-1][s[i-1]-'a'][k];
			if (DP[i][k]>inf) DP[i][k]=inf;
		}
	}
	for (int i=n;i>=0;i--)
	{
		if (K<=DP[n][i])
		{
			ans+=K*(n-i);
			printf("%lld\n",ans);
			return 0;
		}
		ans+=(DP[n][i]*(n-i));
		K-=DP[n][i];
	}
	printf("-1\n");
	return 0;
}