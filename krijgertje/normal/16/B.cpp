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
	int can,n; scanf("%d%d",&can,&n);
	vector<pair<int,int> > have;
	REP(i,n) { int nr,each; scanf("%d%d",&nr,&each); have.PB(MP(each,nr)); }
	sort(have.rbegin(),have.rend());
	int left=can;
	int ret=0;
	for(int i=0;i<SZ(have)&&left>0;++i) {
		int cur=min(left,have[i].second);
		ret+=cur*have[i].first;
		left-=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}