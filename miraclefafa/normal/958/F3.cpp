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
const ll mod=1009;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

// FFT_MAXN = 2^k
// fft_init() to precalc FFT_MAXN-th roots

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

void convo(db*a,int n,db*b,int m,db*c){
	static cp f[FFT_MAXN>>1],g[FFT_MAXN>>1],t[FFT_MAXN>>1];
	int N=2;while(N<=n+m)N<<=1;
	rep(i,0,N)
		if(i&1){
			f[i>>1].b=(i<=n)?a[i]:0.0;
			g[i>>1].b=(i<=m)?b[i]:0.0;
		}else{
			f[i>>1].a=(i<=n)?a[i]:0.0;
			g[i>>1].a=(i<=m)?b[i]:0.0;
		}
	dft(f,N>>1);dft(g,N>>1);
	int del=FFT_MAXN/(N>>1);
	cp qua=(cp){0,0.25},one=(cp){1,0},four=(cp){4,0},*w=nw;
	rep(i,0,N>>1){
		int j=i?(N>>1)-i:0;
		t[i]=(four*!(f[j]*g[j])-(!f[j]-f[i])*(!g[j]-g[i])*(one+*w))*qua;
		w+=del;
	}
	dft(t,N>>1,-1);
	rep(i,0,n+m+1)c[i]=(i&1)?t[i>>1].a:t[i>>1].b;
}

const int N=401000;
int n,m,k,x,cnt[N];
double p[N],q[N],r[N];
VI poly[N];
set<PII> st;
VI mul(VI a,VI b) {
	int n=SZ(a),m=SZ(b);
	rep(i,0,n) p[i]=a[i];
	rep(i,0,m) q[i]=b[i];
	convo(p,n-1,q,m-1,r);
	VI c(n+m-1,0);
	rep(i,0,n+m-1) c[i]=(ll)(r[i]+0.5)%mod;
	return c;
}

int main() {
	fft_init();
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,n) {
		scanf("%d",&x); --x;
		cnt[x]++;
	}
	rep(i,0,m) if (cnt[i]) {
		poly[i]=VI(cnt[i]+1,1);
		if (cnt[i]) st.insert(mp(cnt[i]+1,i));
	}
	while (SZ(st)>1) {
		int u=st.begin()->se; st.erase(st.begin());
		int v=st.begin()->se; st.erase(st.begin());
//		printf("%d %d\n",u,v);
		poly[m]=mul(poly[u],poly[v]);
		st.insert(mp(SZ(poly[m]),m));
//		printf("%d %d\n",SZ(st),SZ(poly[m]));
		m++;
	}
	printf("%d\n",poly[st.begin()->se][k]);
}