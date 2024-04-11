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

void run() {
	int n; scanf("%d",&n);
	vector<int> want(n); REP(i,n) { scanf("%d",&want[i]); --want[i]; }
	vector<int> delta(n); REP(i,n) scanf("%d",&delta[i]);
	vector<vector<int> > e(n);
	REP(at,n) for(int times=-1;times<=+1;times+=2) {
		int to=at+times*delta[at];
		if(to<0||to>=n) continue;
		e[at].PB(to); e[to].PB(at);
	}
	vector<bool> done(n,false); bool ok=true;
	REP(start,n) if(!done[start]) {
		vector<int> a,b;
		queue<int> q;
		q.push(start); done[start]=true;
		while(!q.empty()) {
			int at=q.front(); q.pop();
			a.PB(at); b.PB(want[at]);
			REPSZ(i,e[at]) {
				int to=e[at][i];
				if(!done[to]) { q.push(to); done[to]=true; }
			}
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if(a!=b) ok=false;
	}
	printf("%s\n",ok?"YES":"NO");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}