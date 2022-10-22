#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1<<19,maxk=20,mod=998244353,G=3,invG=(mod+1)/3;
typedef vector<int>poly;
int n,k,m;
int btf[maxn],w[maxk][maxn][2],a[maxn],inv[maxn],fac[maxn],nfac[maxn];
poly T[20];
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
	fac[0]=nfac[0]=1;
	for(int i=1;i<maxn;i++)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=i==1? 1:(mod-1ll*(mod/i)*inv[mod%i]%mod),nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
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
	poly res;
	NTT(a,lim,0),NTT(b,lim,0);
	for(int i=0;i<lim;i++)
		res.push_back(1ll*a[i]*b[i]%mod);
	NTT(res,lim,1),res.resize(deg);
	return res;
}
int main(){
	scanf("%d%d%d",&n,&k,&m),init();
	T[0].resize(k+1);
	for(int i=0;i<=k;i++)
		T[0][i]=1;
	for(int i=1;i<n;i++){
		T[i]=T[i-1]*T[i-1];
		int s=0;
		for(int j=k;j<=k+k;j++)
			s=(s+T[i][j])%mod;
		T[i][k]=s,T[i].resize(k+1);
		s=0;
		for(int j=k;j>=0;j--)
			s=(s+T[i][j])%mod,T[i][j]=(1ll*(k-j+1)*T[i][j]+s-T[i][j])%mod;
	}
	T[n]=T[n-1]*T[n-1];
	if(m>k+k)
		puts("0");
	else printf("%d\n",T[n][m]);
	return 0;
}