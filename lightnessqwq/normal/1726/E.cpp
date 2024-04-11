#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxk=21,maxn=1<<(maxk-1),mod=998244353,G=3,invG=(mod+1)/3,inv2=(mod+1)/2;
typedef vector<int>poly;
int n,T;
int btf[maxn],w[maxk][maxn][2],inv[maxn],fac[maxn],nfac[maxn],mul2[maxn],coef[maxn];
inline int C(int a,int b){
	return a<b? 0:1ll*fac[a]*nfac[b]%mod*nfac[a-b]%mod;
}
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
void init(){
	fac[0]=nfac[0]=mul2[0]=coef[0]=1;
	for(int i=1;i<maxn;i++){
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=i==1? 1:(mod-1ll*(mod/i)*inv[mod%i]%mod),nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
		mul2[i]=(mul2[i-1]+mul2[i-1])%mod;
		if(i>1)
			coef[i]=1ll*(i-1)*coef[i-2]%mod;
	}
	for(int len=2,i=1;i<maxk;len<<=1,i++){
		int o0=ksm(G,(mod-1)/len),o1=ksm(invG,(mod-1)/len);
		w[i][0][0]=w[i][0][1]=1;
		for(int j=1;j<len;j++)
			w[i][j][0]=1ll*w[i][j-1][0]*o0%mod,w[i][j][1]=1ll*w[i][j-1][1]*o1%mod;
	}
}
int getlen(int n){
	int r=0;
	while((1<<r)<n)
		r++;
	for(int i=0;i<(1<<r);i++)
		btf[i]=(btf[i>>1]>>1)|((i&1)<<(r-1));
	return (1<<r);
}
void NTT(poly &x,int lim,int opt){
	x.resize(lim);
	for(int i=0;i<lim;i++)
		if(i<btf[i])
			swap(x[i],x[btf[i]]);
	for(int p=1,l=2;l<=lim;p++,l<<=1)
		for(int i=0;i<lim;i+=l)
			for(int j=0;j<(l>>1);j++){
				int a=x[i+j],b=1ll*x[i+j+(l>>1)]*w[p][j][opt]%mod;
				x[i+j]=(a+b)%mod,x[i+j+(l>>1)]=(a-b+mod)%mod;
			}
	if(opt==1){
		int v=ksm(lim,mod-2);
		for(int i=0;i<lim;i++)
			x[i]=1ll*x[i]*v%mod;
	}
}
poly operator *(poly a,poly b){
	int deg=a.size()+b.size()-1,lim=getlen(deg);
	poly res(lim);
	NTT(a,lim,0),NTT(b,lim,0);
	for(int i=0;i<lim;i++)
		res[i]=1ll*a[i]*b[i]%mod;
	NTT(res,lim,1),res.resize(deg);
	return res;
}
poly f,a,b;
int main(){
	init();
	n=300000,a.resize(n+1),b.resize(n+1);
	for(int i=0;i<=n;i++)
		a[i]=nfac[i],b[i]=i&1? 0:(1ll*coef[i]*nfac[i]%mod);
	f=a*b;
	for(int i=0;i<=n;i++)
		f[i]=1ll*f[i]*fac[i]%mod;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=f[n];
		for(int i=1;i*4<=n;i++){
			int coe=1ll*coef[i+i]*f[n-4*i]%mod;
			ans=(ans+1ll*C(n-2*i,i+i)*mul2[i]%mod*coe)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}