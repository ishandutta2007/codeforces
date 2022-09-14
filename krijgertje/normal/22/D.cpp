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

typedef struct X { int a,b; } X;
bool operator<(const X &s,const X &t) { return s.b<t.b; }

void run() {
	int n; scanf("%d",&n);
	vector<X> x(n); REP(i,n) { scanf("%d%d",&x[i].a,&x[i].b); if(x[i].b<x[i].a) swap(x[i].a,x[i].b); assert(x[i].a<=x[i].b); }
	sort(x.begin(),x.end());

	vector<int> res;
	int have=INT_MIN;
	REP(i,n) {
		if(x[i].a>have) {
			if(have!=INT_MIN) res.PB(have);
			have=x[i].b;
		} else {
			have=min(have,x[i].b);
		}
	}
	if(have!=INT_MIN) res.PB(have);
		
	printf("%d\n",SZ(res));
	REPSZ(i,res) { if(i!=0) printf(" "); printf("%d",res[i]); } puts("");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}