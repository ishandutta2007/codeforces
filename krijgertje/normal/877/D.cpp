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

int h,w,mxrun;
char g[MAXH][MAXW+1];
int sx,sy,tx,ty;

int best[MAXH][MAXW][5];
priority_queue<pair<int,pair<pair<int,int>,int> > > pq;
void upd(int x,int y,int z,int steps,int remrun) {
	int cost=steps*mxrun+(mxrun-remrun-1);
	if(cost>=best[x][y][z]) return;
	best[x][y][z]=cost; pq.push(MP(-cost,MP(MP(x,y),z)));
}

int solve() {
	REP(x,h) REP(y,w) REP(z,5) best[x][y][z]=INT_MAX; pq=priority_queue<pair<int,pair<pair<int,int>,int> > >();
	upd(sx,sy,4,0,0);
	while(!pq.empty()) {
		int cost=-pq.top().first,x=pq.top().second.first.first,y=pq.top().second.first.second,z=pq.top().second.second,steps=cost/mxrun,remrun=mxrun-cost%mxrun-1; pq.pop();
		if(cost>best[x][y][z]) continue;
		if(x==tx&&y==ty&&z==4) return steps;
		if(z!=4) {
			upd(x,y,4,steps,0);
			if(remrun>0) { int nx=x+DX[z],ny=y+DY[z]; if(0<=nx&&nx<h&&0<=ny&&ny<w&&g[nx][ny]!='#') upd(nx,ny,z,steps,remrun-1); }
		} else {
			REP(nz,4) { int nx=x+DX[nz],ny=y+DY[nz]; if(0<=nx&&nx<h&&0<=ny&&ny<w&&g[nx][ny]!='#') upd(nx,ny,nz,steps+1,mxrun-1); }
		}
	}
	return -1;
}

void run() {
	scanf("%d%d%d",&h,&w,&mxrun);
	REP(x,h) scanf("%s",g[x]);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty); --sx,--sy,--tx,--ty;
	int ans=solve();
	printf("%d\n",ans);
}

int main() {
	run();
	return 0;
}