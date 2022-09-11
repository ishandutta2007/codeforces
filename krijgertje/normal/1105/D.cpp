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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXH=1000;
const int MAXW=1000;
const int MAXP=9;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w,np;
int speed[MAXP];
char g[MAXH][MAXW+1];
int ans[MAXP];

vector<pair<int,int>> active[MAXP];
int d[MAXH][MAXW];

vector<pair<int,int>> discovered;
queue<pair<int,int>> q;
bool dead[MAXP];

void solve() {
	REP(i,np) active[i].clear();
	REP(x,h) REP(y,w) if(isdigit(g[x][y])) active[g[x][y]-'0'].PB(MP(x,y));
	REP(x,h) REP(y,w) d[x][y]=-1;
	REP(i,np) dead[i]=false;
	while(true) {
		bool change=false;
		REP(i,np) if(!dead[i]) {
		    discovered.clear(); q=queue<pair<int,int>>();
			REPSZ(j,active[i]) { int x=active[i][j].first,y=active[i][j].second; assert(g[x][y]=='0'+i); q.push(MP(x,y)); d[x][y]=0; }
			while(!q.empty()) {
				int x=q.front().first,y=q.front().second; q.pop(); if(d[x][y]==speed[i]) continue;
				REP(k,4) {
					int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]!='.') continue;
					discovered.PB(MP(nx,ny)); q.push(MP(nx,ny)); g[nx][ny]='0'+i; d[nx][ny]=d[x][y]+1; change=true;
				}
			}
			active[i]=discovered;
			dead[i]=SZ(active[i])==0;
		}
		if(!change) break;
	}
	REP(i,np) ans[i]=0; REP(x,h) REP(y,w) if(isdigit(g[x][y])) ans[g[x][y]-'0']++;
}

void run() {
	scanf("%d%d%d",&h,&w,&np);
	REP(i,np) scanf("%d",&speed[i]);
	REP(x,h) scanf("%s",g[x]); REP(x,h) REP(y,w) if(isdigit(g[x][y])) --g[x][y];
	solve();
	REP(i,np) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

void stress() {
	REP(rep,1) {
		h=MAXH,w=MAXW,np=MAXP; //rand()%MAXP+1;
		REP(i,np) speed[i]=1; //rand()%(h*w)+1;
		REP(x,h) REP(y,w) g[x][y]=x%2==0||x%4==1&&y==w-1||x%4==3&&y==0?'.':'#'; REP(x,h) g[x][w]='\0';
		REP(y,w) g[h-1][y]=g[h-2][y]='#';
		g[0][0]='0';
		FOR(i,1,np) g[h-1][i-1]='0'+i;
		//REP(x,h) printf("%s\n",g[x]);
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}