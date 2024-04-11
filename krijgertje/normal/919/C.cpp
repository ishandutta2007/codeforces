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

const int MAXH=2000;
const int MAXW=2000;

int h,w,need;
char g[MAXH][MAXW+1];

int solve() {
	if(need==1) { int ret=0; REP(x,h) REP(y,w) if(g[x][y]=='.') ++ret; return ret; }
	int ret=0;
	REP(x,h) { int cnt=0; REP(y,w) if(g[x][y]!='.') cnt=0; else { ++cnt; if(cnt>=need) ++ret; }	}
	REP(y,w) { int cnt=0; REP(x,h) if(g[x][y]!='.') cnt=0; else { ++cnt; if(cnt>=need) ++ret; }	}
	return ret;
}

void run() {
	scanf("%d%d%d",&h,&w,&need); REP(x,h) scanf("%s",g[x]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}