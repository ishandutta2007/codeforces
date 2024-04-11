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

typedef struct E { int to,cost; } E;

void run() {
	int n; scanf("%d",&n);
	vector<vector<E> > e(n);
	REP(i,n) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b;
		e[a].PB((E){b,0});
		e[b].PB((E){a,c});
	}
	REP(i,n) assert(SZ(e[i])==2);
	int ret=INT_MAX;
	REP(dir,2) {
		int at=e[0][dir].to,prev=0;
		int cur=e[0][dir].cost;
		while(at!=0) {
			int i=e[at][0].to!=prev?0:1;
//			printf("\t->%d (%d)\n",e[at][i].to,e[at][i].cost);
			cur+=e[at][i].cost,prev=at,at=e[at][i].to;
		}
//		printf("%d: %d\n",dir,cur);
		if(cur<ret) ret=cur;
	}	
	printf("%d\n",ret);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}