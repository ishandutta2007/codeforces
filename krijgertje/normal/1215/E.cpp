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

const int MAXN=400000;
const int MAXCOL=20;

int n;
int a[MAXN];

vector<int> x[MAXCOL];

ll cost[MAXCOL][MAXCOL];

ll dp[1<<MAXCOL];
int prv[1<<MAXCOL];

ll precalc(int i,int j) {
	int ati=0,atj=0; ll ret=0;
	while(ati<SZ(x[i])||atj<SZ(x[j])) {
		if(ati<SZ(x[i])&&(atj>=SZ(x[j])||x[i][ati]<x[j][atj])) {
			ret+=atj;
			++ati;
		} else {
			++atj;
		}
	}
	return ret;
}

ll calc(int pmask,int i) {
	ll ret=0; REP(j,MAXCOL) if(j!=i&&(pmask&(1<<j))!=0) ret+=cost[j][i]; else ret+=cost[i][j]; return ret;
}

ll solve() {
	REP(i,MAXCOL) x[i].clear();
	REP(i,n) x[a[i]].PB(i);

	REP(i,MAXCOL) REP(j,MAXCOL) if(j!=i) cost[i][j]=precalc(i,j);


	dp[0]=0LL,prv[0]=-1;
	FOR(mask,1,1<<MAXCOL) {
		dp[mask]=LLONG_MAX,prv[mask]=-2;
		REP(i,MAXCOL) if(mask&(1<<i)) {
			int pmask=mask-(1<<i);
			assert(dp[pmask]!=LLONG_MAX);
			ll cur=dp[pmask]+calc(pmask,i);
			if(cur<dp[mask]) dp[mask]=cur,prv[mask]=i;
		}
	}
	//for(int mask=(1<<MAXCOL)-1;mask!=0;mask-=1<<prv[mask]) printf("%x: %d (%d): %lld\n",mask,prv[mask],SZ(x[prv[mask]]),dp[mask]);
	ll ret=dp[(1<<MAXCOL)-1];
	assert(ret%2==0); ret/=2;
	return ret;
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}