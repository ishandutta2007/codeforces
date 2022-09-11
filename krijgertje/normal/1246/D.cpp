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

const int MAXN=100000;

int n;
int wantpar[MAXN];
int ans[MAXN],nans;
vector<int> ops;

vector<int> wantch[MAXN];

int dep[MAXN];
int maxdep[MAXN];
int deepest[MAXN];

void dfsinit(int at) {
	maxdep[at]=dep[at]; deepest[at]=-1;
	REPSZ(i,wantch[at]) {
		int to=wantch[at][i];
		dep[to]=dep[at]+1;
		dfsinit(to);
		if(deepest[at]==-1||maxdep[to]>maxdep[at]) maxdep[at]=maxdep[to],deepest[at]=to;
	}
}

void go(int at) {
	ans[nans++]=at;
	REPSZ(i,wantch[at]) {
		int to=wantch[at][i]; if(to==deepest[at]) continue;
		int x=ans[nans-1];
		go(to);
		while(x!=at) ops.PB(to),x=wantpar[x];
	}
	if(deepest[at]!=-1) {
		int to=deepest[at];
		int x=ans[nans-1];
		go(to);
		while(x!=at) ops.PB(to),x=wantpar[x];
	}
}

void solve() {
	REP(i,n) wantch[i].clear();
	REP(i,n) if(wantpar[i]!=-1) wantch[wantpar[i]].PB(i);
	dep[0]=0; dfsinit(0);
	nans=0; ops.clear(); go(0); assert(nans==n);
}

void run() {
	scanf("%d",&n);
	wantpar[0]=-1; FOR(i,1,n) scanf("%d",&wantpar[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
	printf("%d\n",SZ(ops));
	REPSZ(i,ops) { if(i!=0) printf(" "); printf("%d",ops[i]); } puts("");
}

int main() {
	run();
	return 0;
}