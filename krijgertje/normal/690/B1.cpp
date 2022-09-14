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

const int MAXN=50;

int n;
char g[MAXN][MAXN+1];

bool ok() {
	int lx=n+1,hx=-1,ly=n+1,hy=-1;
	REP(x,n) REP(y,n) if(g[x][y]=='4') {
		if(x<lx) lx=x; if(x+1>hx) hx=x+1;
		if(y<ly) ly=y; if(y+1>hy) hy=y+1;
	}
	if(lx>hx||ly>hy) return false;
	REP(x,n) REP(y,n) {
		int want=0;
		FORE(dx,0,+1) FORE(dy,0,+1) if(lx<=x+dx&&x+dx<=hx&&ly<=y+dy&&y+dy<=hy) ++want;
		if(g[x][y]!='0'+want) return false;
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(x,n) scanf("%s",g[x]);
	printf("%s\n",ok()?"Yes":"No");
}

int main() {
	run();
	return 0;
}