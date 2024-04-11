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

const int MOD=1000000007;
const int MAXN=100000;
const int MAXQ=100000;
typedef int Mat[2][2];

void mmult(Mat &A,const Mat &B) { Mat C; REP(i,2) REP(j,2) { ll cur=0; REP(k,2) cur+=(ll)A[i][k]*B[k][j]; C[i][j]=cur%MOD; } REP(i,2) REP(j,2) A[i][j]=C[i][j]; }
void mpow(Mat &A,ll n) {
	Mat B; REP(i,2) REP(j,2) B[i][j]=A[i][j],A[i][j]=i==j?1:0;
	while(true) {
		if(n&1) mmult(A,B);
		if((n>>=1)==0) break;
		mmult(B,B);
	}
}

int n,nq;
int x[MAXN];

int scur[2*MAXN],sprv[2*MAXN]; ll slazy[2*MAXN]; Mat sA[2*MAXN];
void sprep(Mat &A,ll by) { A[0][0]=0,A[0][1]=A[1][0]=A[1][1]=1; mpow(A,by); }
void smod(int idx,const Mat &A,ll by) {
	//printf("smod(%d) by %lld\n",idx,by);
	int nprv=((ll)sprv[idx]*A[0][0]+(ll)scur[idx]*A[0][1])%MOD;
	int ncur=((ll)sprv[idx]*A[1][0]+(ll)scur[idx]*A[1][1])%MOD;
	//printf("%d -> %d %d (%d)\n",idx,ncur,nprv,by);
	scur[idx]=ncur,sprv[idx]=nprv,slazy[idx]+=by; mmult(sA[idx],A);
}
void _spush(int idx) { if(slazy[idx]==0) return; smod(idx<<1,sA[idx],slazy[idx]); smod(idx<<1|1,sA[idx],slazy[idx]); slazy[idx]=0; sA[idx][0][0]=sA[idx][1][1]=1,sA[idx][0][1]=sA[idx][1][0]=0; }
void spush(int idx) { int h=0; while((idx>>h)!=0) ++h; for(--h;h>0;--h) _spush(idx>>h); }
void _sbuild(int idx) { _spush(idx); scur[idx]=(scur[idx<<1]+scur[idx<<1|1])%MOD,sprv[idx]=(sprv[idx<<1]+sprv[idx<<1|1])%MOD; }
void sbuild(int idx) { for(idx>>=1;idx;idx>>=1) _sbuild(idx); }
void sinit() {
	memset(slazy,0,sizeof(slazy));
	FOR(i,1,2*n) sA[i][0][0]=sA[i][1][1]=1,sA[i][0][1]=sA[i][1][0]=0;
	REP(i,n) { Mat A; sprep(A,x[i]-1); sprv[n+i]=A[0][1],scur[n+i]=A[1][1]; }
	for(int i=n-1;i>=1;--i) _sbuild(i);
}
void sinc(int l,int r,int by) {
	//printf("sinc(%d,%d,%d)\n",l,r,by);
	Mat A; sprep(A,by);
	int lidx=l+n,ridx=r+n+1,_lidx=lidx,_ridx=ridx; spush(lidx); spush(ridx-1);
	for(;lidx<ridx;lidx>>=1,ridx>>=1) {
		if(lidx&1) smod(lidx++,A,by);
		if(ridx&1) smod(--ridx,A,by);
	}
	sbuild(_lidx),sbuild(_ridx-1);
	//printf("sincdone(%d,%d,%d)\n",l,r,by);
}
int sget(int l,int r) {
	int lidx=l+n,ridx=r+n+1; spush(lidx); spush(ridx-1);
	ll ret=0;
	for(;lidx<ridx;lidx>>=1,ridx>>=1) {
		if(lidx&1) ret+=scur[lidx++];
		if(ridx&1) ret+=scur[--ridx];
	}
	return ret%MOD;
}
void sprint() {
	FOR(i,1,2*n) printf("%d: cur=%d prv=%d lazy=%lld\n",i,scur[i],sprv[i],slazy[i]);
}

int qtype[MAXQ],ql[MAXQ],qr[MAXQ],qby[MAXQ],ret[MAXQ];
void input() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d",&x[i]);
	REP(i,nq) { scanf("%d%d%d",&qtype[i],&ql[i],&qr[i]); if(qtype[i]==1) scanf("%d",&qby[i]); }
}
void solve() {
	sinit();
	REP(qi,nq) {
		//sprint();
		int type=qtype[qi],l=ql[qi],r=qr[qi],by=qby[qi]; --l,--r;
		if(type==1) { sinc(l,r,by); }
		if(type==2) ret[qi]=sget(l,r);
	}
}
void output() {
	REP(qi,nq) if(qtype[qi]==2) printf("%d\n",ret[qi]);
}

void run() {
	input();
	solve();
	output();
}

int myrand(int n) { ll ret=0; while(ret<n) ret=ret*RAND_MAX+rand(); return ret%n; }
int myrand(int l,int r) { return l+myrand(r-l+1); }
void test() {
	n=100000,nq=100000;
	REP(i,n) x[i]=myrand(1,1000000000);
	REP(i,nq) { qtype[i]=myrand(1,2); ql[i]=myrand(1,n),qr[i]=myrand(1,n); if(ql[i]>qr[i]) swap(ql[i],qr[i]); qby[i]=myrand(1,1000000000); }
	clock_t begin = clock();
	solve();
	clock_t end = clock(); printf("%.9lf\n",(double)(end-begin)/CLOCKS_PER_SEC);
}

int main() {
	run();
	//srand(time(NULL)); test();
	return 0;
}