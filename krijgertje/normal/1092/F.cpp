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

const int MAXN=200000;

int n;
int a[MAXN];
vector<int> adj[MAXN];

int par[MAXN];
ll sum[MAXN]; // sum of subtree
ll cost[MAXN]; // cost of subtree

void dfsinit(int at) {
	sum[at]=a[at]; cost[at]=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		par[to]=at;
		dfsinit(to);
		sum[at]+=sum[to]; cost[at]+=cost[to]+sum[to];
	}
}

ll dfssolve(int at,ll parsum,ll parcost) {
	ll ret=cost[at]+parcost;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		ll cur=dfssolve(to,parsum+sum[at]-sum[to],parcost+parsum+cost[at]-cost[to]-sum[to]+sum[at]-sum[to]);
		ret=max(ret,cur);
	}
	return ret;
}

ll solve() {
	par[0]=-1; dfsinit(0);
	return dfssolve(0,0,0);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}