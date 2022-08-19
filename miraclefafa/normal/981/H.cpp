#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=998244353;

ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=401000;

int q[N],f[N],vis[N],sz[N],ms[N];
VI e[N];

int find(int u) {
	int t=1;q[0]=u;f[u]=-1;
	rep(i,0,t) {
		u=q[i];
		rep(j,0,e[u].size()) {
			int v=e[u][j];
			if (!vis[v]&&v!=f[u]) f[q[t++]=v]=u;
		}
		ms[q[i]]=0;
		sz[q[i]]=1;
	}
	for (int i=t-1;i>=0;i--) {
		ms[q[i]]=max(ms[q[i]],t-sz[q[i]]);
		if (ms[q[i]]*2<=t) return q[i];
		sz[f[q[i]]]+=sz[q[i]];
		ms[f[q[i]]]=max(ms[f[q[i]]],sz[q[i]]);
	}
	return 0;
}

typedef double db;
const int FFT_MAXN=262144;
const db pi=acos(-1.);
struct cp{
	db a,b;
	cp() {}
	cp(db a,db b):a(a),b(b) {}
	cp operator+(const cp&y)const{return (cp){a+y.a,b+y.b};}
	cp operator-(const cp&y)const{return (cp){a-y.a,b-y.b};}
	cp operator*(const cp&y)const{return (cp){a*y.a-b*y.b,a*y.b+b*y.a};}
	cp operator!()const{return (cp){a,-b};};
}nw[FFT_MAXN+1];int bitrev[FFT_MAXN];
void dft(cp*a,int n,int flag=1){
	int d=0;while((1<<d)*n!=FFT_MAXN)d++;
	rep(i,0,n)if(i<(bitrev[i]>>d))swap(a[i],a[bitrev[i]>>d]);
	for (int l=2;l<=n;l<<=1){
		int del=FFT_MAXN/l*flag;
		for (int i=0;i<n;i+=l){
			cp *le=a+i,*ri=a+i+(l>>1),*w=flag==1?nw:nw+FFT_MAXN;
			rep(k,0,l>>1){
				cp ne=*ri**w;
				*ri=*le-ne,*le=*le+ne;
				le++,ri++,w+=del;
			}
		}
	}
	if(flag!=1)rep(i,0,n)a[i].a/=n,a[i].b/=n;
}
void fft_init(){
	int L=0;while((1<<L)!=FFT_MAXN)L++;
	bitrev[0]=0;rep(i,1,FFT_MAXN)bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(L-1));
//	cp ste=(cp){cos(2*pi/FFT_MAXN),sin(2*pi/FFT_MAXN)};
//	nw[0]=nw[FFT_MAXN]=(cp){1,0};
//	rep(i,1,(FFT_MAXN>>1)+1)nw[i]=nw[i-1]*ste;
//	rep(i,(FFT_MAXN>>1)+1,FFT_MAXN)nw[i]=!nw[FFT_MAXN-i];
	rep(i,0,FFT_MAXN+1)nw[i]=(cp){cos(2*pi/FFT_MAXN*i),sin(2*pi/FFT_MAXN*i)};	//very slow
}
int tmpp[N],tmpq[N],ex[N];

void convo(int *a,int *b,int n){// n<=N, 0<=a[i],b[i]<mo
	static cp f[N],g[N],t[N],r[N];
	rep(i,0,n){
		f[i]=cp(a[i]>>15,a[i]&32767);
		g[i]=cp(b[i]>>15,b[i]&32767);
	}
	dft(f,n,1);dft(g,n,1);
	rep(i,0,n){
		int j=i?n-i:0;
		t[i]=( (f[i]+!f[j])*(!g[j]-g[i]) + (!f[j]-f[i])*(g[i]+!g[j]) )*(cp){0,0.25};
		r[i]=(!f[j]-f[i])*(!g[j]-g[i])*(cp){-0.25,0} + (cp){0,0.25}*(f[i]+!f[j])*(g[i]+!g[j]);
	}
	dft(t,n,-1);
	dft(r,n,-1);
	rep(i,0,n)a[i]=( (ll(t[i].a+0.5)%mod<<15) + ll(r[i].a+0.5) + (ll(r[i].b+0.5)%mod<<30) )%mod;
}

