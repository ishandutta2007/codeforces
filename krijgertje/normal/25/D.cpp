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

VI parent,rank;
int find(int a) { if(parent[a]==a) return a; return parent[a]=find(parent[a]); }

bool unite(int a,int b) {
	a=find(a); b=find(b);
	if(a==b) return false;
	if(rank[a]<rank[b]) swap(a,b);
	parent[b]=a; if(rank[a]==rank[b]) ++rank[a];
	return true;
}

void run() {
	int n; scanf("%d",&n);
	parent=VI(n); REP(i,n) parent[i]=i; rank=VI(n,0);
	vector<pair<int,int> > remove;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		if(!unite(a,b)) remove.PB(MP(a,b));
	}
	vector<int> roots;
	REP(i,n) if(parent[i]==i) roots.PB(i);
	int need=SZ(roots)-1;
	assert(SZ(remove)==need);
	printf("%d\n",need);
	REP(i,need) printf("%d %d %d %d\n",remove[i].first+1,remove[i].second+1,roots[0]+1,roots[i+1]+1);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}