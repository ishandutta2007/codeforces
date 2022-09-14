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

const int MAXC=100000;
const int MAXT=100000;

int nc,nt;
int c[MAXC];
int t[MAXT];

bool can(ll d) {
	int ti=0;
	REP(ci,nc) {
		while(ti+1<nt&&abs(t[ti]-c[ci])>=abs(t[ti+1]-c[ci])) ++ti;
		if(abs(t[ti]-c[ci])>d) return false;
	}
	return true;
}

void run() {
	scanf("%d%d",&nc,&nt);
	REP(i,nc) scanf("%d",&c[i]);
	REP(i,nt) scanf("%d",&t[i]);

	ll l=-1,h=max(c[nc-1],t[nt-1])-min(c[0],t[0]);
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(can(m)) h=m; else l=m;
	}
	printf("%lld\n",h);
}

int main() {
	run();
	return 0;
}