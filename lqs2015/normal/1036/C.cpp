#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long t,l,r,a[111],cnt,dp[111][111],cur,res;
long long calc(long long x)
{
	cnt=0;
	while(x)
	{
		a[++cnt]=x%10;
		x/=10;
	}
	reverse(a+1,a+cnt+1);
	cur=0;
	memset(dp,0,sizeof(dp));
	for (long long i=1;i<=cnt;i++)
	{
		for (long long j=0;j<a[i];j++)
		{
			if (j) dp[i][cur+1]++;
			else dp[i][cur]++;
		}
		if (a[i]) cur++;
	}
	dp[cnt][cur]++;
	for (long long i=1;i<cnt;i++)
	{
		for (long long j=0;j<cnt;j++)
		{
			if (!dp[i][j]) continue;
			for (long long k=0;k<=9;k++)
			{
				if (!k) dp[i+1][j]+=dp[i][j];
				else dp[i+1][j+1]+=dp[i][j];
			}
		}
	}
	res=0;
	for (long long i=0;i<4;i++) res+=dp[cnt][i];
	return res;
	
}
int main()
{
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",calc(r)-calc(l-1));
	}
	return 0;
}