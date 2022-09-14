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
const int MAXCOL=100;

int n,ncol,want;
int c[MAXN];
int p[MAXN][MAXCOL];


ll dp[MAXN][MAXCOL][MAXN+1]; // dp[i][j][k] == minimum cost to color first i+1 trees, with the ith tree colored j and the first i+1 trees have beauty k

void upd(ll &x,ll y) { if(y<x) x=y; }
ll solve() {
	REP(i,n) REP(j,ncol) FORE(k,1,n) dp[i][j][k]=LLONG_MAX;
	if(c[0]==-1) REP(j,ncol) dp[0][j][1]=p[0][j]; else dp[0][c[0]][1]=0;
	FOR(i,1,n) REP(j,ncol) FORE(k,1,i) if(dp[i-1][j][k]!=LLONG_MAX) {
		if(c[i]==-1) REP(nj,ncol) upd(dp[i][nj][k+(nj!=j?1:0)],dp[i-1][j][k]+p[i][nj]); else upd(dp[i][c[i]][k+(c[i]!=j?1:0)],dp[i-1][j][k]);
	}
	//REP(i,n) REP(j,ncol) FORE(k,1,n) if(dp[i][j][k]!=LLONG_MAX) printf("%d %d %d = %lld\n",i,j,k,dp[i][j][k]);
	ll ret=LLONG_MAX; REP(j,ncol) upd(ret,dp[n-1][j][want]); if(ret==LLONG_MAX) ret=-1; return ret;
}

void run() {
	scanf("%d%d%d",&n,&ncol,&want);
	REP(i,n) scanf("%d",&c[i]),--c[i];
	REP(i,n) REP(j,ncol) scanf("%d",&p[i][j]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}