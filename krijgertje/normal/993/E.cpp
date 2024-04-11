#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

const int MAXFFTK=19,MAXFFTN=1<<MAXFFTK;
const long double MPI=acos((long double)-1);
typedef struct cplx { long double x,y; cplx(long double x=0,long double y=0):x(x),y(y) {} } cplx;
inline cplx operator*(const cplx &a,const cplx &b) { return cplx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x); }
inline cplx operator+(const cplx &a,const cplx &b) { return cplx(a.x+b.x,a.y+b.y); }
inline cplx operator-(const cplx &a,const cplx &b) { return cplx(a.x-b.x,a.y-b.y); }
inline cplx conj(const cplx &a) { return cplx(a.x,-a.y); }
typedef struct FFT {
	int n,lgn;
	int bitrev[MAXFFTN];
	cplx w[MAXFFTN];

	void prefft(int _n) {
		n=_n; lgn=0; while((1<<lgn)<n) ++lgn; assert(n==(1<<lgn));
		bitrev[0]=0; FOR(i,1,n) bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(lgn-1));
		w[1]=cplx(1,0); REP(i,lgn-1) { long double a=MPI/(n>>(lgn-1-i)); cplx mlt=cplx(cos(a),sin(a)); FOR(j,1<<i,2<<i) w[2*j]=w[j],w[2*j+1]=w[j]*mlt; }
	}

	void fft(cplx *a,int n,bool inv=false) {
		if(n!=this->n) prefft(n);
		REP(i,n) if(i<bitrev[i]) swap(a[i],a[bitrev[i]]);
		if(inv) REP(i,n) a[i].y=-a[i].y;
		for(int len=1;len<n;len<<=1) for(int i=0;i<n;i+=len) for(int rep=0,j=i+len,wi=len;rep<len;++rep,++i,++j,++wi) { cplx tmp=a[j]*w[wi]; a[j]=a[i]-tmp; a[i]=a[i]+tmp; }
	}

	cplx A[MAXFFTN+1];
	int mult(int *a,int na,int *b,int nb,ll *c) {
		if(na==0||nb==0) return 0;
		int n=1; while(n<na+nb-1) n<<=1; assert(n<=MAXFFTN);
		REP(i,n) A[i]=cplx(i<na?a[i]:0,i<nb?b[i]:0);
		fft(A,n,false);
		A[n]=A[0]; for(int i=0,j=n;i<=j;++i,--j) A[i]=(A[i]*A[i]-conj(A[j]*A[j]))*cplx(0,(long double)-1/4/n),A[j]=conj(A[i]);
		fft(A,n,true);
		int ret=0; REP(i,n) { ll cur=(ll)floor(A[i].x+.5); /*assert(fabs(A[i].x-cur)<.1);*/ if(cur!=0) { /*assert(i<na+nb-1);*/ while(ret<=i) c[ret++]=0; c[i]=cur; } } return ret;
	}
} FFT;
FFT fft;

int n,want;
int a[MAXN];

int b[MAXN+1];
int c[MAXN+1],nc;
int d[MAXN+1],nd;
ll e[MAXFFTN]; int ne;

ll ans[MAXN+1];



void run() {
	scanf("%d%d",&n,&want); REP(i,n) scanf("%d",&a[i]);
	//n=MAXN; want=0; REP(i,n) a[i]=i%2==0?-1:+1;
	
	b[0]=0; REP(i,n) b[i+1]=b[i]+(a[i]<want?1:0);
	nc=b[n]+1; REP(i,n) c[i]=0; REPE(i,n) ++c[b[i]];
	nd=nc; REP(i,nd) d[i]=c[nc-i-1];
	//printf("c:"); REP(i,nc) printf(" %d",c[i]); puts("");
	//printf("d:"); REP(i,nd) printf(" %d",d[i]); puts("");
	ne=fft.mult(c,nc,d,nd,e);
	//printf("e:"); REP(i,ne) printf(" %lld",e[i]); puts("");

	ans[0]=0; REP(i,nc) ans[0]=ans[0]+(ll)c[i]*(c[i]-1)/2;
	FORE(i,1,n) ans[i]=e[nc+i-1];
	REPE(i,n) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}