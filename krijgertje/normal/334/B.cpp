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

int x[8],y[8];

int allx[8],ally[8];

void run(int casenr) {
	REP(i,8) scanf("%d%d",&x[i],&y[i]);
	REP(i,8) allx[i]=x[i];
	REP(i,8) ally[i]=y[i];
	sort(allx,allx+8); int cntx=unique(allx,allx+8)-allx;
	sort(ally,ally+8); int cnty=unique(ally,ally+8)-ally;
	if(cntx==3&&cnty==3) {
		bool ok=true;
		REP(xi,3) REP(yi,3) if(xi!=1||yi!=1) {
			bool found=false;
			REP(i,8) if(x[i]==allx[xi]&&y[i]==ally[yi]) found=true;
			if(!found) ok=false;
		}
		if(ok) { printf("respectable\n"); return; }
	}
	printf("ugly\n");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}