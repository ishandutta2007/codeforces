#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <chrono>
#include <random>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int DIM=11;
const int MOD=1000003;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }


int A[DIM][DIM+1];
int q[DIM],qans[DIM];
int a[DIM];

int B[DIM][DIM+1];


void gaussjord(int nrow,int ncol) {
	int r=0,c=0;
	while(r<nrow&&c<ncol) {
		{ int rr=r; while(rr<nrow&&B[rr][c]==0) ++rr; if(rr>=nrow) { ++ncol; continue; } REP(cc,ncol) swap(B[r][cc],B[rr][cc]); assert(B[r][c]!=0); }
		int mlt=pw(B[r][c],MOD-2); REP(cc,ncol) B[r][cc]=(ll)B[r][cc]*mlt%MOD; assert(B[r][c]==1);
		FOR(rr,r+1,nrow) { int t=B[rr][c]; REP(cc,ncol) B[rr][cc]=(B[rr][cc]+MOD-(ll)t*B[r][cc]%MOD)%MOD; }
		++r,++c;
	}
	while(--r>=0) {
		c=0; while(c<nrow&&B[r][c]==0) ++c; assert(c<nrow&&B[r][c]==1);
		REP(rr,r) { int t=B[rr][c]; REP(cc,ncol) B[rr][cc]=(B[rr][cc]+MOD-(ll)t*B[r][cc]%MOD)%MOD; }
	}
}

bool independent(int nrow,int ncol) {
	REP(i,nrow) REP(j,ncol) B[i][j]=A[i][j];
	gaussjord(nrow,ncol);
	REP(i,nrow) { bool any=false; REP(j,ncol) if(B[i][j]!=0) any=true; if(!any) return false; }
	return true;
}

int eval(int x) {
	int ret=0,mlt=1; REP(i,DIM) { ret=(ret+(ll)mlt*a[i])%MOD; mlt=(ll)mlt*x%MOD; } return ret;
}

bool local=false;
int loca[DIM];

int query(int x) {
	if(!local) {
		printf("? %d\n",x); fflush(stdout);
		int ret; scanf("%d",&ret); if(ret==-1) exit(0); return ret;
	} else {
		int ret=0,mlt=1; REP(i,DIM) { ret=(ret+(ll)mlt*loca[i])%MOD; mlt=(ll)mlt*x%MOD; } return ret;
	}
}

int solve() {
	int nrow=0;
	REP(x,MOD) if(nrow<DIM) {
		A[nrow][0]=1; FORE(i,1,DIM) A[nrow][i]=(ll)A[nrow][i-1]*x%MOD;
		if(independent(nrow+1,DIM)) q[nrow++]=x;
	}
	//printf("nrow=%d\n",nrow);
	//printf("q:"); REP(i,nrow) printf(" %d",q[i]); puts("");
	//REP(i,DIM) { REP(j,DIM) { if(j!=0) printf(" "); printf("%d",A[i][j]); } puts(""); }
	assert(nrow==DIM);

	REP(i,DIM) qans[i]=query(q[i]);
	//printf("qans:"); REP(i,DIM) printf(" %d",qans[i]); puts("");
	REP(i,DIM) { REP(j,DIM) B[i][j]=A[i][j]; B[i][DIM]=qans[i]; }
	gaussjord(DIM,DIM+1);
	//REP(i,DIM) { REP(j,DIM+1) { if(j!=0) printf(" "); printf("%d",B[i][j]); } puts(""); }
	REP(i,DIM) REP(j,DIM) assert(B[i][j]==(i==j?1:0));
	REP(i,DIM) a[i]=B[i][DIM];

	REP(x,MOD) if(eval(x)==0) return x;
	return -1;
}

void run() {
	int ans=solve();
	printf("! %d\n",ans); fflush(stdout);
}

void stress() {
	std::mt19937 rnd(123); local=true;
	REP(rep,100) {
		int dim=rnd()%DIM+1; memset(loca,0,sizeof(loca));
		while(true) { REP(i,dim) loca[i]=rnd()%MOD; bool ok=true; REP(i,dim) if(loca[i]!=0) ok=true; if(ok) break; }
		int have=solve();
		bool ok=true; REP(i,DIM) if(a[i]!=loca[i]) ok=false;
		if(have!=-1&&query(have)!=0) ok=false;
		if(ok) { printf("."); continue; }
		printf("err %d -> %d\n",have,query(have));
		printf("want:"); REP(i,DIM) printf(" %d",loca[i]); puts("");
		printf("have:"); REP(i,DIM) printf(" %d",a[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}