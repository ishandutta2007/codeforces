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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const char HARD[]="hard";

int n;
char s[MAXN+1];
int a[MAXN];

ll dp[MAXN+1][4];

void upd(ll &a,ll b) { a=min(a,b); }
ll solve() {
	REPE(i,n) REP(j,4) dp[i][j]=LLONG_MAX; dp[0][0]=0;
	REP(i,n) REP(j,4) if(dp[i][j]!=LLONG_MAX) {
		int nj=s[i]==HARD[j]?j+1:j;
		if(nj<4) upd(dp[i+1][nj],dp[i][j]);
		upd(dp[i+1][j],dp[i][j]+a[i]);
	}
	ll ret=LLONG_MAX; REP(j,4) upd(ret,dp[n][j]); return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}