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

const int MAXH=50;
const int MAXW=50;

int h,w;
int g[MAXH][MAXW];

void run() {
	scanf("%d%d",&h,&w); REP(x,h) REP(y,w) scanf("%d",&g[x][y]);
	ll ret=h*w;
	REP(x,h) {
		int n0=0,n1=0;
		REP(y,w) if(g[x][y]==0) ++n0; else ++n1;
		ret+=(1LL<<n0)-1-n0;
		ret+=(1LL<<n1)-1-n1;
	}
	REP(y,w) {
		int n0=0,n1=0;
		REP(x,h) if(g[x][y]==0) ++n0; else ++n1;
		ret+=(1LL<<n0)-1-n0;
		ret+=(1LL<<n1)-1-n1;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}