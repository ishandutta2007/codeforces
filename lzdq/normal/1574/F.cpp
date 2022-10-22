#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5,mod=998244353,G=3,invG=(mod+1)/3;
int n,m,k,a[MAXN],las[MAXN];
int pre[MAXN],tag[MAXN],sum[MAXN],p[MAXN],s[MAXN],siz[MAXN];
int fnd(int x){
	if(pre[x]!=x) pre[x]=fnd(pre[x]);
	return pre[x];
}
inline void Add(int x,int y){
	if(s[x]&&s[x]!=y) tag[x]=1;
	else s[x]=y;
	if(p[y]&&p[y]!=x) tag[y]=1;
	else p[y]=x;
	pre[fnd(x)]=fnd(y);
}
int g[MAXN];
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
	for(int i=0; i<=k; i++)
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
int main(){
	//freopen("in3.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=k; i++)
		pre[i]=i;
	for(int i=1; i<=n; i++){
		int c,t=0;
		scanf("%d",&c);
		for(int j=0; j<c; j++){
			scanf("%d",a+j);
			if(las[a[j]]==i) t=1;
			las[a[j]]=i;
			if(j) Add(a[j-1],a[j]);
		}
		if(t) for(int j=0; j<c; j++) tag[a[j]]=1;
	}
	for(int i=1; i<=k; i++){
		if(tag[i]) tag[fnd(i)]=1;
		if(!p[i]) sum[fnd(i)]=1;
		siz[fnd(i)]++;
	}
	for(int i=1; i<=k; i++)
		if(i==fnd(i)&&!tag[i]&&sum[i]) g[siz[i]]--;
	g[0]=1;
	for(int i=1; i<=m; i++)
		g[i]=(g[i]+mod)%mod;
	GetInv(g,m,g);
	printf("%d\n",g[m]);
	return 0;
}