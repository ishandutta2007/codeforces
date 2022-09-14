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
	int n,m,cw,hrot,ccw,p; scanf("%d%d%d%d%d%d",&n,&m,&cw,&hrot,&ccw,&p); cw%=4; hrot%=2; ccw%=4;
	REP(i,p) {
		int x,y; scanf("%d%d",&x,&y);
		int nn=n,mm=m;
		REP(j,cw) { int nx=y,ny=nn-x+1; x=nx,y=ny; swap(nn,mm); }
		REP(j,hrot) y=mm-y+1;
		REP(j,ccw) { int nx=mm-y+1,ny=x; x=nx,y=ny; swap(nn,mm); }
		printf("%d %d\n",x,y);
	}
}

int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}