#include<bits/stdc++.h>
#define re register
int fac[1001000];
int main()
{
	re int n,mod,ans=0;
	scanf("%d%d",&n,&mod);
	fac[0]=1;
	for(re int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(re int i=1;i<=n;i++)
	{
		ans=(ans+1ll*(n-i+1)*(n-i+1)%mod*fac[i]%mod*fac[n-i])%mod;
	}
	printf("%d\n",ans);
}