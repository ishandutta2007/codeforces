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

const double eps=1e-9;

int n,m,nlives;
bool trap[500];
int e[500][500],deg[500];

int R,C;
double p[500][500]; // equations: col j = entering room j, equation = prob to end in a room (given by constants for trap rooms)
void gaussjord() {
	int r=0,c=0;
	while(r<R&&c<C) {
		if(trap[c]) { ++c; continue; }
		{ int rr=r; while(rr<R&&fabs(p[rr][c])<eps) ++rr; if(rr>=R) { ++c; continue; } REP(cc,C) p[r][cc]+=p[rr][cc]; }
		REP(cc,C) if(cc!=c) p[r][cc]/=p[r][c]; p[r][c]=1;
		FOR(rr,r+1,R) { REP(cc,C) if(cc!=c) p[rr][cc]-=p[rr][c]*p[r][cc]; p[rr][c]=0; }
		++r,++c;
	}
	--r;
	while(r>=0) {
		c=0; while(c<C&&trap[c]||fabs(p[r][c])<eps) ++c; assert(c<C);
		REP(rr,r) { REP(cc,C) if(cc!=c) p[rr][cc]-=p[rr][c]*p[r][cc]; p[rr][c]=0; }
		--r;
	}
}

int id[500],nid;
double A[101][101]; // A[i][j] = prob when start in trap room i that next trap room is j

double Ap[30][101][101]; // Ap[k][i][j] = prob when start in trap room i that trap room after 2^k steps is j
double Bp[31][101][101];
void matmult(double A[101][101],double B[101][101],double C[101][101]) {
	REP(i,nid) REP(j,nid) { C[i][j]=0; REP(k,nid) C[i][j]+=A[i][k]*B[k][j]; }
}


void run() {
	scanf("%d%d%d",&n,&m,&nlives); nlives-=2;
	REP(i,n) { int x; scanf("%d",&x); trap[i]=x==1; }
	memset(e,0,sizeof(e)); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; ++e[a][b],++e[b][a]; }
	memset(deg,0,sizeof(deg)); REP(i,n) REP(j,n) deg[i]+=e[i][j];

	memset(p,0,sizeof(p));
	R=0; C=n; REP(i,n) if(!trap[i]) { p[R][i]+=deg[i]; REP(j,n) p[R][j]-=e[i][j]; ++R; }
	//REP(r,R) { REP(c,C) printf("%6.2lf",p[r][c]); puts(""); } puts("");
	gaussjord();
	//REP(r,R) { REP(c,C) printf("%6.2lf",p[r][c]); puts(""); } puts("");

	memset(id,-1,sizeof(id)); nid=0; REP(i,n) if(trap[i]) id[i]=nid++;
	memset(A,0,sizeof(A));
	REP(i,n) if(trap[i]) REP(j,n) if(trap[j]) { A[id[i]][id[j]]+=1.0*e[i][j]/deg[i]; }
	REP(r,R) REP(c,C) if(!trap[c]&&fabs(p[r][c])>=eps) {
		REP(i,n) if(trap[i]) REP(j,n) if(trap[j]) A[id[i]][id[j]]+=1.0*e[i][c]/deg[i]*-p[r][j];
	}
	//REP(i,nid) { REP(j,nid) printf("%6.2lf",A[i][j]); puts(""); } puts("");
	
	REP(i,nid) REP(j,nid) Ap[0][i][j]=A[i][j];
	FOR(k,1,30) matmult(Ap[k-1],Ap[k-1],Ap[k]);

	REP(i,nid) REP(j,nid) Bp[0][i][j]=i==j?1:0;
	REP(k,30) if(nlives&(1<<k)) matmult(Bp[k],Ap[k],Bp[k+1]); else REP(i,nid) REP(j,nid) Bp[k+1][i][j]=Bp[k][i][j];
	//REP(i,nid) { REP(j,nid) printf("%6.2lf",Bp[30][i][j]); puts(""); } puts("");

	double ret=0;
	REP(r,R) if(fabs(p[r][0])>=eps) {
		REP(i,n) if(trap[i]) ret+=-p[0][i]*Bp[30][id[i]][nid-1];
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}