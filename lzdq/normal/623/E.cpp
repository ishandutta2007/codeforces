#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<ctime>
using namespace std;
typedef long long ll;
typedef vector<int> Poly;
const int MAXN=3e4+5,mod=1e9+7;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll Fstpw(ll a,int b,int mod){
	a%=mod;
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll n,fac[MAXN],inv[MAXN];
int m,k,ans;
void ntt(int *a,int n,int tp,int mod){
	const ll G=3,invG=Fstpw(G,mod-2,mod);
	int bit=0;
	while(1<<bit<n) bit++;
	static int rev[MAXN<<2];
	for(int i=1; i<n; i++){
		rev[i]=rev[i>>1]>>1|((i&1)<<bit-1);
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	}
	for(int mid=1; mid<n; mid<<=1){
		ll w=1,w1=Fstpw(tp==1?G:invG,(mod-1)/mid/2,mod);
		for(int j=0; j<mid; j++,w=w*w1%mod)
			for(int i=0; i<n; i+=mid*2){
				int x=a[i+j],y=w*a[i+j+mid]%mod;
				a[i+j]=(x+y)%mod;
				a[i+j+mid]=(x-y+mod)%mod;
			}
	}
	if(tp==-1){
		ll t=Fstpw(n,mod-2,mod);
		for(int i=0; i<n; i++)
			a[i]=a[i]*t%mod;
	}
	return ;
}
void NTT(Poly &a,Poly &b,int* c,int mod){
	int siz=1;
	while(siz<=m*2) siz<<=1;
	static int f[MAXN<<2],g[MAXN<<2];
	for(int i=0; i<siz; i++){
		f[i]=i<=m?a[i]%mod:0;
		g[i]=i<=m?b[i]%mod:0;
	}
	ntt(f,siz,1,mod);
	ntt(g,siz,1,mod);
	for(int i=0; i<siz; i++)
		f[i]=1ll*f[i]*g[i]%mod;
	ntt(f,siz,-1,mod);
	for(int i=0; i<=m; i++)
		c[i]=f[i];
	return ;
}
Poly operator *(Poly a,Poly b){
	/*
	Poly c(m+1);
	for(int i=0; i<=m; i++)
		for(int j=0; i+j<=m; j++)
			c[i+j]=(c[i+j]+1ll*a[i]*b[j])%mod;
	return c;
	*/

	/*
	   469762049
	   998244353
	   1004535809
	 */
	static const int md[3]={469762049,998244353,1004535809};
	static const __int128 co[3]={
		(__int128)md[1]*md[2]*Fstpw(1ll*md[1]*md[2]%md[0],md[0]-2,md[0]),
		(__int128)md[0]*md[2]*Fstpw(1ll*md[0]*md[2]%md[1],md[1]-2,md[1]),
		(__int128)md[0]*md[1]*Fstpw(1ll*md[0]*md[1]%md[2],md[2]-2,md[2])
	};
	static int c[3][MAXN];
	for(int i=0; i<3; i++)
		NTT(a,b,c[i],md[i]);
	Poly res(m+1);
	for(int i=0; i<=m; i++){
		__int128 sum=0;
		for(int j=0; j<3; j++)
			sum+=c[j][i]*co[j];
		sum%=(__int128)(md[0])*md[1]*md[2];
		res[i]=sum%mod;
	}
	return res;
}
Poly Calc(int t){
	Poly res,mul;
	if(t==0){
		res.resize(m+1);
		res[0]=1;
		return res;
	}
	res=Calc(t>>1);
	mul.resize(m+1);
	ll x=Fstpw(2,t>>1),y=1;
	for(int i=0; i<=m; i++,y=y*x%mod)
		mul[i]=res[i]*y%mod;
	res=res*mul;
	if(t&1){
		mul.resize(m+1);
		x=Fstpw(2,t-1),y=1;
		for(int i=0; i<=m; i++,y=y*x%mod)
			mul[i]=inv[i+1]*y%mod;
		res=res*mul;
	}
	return res;
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%lld%d",&n,&k);
	if(n>k) return puts("0"),0;
	fac[0]=1;
	for(int i=1; i<=k; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[k]=Fstpw(fac[k],mod-2);
	for(int i=k; i; i--)
		inv[i-1]=inv[i]*i%mod;
	m=k-n;
	Poly res(Calc(n));
	for(int i=0; i<=m; i++)
		ans=(ans+res[i]*inv[m-i])%mod;
	ans=ans*fac[k]%mod*Fstpw(2,n*(n-1)/2)%mod;
	printf("%d\n",ans);
	//printf("%.2f\n",(double)(clock())/CLOCKS_PER_SEC);
	return 0;
}
///