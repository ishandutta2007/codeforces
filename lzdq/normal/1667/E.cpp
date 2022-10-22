#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=2e5+5,mod=998244353,G=3,invG=(mod+1)/3;
int n;
ll fac[MAXN],inv[MAXN];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll C(int n,int m){
	if(n<m) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void ntt(int *a,int n,int tp){
	int bit=0;
	while(1<<bit<n) bit++;
	static int rev[MAXN<<2];
	for(int i=1; i<n; i++){
		rev[i]=rev[i>>1]>>1|((i&1)<<bit-1);
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	}
	for(int mid=1; mid<n; mid<<=1){
		ll w=1,w1=Fstpw(tp==1?G:invG,(mod-1)/mid/2);
		for(int j=0; j<mid; j++,w=w*w1%mod)
			for(int i=0; i<n; i+=mid*2){
				int x=a[i+j],y=w*a[i+j+mid]%mod;
				a[i+j]=(x+y)%mod;
				a[i+j+mid]=(x-y+mod)%mod;
			}
	}
	if(tp==-1){
		ll t=Fstpw(n,mod-2);
		for(int i=0; i<n; i++)
			a[i]=a[i]*t%mod;
	}
	return ;
}
void NTT(int *a,int n,int *b,int m,int *res,int k){
	int siz=1;
	while(siz<=n+m) siz<<=1;
	static int f[MAXN<<2],g[MAXN<<2];
	for(int i=0; i<siz; i++){
		f[i]=i<=n?a[i]:0;
		g[i]=i<=m?b[i]:0;
	}
	ntt(f,siz,1);
	ntt(g,siz,1);
	for(int i=0; i<siz; i++)
		f[i]=1ll*f[i]*g[i]%mod;
	ntt(f,siz,-1);
	for(int i=0; i<=k; i++)
		res[i]=f[i];
	return ;
}
void Ntt(int *a,int n,int *b,int m,int *res,int k){	// n>=k
	static int f[MAXN<<2];
	for(int i=0; i<=m; i++)
		f[i]=b[m-i];
	NTT(a,n,f,m,f,k+m);
	for(int i=0; i<=k; i++)
		res[i]=f[i+m];
	return ;
}
void GetInv(int *a,int n,int *res){
	static int f[MAXN<<2],g[MAXN<<2];
	g[0]=Fstpw(a[0],mod-2);
	for(int siz=2; siz<=n<<1; siz<<=1){
		int mid=siz>>1,m=siz<<1;
		for(int i=0; i<m; i++){
			f[i]=i<siz&&i<=n?a[i]:0;
			if(i>=mid) g[i]=0;
		}
		ntt(f,m,1);
		ntt(g,m,1);
		for(int i=0; i<m; i++)
			g[i]=1ll*g[i]*(2-1ll*f[i]*g[i]%mod+mod)%mod;
		ntt(g,m,-1);
	}
	for(int i=0; i<=n; i++)
		res[i]=g[i];
	return ;
}
void GetLn(int *a,int n,int *res){	//a[0]=1
	static int f[MAXN<<2],g[MAXN<<2];
	for(int i=0; i<n; i++)
		g[i]=a[i+1]*(i+1ll)%mod;
	g[n]=0;
	GetInv(a,n,f);
	NTT(f,n,g,n,f,n);
	for(int i=1; i<=n; i++)
		res[i]=Fstpw(i,mod-2)*f[i-1]%mod;
	res[0]=0;
	return ;
}
void GetExp(int *a,int n,int *res){	// a[0]=0
	static int f[MAXN<<2],ln[MAXN<<2],aa[MAXN<<2];
	// F = F0 * (1 - ln F0 + A)
	f[0]=1;
	for(int siz=2; siz<=n<<1; siz<<=1){
		int mid=siz>>1,m=siz<<1;
		for(int i=0; i<m; i++){
			if(i>=mid) f[i]=0;
			aa[i]=i<siz&&i<=n?a[i]:0;
			ln[i]=i<mid?f[i]:0;
		}
		GetLn(ln,siz-1,ln);
		ntt(f,m,1);
		ntt(ln,m,1);
		ntt(aa,m,1);
		for(int i=0; i<m; i++)
			f[i]=(1ll-ln[i]+aa[i]+mod)%mod*f[i]%mod;
		ntt(f,m,-1);
		//printf("siz %d\n",siz);
	}
	for(int i=0; i<=n; i++)
		res[i]=f[i];
	return ;
}
int f[MAXN],g[MAXN],ans[MAXN];
int main(){
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	for(int i=1; i<=n/2; i++)
		g[i]=fac[i-1]*inv[i]%mod;
	GetExp(g,n,g);
	for(int i=(n+1)/2; i<n; i++)
		f[i]=g[i-1]*fac[n-i-1]%mod;
	ans[1]=g[n-1]*fac[n-1]%mod;
	for(int i=0; i<=n; i++)
		g[i]=inv[i];
	NTT(f,n,g,n,f,n);
	for(int i=2; i<=n; i++)
		ans[i]=f[n-i+1]*fac[n-i]%mod*(i-1)%mod;
	/*
	ans[1]=f[n];
	for(int i=2; i<=n; i++)
		for(int j=(n+1)/2; j<n; j++)
			ans[i]=(ans[i]+C(n-i,j-1)*fac[n-j-1]%mod*f[j]%mod*(i-1))%mod;
	*/
	for(int i=1; i<=n; i++)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}
// fuckccf