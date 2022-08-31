#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

// FFT_MAXN = 2^k
// fft_init() to precalc FFT_MAXN-th roots

typedef long double db;
const int FFT_MAXN=(1<<20);
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
	cp ste=(cp){cosl(2*pi/FFT_MAXN),sinl(2*pi/FFT_MAXN)};
	nw[0]=nw[FFT_MAXN]=(cp){1,0};
	rep(i,1,(FFT_MAXN>>1)+1)nw[i]=nw[i-1]*ste;
	rep(i,(FFT_MAXN>>1)+1,FFT_MAXN)nw[i]=!nw[FFT_MAXN-i];
	//rep(i,0,FFT_MAXN)nw[i]=(cp){cosl(2*pi/FFT_MAXN*i),sinl(2*pi/FFT_MAXN*i)};	//very slow
}

void convo(int*a,int n,int*b,int m,int*c){
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
	rep(i,0,n+m+1)c[i]=(i&1)?int(t[i>>1].a+0.5):int(t[i>>1].b+0.5);
}
const int N=(1<<20)+10;
int n,_,pa[N],pb[N],pc[N],ret[N],x[N],v[N];
char s[N];

int main() {
	fft_init();
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		scanf("%s",s);
		n=strlen(s);
		rep(i,0,n) x[i]=(s[i]=='?')?0:1;
		rep(i,0,n) v[i]=(s[i]=='V')?0:1;
		rep(i,0,n) {
			pa[i]=x[i]*v[i]*v[i];
			pb[i]=x[i];
		}
		reverse(pb,pb+n);
		rep(i,0,n+1) ret[i]=0;
		convo(pa,n-1,pb,n-1,pc);
		rep(i,0,2*n-1) {
			if (i>=n-1) {
				ret[i-(n-1)]+=pc[i];
			}
			if (i<=n-1) {
				ret[(n-1)-i]+=pc[i];
			}
		}
		rep(i,0,n) {
			pa[i]=pb[i]=x[i]*v[i];
		}
		reverse(pb,pb+n);
		convo(pa,n-1,pb,n-1,pc);
		rep(i,n-1,2*n-1) ret[i-(n-1)]-=2*pc[i];
		rep(i,1,n) for (int j=i+i;j<n;j+=i) ret[i]+=ret[j];
		int c=0;
		rep(i,1,n+1) c+=(ret[i]==0);
		printf("%d\n",c);
		rep(i,1,n+1) if (ret[i]==0) {
			printf("%d ",i);
		}
		puts("");
	}
}