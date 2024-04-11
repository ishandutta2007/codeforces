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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2010000;

typedef double db;
const int FFT_MAXN=1<<21;
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
ll tmpp[N],tmpq[N];

const int mo=1000000;
void convo(ll *a,ll *b,int n){// n<=N, 0<=a[i],b[i]<mo
	static cp f[N],g[N],t[N],r[N];
	rep(i,0,n){
		f[i]=cp(a[i]>>15,a[i]&32767);
		g[i]=cp(b[i]>>15,b[i]&32767);
	}
	dft(f,n,1); dft(g,n,1);
	rep(i,0,n){
		int j=i?n-i:0;
		t[i]=( (f[i]+!f[j])*(!g[j]-g[i]) + (!f[j]-f[i])*(g[i]+!g[j]) )*(cp){0,0.25};
		r[i]=(!f[j]-f[i])*(!g[j]-g[i])*(cp){-0.25,0} + (cp){0,0.25}*(f[i]+!f[j])*(g[i]+!g[j]);
	}
	dft(t,n,-1);
	dft(r,n,-1);
	rep(i,0,n)a[i]=( (ll(t[i].a+0.5)<<15) + ll(r[i].a+0.5) + (ll(r[i].b+0.5)<<30) );
	rep(i,0,n) {
		a[i+1]+=a[i]/mo;
		a[i]%=mo;
	}
}

VI mul(VI a,VI b) {
	int n=SZ(a),m=SZ(b),z=1;
	while (z<n+m+5) z=z+z;
	rep(i,0,z+1) tmpp[i]=tmpq[i]=0;
	rep(i,0,n) tmpp[i]=a[i];
	rep(i,0,m) tmpq[i]=b[i];
	convo(tmpp,tmpq,z);
	while (tmpp[z]==0) --z;
	return VI(tmpp,tmpp+z+1);
}

char s[N];
int n,m,z;
VI poww(VI a,ll b) {
	VI ret(1,1);
	for(;b;b>>=1){if(b&1)ret=mul(ret,a);a=mul(a,a);}
	return ret;
}

void div(VI &a,int b) {
	ll rem=0;
	per(i,0,SZ(a)) {
		rem=(rem*mo+a[i]);
		a[i]=rem/b;
		rem%=b;
	}
}
void mul(VI &a,int b) {
	rep(i,0,SZ(a)) a[i]=a[i]*b;
	rep(i,0,SZ(a)-1) {
		a[i+1]+=a[i]/mo;
		a[i]%=mo;
	}
}
int cmp(VI a,VI b) {
	reverse(all(a)); reverse(all(b));
	if (a<b) return -1;
	if (a==b) return 0;
	return 1;
}

void print(VI v) {
	reverse(all(v));
	for (auto p:v) printf("%06d",p);
	puts("");
}

int main() {
	fft_init();
	scanf("%s",s);
	n=strlen(s);
	if (n<=5) {
		sscanf(s,"%d",&m);
		if (m<=3) {
			printf("%d\n",m);
			return 0;
		}
		for (int i=4;i<=100;i++) {
			ll w=1;
			if (i%3==0) w=powmod(3,i/3);
			else if (i%3==1) w=powmod(3,i/3-1)*4;
			else w=powmod(3,i/3)*2;
			if (w>=m) {
				printf("%d\n",i);
				return 0;
			}
		}
	}
	int z=max((int)(n*log(10)/log(3)*3)-10,12);
	while (z%3!=0) --z;
	m=n/6+50;
	VI c=poww(VI{3},z/3);
	while (SZ(c)<m) c.pb(0);
	VI d(m,0);
	per(i,0,n) {
		d[i/6]=d[i/6]*10+(s[n-1-i]-'0');
	}
//	printf("%d\n",z);
//	print(c);
	while (cmp(c,d)==-1) {
		if (z%3==0) {
			div(c,3); mul(c,4);
		}
		if (z%3==1) {
			div(c,2); mul(c,3);
		}
		if (z%3==2) {
			div(c,2); mul(c,3);
		}
		z++;
//		printf("%d\n",z);
//		print(c);
	}
	printf("%d\n",z);
}