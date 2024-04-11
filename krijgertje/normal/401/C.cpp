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

void run() {
	int n0,n1; scanf("%d%d",&n0,&n1);
	if(n1<n0-1||n1>2*(n0+1)) { printf("-1\n"); return; }
	if(n1==n0-1) { printf("0"); REP(i,n1) printf("10"); puts(""); return; }
	int ng1=n0+1;
	REP(i,ng1) {
		int cnt1=n1/ng1+(i<n1%ng1?1:0);
		REP(j,cnt1) printf("1");
		if(i<n0) printf("0");
	}
	puts("");
}

int main() {
	run();
	return 0;
}