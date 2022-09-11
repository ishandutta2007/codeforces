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

const int MAXN=300000;
struct Res { ll mxstart,mxend,mxpath; };

int n;
int gain[MAXN];
vector<pair<int,int>> e[MAXN];

int par[MAXN];
ll mxend[MAXN];

void dfsinit(int at) {
	mxend[at]=gain[at];
	REPSZ(i,e[at]) {
		int to=e[at][i].first,cost=e[at][i].second; if(to==par[at]) continue;
		par[to]=at; dfsinit(to);
		if(mxend[to]>=cost) mxend[at]=max(mxend[at],mxend[to]-cost+gain[at]);
	}
}

ll dfssolve(int at,ll mxhave) {
	ll cmx=mxhave+gain[at],cmx2=mxhave+gain[at]; int cmxidx=par[at];
	REPSZ(i,e[at]) {
		int to=e[at][i].first,cost=e[at][i].second; if(to==par[at]) continue;
		if(mxend[to]<cost) continue;
		ll cur=mxend[to]-cost+gain[at]; if(cur>cmx) cmx2=cmx,cmx=cur,cmxidx=to; else if(cur>cmx2) cmx2=cur;
	}
	ll ret=cmx;
	REPSZ(i,e[at]) {
		int to=e[at][i].first,cost=e[at][i].second; if(to==par[at]) continue;
		ll nmxhave=to!=cmxidx?cmx:cmx2;
		ll cur=dfssolve(to,max(0LL,nmxhave-cost));
		ret=max(ret,cur);
	}
	return ret;
}

ll solve() {
	par[0]=-1;
	dfsinit(0);
	return dfssolve(0,0);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&gain[i]);
	REP(i,n-1) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[a].PB(MP(b,c)); e[b].PB(MP(a,c)); }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}