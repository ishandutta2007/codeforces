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

const int MAXN=500;
struct Opt { int a,b,k; };
bool operator<(const Opt &p,const Opt &q) { return p.b>q.b; }

int n;
Opt opt[MAXN];

ll dp[MAXN+1][MAXN+1]; // opt[i][j] = the maximum value, considering only the first i options, choosing j out of which to take on the last j days (and paying of the other chosen options completely)

void upd(ll &a,ll b) { a=max(a,b); }
ll solve() {
	sort(opt,opt+n);
	REPE(i,n) REPE(j,n) dp[i][j]=LLONG_MIN;
	dp[0][0]=0;
	REP(i,n) REPE(j,i) if(dp[i][j]!=LLONG_MIN) {
		upd(dp[i+1][j],dp[i][j]);
		upd(dp[i+1][j],dp[i][j]+opt[i].a-(ll)opt[i].k*opt[i].b);
		if(j<opt[i].k) upd(dp[i+1][j+1],dp[i][j]+opt[i].a-(ll)j*opt[i].b);
	}
	ll ret=LLONG_MIN; REPE(j,n) upd(ret,dp[n][j]); return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&opt[i].a,&opt[i].b,&opt[i].k);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}