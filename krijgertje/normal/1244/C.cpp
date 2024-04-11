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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

ll games,havepoints,pointswin,pointsdraw;
ll x,y,z;

bool solve() {
	REP(ndraw,pointswin) {
		if(ndraw*pointsdraw>havepoints) break;
		ll rempoints=havepoints-ndraw*pointsdraw;
		if(rempoints%pointswin!=0) continue;
		ll nwin=rempoints/pointswin;
		ll nlose=games-ndraw-nwin; if(nlose<0) continue;
		x=nwin,y=ndraw,z=nlose; return true;
	}
	return false;
}

void run() {
	scanf("%lld%lld%lld%lld",&games,&havepoints,&pointswin,&pointsdraw);
	if(!solve()) { printf("-1\n"); return; }
	printf("%lld %lld %lld\n",x,y,z);
}

int main() {
	run();
	return 0;
}