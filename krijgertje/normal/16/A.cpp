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
	int R,C; scanf("%d%d",&R,&C);
	bool ok=true;
	char prevrow='?';
	REP(r,R) {
		char currow; scanf(" %c",&currow);
		if(currow==prevrow) ok=false;
		FOR(c,1,C) { char now; scanf("%c",&now); if(now!=currow) ok=false; }
		prevrow=currow;
	}
	printf("%s\n",ok?"YES":"NO");
}

int main() {
	run();
	return 0;
}