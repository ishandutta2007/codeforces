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
#include <random>
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
char g[MAXH][MAXW+1];

int dp[MAXH][MAXW][4];
int qx[MAXH*MAXW*4][2],qy[MAXH*MAXW*4][2],qk[MAXH*MAXW*4][2],qhead[2],qtail[2];

void process(int x,int y,int k,int cost) {
	if(x<0||x>=h||y<0||y>=w||g[x][y]=='*'||cost>=dp[x][y][k]) return;
	//printf("\t->(%d,%d,%d)=%d\n",x,y,k,cost);
	dp[x][y][k]=cost; int at=cost%2; qx[qhead[at]][at]=x,qy[qhead[at]][at]=y,qk[qhead[at]][at]=k,++qhead[at];
}

void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	REP(x,h) REP(y,w) REP(k,4) dp[x][y][k]=INT_MAX; REP(i,2) qhead[i]=qtail[i]=0;
	int at=0;
	REP(x,h) REP(y,w) if(g[x][y]=='S') REP(k,4) process(x,y,k,0);
	while(qtail[at]<qhead[at]||qtail[1-at]<qhead[1-at]) {
		if(qtail[at]>=qhead[at]) at=1-at;
		int x=qx[qtail[at]][at],y=qy[qtail[at]][at],k=qk[qtail[at]][at]; ++qtail[at];
		//printf("(%d,%d,%d)=%d\n",x,y,k,dp[x][y][k]);
		process(x+DX[k],y+DY[k],k,dp[x][y][k]);
		REP(nk,4) process(x,y,nk,dp[x][y][k]+1);
	}
	int ret=INT_MAX; REP(x,h) REP(y,w) if(g[x][y]=='T') REP(k,4) ret=min(ret,dp[x][y][k]); printf("%s\n",ret<=2?"YES":"NO");
}

int main() {
	run();
	return 0;
}