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
const int MOD=1000000007;
typedef ll Mat[MAXN][MAXN];

int n; ll len;
ll a[MAXN];

int bitcnt(ll x) { int ret=0; while(x>0) { ret+=x&1; x>>=1; } return ret; }
void mmult(Mat &A,Mat &B) {
	Mat C;
	REP(i,n) REP(j,n) {
		ll cur=0;
		REP(k,n) cur+=(ll)A[i][k]*B[k][j]%MOD;
		C[i][j]=cur%MOD;
	}
	REP(i,n) REP(j,n) A[i][j]=C[i][j];
}

void mpow(Mat &A,ll k) {
	Mat B; REP(i,n) REP(j,n) B[i][j]=A[i][j],A[i][j]=i==j?1:0;
	while(k>0) {
		if(k&1) mmult(A,B);
		if((k>>=1)==0) break;
		mmult(B,B);
	}
}

Mat A;


void run() {
	scanf("%d%lld",&n,&len);
	REP(i,n) scanf("%lld",&a[i]);
	REP(i,n) REP(j,n) A[i][j]=bitcnt(a[i]^a[j])%3==0?1:0;
	//REP(i,n) { for(ll x=a[i];x!=0;x>>=1) printf("%d",(int)(x&1)); puts(""); }
	//REP(i,n) { REP(j,n) printf("%d ",A[i][j]); puts(""); }

	mpow(A,len-1);
	int ret=0; REP(i,n) REP(j,n) if((ret+=A[i][j])>=MOD) ret-=MOD; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}