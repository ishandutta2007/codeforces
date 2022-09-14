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

const int MAXN=100;
const int MAXA=16;
const int MOD=1000000007;
typedef int Mat[MAXA][MAXA];
typedef struct R { ll lx,hx; int y; } R;

int n; ll tx;
R r[MAXN];

void printmat(Mat &A) {
	REP(i,MAXA) { REP(j,MAXA) printf("%d ",A[i][j]); puts(""); }
}
void mmult(Mat &A,Mat &B) {
	//printf("mult\n"); printmat(A); printf("*\n"); printmat(B);
	static Mat C; REP(i,MAXA) REP(j,MAXA) C[i][j]=0;
	REP(i,MAXA) REP(j,MAXA) REP(k,MAXA) C[i][j]=(C[i][j]+(ll)A[i][k]*B[k][j])%MOD;
	//printf("=\n"); printmat(C);
	REP(i,MAXA) REP(j,MAXA) A[i][j]=C[i][j];
}
void mpow(Mat &A,ll k) {
	static Mat x; REP(i,MAXA) REP(j,MAXA) x[i][j]=A[i][j],A[i][j]=i==j?1:0;
	while(true) {
		if(k&1) mmult(A,x);
		if((k>>=1)==0) break;
		mmult(x,x);
	}
}


int cur[MAXA];
int nxt[MAXA];
Mat A;



void run() {
	scanf("%d%lld",&n,&tx);
	REP(i,n) scanf("%lld%lld%d",&r[i].lx,&r[i].hx,&r[i].y); r[n-1].hx=tx;

	memset(cur,0,sizeof(cur)); cur[0]=1;
	REP(i,n) {
		memset(A,0,sizeof(A));
		REPE(y,r[i].y) FORE(dy,-1,+1) {
			int ny=y+dy; if(ny<0||ny>r[i].y) continue;
			A[y][ny]++;
		}
		//printf("A%d [%d]\n",i,r[i].y); printmat(A);
		mpow(A,r[i].hx-r[i].lx);
		//printf("^%lld\n",r[i].hx-r[i].lx); printmat(A);
		FOR(y,r[i].y+1,MAXA) cur[y]=0;
		memset(nxt,0,sizeof(nxt)); REP(i,MAXA) REP(j,MAXA) nxt[j]=(nxt[j]+(ll)cur[i]*A[i][j])%MOD; REP(i,MAXA) cur[i]=nxt[i];
	}
	printf("%d\n",cur[0]);
}

int main() {
	run();
	return 0;
}