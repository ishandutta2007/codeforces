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

typedef struct X { int wins,total,index; } X;
bool operator<(const X &a,const X &b) {
	if(a.wins!=b.wins) return a.wins<b.wins;
	if(a.total!=b.total) return a.total>b.total;
	return false;
}

void run() {
	int n; scanf("%d",&n);
	vector<X> x; REP(i,n) x.PB((X){0,0,i+1});
	REP(i,n*(n-1)/2-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		x[a].wins++; x[a].total++; x[b].total++;
	}
	sort(x.begin(),x.end());
	int need=n-1;
	int win=-1,lose=-1;
	REP(i,n) {
		if(x[i].total==need) {
			assert(x[i].wins==i);
		} else {
			assert(x[i].total+1==need);
			if(x[i].wins==i) {
				assert(lose==-1);
				lose=x[i].index;
				x[i].total++;
			} else {
				assert(x[i].wins+1==i);
				assert(win==-1);
				win=x[i].index;
				x[i].wins++; x[i].total++;
			}
		}
	}
	assert(win!=-1&&lose!=-1);
	printf("%d %d\n",win,lose);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}