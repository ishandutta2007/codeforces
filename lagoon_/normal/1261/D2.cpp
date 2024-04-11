#include<bits/stdc++.h>
using namespace std;
#define re register
const int mod=998244353;
int a[200100];
int ex(re int a,re int b)
{
	re int ans=1;
	for(;b;b>>=1,a=(long long)a*a%mod)if(b&1)ans=(long long)ans*a%mod;
	return ans;
}
int fac[200100],ifac[200100];
int main()
{
	re int n,k,num=1,ans=0;
	scanf("%d%d",&n,&k);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>1&&a[i]==a[i-1])num=(long long)num*k%mod,i--,n--;
	}
	if(n>1&&a[n]==a[1])num=(long long)num*k%mod,n--;
	if(n==1){puts("0");return 0;}
	fac[0]=1;
	for(re int i=1;i<=n;i++)fac[i]=(long long)fac[i-1]*i%mod;ifac[n]=ex(fac[n],mod-2);
	for(re int i=n;i;i--)ifac[i-1]=(long long)ifac[i]*i%mod;
	for(re int i=1;i<=n;i++)
	{
		re int nw=(long long)num*ex(k-2,n-i)%mod,nk=ex(2,i);
		if(!(i&1))nk=(nk+(long long)(mod-fac[i])*ifac[i/2]%mod*ifac[i/2])%mod;
		nk=(long long)nk*ex(2,mod-2)%mod;
		ans=(ans+(long long)nw*nk%mod*fac[n]%mod*ifac[i]%mod*ifac[n-i])%mod;
	}
	printf("%d\n",ans);
}