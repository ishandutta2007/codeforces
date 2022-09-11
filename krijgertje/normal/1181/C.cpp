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

const int MAXH=1000;
const int MAXW=1000;

int h,w;
char g[MAXH][MAXW+1];

int cntrgt[MAXH][MAXW];
vector<pair<int,int>> parts;


ll solve() {
	REP(x,h) for(int y=w-1;y>=0;--y) cntrgt[x][y]=1+(y+1<w&&g[x][y+1]==g[x][y]?cntrgt[x][y+1]:0);
	ll ret=0;
	REP(y,w) {
		parts.clear();
		for(int lx=0,hx=lx;lx<h;lx=hx) {
			while(hx<h&&g[lx][y]==g[hx][y]) ++hx;
			parts.PB(MP(lx,hx-1));
		}
		FOR(i,1,SZ(parts)-1) {
			int vert=parts[i].second-parts[i].first+1,bx=parts[i].first,ax=bx-vert,cx=bx+vert;
			if(ax<parts[i-1].first||cx+vert-1>parts[i+1].second) continue;
			int hor=INT_MAX; FORE(x,ax,cx+vert-1) hor=min(hor,cntrgt[x][y]);
			ret+=hor;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}