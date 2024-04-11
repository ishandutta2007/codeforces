#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long num[22][2222][2][2],dp[22][2222][2][2],l,r,K,x[22],cnt,kk,hh,sum,pw[22];
const long long mod=998244353;
long long calc(long long n)
{
	cnt=0;
	while(n)
	{
		x[++cnt]=n%10;
		n/=10;
	}
	reverse(x+1,x+cnt+1);
	memset(num,0,sizeof(num));
	memset(dp,0,sizeof(dp));
	num[0][0][0][0]=1;
	for (long long i=0;i<cnt;i++)
	{
		for (long long j=0;j<(1<<10);j++)
		{
			for (long long k=0;k<=1;k++)
			{
				for (long long h=0;h<=1;h++)
				{
					if (!num[i][j][k][h]) continue;
					for (long long p=0;p<=9;p++)
					{
						if (p>x[i+1] && !k) continue;
						kk=k;hh=h;
						if (p<x[i+1] && !kk) kk=1;
						if (p && !hh) hh=1;
						if (!hh) 
						{
							num[i+1][j][kk][hh]=(num[i+1][j][kk][hh]+num[i][j][k][h])%mod;
							dp[i+1][j][kk][hh]=(dp[i+1][j][kk][hh]+dp[i][j][k][h])%mod;
						}
						else 
						{
							num[i+1][j|(1<<p)][kk][hh]=(num[i+1][j|(1<<p)][kk][hh]+num[i][j][k][h])%mod;
							dp[i+1][j|(1<<p)][kk][hh]=(dp[i+1][j|(1<<p)][kk][hh]+dp[i][j][k][h]+(num[i][j][k][h]*pw[cnt-i-1]%mod)*p)%mod;
						} 
					}
				}
			}
		}
	}
	long long res=0;
	for (long long i=0;i<(1<<10);i++)
	{
		sum=0;
		for (long long j=0;j<10;j++)
		{
			if (i&(1<<j)) sum++;
		}
		if (sum<=K) res=(res+dp[cnt][i][0][0]+dp[cnt][i][0][1]+dp[cnt][i][1][0]+dp[cnt][i][1][1])%mod;
	}
	return res;
}
int main()
{
	pw[0]=1;
	for (long long i=1;i<=20;i++) pw[i]=pw[i-1]*10%mod;
	scanf("%I64d%I64d%I64d",&l,&r,&K);
	printf("%I64d\n",(calc(r)-calc(l-1)+mod)%mod);
	return 0;
}