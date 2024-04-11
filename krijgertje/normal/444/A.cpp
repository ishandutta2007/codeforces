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

int n,m;
int x[500];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&x[i]);
	double ret=0;
	REP(i,m) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b;
		double cur=1.0*(x[a]+x[b])/c;
		if(cur>ret) ret=cur;
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}