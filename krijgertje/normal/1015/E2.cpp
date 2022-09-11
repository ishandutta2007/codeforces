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

const int MAXH=1000;
const int MAXW=1000;

int h,w;
char g[MAXH][MAXW+1];

int up[MAXH][MAXW],dn[MAXH][MAXW],lt[MAXH][MAXW],rt[MAXH][MAXW];

int sz[MAXH][MAXW];
int vmark[MAXH+1][MAXW];
int hmark[MAXH][MAXW+1];

int ret[MAXH*MAXW][3],nret;

void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);

	REP(x,h) REP(y,w) up[x][y]=g[x][y]!='*'?-1:x==0?0:up[x-1][y]+1;
	REP(x,h) REP(y,w) lt[x][y]=g[x][y]!='*'?-1:y==0?0:lt[x][y-1]+1;
	for(int x=h-1;x>=0;--x) for(int y=w-1;y>=0;--y) dn[x][y]=g[x][y]!='*'?-1:x==h-1?0:dn[x+1][y]+1;
	for(int x=h-1;x>=0;--x) for(int y=w-1;y>=0;--y) rt[x][y]=g[x][y]!='*'?-1:y==w-1?0:rt[x][y+1]+1;

	REP(x,h) REP(y,w) sz[x][y]=max(0,min(min(up[x][y],dn[x][y]),min(lt[x][y],rt[x][y])));
	//REP(x,h) { REP(y,w) printf("%3d",sz[x][y]); puts(""); }
	REPE(x,h) REP(y,w) vmark[x][y]=0; REP(x,h) REP(y,w) if(sz[x][y]>0) ++vmark[x-sz[x][y]][y],--vmark[x+sz[x][y]+1][y]; REP(x,h) REP(y,w) vmark[x+1][y]+=vmark[x][y];
	REP(x,h) REPE(y,w) hmark[x][y]=0; REP(x,h) REP(y,w) if(sz[x][y]>0) ++hmark[x][y-sz[x][y]],--hmark[x][y+sz[x][y]+1]; REP(x,h) REP(y,w) hmark[x][y+1]+=hmark[x][y];
	REP(x,h) REP(y,w) if(vmark[x][y]>0||hmark[x][y]>0) assert(g[x][y]=='*');
	REP(x,h) REP(y,w) if(g[x][y]=='*'&&vmark[x][y]==0&&hmark[x][y]==0) { printf("-1\n"); return; }
	nret=0; REP(x,h) REP(y,w) if(sz[x][y]!=0) ret[nret][0]=x,ret[nret][1]=y,ret[nret][2]=sz[x][y],++nret;
	printf("%d\n",nret); REP(i,nret) printf("%d %d %d\n",ret[i][0]+1,ret[i][1]+1,ret[i][2]);
}

int main() {
	run();
	return 0;
}