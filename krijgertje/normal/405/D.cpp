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

int n;
int x[500000];
bool can[1000001];

int nret,ret[500000];

void run() {
	FORE(i,1,1000000) can[i]=true;
	scanf("%d",&n);
	REP(i,n) { scanf("%d",&x[i]); can[x[i]]=false; }

	nret=0; int at=1;
	REP(i,n) {
		int y=1000001-x[i];
		if(can[y]) { can[y]=false; ret[nret++]=y; continue; }
		if(y<x[i]) continue;
		while(at<=1000000&&(!can[at]||!can[1000001-at])) ++at;
		assert(at<=1000000);
		can[at]=can[1000001-at]=false;
		ret[nret++]=at; ret[nret++]=1000001-at;
	}
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}