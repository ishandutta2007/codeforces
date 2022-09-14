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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int nseller,have;
int nitems[50],cost[50][50];

bool can[50]; int ncan;

void run() {
	scanf("%d%d",&nseller,&have);
	REP(i,nseller) { scanf("%d",&nitems[i]); REP(j,nitems[i]) scanf("%d",&cost[i][j]); }

	REP(i,nseller) { can[i]=false; REP(j,nitems[i]) if(have>cost[i][j]) can[i]=true; }
	ncan=0; REP(i,nseller) if(can[i]) ++ncan;

	printf("%d\n",ncan);
	bool first=true; REP(i,nseller) if(can[i]) { if(first) first=false; else printf(" "); printf("%d",i+1); } puts("");
}

int main() {
	run();
	return 0;
}