#include<bits/stdc++.h>
using namespace std;
long long n,K,dp[555555][2][2],nj,nk,ans;
char s[555555],t[555555];
int main()
{
	scanf("%I64d%I64d",&n,&K);
	scanf("%s%s",s,t);
	dp[0][0][0]=1;
	for (long long i=0;i<n;i++)
	{
		for (long long j=0;j<=1;j++)
		{
			for (long long k=0;k<=1;k++)
			{
				if (!dp[i][j][k]) continue;
				if (dp[i][j][k]>K) dp[i][j][k]=K;
				for (long long h=0;h<=1;h++)
				{
					if (!j && !h && s[i]=='b') continue;
					if (!k && h && t[i]=='a') continue;
					nj=j;nk=k;
					if (h!=s[i]-'a') nj=1;
					if (h!=t[i]-'a') nk=1;
					dp[i+1][nj][nk]+=dp[i][j][k]; 
				}
			}
		}
	}
	for (long long i=1;i<=n;i++)
	{
		ans+=min(K,dp[i][0][0]+dp[i][0][1]+dp[i][1][0]+dp[i][1][1]);
	}
	printf("%I64d\n",ans);
	return 0;
}