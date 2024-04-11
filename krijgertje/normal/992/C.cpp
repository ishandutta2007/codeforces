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
const int INV2=(MOD+1)/2;

typedef int Mat[2][2];
void mmult(Mat &A,Mat B) {
	Mat C; REP(i,2) REP(j,2) { ll cur=0; REP(k,2) cur=(cur+(ll)A[i][k]*B[k][j])%MOD; C[i][j]=cur; }
	//printf("[%d %d %d %d]*[%d %d %d %d]=[%d %d %d %d]\n",A[0][0],A[0][1],A[1][0],A[1][1],B[0][0],B[0][1],B[1][0],B[1][1],C[0][0],C[0][1],C[1][0],C[1][1]);
	REP(i,2) REP(j,2) A[i][j]=C[i][j];
}
void mpow(Mat &A,ll n) {
	Mat B;
	//printf("A:[%d %d %d %d] B:[%d %d %d %d]\n",A[0][0],A[0][1],A[1][0],A[1][1],B[0][0],B[0][1],B[1][0],B[1][1]);
	REP(i,2) REP(j,2) B[i][j]=A[i][j],A[i][j]=i==j?1:0;
	//printf("A:[%d %d %d %d] B:[%d %d %d %d]\n",A[0][0],A[0][1],A[1][0],A[1][1],B[0][0],B[0][1],B[1][0],B[1][1]);
	while(true) { if(n&1) mmult(A,B); if((n>>=1)==0) return; mmult(B,B); }
}

Mat A;
int b[2];


int solve(ll x,ll k) {
	if(x==0) return 0;
	A[0][0]=2; A[0][1]=1; A[1][0]=0; A[1][1]=1; b[0]=x%MOD; b[1]=(ll)(MOD-1)*INV2%MOD;
	mpow(A,k);
	//printf("A:%d %d %d %d\n",A[0][0],A[0][1],A[1][0],A[1][1]);

	int ret=((ll)b[0]*A[0][0]+(ll)b[1]*A[0][1])%MOD;
	ret=(ll)2*ret%MOD;
	return ret;

	REPE(i,k) {
		x=(ll)2*x%MOD;
		if(i!=k) {
			x=((ll)x+x+MOD-1)*INV2%MOD;
		}
	}
	return x;
}

void run() {
	ll x,k; scanf("%lld%lld",&x,&k);
	printf("%d\n",solve(x,k));
}

int main() {
	run();
	return 0;
}