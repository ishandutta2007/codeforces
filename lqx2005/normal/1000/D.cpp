#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000;
const int mod=998244353;
int n;
int a[maxn+5],f[maxn+5],C[maxn+5][maxn+5];
void info()
{
	for(int i=0;i<=maxn;i++) C[i][0]=1;
	for(int i=1;i<=maxn;i++)
	{
		for(int j=1;j<=maxn;j++)
		{
			if(j>i) continue;
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=mod;
		}
	}
	return;
}
signed main()
{
	scanf("%lld",&n);
	info();
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=n;i>=1;i--)
	{
		if(n-i<a[i]) continue;
		if(a[i]<=0) continue;
		f[i]=C[n-i][a[i]];
		for(int j=i+a[i]+1;j<=n;j++)
		{
			f[i]+=f[j]*C[j-i-1][a[i]];
			f[i]%=mod;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++) sum=(sum+f[i])%mod;
	printf("%lld\n",sum);
	return 0;
}