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
const int MAXN=MAXH*MAXW;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w,nq;
char g[MAXH][MAXW];

int comp[MAXH][MAXW];
int sz[MAXN],ncomp;
int qx[MAXN],qy[MAXN],qhead,qtail;



void run() {
	scanf("%d%d%d",&h,&w,&nq); REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	ncomp=0; memset(comp,-1,sizeof(comp)); qhead=qtail=0;
	REP(sx,h) REP(sy,w) if(g[sx][sy]=='.'&&comp[sx][sy]==-1) {
		comp[sx][sy]=ncomp++; sz[ncomp-1]=0;
		qx[qhead]=sx,qy[qhead]=sy,++qhead;
		while(qtail<qhead) {
			int x=qx[qtail],y=qy[qtail]; ++qtail; 
			REP(k,4) {
				int nx=x+DX[k],ny=y+DY[k];
				if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]!='.') ++sz[ncomp-1];
				else if(comp[nx][ny]==-1) qx[qhead]=nx,qy[qhead]=ny,++qhead,comp[nx][ny]=comp[sx][sy];
			}
		}
	}
	REP(qi,nq) { int x,y; scanf("%d%d",&x,&y); --x,--y; printf("%d\n",sz[comp[x][y]]); }
}

int main() {
	run();
	return 0;
}