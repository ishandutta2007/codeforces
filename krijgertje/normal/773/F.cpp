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

const int MAXN=30000;
const int MAXFFT=1<<16; //2*32768
const double MYPI=acos(-1);

typedef struct FFT {

	int bitrev[MAXFFT];
	complex<long double> w[MAXFFT];
	void prefft(int m,int lgm) {
		REP(i,m) bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(lgm-1));
		REP(i,m) w[i]=complex<long double>(cos(2*MYPI*i/m),sin(2*MYPI*i/m));
	}
	void fft(complex<long double> a[MAXFFT],int m) {
		REP(i,m) if(i<bitrev[i]) swap(a[i],a[bitrev[i]]);
		for(int len=2,step=m>>1;len<=m;len<<=1,step>>=1) {
			for(int i=0;i<m;i+=len) {
				complex<long double> *l=a+i,*r=l+(len>>1),*p=w;
				REP(off,len>>1) {
					complex<long double> v=*r**p;
					*r=*l-v; *l=*l+v;
					++l,++r,p+=step;
				}
			}
		}
	}

	void mlt(int a[MAXFFT],int b[MAXFFT],int c[MAXFFT],int mx,int MOD) {
		static complex<long double> A[MAXFFT],B[MAXFFT];
		memset(A,0,sizeof(A)); memset(B,0,sizeof(B));
		REPE(i,mx) A[i]=complex<double>(a[i],0);
		REPE(i,mx) B[i]=complex<double>(b[i],0);
		//printf("A:"); REPE(i,2*mx) printf(" (%.2lf,%2.lf)",real(A[i]),imag(A[i])); puts("");
		//printf("B:"); REPE(i,2*mx) printf(" (%.2lf,%2.lf)",real(B[i]),imag(B[i])); puts("");
		int m=1,lgm=0; while(m<=2*mx) m*=2,++lgm;
		prefft(m,lgm);
		fft(A,m); fft(B,m);
		//printf("A:"); REPE(i,2*mx) printf(" (%.2lf,%2.lf)",real(A[i]),imag(A[i])); puts("");
		//printf("B:"); REPE(i,2*mx) printf(" (%.2lf,%2.lf)",real(B[i]),imag(B[i])); puts("");
		REP(i,m) A[i]*=B[i];
		//printf("A:"); REPE(i,2*mx) printf(" (%.2lf,%2.lf)",real(A[i]),imag(A[i])); puts("");
		reverse(w+1,w+m); fft(A,m);
		//printf("A:"); REPE(i,2*mx) printf(" (%.2lf,%2.lf)",real(A[i]),imag(A[i])); puts("");
		REPE(i,mx) c[i]=((ll)floor(real(A[i])/m+.5))%MOD;
		//printf("m=%d lgm=%d\n",m,lgm);
		//printf("a:"); REPE(i,mx) printf(" %d",a[i]); puts("");
		//printf("b:"); REPE(i,mx) printf(" %d",b[i]); puts("");
		//printf("c:"); REPE(i,mx) printf(" %d",c[i]); puts("");
	}
} FFT;
FFT fft;

int maxn,maxa,MOD;
vector<int> p;
vector<vector<int> > ppp;

int ways[MAXN+1]; // ways[i] = ways to choose i numbers from the current range so that the last is odd
int nways[MAXN+1];

int choose[MAXN+1];
int tmp[MAXN+1];
int inv[MAXN+1];

int A[MAXFFT];
int B[MAXFFT];
int C[MAXFFT];
int D[MAXFFT];

void calcchoose(int a) {
	choose[0]=tmp[0]=1;
	vector<int> pp(SZ(p),0);
	REP(i,maxn) {
		int num=a-i; REPSZ(j,p) while(num>0&&num%p[j]==0) num/=p[j],++pp[j];
		int den=num==0||tmp[i]==0?1:i+1; REPSZ(j,p) while(den%p[j]==0) den/=p[j],--pp[j];
		tmp[i+1]=(ll)tmp[i]*num%MOD*inv[den]%MOD;
		choose[i+1]=tmp[i+1]; REPSZ(j,p) choose[i+1]=(ll)choose[i+1]*ppp[j][pp[j]%(MOD-1)]%MOD;
	}
	//REPE(i,maxn) printf("%d ",choose[i]); puts("");
}

