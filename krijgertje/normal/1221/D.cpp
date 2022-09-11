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
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=300000;

int n;
int a[MAXN],b[MAXN];

ll dp[MAXN][3];

ll solve() {
	REP(j,3) dp[0][j]=(ll)j*b[0];
	FOR(i,1,n) REP(j,3) {
		dp[i][j]=LLONG_MAX;
		REP(k,3) if(a[i-1]+k!=a[i]+j) dp[i][j]=min(dp[i][j],dp[i-1][k]+j*b[i]);
	}
	//REP(i,n) { printf("dp%d:",i); REP(j,3) printf(" %d:%lld",a[i]+j,dp[i][j]); puts(""); }
	ll ret=LLONG_MAX; REP(j,3) ret=min(ret,dp[n-1][j]); return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&a[i],&b[i]);
	printf("%lld\n",solve());
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}