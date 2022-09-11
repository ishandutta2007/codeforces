#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXN=300000;

int n;
int g[2][MAXN];

ll suffsum[2][MAXN+1];
ll wsuffsum[2][MAXN+1];

ll dp[2][MAXN+1]; // dp[x][y] = maximum sum when starting at (x,y) at time 0 and visiting exactly all squares >=y


void run() {
	scanf("%d",&n); REP(x,2) REP(y,n) scanf("%d",&g[x][y]);

	REP(x,2) { suffsum[x][n]=0; for(int y=n-1;y>=0;--y) suffsum[x][y]=suffsum[x][y+1]+g[x][y]; }
	REP(x,2) { wsuffsum[x][n]=0; for(int y=n-1;y>=0;--y) wsuffsum[x][y]=wsuffsum[x][y+1]+(ll)y*g[x][y]; }

	dp[0][n]=dp[1][n]=0;
	for(int y=n-1;y>=0;--y) REP(x,2) {
		ll a=0*g[x][y]+1*g[1-x][y]+2*(suffsum[0][y+1]+suffsum[1][y+1])+dp[1-x][y+1];
		ll b=wsuffsum[x][y]-y*suffsum[x][y]+(n-y)*suffsum[1-x][y]+(n-1)*suffsum[1-x][y]-wsuffsum[1-x][y];
		//printf("(%d,%d): %lld vs %lld\n",x,y,a,b);
		dp[x][y]=max(a,b);
	}
	printf("%lld\n",dp[0][0]);
}

int main() {
	run();
	return 0;
}