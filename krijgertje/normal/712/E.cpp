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

const int MAXN=100000;
typedef struct R { double pwin,pretry; } R;

int n,nq;
int sa[MAXN],sb[MAXN];

// pwin(a+b)=pwin(a)*pwin(b)/(1-plose(b)*pretry(a))
// pretry(a+b)=pretry(b)+pdone(b)*pretry(a)*pwin(b)/(1-pretry(a)*plose(b))

R sval[2*MAXN];

R scalc(const R& a,const R& b) {
	double times=1.0/(1-(1-b.pwin)*a.pretry); R ret;
	ret.pwin=a.pwin*b.pwin*times;
	ret.pretry=b.pretry+(1-b.pretry)*a.pretry*b.pwin*times;
	return ret;
}
void srecalc(int idx) {
	sval[idx]=scalc(sval[idx<<1],sval[idx<<1|1]);
}
void sinit() {
	REP(i,n) sval[n+i].pwin=sval[n+i].pretry=1.0*sa[i]/sb[i];
	for(int idx=n-1;idx>=1;--idx) srecalc(idx);
}
void sset(int idx,double val) {
	idx+=n;
	sval[idx].pwin=sval[idx].pretry=val;
	for(idx>>=1;idx>0;idx>>=1) srecalc(idx);
}
double sget(int lidx,int ridx) {
	lidx+=n,ridx+=n+1; R lret; lret.pwin=1; lret.pretry=0; R rret; rret.pwin=1; rret.pretry=0;
	for(;lidx<ridx;lidx>>=1,ridx>>=1) {
		if(lidx&1) lret=scalc(lret,sval[lidx++]);
		if(ridx&1) rret=scalc(sval[--ridx],rret);
	}
	return scalc(lret,rret).pwin;
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d%d",&sa[i],&sb[i]);

	sinit();
	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) { int i,a,b; scanf("%d%d%d",&i,&a,&b); --i; sset(i,1.0*a/b); }
		if(type==2) { int l,r; scanf("%d%d",&l,&r); --l,--r; double ret=sget(l,r); printf("%.9lf\n",ret); }
	}

}

int main() {
	run();
	return 0;
}