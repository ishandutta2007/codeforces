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
	int n,want; scanf("%d%d",&n,&want);
	vector<pair<int,int> > have;
	REP(i,n) { int x,y; scanf("%d%d",&x,&y); have.PB(MP(x,y)); }
	sort(have.begin(),have.end());
	int ret=2;
	FORSZ(i,1,have) {
		int margin=2*(have[i].first-have[i-1].first)-(have[i-1].second+2*want+have[i].second);
		if(margin>0) ret+=2; else if(margin==0) ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}