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

const int MAXN=2000;

int n;
int d[MAXN][MAXN];

priority_queue<pair<ll,int> > q;
ll dp[MAXN]; // minimum cost of a path to a free edge with current node still to be paid for

void run() {
	scanf("%d",&n); memset(d,0,sizeof(d)); int mn=INT_MAX;
	REP(i,n) FOR(j,i+1,n) { int x; scanf("%d",&x); d[i][j]=d[j][i]=x; if(x<mn) mn=x; }
	REP(i,n) FOR(j,i+1,n) d[i][j]-=mn,d[j][i]-=mn;

	q=priority_queue<pair<ll,int> >();
	REP(i,n) dp[i]=LLONG_MAX; bool done=false;
	REP(i,n) FOR(j,i+1,n) if(!done&&d[i][j]==0) {
		dp[i]=dp[j]=0;
		REP(k,n) if(k!=i&&k!=j) REP(l,n) if(l!=k&&l!=i&&l!=j) {
			ll cur=(ll)2*d[k][l];
			if(cur<dp[l]) dp[l]=cur;
		}
		done=true;
	}
	REP(i,n) if(dp[i]!=LLONG_MAX) q.push(MP(-dp[i],i));
	while(!q.empty()) {
		ll cost=-q.top().first; int at=q.top().second; q.pop();
		if(cost>dp[at]) continue;
		REP(to,n) if(to!=at) {
			ll ncost=cost+d[at][to];
			if(ncost<dp[to]) dp[to]=ncost,q.push(MP(-dp[to],to));
		}
	}
	REP(i,n) printf("%lld\n",dp[i]+(ll)(n-1)*mn);
}

int main() {
	run();
	return 0;
}