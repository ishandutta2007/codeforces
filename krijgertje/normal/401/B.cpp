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

int now,n;
bool seen[4001];

void run() {
	scanf("%d%d",&now,&n);
	memset(seen,false,sizeof(seen)); seen[0]=true; seen[now]=true;
	REP(i,n) {
		int type; scanf("%d",&type); REP(j,3-type) { int x; scanf("%d",&x); seen[x]=true; }
	}
	int l=0,h=0; int unseen=0;
	FORE(i,0,now) {
		if(!seen[i]) { ++unseen; continue; }
		h+=unseen; l+=(unseen+1)/2; unseen=0;
	}
	printf("%d %d\n",l,h);
}

int main() {
	run();
	return 0;
}