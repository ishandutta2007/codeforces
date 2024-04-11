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

const int MAXN=1000000;

int n,remcost,modcost;
int x[MAXN];

ll dp[MAXN][3]; // dp[i] = min cost for processing [0..i]. dp[i][0]=no seg started, dp[i][1]=in seg, dp[i][2]=seg finished

inline void upd(ll &a,ll &b,int c) { if(b<a-c) a=b+c; }
ll calc(int g) {
	dp[0][0]=0; dp[0][1]=dp[0][2]=LLONG_MAX;
	FOR(i,1,n) {
		REP(j,3) dp[i][j]=LLONG_MAX;
		bool ok=x[i]%g==0;
		if(ok) {
			upd(dp[i][0],dp[i-1][0],0);
			upd(dp[i][1],dp[i-1][1],remcost);
			upd(dp[i][2],dp[i-1][2],0);
		}
		bool okmod=(x[i]-1)%g==0||(x[i]+1)%g==0;
		if(okmod) {
			upd(dp[i][0],dp[i-1][0],modcost);
			upd(dp[i][2],dp[i-1][2],modcost);
		}
		upd(dp[i][1],dp[i-1][0],remcost);
		upd(dp[i][1],dp[i-1][1],remcost);
		upd(dp[i][2],dp[i-1][0],remcost);
		upd(dp[i][2],dp[i-1][1],remcost);
	}
	//REP(i,n) { printf("\t"); REP(j,3) printf("%lld ",dp[i][j]); puts(""); }
	return min(dp[n-1][0],dp[n-1][2]);
}

void run() {
	scanf("%d%d%d",&n,&remcost,&modcost);
	REP(i,n) scanf("%d",&x[i]);

	ll ret=LLONG_MAX;
	REP(i,2) {
		FORE(j,-1,+1) {
			int x0=x[0]+j;
			for(int p=2;(ll)p*p<=x0;++p) if(x0%p==0) {
				ll cur=calc(p)+(j==0?0:modcost); if(cur<ret) ret=cur;
				while(x0%p==0) x0/=p;
			}
			if(x0!=1) {
				ll cur=calc(x0)+(j==0?0:modcost); if(cur<ret) ret=cur;
			}
		}
		reverse(x,x+n);
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}