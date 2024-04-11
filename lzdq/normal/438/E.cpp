#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
const bool debug=0;
typedef long long ll;
const int MAXN=2e5+5,mod=998244353,G=3,invG=(mod+1)/3;
int n,m,c[MAXN];
int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x*10ll+(ch^48))%mod,ch=getchar();
	return x;
}
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
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
	for(int i=0; i<=min(k,n+m); i++)
		res[i]=f[i];
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
void GetSqrt(int *a,int n,int *res){	// a[0] Quadratic residue
	const int blks=1e5;
	static int f[MAXN<<2],g[MAXN<<2],pw1[blks+5],pw2[blks+5];;
	map<int,int> mp;
	pw1[0]=pw2[0]=1;
	mp[1]=0;
	for(int i=1; i<=blks; i++)
		pw1[i]=1ll*pw1[i-1]*G%mod,mp[pw1[i]]=i;
	for(int i=1; i<=blks; i++)
		pw2[i]=1ll*pw2[i-1]*pw1[blks]%mod;
	for(int i=0; i<=blks; i++){
		int t=a[0]*Fstpw(pw2[i],mod-2)%mod;
		if(mp.count(t)){
			f[0]=(1ll*i*blks+mp[t])%(mod-1)/2;
			f[0]=Fstpw(G,f[0]);
			break;
		}
	}
	for(int siz=2; siz<=n<<1; siz<<=1){
		int mid=siz>>1;
		for(int i=mid; i<siz; i++)
			f[i]=0;
		GetInv(f,siz-1,g);
		NTT(f,siz-1,f,siz-1,f,siz-1);
		for(int i=0; i<siz; i++)
			f[i]=(f[i]+a[i])%mod;
		NTT(f,siz-1,g,siz-1,f,siz-1);
		for(int i=0; i<siz; i++)
			f[i]=f[i]*(mod+1ll)/2%mod;
	}
	for(int i=0; i<=n; i++)
		res[i]=f[i];
	return ;
}
int ans[MAXN],a[MAXN];
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&m);
	int pos=m;
	while(n--){
		int a; scanf("%d",&a);
		if(a>m) continue;
		c[a]=1;
		pos=min(pos,a);
	}
	for(int i=1; i<=m; i++)
		if(c[i]) a[i]=mod-4;
	a[0]=1;
	GetSqrt(a,m*2,a);
	for(int i=1; i<=m*2; i++)
		a[i]=(mod-a[i])%mod;
	a[0]=0;
	GetInv(c+pos,m,c);
	NTT(a+pos,m,c,m,ans,m);
	for(int i=1; i<=m; i++)
		printf("%lld\n",ans[i]*(mod+1ll)/2%mod);
	return 0;
}