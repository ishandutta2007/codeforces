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

const int MAXN=500000;
const int MAXH=60;
const int MAXW=MAXN+1;

int n;
ll a[MAXN],b[MAXN];

int R,C;
int A[MAXH][MAXW];

void solve() {
	int r=0,c=0;
	while(r<R&&c<C) {
		{ int rr=r; while(rr<R&&A[rr][c]==0) ++rr; if(rr>=R) { ++c; continue; } FOR(cc,c,C) swap(A[r][cc],A[rr][cc]); }
		FOR(rr,r+1,R) if(A[rr][c]==1) FOR(cc,c,C) A[rr][cc]^=A[r][cc];
		++r,++c;
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%I64d%I64d",&a[i],&b[i]);

	R=0,C=n+1;
	ll asum=0; REP(i,n) asum^=a[i];
	REP(j,n) while(((a[j]^b[j])>>R)!=0) ++R;
	while((asum>>R)!=0) ++R;
	REP(j,n) REP(i,R) A[i][j]=((a[j]^b[j])>>i)&1;
	REP(i,R) A[i][n]=(asum>>i)&1;

	solve();
	//REP(x,R) { REP(y,C-1) printf("%d",A[x][y]); printf("=%d\n",A[x][C-1]); }

	int nfree=n;
	REP(r,R) { int c=0; while(c<C&&A[r][c]==0) ++c; if(c==C-1) { printf("1/1\n"); return; } if(c!=C) --nfree; }
	printf("%I64d/%I64d\n",(1LL<<(n-nfree))-1,1LL<<(n-nfree));
}

int main() {
	run();
	return 0;
}