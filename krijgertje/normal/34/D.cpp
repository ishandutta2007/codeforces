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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

vector<int> p1;
vector<int> p2;
vector<vector<int> > adj;

void dfs(int at,int prev) {
	p2[at]=prev;
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to!=prev) dfs(to,at); }
}

void run() {
	int n,r1,r2; scanf("%d%d%d",&n,&r1,&r2); --r1,--r2;
	p1=p2=vector<int>(n,-1);
	adj=vector<vector<int> >(n);
	REP(i,n) if(i!=r1) { int x; scanf("%d",&x); --x; p1[i]=x; adj[i].PB(x); adj[x].PB(i); }
	dfs(r2,-1);
	bool first=true; REP(i,n) if(i!=r2) { if(first) first=false; else printf(" "); printf("%d",p2[i]+1); } puts("");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}