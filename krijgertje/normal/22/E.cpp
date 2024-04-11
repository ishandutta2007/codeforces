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

typedef struct Comp { vector<int> leafs; int center; } X;

void run() {
	int n; scanf("%d",&n);
	vector<int> x(n); REP(i,n) { scanf("%d",&x[i]); --x[i]; }
	
	vector<Comp> comps;
	vector<int> incomp(n,-1);
	REP(i,n) if(incomp[i]==-1) {
		int at=i;
		while(incomp[at]==-1) {
			incomp[at]=-2;
			at=x[at];
		}
		int nr;
		if(incomp[at]==-2) {
			Comp cur; cur.leafs.clear(); cur.center=at; comps.PB(cur);
			nr=SZ(comps)-1;
		} else {
			nr=incomp[at];
		}
		at=i;
		while(incomp[at]==-2) {
			incomp[at]=nr;
			at=x[at];
		}
	}
	
	vector<int> indeg(n,0);
	REP(i,n) indeg[x[i]]++;
	REP(i,n) if(indeg[i]==0) comps[incomp[i]].leafs.PB(i);
	
	vector<Comp> with,without;
	REPSZ(i,comps) if(SZ(comps[i].leafs)==0) without.PB(comps[i]); else with.PB(comps[i]);

	if(SZ(with)==0&&SZ(without)==1) {
		printf("0\n"); return;
	}
	
	vector<pair<int,int> > res;
	if(SZ(with)==0&&SZ(without)>=2) {
		Comp a=without.back(); without.pop_back();
		Comp b=without.back(); without.pop_back();
		res.PB(MP(a.center,b.center));
		b.leafs.PB(a.center);
		with.PB(b);
	}
	
//	printf("with:\n"); REPSZ(i,with) { printf("%d:",with[i].center+1); REPSZ(j,with[i].leafs) printf(" %d",with[i].leafs[j]+1); puts(""); }
//	printf("without:\n"); REPSZ(i,without) { printf("%d:\n",without[i].center+1); }
	
	while(SZ(without)>0) {
		Comp a=without.back(); without.pop_back();
		Comp &b=with[0];
		res.PB(MP(a.center,b.leafs.back())); b.leafs.pop_back();
		b.leafs.PB(a.center);
	}
	
	while(SZ(with)>1) {
		Comp a=with.back(); with.pop_back();
		Comp &b=with[0];
		res.PB(MP(a.center,b.leafs.back())); b.leafs.pop_back();
		REPSZ(i,a.leafs) b.leafs.PB(a.leafs[i]);
	}
	
	while(SZ(with[0].leafs)>0) {
		Comp &b=with[0];
		res.PB(MP(b.center,b.leafs.back())); b.leafs.pop_back();
	}
	
	printf("%d\n",SZ(res));
	REPSZ(i,res) printf("%d %d\n",res[i].first+1,res[i].second+1);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}