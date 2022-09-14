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

const int MAXH=1000;
const int MAXW=1000;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w;
char g[MAXH][MAXW];

int d[MAXH][MAXW][3];
int qx[MAXH*MAXW*3],qy[MAXH*MAXW*3],qz[MAXH*MAXW*3],qhead,qtail;

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	#define QADD(x,y,z,c) { d[x][y][z]=c; qx[qhead]=x,qy[qhead]=y,qz[qhead]=z,++qhead; }
	REP(x,h) REP(y,w) REP(z,3) d[x][y][z]=INT_MAX;
	qhead=qtail=0;
	REP(x,h) REP(y,w) if(isdigit(g[x][y])) QADD(x,y,g[x][y]-'1',0);
	while(qtail<qhead) {
		int x=qx[qtail],y=qy[qtail],z=qz[qtail]; ++qtail;
		//printf("%d %d %d = %d\n",x,y,z,d[x][y][z]);
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k];
			if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='#'||d[nx][ny][z]!=INT_MAX) continue;
			QADD(nx,ny,z,d[x][y][z]+1);
		}
	}
	int d01=INT_MAX; REP(x,h) REP(y,w) if(d[x][y][0]<d01&&g[x][y]=='2') d01=d[x][y][0];
	int d12=INT_MAX; REP(x,h) REP(y,w) if(d[x][y][1]<d12&&g[x][y]=='3') d12=d[x][y][1];
	int d20=INT_MAX; REP(x,h) REP(y,w) if(d[x][y][2]<d20&&g[x][y]=='1') d20=d[x][y][2];
	if(d01==INT_MAX||d12==INT_MAX||d20==INT_MAX) { printf("-1\n"); return; }
	int ret=d01-1+d12-1+d20-1-max(d01-1,max(d12-1,d20-1));
	REP(x,h) REP(y,w) if(d[x][y][0]!=INT_MAX&&d[x][y][1]!=INT_MAX&&d[x][y][2]!=INT_MAX&&g[x][y]=='.') { int cur=d[x][y][0]+d[x][y][1]+d[x][y][2]-2; if(cur<ret) ret=cur; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}