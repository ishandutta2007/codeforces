#include <iostream>
using namespace std;
#define mod 1000000007
int dp[1000005][21];
long long ncr[1000005][21],p[1000005];
int main()
{
	p[0]=1;
	p[1]=2;
	for (int i=2;i<1000005;i++)
	{
		dp[i][1]=1;
		p[i]=(2*p[i-1])%mod;
		for (int x=2*i;x<1000005;x+=i)
		{
			for (int j=1;dp[i][j];j++)
			dp[x][j+1]=(dp[x][j+1]+dp[i][j])%mod;
		}
	}
	ncr[0][0]=1;
	for (int i=1;i<1000005;i++)
	{
		ncr[i][0]=1;
		for (int x=1;x<=min(i,20);x++)
		ncr[i][x]=(ncr[i-1][x]+ncr[i-1][x-1])%mod;
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=0;
		for (int i=1;i<=y && dp[x][i];i++)
		ans=(ans+dp[x][i]*ncr[y][i])%mod;
		if (x==1)
		ans=1;
		printf("%I64d\n",(ans*p[y-1])%mod);
	}
}