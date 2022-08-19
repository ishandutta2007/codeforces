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
const ll mo=490019;
ll powmod(ll a,ll b) {ll res=1;a%=mo; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
// FFT_MAXN = 2^k
// fft_init() to precalc FFT_MAXN-th roots

const int N=500000;
typedef double db;
const int FFT_MAXN=262144;
const db pi=acos(-1.);
struct cp{
	db a,b;
	cp operator+(const cp&y)const{return (cp){a+y.a,b+y.b};}
	cp operator-(const cp&y)const{return (cp){a-y.a,b-y.b};}
	cp operator*(const cp&y)const{return (cp){a*y.a-b*y.b,a*y.b+b*y.a};}
	cp operator!()const{return (cp){a,-b};};

}nw[FFT_MAXN+1];int bitrev[FFT_MAXN];
int ccc=0;
void dft(cp*a,int n,int flag=1){
	ccc++;
//	printf("dft %d\n",ccc);
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
	nw[0]=nw[FFT_MAXN]=(cp){1,0};
	rep(i,0,FFT_MAXN+1)nw[i]=(cp){cos(2*pi/FFT_MAXN*i),sin(2*pi/FFT_MAXN*i)};	//very slow
}

map<int,vector<cp>> fa,fb;
void mul(int *a,int *b,int n){// n<=N, 0<=a[i],b[i]<mo
	static cp f[N],g[N],t[N],r[N];
	static int p1[N],q1[N];
	rep(i,0,n) p1[i]=a[i],q1[i]=b[i];
	int nn=2;while(nn<=n+n)nn<<=1;
	rep(i,0,nn){
		f[i]=(i<=n)?(cp){(db)(a[i]>>15),(db)(a[i]&32767)}:(cp){0,0};
		g[i]=(i<=n)?(cp){(db)(b[i]>>15),(db)(b[i]&32767)}:(cp){0,0};
	}
	swap(n,nn);
	dft(f,n,1);dft(g,n,1);
	rep(i,0,n){
		int j=i?n-i:0;
		t[i]=( (f[i]+!f[j])*(!g[j]-g[i]) + (!f[j]-f[i])*(g[i]+!g[j]) )*(cp){0,0.25};
		r[i]=(!f[j]-f[i])*(!g[j]-g[i])*(cp){-0.25,0} + (cp){0,0.25}*(f[i]+!f[j])*(g[i]+!g[j]);
	}
	dft(t,n,-1); dft(r,n,-1);
	rep(i,0,n)a[i]=( (ll(t[i].a+0.5)%mo<<15) + ll(r[i].a+0.5) + (ll(r[i].b+0.5)%mo<<30) )%mo;
}

const ll inf=1ll<<60;
int n,m,c,x;
int va[4][N],vb[4][N],p[N],q[N];
ll posa[N],posb[N],a[N],b[N];
ll pos[N],ans[N],ans2[N];
PII c1[N];
int main() {
	fft_init();
	scanf("%d%d%d",&n,&m,&c);
	rep(i,0,n) {
		scanf("%d",&x);
		a[i]=x;
		posa[(ll)i*i%(mo-1)]+=x;
	}
	rep(i,0,m) {
		scanf("%d",&x);
		b[i]=x;
		posb[(ll)i*i*i%(mo-1)]+=x;
	}
	rep(i,0,mo) posa[i]%=mo,posb[i]%=mo;
	int pl=122010;
	int pp=1;
	int base[]={1,2,11,22};
	rep(i,0,mo) c1[i]=mp(-1,-1);
	rep(i,0,pl) {
		ll qq=pp;
		c1[qq]=mp(i,0);
		qq=pp*2%(mo-1);
		c1[qq]=mp(i,1);
		qq=pp*11%(mo-1);
		c1[qq]=mp(i,2);
		qq=pp*22%(mo-1);
		c1[qq]=mp(i,3);
		pos[i]=pp;
		pp=pp*19%(mo-1);
	}
	rep(i,0,mo-1) {
		if (c1[i]!=mp(-1,-1)) {
			va[c1[i].se][c1[i].fi]=posa[i];
			vb[c1[i].se][c1[i].fi]=posb[i];
		} else {
			if (posa[i]) {
				int po=0;
				rep(j,0,mo-1) {
					ans[po]+=posa[i]*posb[j];
					if (ans[po]>=inf) ans[po]%=mo;
					po+=i; if (po>=mo-1) po-=mo-1;
				}
			}
			if (posb[i]) {
				int po=0;
				rep(j,0,mo-1) {
					if (c1[j]!=mp(-1,-1)) {
						ans[po]+=posa[j]*posb[i];
						if (ans[po]>=inf) ans[po]%=mo;
					}
					po+=i; if (po>=mo-1) po-=mo-1;
				}
			}
		}
	}
	rep(i,0,mo-1) ans[i]%=mo;
	rep(i,0,4) rep(j,0,4) {
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		rep(k,0,pl) p[k]=va[i][k],q[k]=vb[j][k];
		mul(p,q,pl);
		rep(k,0,2*pl) {
			int w=(ll)base[i]*base[j]*pos[k%pl]%(mo-1);
			ans[w]+=p[k];
		}
	}
	rep(i,0,mo-1) ans[i]%=mo;
	ll ret=0;
	ll cc=1;
	rep(i,0,mo) {
		ret=(ret+ans[i]*cc)%mo;
		cc=cc*c%mo;
	}
	printf("%lld\n",ret);
}