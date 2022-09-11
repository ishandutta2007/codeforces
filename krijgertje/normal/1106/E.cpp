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

const int MAXT=100000;
const int MAXENV=100000;
const int MAXDISTURB=200;

int tend,maxdisturb,nenv;
int envl[MAXENV],envr[MAXENV],envnxt[MAXENV],envcost[MAXENV];

ll dp[MAXT+1][MAXDISTURB+1];
int nxt[MAXT],cost[MAXT];

priority_queue<pair<pair<int,int>,int>> pq;
vector<int> byl[MAXT];

void upd(ll &a,ll b) { a=min(a,b); }
ll solve() {
	pq=priority_queue<pair<pair<int,int>,int>>();
	REP(t,tend) byl[t].clear(); REP(i,nenv) byl[envl[i]].PB(i);
	REP(t,tend) {
		REPSZ(i,byl[t]) { int at=byl[t][i]; pq.push(MP(MP(envcost[at],envnxt[at]),envr[at])); }
		while(!pq.empty()&&pq.top().second<t) pq.pop();
		if(pq.empty()) nxt[t]=t+1,cost[t]=0; else nxt[t]=pq.top().first.second,cost[t]=pq.top().first.first;
	}
	//REP(t,tend) printf("%d: nxt=%d cost=%d\n",t+1,nxt[t]+1,cost[t]);

	REPE(t,tend) REPE(i,maxdisturb) dp[t][i]=LLONG_MAX; dp[0][0]=0;
	REPE(t,tend) REPE(i,maxdisturb) if(dp[t][i]!=LLONG_MAX) {
		//printf("dp[%d][%d]=%lld\n",t+1,i,dp[t][i]);
		if(t<tend) upd(dp[nxt[t]][i],dp[t][i]+cost[t]);
		if(t<tend&&i+1<=maxdisturb) upd(dp[t+1][i+1],dp[t][i]);
	}
	ll ret=LLONG_MAX; REPE(i,maxdisturb) upd(ret,dp[tend][i]); return ret;
}

void run() {
	scanf("%d%d%d",&tend,&maxdisturb,&nenv);
	REP(i,nenv) scanf("%d%d%d%d",&envl[i],&envr[i],&envnxt[i],&envcost[i]),--envl[i],--envr[i];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}