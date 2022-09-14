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


void run() {
	int n; scanf("%d",&n);
	vector<int> q(n); REP(i,n) scanf("%d",&q[i]);
	int m; scanf("%d",&m);
	vector<int> e(n,INT_MAX); REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[b]=min(e[b],c); }
	
	vector<pair<int,int> > order; REP(i,n) order.PB(MP(q[i],i)); sort(order.rbegin(),order.rend());
	int ret=0; bool ok=true;
	FOR(i,1,n) if(e[order[i].second]==INT_MAX) ok=false; else ret+=e[order[i].second];
	printf("%d\n",ok?ret:-1);
}

int main() {
	run();
	return 0;
}