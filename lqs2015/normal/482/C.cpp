#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
long long n,m,pos;
pair<long long,long long> a[55];
double dp[1111111],cnt,ans;
long long f[1111111];
string s[55];
int main()
{
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	m=s[1].size();
	for (long long i=1;i<=n;i++)
	{
		for (long long j=i+1;j<=n;j++)
		{
			pos=0;
			for (long long k=0;k<m;k++)
			{
				if (s[i][k]==s[j][k]) pos|=(1<<k);
			}
			f[pos]|=(1ll<<(j-1ll));
			f[pos]|=(1ll<<(i-1ll));
		}
	}
	for (long long i=(1<<m)-1;i>0;i--)
	{
		for (long long j=0;j<m;j++)
		{
			if (i&(1<<j)) f[i^(1<<j)]|=f[i];
		}
	}
	dp[0]=1.00;
	for (long long i=1;i<(1<<m);i++)
	{
		cnt=1.00;
		for (long long j=0;j<m;j++)
		{
			if (!(i&(1<<j))) cnt+=1.00;
		}
		for (long long j=0;j<m;j++)
		{
			if (i&(1<<j)) 
			{
				dp[i]+=dp[i^(1<<j)]/cnt;
			}
		}
		for (long long j=0;j<n;j++)
		{
			if (f[i]&(1ll<<j)) ans+=dp[i];
		}
	}
	if (n==1) printf("0.00000000\n");
	else printf("%.9lf\n",ans/(double)n+1.00);
	return 0;
}