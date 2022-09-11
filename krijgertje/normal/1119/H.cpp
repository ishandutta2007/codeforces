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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MOD=998244353;
const int MAXROWS=100000;
const int NITEMS=3;
const int MAXCOLBITS=17;
const int INV2=(MOD+1)/2;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int nrows,colbits;
int itemweight[NITEMS];
int cols[MAXROWS][NITEMS];

int ways[1<<(MAXCOLBITS+NITEMS)];
int prod[1<<MAXCOLBITS];

void wht(int *a,int nbits) {
	REP(bit,nbits) for(int off=0;off<(1<<nbits);off+=2<<bit) REP(i,1<<bit) { int x=a[off+i],y=a[off+(1<<bit)+i]; a[off+i]=a[off+(1<<bit)+i]=x; inc(a[off+i],y); dec(a[off+(1<<bit)+i],y); }
}

void solve() {
	REP(mask,1<<(colbits+NITEMS)) ways[mask]=0;
	REP(i,nrows) REP(jmask,1<<NITEMS) { int mask=0; REP(j,NITEMS) if(jmask&(1<<j)) mask^=cols[i][j]^(1<<(colbits+j)); inc(ways[mask],1); }
	wht(ways,colbits+NITEMS);
	int mltways=1; REP(i,NITEMS) mltways=(ll)mltways*INV2%MOD;
	REP(mask,1<<(colbits+NITEMS)) ways[mask]=(ll)ways[mask]*mltways%MOD;
	//printf("ways:"); REP(mask,1<<(colbits+NITEMS)) printf(" %d",ways[mask]); puts("");
	REP(mask,1<<colbits) {
		prod[mask]=1;
		REP(jmask,1<<NITEMS) {
			int exp=ways[mask+(jmask<<colbits)];
			if(exp==0) continue;
			int cur=0; REP(j,NITEMS) if(jmask&(1<<j)) dec(cur,itemweight[j]); else inc(cur,itemweight[j]);
			prod[mask]=(ll)prod[mask]*pw(cur,exp)%MOD;
		}
	}
	wht(prod,colbits);
	int mltprod=1; REP(i,colbits) mltprod=(ll)mltprod*INV2%MOD;
	REP(mask,1<<colbits) prod[mask]=(ll)prod[mask]*mltprod%MOD;
	//printf("prod:"); REP(mask,1<<colbits) printf(" %d",prod[mask]); puts("");
}

void run() {
	scanf("%d%d",&nrows,&colbits);
	REP(i,NITEMS) scanf("%d",&itemweight[i]);
	REP(i,nrows) REP(j,NITEMS) scanf("%d",&cols[i][j]);
	solve();
	REP(i,1<<colbits) { if(i!=0) printf(" "); printf("%d",prod[i]); } puts("");
}

int main() {
	run();
	return 0;
}