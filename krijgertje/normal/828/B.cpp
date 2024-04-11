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
#include <functional>
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

const int MAXH=100;
const int MAXW=100;

int h,w;
char g[MAXH][MAXW+1];

int solve() {
	int cnt=0; REP(x,h) REP(y,w) if(g[x][y]=='B') ++cnt; if(cnt==0) return 1;
	int lx=INT_MAX,hx=INT_MIN,ly=INT_MAX,hy=INT_MIN;
	REP(x,h) REP(y,w) if(g[x][y]=='B') { if(x<lx) lx=x; if(x>hx) hx=x; if(y<ly) ly=y; if(y>hy) hy=y; }
	int dx=hx-lx+1,dy=hy-ly+1,sz=max(dx,dy); if(sz>h||sz>w) return -1;
	return sz*sz-cnt;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}