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

const int MAXH=50;
const int MAXW=50;

int h,w;
char g[MAXH][MAXW+1];

int dp[MAXH+1][8];
int calc(char c) { int ret=0; if(isdigit(c)) ret|=1<<0; if(islower(c)) ret|=1<<1; if(c=='#'||c=='*'||c=='&') ret|=1<<2; return ret; }

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);

	REPE(i,h) REP(j,8) dp[i][j]=INT_MAX; dp[0][0]=0;
	REP(i,h) REP(j,8) if(dp[i][j]!=INT_MAX) {
		REP(k,w) {
			int nj=j|calc(g[i][k]),nc=dp[i][j]+min(k,w-k);
			if(nc<dp[i+1][nj]) dp[i+1][nj]=nc;
		}
	}
	printf("%d\n",dp[h][7]);
}

int main() {
	run();
	return 0;
}