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

const int MAXN=100000;
const int MAXM=100000;

int n,m;
int e[MAXM][2],ecost[MAXM];
int ans[MAXM],nans;

int opt[MAXM],nopt;
vector<int> adj[MAXN];
int state[MAXN];

bool dfscyc(int at) {
	state[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i];
		if(state[to]==1||state[to]==0&&dfscyc(to)) return true;
	}
	state[at]=2; return false;
}

bool can(int cost) {
	REP(i,n) adj[i].clear();
	REP(i,m) if(ecost[i]>cost) adj[e[i][0]].PB(e[i][1]);
	REP(i,n) state[i]=0;
	REP(i,n) if(state[i]==0) if(dfscyc(i)) return false;
	return true;
}

int top[MAXN],topidx[MAXN],ntop;
void dfstop(int at) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i];
		if(topidx[to]==-1) dfstop(to);
	}
	top[ntop]=at,topidx[at]=ntop,++ntop;
}

void solve() {
	nans=0;
	nopt=0; REP(i,m) opt[nopt++]=ecost[i]; sort(opt,opt+nopt); nopt=unique(opt,opt+nopt)-opt;
	if(can(0)) return;
	int lo=-1,hi=nopt-1;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		if(can(opt[mi])) hi=mi; else lo=mi;
	}
	int cost=opt[hi];
	//printf("cost=%d\n",cost);

	ntop=0;
	REP(i,n) adj[i].clear();
	REP(i,m) if(ecost[i]>cost) adj[e[i][0]].PB(e[i][1]);
	REP(i,n) topidx[i]=-1;
	REP(i,n) if(topidx[i]==-1) dfstop(i);
	//printf("top:"); REP(i,ntop) printf(" %d",top[i]+1); puts("");

	REP(i,m) if(ecost[i]<=cost&&topidx[e[i][0]]<topidx[e[i][1]]) ans[nans++]=i;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) scanf("%d%d%d",&e[i][0],&e[i][1],&ecost[i]),--e[i][0],--e[i][1];
	solve();
	int cost=0; REP(i,nans) cost=max(cost,ecost[ans[i]]);
	printf("%d %d\n",cost,nans); REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}