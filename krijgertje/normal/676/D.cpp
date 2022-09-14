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
const int MAXN=MAXH*MAXW*4;
const int DX[]={0,+1,0,-1},DY[]={+1,0,-1,0};

int h,w;
char g[MAXH][MAXW+1];
int sx,sy,tx,ty;

int d[MAXH][MAXW][4];

int qtail,qhead,qx[MAXN],qy[MAXN],qz[MAXN];
void add(int x,int y,int z,int dd) { if(d[x][y][z]!=INT_MAX) return; d[x][y][z]=dd; qx[qhead]=x,qy[qhead]=y,qz[qhead]=z,++qhead; }
bool can(char c,int k) {
	if(c=='+') return true;
	if(c=='-') return k%2==0;
	if(c=='|') return k%2==1;
	if(c=='>') return k==0;
	if(c=='v') return k==1;
	if(c=='<') return k==2;
	if(c=='^') return k==3;
	if(c=='R') return k!=0;
	if(c=='D') return k!=1;
	if(c=='L') return k!=2;
	if(c=='U') return k!=3;
	if(c=='*') return false;
	assert(false); return false;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty); --sx,--sy,--tx,--ty;
	
	qhead=qtail=0;
	REP(x,h) REP(y,w) REP(z,4) d[x][y][z]=INT_MAX;
	add(sx,sy,0,0);
	while(qtail<qhead) {
		int x=qx[qtail],y=qy[qtail],z=qz[qtail]; ++qtail;
		//printf("%d %d %d: %d\n",x,y,z,d[x][y][z]);
		add(x,y,(z+1)%4,d[x][y][z]+1);
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k],nz=z;
			if(nx<0||nx>=h||ny<0||ny>=w) continue;
			if(!can(g[x][y],(k+4-z)%4)) continue;
			if(!can(g[nx][ny],(k+6-z)%4)) continue;
			add(nx,ny,nz,d[x][y][z]+1);
		}
	}
	int ret=INT_MAX; REP(k,4) if(d[tx][ty][k]<ret) ret=d[tx][ty][k];
	printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}