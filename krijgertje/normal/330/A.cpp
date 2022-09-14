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

int h,w;
char g[10][10];

void run(int casenr) {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	int ret=0;
	REP(x,h) {
		bool ok=true; REP(y,w) if(g[x][y]=='S') ok=false; if(!ok) continue;
		REP(y,w) if(g[x][y]=='.') { g[x][y]='x'; ++ret; }
	}
	REP(y,w) {
		bool ok=true; REP(x,h) if(g[x][y]=='S') ok=false; if(!ok) continue;
		REP(x,h) if(g[x][y]=='.') { g[x][y]='x'; ++ret; }
	}
	printf("%d\n",ret);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}