#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
int s2[5555][5555],n,m,k,p,pw[5555],xjm[5555],ans;
void Init()
{
	s2[0][0]=1;
	for (int i=1;i<=k;i++)
	{
		s2[i][0]=0;
		for (int j=1;j<=i;j++)
		{
			s2[i][j]=(1ll*s2[i-1][j]*j+s2[i-1][j-1])%mod;
		}
	}
	pw[0]=1;
	for (int i=1;i<=k;i++) pw[i]=1ll*pw[i-1]*p%mod;
	xjm[0]=1;
	for (int i=1;i<=k;i++) xjm[i]=1ll*xjm[i-1]*(n-i+1)%mod;
}
int main()
{
	cin>>n>>m>>k;
	p=binpow(m,mod-2);
	Init();
	for (int i=0;i<=k;i++)
	{
		ans=(1ll*s2[k][i]*xjm[i]%mod*pw[i]+ans)%mod;
	}
	printf("%d\n",ans);
	return 0;
}