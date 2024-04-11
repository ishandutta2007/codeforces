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
	int an,bn,ntypes; scanf("%d%d%d",&an,&bn,&ntypes);
	vector<int> a(an); REP(i,an) scanf("%d",&a[i]); sort(a.begin(),a.end());
	vector<int> b(bn); REP(i,bn) scanf("%d",&b[i]); sort(b.begin(),b.end());
	int ai=an-1,bi=bn-1; bool ok=false;
	while(ai>=0) {
		if(bi<0||a[ai]>b[bi]) { ok=true; break; }
		--ai,--bi;
	}
	printf("%s\n",ok?"YES":"NO");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}