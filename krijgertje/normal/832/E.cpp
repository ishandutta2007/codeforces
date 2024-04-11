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

const int MAXEQ=500;
const int MAXVAR=500;
const int MAXQ=300;

int neq,nvar,nq;
char s[MAXVAR+1];

int nr,nc;
int A[MAXEQ][MAXVAR+MAXQ];
int inv[5];

int gaussjord() {
	int r=0,c=0;
	while(r<nr&&c<neq) {
		{ int rr=r; while(rr<nr&&A[rr][c]==0) ++rr; if(rr>=nr) { ++c; continue; } if(rr!=r) FOR(cc,c,nc) swap(A[r][cc],A[rr][cc]); }
		int mlt=inv[A[r][c]]; FOR(cc,c,nc) A[r][cc]=A[r][cc]*mlt%5;
		FOR(rr,r+1,nr) { int t=A[rr][c]; FOR(cc,c,nc) A[rr][cc]=(A[rr][cc]+(5-t)*A[r][cc])%5; }
		++r,++c;
	}
	--r; int ndim=0;
	while(r>=0) {
		c=0; while(A[r][c]==0) ++c; assert(A[r][c]==1);
		REP(rr,r) { int t=A[rr][c]; FOR(cc,c,nc) A[rr][cc]=(A[rr][cc]+(5-t)*A[r][cc])%5; }
		++ndim; --r;
	}
	return ndim;
}

void run() {
	inv[1]=1; inv[2]=3; inv[3]=2; inv[4]=4;
	scanf("%d%d",&neq,&nvar);
	REP(i,neq) { scanf("%s",s); REP(j,nvar) A[j][i]=s[j]-'a'; }
	scanf("%d",&nq);
	REP(i,nq) { scanf("%s",s); REP(j,nvar) A[j][neq+i]=s[j]-'a'; }
	nr=nvar,nc=neq+nq;
	//REP(i,nr) { REP(j,nc) printf("%d",A[i][j]); puts(""); } puts("");
	
	int ndim=gaussjord();
	//REP(i,nr) { REP(j,nc) printf("%d",A[i][j]); puts(""); } puts("");
	
	int ans=1; REP(i,neq-ndim) ans=(ll)ans*5%1000000007;
	REP(i,nq) {
		bool ok=true; FOR(j,ndim,nvar) if(A[j][neq+i]!=0) ok=false;
		printf("%d\n",ok?ans:0);
	}
}

int main() {
	run();
	return 0;
}