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

const int MAXBOX=100000;
const int MAXGUESS=100000;
const int MAXH=MAXGUESS+2;
const int MAXW=MAXBOX;

int nbox,nguess;
int guess[MAXGUESS];

int h,w;
int blocked[MAXH];

int rbound[MAXW];
int lbound[MAXW];

int dp[MAXW+MAXH];

void calc(int *res) {
	REP(y,w) dp[y]=blocked[0]==y?-1:y;
	int off=0;
	FOR(x,1,h) {
		++off;
		if(blocked[x-1]!=w-1) {
			dp[off+w-1]=dp[off+w-2];
		} else {
			dp[off+w-1]=dp[off+w-3];
		}
		if(blocked[x-1]!=-1&&blocked[x-1]!=0) dp[off+blocked[x-1]-1]=dp[off+blocked[x-1]-2];
		if(blocked[x]!=-1) dp[off+blocked[x]]=-1;
		//printf("\tdp:"); REP(y,w) printf(" %d",dp[off+y]); puts("");
	}
	REP(y,w) res[y]=dp[off+y];
}

ll solve() {
	if(nbox==1) return nguess>=1?0:1;
	h=nguess+2,w=nbox;
	REP(x,h) blocked[x]=x==0||x==h-1?-1:guess[nguess-(x-1)-1];
	//printf("blocked:"); REP(x,h) printf(" %d",blocked[x]); puts("");

	calc(rbound);
	REP(x,h) if(blocked[x]!=-1) blocked[x]=w-blocked[x]-1;
	//printf("rbound:"); REP(y,w) printf(" %d",rbound[y]); puts("");
	calc(lbound);
	reverse(lbound,lbound+w);
	REP(y,w) lbound[y]=w-lbound[y]-1;
	REP(x,h) if(blocked[x]!=-1) blocked[x]=w-blocked[x]-1;
	//printf("lbound:"); REP(y,w) printf(" %d",lbound[y]); puts("");
	ll ret=0; REP(y,w) ret+=rbound[y]-lbound[y]+1; return ret;
}

void run() {
	scanf("%d%d",&nbox,&nguess);
	REP(i,nguess) scanf("%d",&guess[i]),--guess[i];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}