#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,c[5555][5555],s[5555][5555],jc[5555],injc[5555],ans[5555],a[5555];
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=res*p;
		p=p*p;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	c[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for (int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	jc[0]=injc[0]=1;
	for (int i=1;i<=n;i++)
	{
		jc[i]=1ll*jc[i-1]*i%mod;
		injc[i]=1ll*injc[i-1]*binpow(i,mod-2)%mod;
	}
	s[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			s[i][j]=(1ll*j*s[i-1][j]+s[i-1][j-1])%mod;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			s[i][j]=1ll*s[i][j]*jc[j]%mod;
		}
		for (int j=0;j<=i-j;j++) swap(s[i][j],s[i][i-j]);
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			a[i]=(1ll*s[j][i]*c[n][j]%mod*jc[n-j]+a[i])%mod;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i-1;j<=n;j++)
		{
			if ((j-i+1)&1) ans[i]=(-1ll*c[j][i-1]*a[j]+ans[i])%mod;
			else ans[i]=(1ll*c[j][i-1]*a[j]+ans[i])%mod;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",(ans[i]+mod)%mod);
	printf("\n");
	return 0;
}