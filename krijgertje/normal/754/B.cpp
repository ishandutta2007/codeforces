#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
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
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

char g[4][5];

bool finished() {
	REP(sx,4) REP(sy,4) if(g[sx][sy]!='.') FORE(dx,-1,+1) FORE(dy,-1,+1) if(dx||dy) {
		int x=sx,y=sy; bool ok=true;
		REP(i,2) {
			x+=dx,y+=dy;
			if(x<0||x>=4||y<0||y>=4||g[x][y]!=g[sx][sy]) { ok=false; break; }
		}
		if(ok) return true;
	}
	return false;
}

void run() {
	REP(i,4) scanf("%s",g[i]);
	bool ret=false;
	REP(sx,4) REP(sy,4) if(g[sx][sy]=='.') {
		g[sx][sy]='x';
		if(finished()) ret=true;
		g[sx][sy]='.';
	}
	printf("%s\n",ret?"YES":"NO");
}

int main() {
	run();
	return 0;
}