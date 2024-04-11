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

const int MAXN=100000;

int n;
ll x[3][MAXN];
ll dp[3][MAXN];

void upd(ll &a,ll b) { if(b>a) a=b; }
void run() {
	scanf("%d",&n); REP(i,3) REP(j,n) scanf("%lld",&x[i][j]);

	REP(i,3) REP(j,n) dp[i][j]=LLONG_MIN;
	dp[0][0]=x[0][0];
	REP(j,n) {
		if(dp[0][j]!=LLONG_MIN) {
			if(j+1<n) upd(dp[0][j+1],dp[0][j]+x[0][j+1]);
			if(j+1<n) upd(dp[1][j+1],dp[0][j]+x[1][j]+x[1][j+1]);
			if(j+1<n) upd(dp[2][j+1],dp[0][j]+x[1][j]+x[2][j]+x[2][j+1]);
			if(j+2<n) upd(dp[2][j+2],dp[0][j]+x[0][j+1]+x[1][j+1]+x[1][j]+x[2][j]+x[2][j+1]+x[2][j+2]);
		}
		if(dp[1][j]!=LLONG_MIN) {
			if(j+1<n) upd(dp[0][j+1],dp[1][j]+x[0][j]+x[0][j+1]);
			if(j+1<n) upd(dp[1][j+1],dp[1][j]+x[1][j+1]);
			if(j+1<n) upd(dp[2][j+1],dp[1][j]+x[2][j]+x[2][j+1]);
		}
		if(dp[2][j]!=LLONG_MIN) {
			if(j+1<n) upd(dp[0][j+1],dp[2][j]+x[1][j]+x[0][j]+x[0][j+1]);
			if(j+1<n) upd(dp[1][j+1],dp[2][j]+x[1][j]+x[1][j+1]);
			if(j+1<n) upd(dp[2][j+1],dp[2][j]+x[2][j+1]);
			if(j+2<n) upd(dp[0][j+2],dp[2][j]+x[2][j+1]+x[1][j+1]+x[1][j]+x[0][j]+x[0][j+1]+x[0][j+2]);
		}
	}
	ll ret=dp[2][n-1];
	if(dp[1][n-1]!=LLONG_MIN) upd(ret,dp[1][n-1]+x[2][n-1]);
	if(dp[0][n-1]!=LLONG_MIN) upd(ret,dp[0][n-1]+x[1][n-1]+x[2][n-1]);
	if(n>=2&&dp[0][n-2]!=LLONG_MIN) upd(ret,dp[0][n-2]+x[0][n-1]+x[1][n-1]+x[1][n-2]+x[2][n-2]+x[2][n-1]);
	//REP(i,3) { REP(j,n) printf("%lld ",dp[i][j]); puts(""); }
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}