#include<stdio.h>
const int maxn=2005,mod=998244353;
int T,n,m,k,ans,ivm;
int S[maxn][maxn],fac[maxn],nfac[maxn];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int main(){
	fac[0]=nfac[0]=1;
	for(int i=1;i<=2000;i++){
		S[i][1]=1;
		for(int j=2;j<=i;j++)
			S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%mod;
		fac[i]=1ll*fac[i-1]*i%mod,nfac[i]=ksm(fac[i],mod-2);
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k),ans=0,ivm=ksm(m,mod-2);
		int mul=1,mul1=1,mul2=ksm(m,n);
		for(int i=1;i<=k&&i<=n;i++){
			mul=1ll*mul*(n-i+1)%mod,mul1=1ll*mul1*((m+1)/2)%mod,mul2=1ll*mul2*ivm%mod;
			ans=(ans+1ll*S[k][i]*mul%mod*mul1%mod*mul2)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}