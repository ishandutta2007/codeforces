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
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m),b(m); 
	REP(i,m) { scanf("%d%d",&a[i],&b[i]); --a[i],--b[i]; if(a[i]>b[i]) swap(a[i],b[i]); }
	vector<vector<int> > conflict(m);
	REP(i,m) FOR(j,i+1,m) {
		if(a[i]==a[j]||a[i]==b[j]||b[i]==a[j]||b[i]==b[j]) continue;
		if((a[i]<a[j]&&a[j]<b[i])^(a[i]<b[j]&&b[j]<b[i])) conflict[i].PB(j),conflict[j].PB(i);
	}
//	REP(i,m) REPSZ(j,conflict[i]) printf("%d vs %d\n",i,conflict[i][j]);
	bool ok=true;
	string color(m,'?');
	REP(i,m) if(color[i]=='?') {
		color[i]='o';
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			int at=q.front(); q.pop();
			REPSZ(j,conflict[at]) {
				int to=conflict[at][j];
				if(color[to]==color[at]) { color[to]='x'; ok=false; }
				else if(color[to]=='?') { color[to]=(color[at]=='o'?'i':'o'); q.push(to); }
			}
		}
	}
	if(ok) printf("%s\n",color.c_str()); else printf("Impossible\n");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}