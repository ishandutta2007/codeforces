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

const int MAXN=100000;
const int MAXVAL=200;
const int MOD=998244353;
void inc(int &a,ll b) { a=(a+b)%MOD; }

int n;
int a[MAXN];

int dp[2][2][MAXVAL+1];

ll sum[2][MAXVAL+1];

int solve() {
	int at=0;
	memset(dp[at],0,sizeof(dp[at]));
	FORE(j,1,MAXVAL) if(a[0]==-1||a[0]==j) inc(dp[at][0][j],1);
	FOR(i,1,n) {
		int to=1-at;
		memset(dp[to],0,sizeof(dp[to]));
		REP(k,2) { sum[k][0]=0; FORE(j,1,MAXVAL) sum[k][j]=sum[k][j-1]+dp[at][k][j]; }
		FORE(j,1,MAXVAL) if(a[i]==-1||a[i]==j) {
			inc(dp[to][0][j],sum[0][j-1]+sum[1][j-1]);
			inc(dp[to][1][j],sum[1][MAXVAL]-sum[1][j]);
			inc(dp[to][1][j],dp[at][0][j]+dp[at][1][j]);
		}
		at=to;
	}
	int ret=0; FORE(j,1,MAXVAL) inc(ret,dp[at][1][j]); return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}