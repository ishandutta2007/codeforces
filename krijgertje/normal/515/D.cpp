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

const int DX[]={0,+1,0,-1},DY[]={+1,0,-1,0};
const char DC[4][2]={{'<','>'},{'^','v'},{'>','<'},{'v','^'}};

int h,w;
char g[2000][2000];
int deg[2000][2000];

int qx[2000*2000],qy[2000*2000],qhead,qtail;

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	REP(x,h) REP(y,w) if(g[x][y]=='.') {
		deg[x][y]=0;
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k];
			if(0<=nx&&nx<h&&0<=ny&&ny<w&&g[nx][ny]=='.') ++deg[x][y];
		}
	}

	qhead=qtail=0;
	REP(x,h) REP(y,w) if(g[x][y]=='.'&&deg[x][y]==1) { qx[qhead]=x; qy[qhead]=y; ++qhead; }
	while(qtail<qhead) {
		int x=qx[qtail],y=qy[qtail]; ++qtail;
		if(g[x][y]!='.') continue;
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k];
			if(0<=nx&&nx<h&&0<=ny&&ny<w&&g[nx][ny]=='.') {
				g[x][y]=DC[k][0]; g[nx][ny]=DC[k][1];
				REP(kk,4) {
					int xx=nx+DX[kk],yy=ny+DY[kk];
					if(0<=xx&&xx<h&&0<=yy&&yy<w&&g[xx][yy]=='.'&&--deg[xx][yy]==1) { qx[qhead]=xx; qy[qhead]=yy; ++qhead; }
				}
				break;
			}
		}
	}
	REP(x,h) REP(y,w) if(g[x][y]=='.') { printf("Not unique\n"); return; }
	REP(x,h) { REP(y,w) printf("%c",g[x][y]); puts(""); }
}

int main() {
	run();
	return 0;
}