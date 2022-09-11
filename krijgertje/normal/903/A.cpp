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

const int MAXX=100;

bool can[MAXX+1];

void precalc() {
	memset(can,false,sizeof(can));
	can[0]=true;
	REPE(i,MAXX) if(can[i]) {
		if(i+3<=MAXX) can[i+3]=true;
		if(i+7<=MAXX) can[i+7]=true;
	}
}

void run() {
	int n; scanf("%d",&n);
	REP(i,n) { int x; scanf("%d",&x); printf("%s\n",can[x]?"YES":"NO"); }
}

int main() {
	precalc();
	run();
	return 0;
}