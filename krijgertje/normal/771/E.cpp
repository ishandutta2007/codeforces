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

const int MAXN=300000;

int n;
int a[3][MAXN];
ll asum[3][MAXN+1];
pair<ll,int> b[MAXN+1];
int nxt[3][MAXN];

int dp[MAXN+1]; // dp[j] = maximum rectangles in [0..j)
int dpextra[2][MAXN+1]; // dpextra[i][j] = minimum k>j such that maximum rectangles in [0..k) for row i and [0..j) for row 1-i is dp[j]+1

void run() {
	scanf("%d",&n); REP(i,2) REP(j,n) scanf("%d",&a[i][j]); REP(j,n) a[2][j]=a[0][j]+a[1][j];
	
	REP(i,3) {
		asum[i][0]=0; REP(j,n) asum[i][j+1]=asum[i][j]+a[i][j];
		REPE(j,n) b[j]=MP(asum[i][j],j); sort(b,b+n+1);
		REP(j,n) nxt[i][j]=-1;
		REP(j,n) if(b[j+1].first==b[j].first) nxt[i][b[j].second]=b[j+1].second;
		for(int j=n-2;j>=0;--j) if(nxt[i][j+1]!=-1&&(nxt[i][j]==-1||nxt[i][j]>nxt[i][j+1])) nxt[i][j]=nxt[i][j+1];
	}
	//REP(i,3) { printf("nxt%d:",i); REP(j,n) printf(" %d",nxt[i][j]); puts(""); }

	memset(dp,0,sizeof(dp));
	memset(dpextra,-1,sizeof(dpextra));
	REP(j,n) {
		// from dp[j], skip 1 column
		if(dp[j]>dp[j+1]) { dp[j+1]=dp[j]; dpextra[0][j+1]=dpextra[1][j+1]=-1; }
		// from dp[j], find rectangle in both rows
		{ int nj=nxt[2][j],nval=dp[j]+1; if(nj!=-1&&nval>dp[nj]) { dp[nj]=nval; dpextra[0][nj]=dpextra[1][nj]=-1; } }
		// from dp[j], find rectangle in row i
		REP(i,2) { int nval=nxt[i][j]; if(nval!=-1&&(dpextra[i][j]==-1||nval<dpextra[i][j])) dpextra[i][j]=nval; }
		REP(i,2) { int nj=nxt[i][j],nval=dp[j]+1; if(nj!=-1&&nval>dp[nj]) { dp[nj]=nval; dpextra[0][nj]=dpextra[1][nj]=-1; } }
		// from dpextra[i][j], skip row 1-i upto dpextra[i][j]
		REP(i,2) if(dpextra[i][j]!=-1) { int nj=dpextra[i][j],nval=dp[j]+1; if(nj!=-1&&nval>dp[nj]) { dp[nj]=nval; dpextra[0][nj]=dpextra[1][nj]=-1; } }
		// from dpextra[i][j], find rectangle in row 1-i
		REP(i,2) if(dpextra[i][j]!=-1&&nxt[1-i][j]!=-1&&nxt[1-i][j]<dpextra[i][j]) { int ni=i,nj=nxt[1-i][j],nval=dpextra[i][j]; assert(dp[nj]>=dp[j]+1); if(dp[nj]==dp[j]+1&&(dpextra[ni][nj]==-1||nval<dpextra[ni][nj])) dpextra[ni][nj]=nval; }
		REP(i,2) if(dpextra[i][j]!=-1&&nxt[1-i][j]!=-1&&nxt[1-i][j]==dpextra[i][j]) { int nj=dpextra[i][j],nval=dp[j]+2; if(nval>dp[nj]) { dp[nj]=nval; dpextra[0][nj]=dpextra[1][nj]=-1; } }
		REP(i,2) if(dpextra[i][j]!=-1&&nxt[1-i][j]!=-1&&nxt[1-i][j]>dpextra[i][j]) { int ni=1-i,nj=dpextra[i][j],nval=nxt[1-i][j]; assert(dp[nj]>=dp[j]+1); if(dp[nj]==dp[j]+1&&(dpextra[ni][nj]==-1||nval<dpextra[ni][nj])) dpextra[ni][nj]=nval; }
	}
	//REPE(k,n) printf("%d: %d (%d,%d)\n",k,dp[k],dpextra[0][k],dpextra[1][k]);
	printf("%d\n",dp[n]);
}

int main() {
	run();
	return 0;
}