VI mul(VI a,VI b,int k=1e9) {
	int n=SZ(a),m=SZ(b),z=1;
	while (z<n+m+5) z=z+z;
	rep(i,0,z+1) tmpp[i]=tmpq[i]=0;
	rep(i,0,n) tmpp[i]=a[i];
	rep(i,0,m) tmpq[i]=b[i];
	convo(tmpp,tmpq,z);
	VI c(min(n+m-1,k),0);
	rep(i,0,SZ(c)) c[i]=tmpp[i];
	return c;
}

VI poly[N];
int n,k,u,v;
ll ans,bb[N],fac[N],fnv[N],ff[N];
VI extra[N];

ll merge(VI c) {
	if (SZ(c)==0) return 1;
	int h=0,t=0;
	rep(i,0,SZ(c)) {
		poly[t++]=VI{1,c[i]};
	}
	rep(i,0,SZ(c)-1) {
		poly[t++]=mul(poly[h],poly[h+1],k);
		h+=2;
	}
//	for (auto p:c) printf("%d ",p); puts("mm");
//	for (auto p:poly[t-1]) printf("%d ",p); puts("cc");
	ll w=0;
	for (int i=0;i<=k&&i<SZ(poly[t-1]);i++) w=(w+poly[t-1][i]*ff[i])%mod;
//	printf("tt %lld\n",w);
	return w;
}
VI Merge(VI c) {
	if (SZ(c)==0) return VI{1};
	int h=0,t=0;
	rep(i,0,SZ(c)) {
		poly[t++]=VI{1,c[i]};
	}
	rep(i,0,SZ(c)-1) {
		poly[t++]=mul(poly[h],poly[h+1]);
		h+=2;
	}
	return poly[t-1];
}
void dfs(int u,int f,int br) {
	VI cc=extra[u];
	sz[u]=1+ex[u];
	for (auto v:e[u]) if (v!=f&&!vis[v]) {
		dfs(v,u,br);
		cc.pb(sz[v]);
		sz[u]+=sz[v];
	}
	bb[br]=(bb[br]+merge(cc))%mod;
}

int calc(const VI &a,int p) {
	int rem=0;
	ll inv=(mod-powmod(p,mod-2))%mod;
	int m=SZ(a)-1;
	per(i,1,SZ(a)) {
		rem=(rem+a[i])*inv%mod;
//		printf("%lld ",mod-rem);
		tmpp[i-1]=mod-rem;
	}
//	puts("div");
	ll w=0;
	for (int i=0;i<=k&&i<m;i++) w=(w+tmpp[i]*ff[i])%mod;
	return w;
}
void solve(int u) {
	u=find(u);
	VI dd=extra[u];
	ll cur=0;
	sz[u]=1+ex[u];
	for (auto v:e[u]) if (!vis[v]) {
		bb[v]=0;
		dfs(v,u,v);
		sz[u]+=sz[v];
		dd.pb(sz[v]);
//		printf("bb %d %lld %d\n",v,bb[v],sz[v]);
		ans=(ans+bb[v]*cur)%mod;
		cur=(cur+bb[v])%mod;
	}
	VI p=Merge(dd);
//	for (auto q:p) printf("%d ",q); puts("dd");
	map<int,int> cache;
//	printf("ggggggg %lld\n",ans);
	for (auto v:e[u]) if (!vis[v]) {
		if (!cache.count(sz[v])) {
			cache[sz[v]]=calc(p,sz[v]);
		}
/*		VI cc=extra[u];
		for (auto w:e[u]) if (!vis[w]&&w!=v) cc.pb(sz[w]);
//		cc.pb(n-sz[u]);
		printf("zz %d %lld\n",v,bb[v]*merge(cc)%mod);
		ans=(ans+bb[v]*merge(cc))%mod;*/
		ans=(ans+bb[v]*cache[sz[v]])%mod;
	}
//	printf("ggggggg %lld\n",ans);
	vis[u]=1;
	for (auto v:e[u]) if (!vis[v]) {
		extra[v].pb(sz[u]-sz[v]);
		ex[v]+=sz[u]-sz[v];
		solve(v);
	}
}
int main() {
	fft_init();
	scanf("%d%d",&n,&k);
	fac[0]=fnv[0]=1;
	rep(i,1,k+1) fac[i]=fac[i-1]*i%mod,fnv[i]=powmod(fac[i],mod-2);
	rep(i,0,k+1) ff[i]=fac[k]*fnv[k-i]%mod;
	if (k==1) ff[1]=0;
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	solve(1);
	printf("%lld\n",ans);
}