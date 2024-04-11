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

const int MAXN=1000;
const int MAXK=1000;
const int MAXVAL=1000;
const int MAXSUM=MAXVAL*MAXK;
const int MAXM=1<<20;
const double MYPI=acos(-1);

int bitrev[MAXM];
complex<double> w[MAXM];
void prefft(int m,int lgm) {
	REP(i,m) bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(lgm-1));
	REP(i,m) w[i]=complex<double>(cos(2*MYPI*i/m),sin(2*MYPI*i/m));
}
void fft(complex<double> a[MAXM],int m) {
	REP(i,m) if(i<bitrev[i]) swap(a[i],a[bitrev[i]]);
	for(int len=2,step=m>>1;len<=m;len<<=1,step>>=1) {
        for(int i=0;i<m;i+=len) {
			complex<double> *l=a+i,*r=l+(len>>1),*p=w;
			REP(off,len>>1) {
                complex<double> v=*r**p;
                *r=*l-v; *l=*l+v;
				++l,++r,p+=step;
            }
        }
	}
}

void print(bool A[MAXSUM+1]) {
	bool first=true; REPE(i,MAXSUM) if(A[i]) { if(!first) printf(" "); first=false; printf("%d",i); } puts("");
}

void mymlt(bool a[MAXSUM+1],bool b[MAXSUM+1],int mx) {
/*	static bool C[MAXSUM+1];
	REPE(i,mx) {
		C[i]=false;
		REPE(j,i) if(A[j]&&B[i-j]) { C[i]=true; break; }
	}
	REPE(i,mx) A[i]=C[i];
	*/
	static complex<double> A[MAXM],B[MAXM];
	memset(A,0,sizeof(A)); memset(B,0,sizeof(B));
	REPE(i,mx) A[i]=complex<double>(a[i]?1:0,0);
	REPE(i,mx) B[i]=complex<double>(b[i]?1:0,0);
	int m=1,lgm=0; while(m<=mx) m*=2,++lgm;
	prefft(m,lgm);
	fft(A,m); fft(B,m);
	REP(i,m) A[i]*=B[i];
	reverse(w+1,w+m); fft(A,m);
	REPE(i,mx) a[i]=fabs(real(A[i]))>=.5*m;
}

void mypow(bool B[MAXSUM+1],bool A[MAXSUM+1],int k,int amx) {
	memset(B,false,sizeof(B)); B[0]=true; int bmx=0;
	while(true) {
		if(k&1) mymlt(B,A,bmx+amx),bmx+=amx;

		if((k>>=1)==0) break;
		mymlt(A,A,amx+amx),amx+=amx;
	}
}


int n,k;
bool A[MAXSUM+1];
bool B[MAXSUM+1];


void run() {
	scanf("%d%d",&n,&k); int mx=0;
	memset(A,false,sizeof(A)); REP(i,n) { int x; scanf("%d",&x); A[x]=true; if(x>mx) mx=x; }

	mypow(B,A,k,mx);
	print(B);
}

int main() {
	run();
	return 0;
}