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

int h,w;
char g[1000][1000];

void transpose() {
	int lim=max(h,w);
	REP(i,lim) FOR(j,i+1,lim) swap(g[i][j],g[j][i]);
	swap(h,w);
}

int sim(int x,int y,int X,int Y) {
	REP(dx,X) REP(dy,Y) if(g[x+dx][y+dy]!='X') return 0;
	int ret=X*Y;
	while(true) {
		if(x+X<h&&g[x+X][y]=='X') {
			REP(dy,Y) if(g[x+X][y+dy]!='X') return ret;
			ret+=Y; ++x;
		} else if(y+Y<w&&g[x][y+Y]=='X') {
			REP(dx,X) if(g[x+dx][y+Y]!='X') return ret;
			ret+=X; ++y;
		} else {
			return ret;
		}
	}
}

int calc() {
	int sx=-1,sy=-1;
	REP(x,h) REP(y,w) if(sx==-1&&sy==-1&&g[x][y]=='X') sx=x,sy=y;
	assert(sx!=-1&&sy!=-1);

	int X=1,Y=1;
	FOR(y,sy+1,w) if(g[sx][y]!='X') break; else ++Y;
	FOR(x,sx+1,h) if(g[x][sy]!='X') break; else ++X;
//	printf("%d*%d\n",X,Y);
	int DX=0; FOR(x,sx,sx+X-1) if(sy+Y<w&&g[x][sy+Y]=='X') break; else ++DX; X-=DX;
//	printf("%d*%d\n",X,Y);

	int want=0; REP(x,h) REP(y,w) if(g[x][y]=='X') ++want;
	int have=sim(sx,sy,X,Y);

//	REP(i,h) { REP(j,w) printf("%c",g[i][j]); puts(""); } puts("");
//	printf("start at (%d,%d) brush of size (%d,%d)=%d -> %d (want %d)\n",sx,sy,X,Y,X*Y,have,want);

	return have==want?X*Y:INT_MAX;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(i,h) REP(j,w) scanf(" %c",&g[i][j]);
	int ret=INT_MAX;
	{ int cur=calc(); if(cur<ret) ret=cur; }
	transpose();
	{ int cur=calc(); if(cur<ret) ret=cur; }
	printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}