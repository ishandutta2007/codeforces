#include<bits/stdc++.h>
#define re register
const int mod=998244353;
int f[2000100],fac[4001000],ifac[4001000],inv[4001000];
int main()
{
	re int n,m;
	scanf("%d%d",&n,&m);
	inv[1]=1;
	re int N=std::max(n,m);
	for(re int i=2;i<=2*N;i++)inv[i]=1llu*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=ifac[0]=1;
	for(re int i=1;i<=2*N;i++)
	{
		fac[i]=1llu*i*fac[i-1]%mod;
		ifac[i]=1llu*inv[i]*ifac[i-1]%mod;
	}
	f[n]=1llu*(n+m)*inv[n]%mod;
	re int nw=1llu*f[n]*fac[m]%mod*fac[n]%mod*ifac[n+m]%mod;
	for(re int i=n-1;i;i--)
	{
		f[i]=1llu*fac[i+m]*inv[i]%mod*ifac[m-1]%mod*ifac[i]%mod*nw%mod;
		nw=(nw+1llu*f[i]*fac[m]%mod*fac[i]%mod*ifac[i+m])%mod;
	}
	re int ans=0;
	for(re int i=1;i<=n;i++)ans=(ans+1llu*f[i]*(1llu*n*inv[m+1]%mod+1))%mod;
	printf("%d\n",ans);
}