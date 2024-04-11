#include<cstdio>
const int maxn=2e5+10,mod=998244353;
int ans[maxn],fac[maxn],ifac[maxn],inv[maxn],m,n,sum;
int main(){
	scanf("%d",&n);
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
	for(int i=2;i<=n;++i){
		fac[i]=1ll*fac[i-1]*i%mod;
		ifac[i]=1ll*ifac[i-1]*(inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod)%mod;
	}
	m=n+1>>1;
	for(int i=n-m+1;i;--i){
		if((ans[i]=(1ll*fac[n-i]*fac[n-m]%mod*ifac[n-i-m+1]-1ll*inv[i]*sum)%mod)<0)ans[i]+=mod;
		if((sum+=ans[i])>=mod)sum-=mod;
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}