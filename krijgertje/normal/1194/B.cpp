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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXH=50000;
const int MAXW=50000;

int h,w;
string g[MAXH];

int rowcnt[MAXH];
int colcnt[MAXW];

int solve() {
	REP(x,h) assert(SZ(g[x])==w);
	REP(x,h) rowcnt[x]=0; REP(y,w) colcnt[y]=0;
	REP(x,h) REP(y,w) if(g[x][y]=='.') ++rowcnt[x],++colcnt[y];
	int ret=INT_MAX;
	REP(x,h) REP(y,w) {
		int cur=rowcnt[x]+colcnt[y];
		if(g[x][y]=='.') --cur;
		ret=min(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) cin>>g[x];
	printf("%d\n",solve());
	REP(x,h) g[x].clear();
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}