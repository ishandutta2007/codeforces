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

const int MAXW=100;
const int MOD=1000003;
typedef int Mat[MAXW+1][MAXW+1];

int n,w,h;
Mat A;
int b[MAXW+1];
int g[MAXW+1];

Mat C;
void mmult(Mat &A,Mat &B) {
	REPE(i,w) REPE(j,w) {
		int c=0; REPE(k,w) c=(c+(ll)A[i][k]*B[k][j])%MOD; C[i][j]=c;
	}
	REPE(i,w) REPE(j,w) A[i][j]=C[i][j];
}

void mpow(Mat &A,int k) {
	Mat B; REPE(i,w) REPE(j,w) B[i][j]=A[i][j],A[i][j]=i==j?1:0;
	while(true) {
		if(k&1) mmult(A,B);
		if((k>>=1)==0) break;
		mmult(B,B);
	}
}

void run() {
	scanf("%d%d%d",&n,&w,&h);
	g[1]=h; FORE(i,2,w) g[i]=(ll)g[i-1]*h%MOD;
	REP(i,w+1) REP(j,w+1) A[i][j]=0;
	REP(i,w) A[i][i+1]=1;
	FORE(j,1,w) A[w][w-j]=g[j];
	if((A[w][w]++)>=MOD) A[w][w]-=MOD;
	b[0]=1; FORE(i,1,w) { b[i]=b[i-1]; FORE(j,1,i-1) b[i]=(b[i]+(ll)g[j]*b[i-j-1])%MOD; }

	//REPE(i,w) { REPE(j,w) printf("%3d ",A[i][j]); printf("       %d\n",b[i]); }

	if(n+1<=w) {
		printf("%d\n",b[n+1]);
	} else {
		mpow(A,n+1-w);
		int ret=0; REPE(i,w) ret=(ret+(ll)b[i]*A[w][i])%MOD; printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}