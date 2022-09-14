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
typedef int Mat[32][32];
ll n; int base;

void mmult(const Mat &A,const Mat &B,Mat &C) {
	REP(i,base+1) REP(j,base+1) {
		ll cur=0;
		REP(k,base+1) { if(cur>LIM) cur%=MOD; cur+=(ll)A[i][k]*B[k][j]; }
		C[i][j]=cur%MOD;
	}
}
void mcopy(const Mat &A,Mat &B) {
	REP(i,base+1) REP(j,base+1) B[i][j]=A[i][j];
}
void printmat(const Mat &A) {
	REP(i,base+1) { REP(j,base+1) printf("%2d ",A[i][j]); puts(""); }
}

Mat mat[60][32]; // mat[i][j] = matrix for sequence of base^i integers, starting with j

Mat have,tmp;

void run() {
	cin>>n>>base;
	REP(i,base) REP(j,base+1) REP(k,base+1) mat[0][i][j][k]=i==j||j==k?1:0;
	int ci=0,cj=0; ll step=1;
	while(step<=n/base) ++ci,step*=base;

	FORE(i,1,ci) REP(j,base) {
		REP(k,base+1) REP(l,base+1) mat[i][j][k][l]=k==l?1:0;
		REP(k,base) { mmult(mat[i][j],mat[i-1][(j+k)%base],tmp); mcopy(tmp,mat[i][j]); }
	}

	REP(k,base+1) REP(l,base+1) have[k][l]=k==l?1:0;
	for(;ci>=0;--ci,step/=base) {
		int times=(n/step)%base;
		REP(x,times) { 
			mmult(have,mat[ci][cj],tmp); mcopy(tmp,have); 
			//printf("after %d times %d^%d (starting with %d)\n",x+1,base,ci,cj); printmat(have); printf("\tmult with\n"); printmat(mat[ci][cj]);
			if(++cj>=base) cj-=base;
		}
	}
	//printf("have\n"); printmat(have);
	int ret=0; REP(k,base+1) { ret+=have[k][base]; if(ret>=MOD) ret-=MOD; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}