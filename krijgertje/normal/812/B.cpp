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

const int MAXH=15;
const int MAXW=102;

int h,w;
char g[MAXH][MAXW+1];
int dpl[MAXH],dpr[MAXH];

int solve() {
	int last=-1; REP(x,h) REP(y,w) if(g[x][y]=='1') last=max(x,last); if(last==-1) return 0;
	int mx0=0; REP(y,w) if(g[0][y]=='1') mx0=y;
	if(last==0) return mx0;
	dpl[0]=(mx0==0?0:2*mx0); dpr[0]=w-1;
	FORE(x,1,last) {
		int mx=0,mn=w-1; bool any=false;
		REP(y,w) if(g[x][y]=='1') { mx=y; mn=min(mn,y); any=true; }
		//printf("x=%d prv=(%d,%d)",x,dpl[x-1],dpr[x-1]); if(!any) printf(" -\n"); else printf(" [mn=%d,mx=%d]\n",mn,mx);
		if(x==last) {
			assert(any);
			return min(dpl[x-1]+1+mx,dpr[x-1]+1+(w-1-mn));
		}
		if(!any) {
			dpl[x]=min(dpl[x-1]+1,dpr[x-1]+1+w-1);
			dpr[x]=min(dpr[x-1]+1,dpl[x-1]+1+w-1);
		} else {
			dpl[x]=min(dpl[x-1]+1+2*mx,dpr[x-1]+1+w-1);
			dpr[x]=min(dpr[x-1]+1+2*(w-1-mn),dpl[x-1]+1+w-1);
		}
	}
	assert(false);
}

void run() {
	scanf("%d%d",&h,&w); w+=2;
	REP(x,h) scanf("%s",g[h-x-1]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}