int egcd(int a,int b,int &x,int &y) { if(b==0) { x=1,y=0; return a; } int ret=egcd(b,a%b,y,x); y-=x*(a/b); return ret; }
void doublerange(int a) { // double the current range
	//printf("doublerange(%d)\n",a);

	calcchoose(a);

	
	memset(A,0,sizeof(A)); memset(B,0,sizeof(B)); memset(C,0,sizeof(C)); memset(D,0,sizeof(D)); 
	if(a%2==0) REPE(i,maxn) A[i]=choose[i],B[i]=ways[i];
	if(a%2==1) REPE(i,maxn) A[i]=choose[i],B[i]=(choose[i]+MOD-ways[i])%MOD;
	//REPE(i,maxn) REPE(j,maxn-i) D[i+j]=(D[i+j]+(ll)A[i]*B[j])%MOD;
	fft.mlt(A,B,C,maxn,MOD);
	REPE(i,maxn) C[i]=(C[i]%MOD+MOD)%MOD;
	//bool anyerr=false; REPE(i,maxn) if(C[i]!=D[i]) printf("err at %d: %d vs %d\n",i,C[i],D[i]),anyerr=true; if(anyerr) exit(0);
	REPE(i,maxn) ways[i]=(C[i]+MOD-(ll)A[i]*B[0]%MOD+ways[i])%MOD;


	/*memset(nways,0,sizeof(nways));
	REPE(i,maxn) REPE(j,maxn-i) { // i out of [1..a] and j out of [a+1..2*a]
		if(j==0) { nways[i+j]=(nways[i+j]+ways[i])%MOD; continue; }
		if(a%2==0) {
			nways[i+j]=(nways[i+j]+(ll)choose[i]*ways[j])%MOD;
		} else {
			nways[i+j]=(nways[i+j]+(ll)choose[i]*((ll)choose[j]+MOD-ways[j]))%MOD;
		}
	}
	REPE(i,maxn) ways[i]=nways[i]; */
	//printf("-> "); REPE(i,maxn) printf("%d ",ways[i]); puts("");
}
void increaserange(int a) {
	//printf("increaserange(%d)\n",a);
	calcchoose(a);
	for(int i=maxn;i>=1;--i) ways[i]=(ways[i]+choose[i-1])%MOD;
	//printf("=> "); REPE(i,maxn) printf("%d ",ways[i]); puts("");
}

void run() {
	scanf("%d%d%d",&maxn,&maxa,&MOD);
	p.clear(); { int tmp=MOD; for(int i=2;i*i<=tmp;++i) if(tmp%i==0) { p.PB(i); while(tmp%i==0) tmp/=i; } if(tmp!=1) p.PB(tmp); }
	ppp=vector<vector<int> >(SZ(p)); REPSZ(i,p) { ppp[i].PB(1); REP(j,MOD-2) ppp[i].PB((ll)ppp[i].back()*p[i]%MOD); }
	//printf("p:"); REPSZ(i,p) printf(" %d",p[i]); puts("");
	inv[1]=1; FORE(i,2,maxn) if(gcd(i,MOD)==1) { int x,y; egcd(i,MOD,x,y); inv[i]=(x%MOD+MOD)%MOD; }

	int q=0; while((2LL<<q)<=maxa) ++q;
	assert(maxa/(1<<q)==1); memset(ways,0,sizeof(ways)); ways[1]=1;

	int ret=0;
	if(q>=1) ++ret;
	for(--q;q>=1;--q) {
		doublerange(maxa/(2<<q));
		if((maxa/(1<<q))%2==1) increaserange(maxa/(1<<q)-1); 
		for(int n=1;n<=maxn;n+=2) ret=(ret+ways[n])%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}