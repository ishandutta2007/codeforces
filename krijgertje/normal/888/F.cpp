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

const int MAXN=500;
const int MOD=1000000007;

int n;
int can[MAXN][MAXN];

int dp[MAXN][MAXN][3]; // dp[i][j][state] is number of ways to connect [i..j] using (i..j) where state=0 -> not connected can use both, state=1 -> connected can use both, state=2 -> connected can use only j

void run() {
	scanf("%d",&n); REP(i,n) REP(j,n) scanf("%d",&can[i][j]);

	REP(i,n) dp[i][i][0]=dp[i][i][1]=dp[i][i][2]=1;
	REP(i,n-1) dp[i][i+1][0]=can[i][i+1],dp[i][i+1][1]=dp[i][i+1][2]=1;
	FORE(cnt,3,n) REPE(i,n-cnt) {
		int j=i+cnt-1;
		dp[i][j][2]=0;
		FORE(k,i+1,j-1) if(can[j][k]) {
			dp[i][j][2]=(dp[i][j][2]+(ll)dp[i][k][2]*dp[k][j][1])%MOD;
		}
		dp[i][j][1]=dp[i][j][2];
		FORE(k,i+1,j-1) if(can[i][k]) {
			dp[i][j][1]=(dp[i][j][1]+(ll)dp[i][k][1]*dp[k][j][1])%MOD;
		}
		dp[i][j][0]=can[i][j]?dp[i][j][1]:0;
		FORE(k,i+1,j-1) if(can[i][k]) {
			dp[i][j][0]=(dp[i][j][0]+(ll)dp[i][k][1]*dp[k][j][0])%MOD;
		}
		//printf("%d..%d = %d / %d / %d\n",i,j,dp[i][j][0],dp[i][j][1],dp[i][j][2]);
	}
	int ret=dp[0][n-1][0];
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}