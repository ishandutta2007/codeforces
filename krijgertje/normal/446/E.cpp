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

//			[ A{m}			A{m}+(2^m-1)I ]
// A{m+1} = [ A{m}+(2^m-1)I	A{m}		  ]

// [ A		A+xI ]^t	   [ (2A+xI)^t+(-x)^tI	(2A+xI)^t-(-x)^tI ]
// [ A+xI	A	 ]   =	1/2[ (2A+xI)^t-(-x)^tI	(2A+xI)^t+(-x)^tI ]

//					=		 [xAm+yI				xAm+yI+(2^mx-x-y)I]^t	= 		    [(2xAm+2yI+(2^mx-x-y)I)^t+(x+y-2^mx)^tI	(2xAm+2yI+(2^mx-x-y)I)^t-(x+y-2^mx)^tI ]
// b(xA{m+1}+yI)^t	= (b1 b2)[xAm+yI+(2^mx-x-y)I	xAm+yI		  	  ]		= 1/2(b1 b2)[(2xAm+2yI+(2^mx-x-y)I)^t-(x+y-2^mx)^tI	(2xAm+2yI+(2^mx-x-y)I)^t+(x+y-2^mx)^tI ]
// = 1/2[ (b1+b2){2xAm+(2^mx-x+y)I}^t+(b1-b2){x+y-2^mx}^tI	(b1+b2){2xAm+(2^mx-x+y)I}^t-(b1-b2){x+y-2^mx}^tI ]

const int MOD=1051131;
const int DIV2=525566;
int mypow(int x,ll n) { int ret=1; while(n>0) { if(n&1) ret=(ll)ret*x%MOD; x=(ll)x*x%MOD; n/=2; } return ret; }

int offset[27];
int bval[1<<26];
int resval[1<<25];
int ret;

ll t;

// calc b(xA{m+1}+yI)^t, where b in bval[offset[m]]..bval[offset[m]+2^m-1] and put it in resval[offset[m]]..resval[offset[m]+2^m-1]
void calc(int m,int x,int y, bool first) {
//	printf("calc(%d,%d,%d) b=",m,x,y); REP(i,1<<m) printf("%d ",bval[offset[m]+i]); puts("");
	if(m==0) {
		resval[offset[m]]=(ll)bval[offset[m]]*mypow((x+y)%MOD,t)%MOD;
	} else {
		int nm=m-1,nx=2*x%MOD,ny=((1LL<<nm)*x-x+y+MOD)%MOD;
		REP(i,1<<nm) bval[offset[nm]+i]=(bval[offset[m]+i]+bval[offset[m]+(1<<nm)+i])%MOD;
		calc(nm,nx,ny,false);
		int times=mypow(((x+y-(1LL<<nm)*x)%MOD+MOD)%MOD,t);
		REP(i,1<<nm) {
			int bdiff=(bval[offset[m]+i]-bval[offset[m]+(1<<nm)+i]+MOD)%MOD;
			int v1=(resval[offset[nm]+i]+(ll)bdiff*times)%MOD*DIV2%MOD;
			int v2=((resval[offset[nm]+i]-(ll)bdiff*times)%MOD+MOD)*DIV2%MOD;
			if(first) ret^=v1^v2; else resval[offset[m]+i]=v1,resval[offset[m]+(1<<nm)+i]=v2;
		}
	}
//	printf("calc(%d,%d,%d) res=",m,x,y); REP(i,1<<m) printf("%d ",resval[offset[m]+i]); puts("");
}

int m,s;
int binit[100000];

void run() {
	offset[0]=0; REPE(i,25) offset[i+1]=offset[i]+(1<<i);
	cin>>m>>t>>s;
	REP(i,s) cin>>binit[i];
	REP(i,s) bval[offset[m]+i]=binit[i];
	FOR(i,s,1<<m) bval[offset[m]+i]=((ll)101*bval[offset[m]+i-s]+10007)%MOD;
	ret=0;
	calc(m,1,0,true);
//	REP(i,1<<m) printf("%d: %d\n",i,resval[offset[m]+i]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}