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

const int MAXN=100;

int n,sz;
char g[MAXN][MAXN+1];

int cnt[MAXN][MAXN];

void run() {
	scanf("%d%d",&n,&sz); REP(x,n) scanf("%s",g[x]);

	memset(cnt,0,sizeof(cnt));
	REP(x,n) REPE(sy,n-sz) {
		bool ok=true; REP(dy,sz) if(g[x][sy+dy]!='.') ok=false; if(!ok) continue;
		REP(dy,sz) ++cnt[x][sy+dy];
	}
	REP(y,n) REPE(sx,n-sz) {
		bool ok=true; REP(dx,sz) if(g[sx+dx][y]!='.') ok=false; if(!ok) continue;
		REP(dx,sz) ++cnt[sx+dx][y];
	}
	pair<int,int> ret=MP(0,0);
	REP(x,n) REP(y,n) if(cnt[x][y]>cnt[ret.first][ret.second]) ret=MP(x,y);
	printf("%d %d\n",ret.first+1,ret.second+1);
}

int main() {
	run();
	return 0;
}