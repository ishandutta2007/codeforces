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

int h,w,n; ll want;
int g[MAXH][MAXW];
bool done[MAXN];

int p[MAXN];
bool pcmp(const int &a,const int &b) { int ax=a/w,ay=a%w,bx=b/w,by=b%w; return g[ax][ay]>g[bx][by]; }

int uf[MAXN];
int find(int x) { if(uf[x]<0) return x; return uf[x]=find(uf[x]); }
void unite(int x,int y) {
	x=find(x); y=find(y);
	if(x==y) return;
	if(-uf[x]<-uf[y]) swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
}

int qx[MAXN],qy[MAXN],qhead,qtail;
bool hasret; int ret[MAXH][MAXW];
void calcsol(int sx,int sy,ll need) {
	REP(x,h) REP(y,w) ret[x][y]=0; qhead=qtail=0;
	ret[sx][sy]=g[sx][sy],qx[qhead]=sx,qy[qhead]=sy,++qhead;
	while(qtail<qhead&&qhead<need) {
		int x=qx[qtail],y=qy[qtail]; ++qtail;
		REP(k,4) if(qhead<need) {
			int nx=x+DX[k],ny=y+DY[k];
			if(nx<0||nx>=h||ny<0||ny>=w||ret[nx][ny]!=0||g[nx][ny]<g[sx][sy]) continue;
			ret[nx][ny]=g[sx][sy],qx[qhead]=nx,qy[qhead]=ny,++qhead;
		}
	}
	if(qhead!=need) { printf("err have %d want %lld\n",qhead,need); exit(0); }
}

void solve() {
	REP(i,n) p[i]=i; sort(p,p+n,pcmp);
	REP(i,n) uf[i]=-1,done[i]=false;

	REP(i,n) {
		int at=p[i],x=at/w,y=at%w; //printf("%d=(%d,%d)\n",at,x,y);
		done[at]=true;
		if(x-1>=0&&done[at-w]) unite(at,at-w);
		if(x+1<h&&done[at+w]) unite(at,at+w);
		if(y-1>=0&&done[at-1]) unite(at,at-1);
		if(y+1<w&&done[at+1]) unite(at,at+1);
		if(want%g[x][y]!=0) continue;
		at=find(at); ll need=want/g[x][y];
		if(-uf[at]>=need) { hasret=true; calcsol(x,y,need); return; }
	}
	hasret=false;
}

void run() {
	scanf("%d%d%I64d",&h,&w,&want); n=h*w;
	REP(x,h) REP(y,w) scanf("%d",&g[x][y]);
	solve();
	printf("%s\n",hasret?"YES":"NO");
	if(hasret) REP(x,h) { REP(y,w) { if(y!=0) printf(" "); printf("%d",ret[x][y]); } puts(""); }
}

void stress() {
	h=1000; w=1000; n=h*w; want=22181805360;
	REP(x,h) REP(y,w) {
		g[x][y]=1;
		for(int i=rand()%6;i>=0;--i) g[x][y]*=2;
		for(int i=rand()%4;i>=0;--i) g[x][y]*=3;
		for(int i=rand()%3;i>=0;--i) g[x][y]*=5;
		if(rand()%2) g[x][y]*=7; if(rand()%2) g[x][y]*=11; if(rand()%2) g[x][y]*=13; if(rand()%2) g[x][y]*=17; if(rand()%2) g[x][y]*=19; if(rand()%2) g[x][y]*=23;
		if(rand()%2) g[x][y]*=29; if(rand()%2) g[x][y]*=31; if(rand()%2) g[x][y]*=37; if(rand()%2) g[x][y]*=41;
	}
	solve(); printf("%c",hasret?'V':'.');
}

int main() {
	//REP(i,100) stress();
	run();
	return 0;
}