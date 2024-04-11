#include <bits/stdc++.h>
#define maxn 1200005
#define ll long long
const int mod=998244353;
const int g=3;
int n,k,c[maxn],A[maxn<<1],B[maxn<<1],q,ans[maxn<<1],rev[maxn<<1],x,fac[maxn],ifac[maxn];
int qpow(int a,int b){
	if (b==0)return 1;int d=qpow(a,b>>1);d=(ll)d*d%mod;if (b&1)d=(ll)d*a%mod;return d;
}
void NTT(int *a,int lim,int flag){
	for(int i=1;i<lim;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
	for(int i=0;i<lim;++i)if(i<rev[i])std::swap(a[i],a[rev[i]]);
	for(int i=1;i<lim;i<<=1){
		int wn=qpow(g,(mod-1)/(i<<1));if (flag==-1)wn=qpow(wn,mod-2);
		for(int j=0;j<lim;j+=i*2)
		for(int k=0,w=1;k<i;++k,w=(ll)w*wn%mod){
			int a0=a[j+k],a1=(ll)w*a[j+k+i]%mod;
			a[j+k]=(a0+a1)%mod;a[j+k+i]=(a0-a1+mod)%mod;
		}
	}if (flag==-1)for(int i=0;i<lim;++i)a[i]=(ll)a[i]*qpow(lim,mod-2)%mod;
}	int C(int a,int b){return (ll)fac[a]*ifac[b]%mod*ifac[a-b]%mod;}
int main(){
	scanf("%d%d",&n,&k);fac[0]=ifac[0]=1;
	for(int i=1;i<=n;++i){fac[i]=(ll)fac[i-1]*i%mod;ifac[i]=qpow(fac[i],mod-2);}
	for(int i=1;i<=n;++i){scanf("%d",&x);c[x]++;}
	for(int j=1;j<=k;++j){
		int c1=0,c2=0;
		scanf("%d",&x);
		for(int i=1;i<x;++i){if(c[i]==1)c1++;else if (c[i]>1)c2++;}
		std::memset(A,0,sizeof(A));std::memset(B,0,sizeof(B));
		for(int i=0;i<=c2*2;++i)A[i]=C(c2*2,i);
		for(int i=0;i<=c1;++i)B[i]=(ll)C(c1,i)*qpow(2,i)%mod;
		int lim=1;while(lim<=c2*2+c1)lim<<=1;
		NTT(A,lim,1);NTT(B,lim,1);for(int i=0;i<lim;++i)A[i]=(ll)A[i]*B[i]%mod;NTT(A,lim,-1);
		for(int i=0;i<=c2*2+c1;++i)ans[i+x+1]=(ans[i+x+1]+A[i])%mod;
	}scanf("%d",&q);while(q--){scanf("%d",&x);printf("%d\n",ans[x/2]);}
	return 0;
}