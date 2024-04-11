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

const int MOD=1000000007;
const ll LIM=LLONG_MAX-(ll)MOD*MOD;
const int N=128;
int w[8];

int ways[N];
int A[N][N];
int B[N][N];
int C[N][N];

void mmult(int A[N][N],int B[N][N],int C[N][N]) {
	REP(i,N) REP(j,N) {
		ll cur=0;
		REP(k,N) { cur+=(ll)A[i][k]*B[k][j]; if(cur>LIM) cur%=MOD; }
		C[i][j]=cur%MOD;
	}
}

void mpow(int A[N][N],int x) {
	REP(i,N) REP(j,N) B[i][j]=A[i][j];
	REP(i,N) REP(j,N) A[i][j]=i==j?1:0;
	for(int at=0;(1<<at)<=x;++at) {
		if(x&(1<<at)) {
			mmult(A,B,C);
			REP(i,N) REP(j,N) A[i][j]=C[i][j];
		}
		mmult(B,B,C);
		REP(i,N) REP(j,N) B[i][j]=C[i][j];
	}
}

int c[N];
void vmult(int b[N],int A[N][N]) {
	REP(j,N) {
		ll cur=0;
		REP(i,N) { cur+=(ll)b[i]*A[i][j]; if(cur>LIM) cur%=MOD; }
		c[j]=cur%MOD;
	}
	REP(j,N) b[j]=c[j];
}


void run() {
	FORE(i,1,7) scanf("%d",&w[i]);

	memset(ways,0,sizeof(ways)); ways[0]=1;
	FORE(i,1,7) if(w[i]!=0) {
		memset(A,0,sizeof(A));
		REP(lft,1<<i) REP(mid,1<<(i-1)) REP(rgt,1<<i) {
			bool ok=true;
			REP(j,i) {
				if(lft&(1<<j)) continue;
				if(rgt&(1<<j)) continue;
				if(j!=0&&mid&(1<<(j-1))) continue;
				if(j!=i-1&&mid&(1<<j)) continue;
				ok=false; break;
			}
			if(!ok) continue;
			A[lft][rgt]++;
		}
		//REP(lft,1<<i) { REP(rgt,1<<i) printf("%2d ",A[lft][rgt]); puts(""); } puts("");
		mpow(A,w[i]);
		//REP(lft,1<<i) { REP(rgt,1<<i) printf("%2d ",A[lft][rgt]); puts(""); } puts("");
		vmult(ways,A);
		//REP(lft,1<<i) printf("%2d ",ways[lft]); puts(""); puts("");
	}
	printf("%d\n",ways[0]);

}

int main() {
	run();
	return 0;
}