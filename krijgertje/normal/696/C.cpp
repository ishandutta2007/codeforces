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

const int MAXN=100000;
const int MOD=1000000007;
const int INV2=(MOD+1)/2;
typedef int Mat[3][3];

int n;
ll a[MAXN];

void mmult(Mat &A,Mat &B) {
	Mat C;
	REP(i,3) REP(j,3) { ll cur=0; REP(k,3) cur+=(ll)A[i][k]*B[k][j]; C[i][j]=cur%MOD; }
	REP(i,3) REP(j,3) A[i][j]=C[i][j];
}
void mpow(Mat &A,ll k) {
	Mat B; REP(i,3) REP(j,3) B[i][j]=A[i][j],A[i][j]=i==j?1:0;
	while(k>0) {
		if(k&1) mmult(A,B);
		if((k>>=1)==0) break;
		mmult(B,B);
	}
}

Mat A;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld",&a[i]);

	REP(i,3) REP(j,3) A[i][j]=0;
	A[0][1]=1; A[1][0]=2; A[1][1]=1; A[2][2]=2;

	REP(i,n) mpow(A,a[i]);
	int num=((ll)INV2*(A[0][0]+A[0][2]))%MOD;
	int den=((ll)INV2*(A[2][0]+A[2][2]))%MOD;
	printf("%d/%d\n",num,den);
}

int main() {
	run();
	return 0;
}