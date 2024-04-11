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

const int MAXH=500;
const int MAXW=500;

int h,w;
char g[MAXH][MAXW];
int nq;

int cntup[MAXH+1][MAXW+1];
int cntlt[MAXH+1][MAXW+1];

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);
	memset(cntup,0,sizeof(cntup));
	memset(cntlt,0,sizeof(cntlt));
	FOR(x,1,h) REP(y,w) if(g[x][y]=='.'&&g[x-1][y]=='.') ++cntup[x+1][y+1];
	REP(x,h) FOR(y,1,w) if(g[x][y]=='.'&&g[x][y-1]=='.') ++cntlt[x+1][y+1];
	//REPE(x,h) { REPE(y,w) printf("%d ",cntup[x][y]); puts(""); } puts("");
	//REPE(x,h) { REPE(y,w) printf("%d ",cntlt[x][y]); puts(""); } puts("");
	FORE(x,1,h) FORE(y,1,w) cntup[x][y]+=cntup[x-1][y]+cntup[x][y-1]-cntup[x-1][y-1];
	FORE(x,1,h) FORE(y,1,w) cntlt[x][y]+=cntlt[x-1][y]+cntlt[x][y-1]-cntlt[x-1][y-1];
	//REPE(x,h) { REPE(y,w) printf("%3d ",cntup[x][y]); puts(""); } puts("");
	//REPE(x,h) { REPE(y,w) printf("%3d ",cntlt[x][y]); puts(""); } puts("");
	scanf("%d",&nq);
	REP(qi,nq) {
		int lx,hx,ly,hy,ret=0; scanf("%d%d%d%d",&lx,&ly,&hx,&hy);
		ret+=cntup[hx][hy]-cntup[lx][hy]-cntup[hx][ly-1]+cntup[lx][ly-1];
		ret+=cntlt[hx][hy]-cntlt[lx-1][hy]-cntlt[hx][ly]+cntlt[lx-1][ly];
		printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}