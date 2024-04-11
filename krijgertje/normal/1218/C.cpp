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
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXH=500;
const int MAXW=500;
const int MAXGUARD=500000;

int h,w,nguard;
int gx[MAXGUARD],gy[MAXGUARD],gd[MAXGUARD],gt[MAXGUARD],ge[MAXGUARD];

ll cost[MAXH][MAXW];
vector<pair<int,int>> horsave[MAXH][MAXW];
vector<pair<int,int>> versave[MAXH][MAXW];

ll hordp[MAXW][MAXW],nhordp[MAXW][MAXW];
ll verdp[MAXW][MAXH],nverdp[MAXW][MAXH];
ll chorsave[MAXW],cversave[MAXH];

ll solve() {
	REP(x,h) REP(y,w) cost[x][y]=0;
	REP(x,h) REP(y,w) horsave[x][y].clear();
	REP(x,h) REP(y,w) versave[x][y].clear();
	REP(i,nguard) {
		int ax=gx[i],ay=gy[i],at=gt[i];
		int bx=gx[i]+gd[i],by=gy[i]-gd[i],bt=gt[i]+1;
		int cx=gx[i]+gd[i],cy=gy[i],ct=gt[i]+2;
		int dx=gx[i],dy=gy[i]+gd[i],dt=gt[i]+3;
		bool hita=false; if((ax+ay)%4==at%4&&at<=ax+ay) hita=true,at=ax+ay;
		bool hitb=false; if((bx+by)%4==bt%4&&bt<=bx+by) hitb=true,bt=bx+by;
		bool hitc=false; if((cx+cy)%4==ct%4&&ct<=cx+cy) hitc=true,ct=cx+cy;
		bool hitd=false; if((dx+dy)%4==dt%4&&dt<=dx+dy) hitd=true,dt=dx+dy;
		if(hita) cost[ax][ay]+=ge[i];
		if(hitb) cost[bx][by]+=ge[i];
		if(hitc) {
			cost[cx][cy]+=ge[i];
			if(hita) versave[cx][cy].PB(MP(ax,ge[i]));
			if(hitb) horsave[cx][cy].PB(MP(by,ge[i]));
		}
		if(hitd) {
			cost[dx][dy]+=ge[i];
			if(hita) horsave[dx][dy].PB(MP(ay,ge[i]));
		}
	}
	
	REP(x,h) {
		REP(y,w) {
			REPE(k,y) chorsave[k]=0; REPSZ(i,horsave[x][y]) chorsave[horsave[x][y][i].first]+=horsave[x][y][i].second; for(int k=y;k>0;--k) chorsave[k-1]+=chorsave[k];
			REPE(k,x) cversave[k]=0; REPSZ(i,versave[x][y]) cversave[versave[x][y][i].first]+=versave[x][y][i].second; for(int k=x;k>0;--k) cversave[k-1]+=cversave[k];
			nhordp[y][y]=x==0&&y==0?cost[x][y]:LLONG_MAX;
			REP(k,x) if(verdp[y][k]!=LLONG_MAX) nhordp[y][y]=min(nhordp[y][y],verdp[y][k]+cost[x][y]-cversave[k]);
			REP(k,y) nhordp[y][k]=nhordp[y-1][k]==LLONG_MAX?LLONG_MAX:nhordp[y-1][k]+cost[x][y]-chorsave[k];
			nverdp[y][x]=x==0&&y==0?cost[x][y]:LLONG_MAX;
			REP(k,y) if(nhordp[y-1][k]!=LLONG_MAX) nverdp[y][x]=min(nverdp[y][x],nhordp[y-1][k]+cost[x][y]-chorsave[k]);
			REP(k,x) nverdp[y][k]=verdp[y][k]==LLONG_MAX?LLONG_MAX:verdp[y][k]+cost[x][y]-cversave[k];
		}
		REP(y,w) REPE(k,y) hordp[y][k]=nhordp[y][k];
		REP(y,w) REPE(k,x) verdp[y][k]=nverdp[y][k];
	}
	ll ret=LLONG_MAX; REP(k,w) ret=min(ret,hordp[w-1][k]); REP(k,h) ret=min(ret,verdp[w-1][k]); return ret;
}

void run() {
	scanf("%d%d%d",&h,&w,&nguard);
	REP(i,nguard) scanf("%d%d%d%d%d",&gx[i],&gy[i],&gd[i],&gt[i],&ge[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}