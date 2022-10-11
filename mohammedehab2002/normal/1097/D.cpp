#include <iostream>
using namespace std;
#define MX 50
#define mod 1000000007
int dp[10005][MX+5][MX+5],cum[10005][MX+5][MX+5];
long long inv[MX+5];
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
int main()
{
	int k;
	long long n,ans=1;
	scanf("%I64d%d",&n,&k);
	for (int i=0;i<=MX;i++)
	{
		dp[0][i][i]=1;
		inv[i]=pow_log(i+1,mod-2);
		for (int j=0;j<=i;j++)
		cum[0][i][j]=inv[i];
	}
	for (int i=1;i<=k;i++)
	{
		for (int s=0;s<=MX;s++)
		{
			for (int j=s;j>=0;j--)
			{
				dp[i][s][j]=cum[i-1][s][j];
				cum[i][s][j]=(cum[i][s][j+1]+dp[i][s][j]*inv[j])%mod;
			}
		}
	}
	for (int i=2;i<=n/i;i++)
	{
		int cnt=0;
		while (n%i==0)
		{
			n/=i;
			cnt++;
		}
		long long tmp=0;
		for (int j=0;j<=cnt;j++)
		tmp=(tmp+pow_log(i,j)*dp[k][cnt][j])%mod;
		ans=(ans*tmp)%mod;
	}
	if (n!=1)
	ans=(ans*((dp[k][1][0]+(n%mod)*dp[k][1][1])%mod))%mod;
	printf("%I64d",ans);
}