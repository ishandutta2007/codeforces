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
	vector<int> x(n); REP(i,n) scanf("%d",&x[i]);
	
	map<int,vector<int> > occ; REP(i,n) occ[x[i]].PB(i);
	
	map<int,vector<int> > deltas;
	for(map<int,vector<int> >::iterator i=occ.begin();i!=occ.end();++i) {
		vector<int> &y=i->second;
		REPSZ(j,y) FORSZ(k,j+1,i->second) deltas[y[k]-y[j]].PB(y[j]);
	}
			
	int start=0;
	for(map<int,vector<int> >::iterator i=deltas.begin();i!=deltas.end();++i) {
		vector<int> &y=i->second; int delta=i->first;
		sort(y.begin(),y.end());
//		printf("delta: %d\n",delta);
		int at=0;
		while(at<SZ(y)) {
			if(y[at]<start) { ++at; continue; }
//			printf("%d: %d\n",y[at],at+delta-1<SZ(y)?y[at+delta-1]:-1);
			assert(x[y[at]]==x[y[at]+delta]);
			if(at+delta-1<SZ(y)&&y[at+delta-1]==y[at]+delta-1) {
				start=y[at]+delta;
//				printf("-> %d\n",start);
			}
			++at;
		}
	}

	printf("%d\n",n-start);
	FOR(i,start,n) { if(i!=start) printf(" "); printf("%d",x[i]); } puts("");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}