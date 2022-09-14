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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXD=100;
const int MOD=1000000007;

int n,maxdist;
int d[100000];

ll A[MAXD+1][MAXD+1];
ll B[MAXD+1][MAXD+1];
ll C[MAXD+1][MAXD+1];

void mmult(ll A[MAXD+1][MAXD+1],ll B[MAXD+1][MAXD+1]) {
	REPE(i,MAXD) REPE(j,MAXD) {
		ll cur=0;
		REPE(k,MAXD) {
			cur+=A[i][k]*B[k][j];
			if(cur>LLONG_MAX-MOD*MOD) cur%=MOD;
		}
		C[i][j]=cur%MOD;
	}
	REPE(i,MAXD) REPE(j,MAXD) A[i][j]=C[i][j];
//	REPE(i,MAXD) { REPE(j,MAXD) printf("%lld ",A[i][j]); puts(""); } puts("");
}

void mpow(int k) {
	REPE(i,MAXD) REPE(j,MAXD) B[i][j]=A[i][j];
	REPE(i,MAXD) REPE(j,MAXD) A[i][j]=i==j?1:0;
	while(k>0) {
		if(k&1) mmult(A,B);
		mmult(B,B); k/=2;
	}
}

void run() {
	scanf("%d%d",&n,&maxdist);
	REP(i,n) scanf("%d",&d[i]);

	REPE(i,MAXD) REPE(j,MAXD) A[i][j]=0;
	REP(i,n) A[0][d[i]-1]++; A[0][MAXD]=1;
	FOR(i,1,MAXD) A[i][i-1]=1;
	A[MAXD][MAXD]=1;

	//REPE(i,MAXD) { REPE(j,MAXD) printf("%lld ",A[i][j]); puts(""); } puts("");
	mpow(maxdist);
	//REPE(i,MAXD) { REPE(j,MAXD) printf("%lld ",A[i][j]); puts(""); } puts("");
	ll ret=(A[0][0]+A[0][MAXD])%MOD;
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}