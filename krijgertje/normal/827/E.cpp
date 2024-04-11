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
#include <complex>
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

const int MAXFFTK=21,MAXFFTN=1<<MAXFFTK;
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
		int ret=0; REP(i,n) { ll cur=(ll)floor(A[i].x+.5); assert(fabs(A[i].x-cur)<.1); if(cur!=0) { assert(i<na+nb-1); while(ret<=i) c[ret++]=0; c[i]=cur; } } return ret;
	}
} FFT;
FFT fft;

const int MAXN=500000;
char s[MAXN+1]; int n;

bool ok[MAXN+1];
int ret[MAXN],nret;

int a[MAXN],na;
int b[MAXN],nb;
ll c[2*MAXN-1]; int nc;

void run() {
	scanf("%d%s",&n,s);
	//n=MAXN; REP(i,n) s[i]='?'; s[n]='\0';
	ok[0]=false; FORE(i,1,n) ok[i]=true;

	na=n,nb=n;
	REP(i,na) a[i]=s[n-i-1]=='V'?1:0;
	REP(i,nb) b[i]=s[i]=='K'?1:0;
	nc=fft.mult(a,na,b,nb,c);

	REP(i,nc) if(c[i]!=0) ok[abs(i-(n-1))]=false;
	FORE(i,1,n) { bool err=false; for(int j=i+i;j<=n;j+=i) if(!ok[j]) err=true; if(err) ok[i]=false; }
	nret=0; FORE(i,1,n) if(ok[i]) ret[nret++]=i;

	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}