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

const int MAXN=200000;
const int NSTATE=5;
typedef int Mat[NSTATE][NSTATE];

int n,nq;
char s[MAXN+1];
Mat sval[4*MAXN];

inline void scopy(Mat &A,Mat &B) { REP(i,NSTATE) FOR(j,i,NSTATE) A[i][j]=B[i][j]; }
inline void smult(Mat &A,Mat &B,Mat &C) { REP(i,NSTATE) FOR(j,i,NSTATE) { int cur=2*MAXN; FORE(k,i,j) cur=min(cur,A[i][k]+B[k][j]); C[i][j]=cur; } }
inline void smult(Mat &A,Mat &B) { static Mat C; scopy(C,A); smult(C,B,A); }
void sinit(int x,int l,int r) {
	if(l==r) {
		REP(i,NSTATE) REP(j,NSTATE) sval[x][i][j]=2*MAXN;
		sval[x][0][0]=s[l]=='2'?1:0; if(s[l]=='2') sval[x][0][1]=0;
		sval[x][1][1]=s[l]=='0'?1:0; if(s[l]=='0') sval[x][1][2]=0;
		sval[x][2][2]=s[l]=='1'?1:0; if(s[l]=='1') sval[x][2][3]=0;
		sval[x][3][3]=s[l]=='6'||s[l]=='7'?1:0; if(s[l]=='7') sval[x][3][4]=0; //if(s[l]=='6') sval[x][3][5]=0;
		sval[x][4][4]=s[l]=='6'?1:0; //if(s[l]=='6') sval[x][4][5]=0;
		//sval[x][5][5]=0;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		smult(sval[2*x+1],sval[2*x+2],sval[x]);
	}
	//printf("%d..%d:",l,r); REP(i,NSTATE) REP(j,NSTATE) if(sval[x][i][j]!=INT_MAX) printf(" %d->%d=%d",i,j,sval[x][i][j]); puts("");
}
void sget(int x,int l,int r,int L,int R,Mat &RES) {
	if(L<=l&&r<=R) {
		smult(RES,sval[x]);
	} else {
		int m=l+(r-l)/2;
		if(L<=m) sget(2*x+1,l,m,L,R,RES);
		if(m+1<=R) sget(2*x+2,m+1,r,L,R,RES);
	}
	//printf("%d..%d -> %d..%d:",L,R,L,r); REP(i,NSTATE) REP(j,NSTATE) if(RES[i][j]!=INT_MAX) printf(" %d->%d=%d",i,j,RES[i][j]); puts("");
}

void run() {
	scanf("%d%d%s",&n,&nq,s);
	sinit(0,0,n-1);
	REP(i,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		Mat res; REP(i,NSTATE) REP(j,NSTATE) res[i][j]=i==j?0:2*MAXN; sget(0,0,n-1,l,r,res);
		int ret=res[0][4]; printf("%d\n",ret==2*MAXN?-1:ret);
	}
}

int main() {
	run();
	return 0;
}