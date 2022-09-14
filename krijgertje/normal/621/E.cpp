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

const int MAXMOD=100;
const int MOD=1000000007;
typedef int Mat[MAXMOD][MAXMOD];

int ndig,nblk,rem,mod;
int cnt[10];

Mat A;
Mat B;


void mmult(Mat &A,Mat &B) {
	static Mat oA,oB; REP(i,mod) REP(j,mod) oA[i][j]=A[i][j],oB[i][j]=B[i][j];
	REP(i,mod) REP(j,mod) {
		ll cur=0;
		REP(k,mod) { cur+=(ll)oA[i][k]*oB[k][j]; if(cur>LLONG_MAX-(ll)MOD*MOD) cur%=MOD; }
		A[i][j]=cur%MOD;
	}
}

void mpow(Mat &B,Mat &A,int n) {
	REP(i,mod) REP(j,mod) B[i][j]=i==j?1:0;
	while(n>0) {
		if(n&1) mmult(B,A);
		mmult(A,A); n/=2;
	}
}



void run() {
	scanf("%d%d%d%d",&ndig,&nblk,&rem,&mod);
	REP(i,10) cnt[i]=0;
	REP(i,ndig) { int x; scanf("%d",&x); ++cnt[x]; }
	
	REP(i,mod) REP(j,mod) A[i][j]=0;
	REP(i,mod) REP(k,10) { int j=(10*i+k)%mod; A[i][j]=(A[i][j]+cnt[k])%MOD; }
	//REP(i,mod) { REP(j,mod) printf("%3d ",A[i][j]); puts(""); }

	mpow(B,A,nblk);
	printf("%d\n",B[0][rem]);
}

int main() {
	run();
	return 0;
}