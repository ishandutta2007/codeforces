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

const int MAXK=30000;
const int LGN=16;
const int N=1<<LGN;
const int MOD=1000000007;
const double MYPI=acos(-1);
typedef struct Pol { int x[MAXK+1]; } Pol;

int bitrev[N];
complex<double> w[N];
void prefft() {
	REP(i,N) bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(LGN-1));
	REP(i,N) w[i]=complex<double>(cos(2*MYPI*i/N),sin(2*MYPI*i/N));
}
void fft(complex<double> a[N]) {
	REP(i,N) if(i<bitrev[i]) swap(a[i],a[bitrev[i]]);
	for(int len=2,step=N>>1;len<=N;len<<=1,step>>=1) {
        for(int i=0;i<N;i+=len) {
			complex<double> *l=a+i,*r=l+(len>>1),*p=w;
			REP(off,len>>1) {
                complex<double> v=*r**p;
                *r=*l-v; *l=*l+v;
				++l,++r,p+=step;
            }
        }
	}
}
int inv[MAXK+1];
int fact[MAXK+1];
int ifact[MAXK+1];
int ipow(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int K;
void pmult(Pol &c,Pol &a,Pol &b) {
	static complex<double> A[N],B[N],C[N],D[N];
	REPE(i,K) A[i]=complex<double>(a.x[i]&((1<<15)-1),a.x[i]>>15);
	REPE(i,K) B[i]=complex<double>(b.x[i]&((1<<15)-1),b.x[i]>>15);
	FOR(i,K+1,N) A[i]=B[i]=complex<double>(0,0);
	fft(A); fft(B);
	REP(i,N) {
		int j=(N-i)&(N-1);
		complex<double> w=(A[i]+conj(A[j]))*complex<double>(.5,0);
		complex<double> x=(A[i]-conj(A[j]))*complex<double>(0,-.5);
		complex<double> y=(B[i]+conj(B[j]))*complex<double>(.5,0);
		complex<double> z=(B[i]-conj(B[j]))*complex<double>(0,-.5);
		C[j]=w*y+w*z*complex<double>(0,1);
		D[j]=x*y+x*z*complex<double>(0,1);
	}
	fft(C); fft(D);
	REPE(i,K) {
		int w=(ll)(real(C[i])/N+.5)%MOD;
		int x=(ll)(imag(C[i])/N+.5)%MOD;
		int y=(ll)(real(D[i])/N+.5)%MOD;
		int z=(ll)(imag(D[i])/N+.5)%MOD;
		c.x[i]=(w+((ll)(x+y)<<15)+((ll)z<<30))%MOD;
	}
}
void pmult(Pol &a,int n2,Pol &b) {
	static Pol c; int step=ipow(2,n2),mlt=1;
	REPE(i,K) c.x[i]=(ll)a.x[i]*mlt%MOD,mlt=(ll)mlt*step%MOD;
	pmult(a,c,b);
}
void ppow(Pol &a,Pol &b,int n) {
	REPE(i,K) a.x[i]=i==0?1:0;
	static Pol c; REPE(i,K) c.x[i]=b.x[i]; int cn=1;
	while(true) {
		if(n&1) pmult(a,cn,c);
		if((n>>=1)==0) break;
		pmult(c,cn,c),cn+=cn;
	}
}

ll n;
Pol h1;
Pol hn;

void run() {
	fact[0]=1; FORE(i,1,MAXK) fact[i]=(ll)fact[i-1]*i%MOD;
	inv[1]=1; FORE(i,2,MAXK) inv[i]=(MOD-(ll)(MOD/i)*inv[MOD%i]%MOD)%MOD;
	ifact[0]=1; FORE(i,1,MAXK) ifact[i]=(ll)ifact[i-1]*inv[i]%MOD;

	scanf("%I64d%d",&n,&K);
	if(n>K) { printf("0\n"); return; }
	//REPE(i,K) printf("%d: %d %d %d\n",i,fact[i],inv[i],ifact[i]);

	h1.x[0]=0; FORE(i,1,K) h1.x[i]=ifact[i];
	prefft();
	ppow(hn,h1,n);
	//REPE(i,K) printf("%d: %d\n",i,(int)(((ll)hn.x[i]*fact[i])%MOD));

	int ret=0;
	REPE(i,K) {
		int cur=(ll)hn.x[i]*fact[K]%MOD*ifact[K-i]%MOD;
		if((ret+=cur)>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}