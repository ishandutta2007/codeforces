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

int n,m;
bool cancenter[1000];

void run(int casenr) {
	scanf("%d%d",&n,&m);
	REP(i,n) cancenter[i]=true;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; cancenter[a]=cancenter[b]=false; }
	REP(i,n) if(cancenter[i]) {
		printf("%d\n",n-1);
		REP(j,n) if(i!=j) printf("%d %d\n",i+1,j+1);
		return;
	}
	assert(false);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}