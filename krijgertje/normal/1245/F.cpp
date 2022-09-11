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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXBIT=30;

ll dp[MAXBIT+1][2][2]; // dp[i][acmp][bcmp] = #ways to choose i least significant digits so that asuffix is lower than alim iff acmp and bsuffix is lower than blim iff bcmp


ll calc(int alim,int blim) {
	memset(dp,0,sizeof(dp)); dp[0][0][0]=1;
	REP(i,MAXBIT) {
		int ahave=(alim>>i)&1,bhave=(blim>>i)&1;
		REP(acmp,2) REP(bcmp,2) REP(abit,2) REP(bbit,2) {
			if(abit==1&&bbit==1) continue;
			int nacmp=abit<ahave||abit==ahave&&acmp?1:0;
			int nbcmp=bbit<bhave||bbit==bhave&&bcmp?1:0;
			dp[i+1][nacmp][nbcmp]+=dp[i][acmp][bcmp];
		}
	}
	return dp[MAXBIT][1][1];
}

int l,r;

ll solve() {
	return calc(r+1,r+1)-2*calc(r+1,l)+calc(l,l);
}

void run() {
	scanf("%d%d",&l,&r);
	printf("%lld\n",solve());
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}