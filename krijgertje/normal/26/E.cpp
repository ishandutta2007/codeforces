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
	int n,want; scanf("%d%d",&n,&want);
	vector<pair<int,int> > have(n); REP(i,n) { scanf("%d",&have[i].first); have[i].second=i+1; }
	sort(have.begin(),have.end());
	int sum=0; REP(i,n) sum+=have[i].first;
	
//	REPSZ(i,have) printf("%d %d\n",have[i].first,have[i].second); printf("%d/%d\n",want,sum);
	
	vector<int> ret;
	while(sum>want) {
		ret.PB(have[0].second);
		while(sum>want&&SZ(have)>=3) {
			ret.PB(have.back().second); ret.PB(have.back().second);
			if(--have.back().first==0) have.pop_back(); --sum;
		}
		while(sum>want&&SZ(have)==2&&(have[1].first>1||have[0].first==1)) {
			ret.PB(have[1].second); ret.PB(have[1].second);
			if(--have[1].first==0) have.pop_back(); --sum;
		}
		ret.PB(have[0].second);
		--have[0].first; --sum; --want;
		if(sum>want&&SZ(have)==2&&have[0].first>0) {
			swap(have[0],have[1]);
		} else {
			break;
		}
	}
	if(sum==want) {
		REPSZ(i,have) {
			while(have[i].first>0) { ret.PB(have[i].second); ret.PB(have[i].second); --have[i].first; --sum; --want; }
		}
		have.clear();
		printf("Yes\n");
		REPSZ(i,ret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
	} else {
		printf("No\n");
	}
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}