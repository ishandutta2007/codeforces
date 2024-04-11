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

const int MAXN=300000;

int n;
vector<int> adj[MAXN];

int dpone[MAXN];
int dptwo[MAXN];

void dfs(int at,int par) {
	int mxchone=0,mxchone2=0,cntch=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfs(to,at);
		++cntch;
		if(dpone[to]>mxchone) mxchone2=mxchone,mxchone=dpone[to]; else if(dpone[to]>mxchone2) mxchone2=dpone[to];
	}
	dpone[at]=1+mxchone+max(cntch-1,0);
	dptwo[at]=1+mxchone+mxchone2+max(cntch-2,0)+(par!=-1?1:0);
}

int solve() {
	dfs(0,-1);
	int ret=0; REP(i,n) ret=max(ret,dptwo[i]); return ret;
}

void cleanup() {
	REP(i,n) adj[i].clear();
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
	cleanup();
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}