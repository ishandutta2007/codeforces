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
#include <climits>
#include <cassert>
#include <ctime>
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


void run(int casenr) {
	int n; scanf("%d",&n);
	vector<int> w1,w2; REP(i,n) { int t,w; scanf("%d%d",&t,&w); if(t==1) w1.PB(w); else w2.PB(w); }
	sort(w1.begin(),w1.end()); sort(w2.begin(),w2.end());
	int ret=INT_MAX;
	REPE(i,SZ(w2)) {
		int sumw=0; REP(j,i) sumw+=w2[j];
		int sumt=2*(SZ(w2)-i)+SZ(w1);
		REPE(j,SZ(w1)) {
			if(sumt>=sumw&&sumt<ret) ret=sumt;
			if(j<SZ(w1)) { sumw+=w1[j]; --sumt; }
		}
	}
	printf("%d\n",ret);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}