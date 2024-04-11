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

const int MAXN=10;
const int KDX[]={-2,+2,-1,+1,-1,+1,-2,+2},KDY[]={-1,-1,-2,-2,+2,+2,+1,+1};

int n;
int a[MAXN][MAXN];

pair<int,int> d[MAXN*MAXN][3][MAXN][MAXN];
priority_queue<pair<pair<int,int>,pair<pair<int,int>,pair<int,int>>>> pq;

void upd(int i,int j,int x,int y,int steps,int swaps) {
	if(steps>d[i][j][x][y].first||steps==d[i][j][x][y].first&&swaps>=d[i][j][x][y].second) return;
	d[i][j][x][y]=MP(steps,swaps),pq.push(MP(MP(-steps,-swaps),MP(MP(i,j),MP(x,y))));
}
pair<int,int> solve() {
	pq=priority_queue<pair<pair<int,int>,pair<pair<int,int>,pair<int,int>>>>();
	REP(i,n*n) REP(j,3) REP(x,n) REP(y,n) d[i][j][x][y]=MP(INT_MAX,INT_MAX);
	REP(x,n) REP(y,n) if(a[x][y]==0) REP(j,3) upd(0,j,x,y,0,0);
	while(!pq.empty()) {
		int i=pq.top().second.first.first,j=pq.top().second.first.second,x=pq.top().second.second.first,y=pq.top().second.second.second,steps=-pq.top().first.first,swaps=-pq.top().first.second; pq.pop();
		if(d[i][j][x][y]!=MP(steps,swaps)) continue;
		//printf("%d %d %d %d = (%d,%d)\n",i,j,x,y,steps,swaps);
		if(a[x][y]==i+1) upd(i+1,j,x,y,steps,swaps);
		REP(nj,3) upd(i,nj,x,y,steps+1,swaps+1);
		if(j==0) { // knight
			REP(k,8) {
				int nx=x+KDX[k],ny=y+KDY[k]; 
				if(0<=nx&&nx<n&&0<=ny&&ny<n) upd(i,j,nx,ny,steps+1,swaps);
			}
		}
		if(j==1) { // bishop
			for(int nx=x,ny=y;0<=nx&&nx<n&&0<=ny&&ny<n;++nx,++ny) upd(i,j,nx,ny,steps+1,swaps);
			for(int nx=x,ny=y;0<=nx&&nx<n&&0<=ny&&ny<n;++nx,--ny) upd(i,j,nx,ny,steps+1,swaps);
			for(int nx=x,ny=y;0<=nx&&nx<n&&0<=ny&&ny<n;--nx,++ny) upd(i,j,nx,ny,steps+1,swaps);
			for(int nx=x,ny=y;0<=nx&&nx<n&&0<=ny&&ny<n;--nx,--ny) upd(i,j,nx,ny,steps+1,swaps);
		}
		if(j==2) { // rook
			{ int ny=y; REP(nx,n) upd(i,j,nx,ny,steps+1,swaps); }
			{ int nx=x; REP(ny,n) upd(i,j,nx,ny,steps+1,swaps); }
		}
	}
	pair<int,int> ret=MP(INT_MAX,INT_MAX);
	REP(x,n) REP(y,n) if(a[x][y]==n*n-1) REP(j,3) { pair<int,int> cur=d[n*n-1][j][x][y]; if(cur.first<ret.first||cur.first==ret.first&&cur.second<ret.second) ret=cur; }
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&a[i][j]),--a[i][j];
	pair<int,int> ans=solve();
	printf("%d %d\n",ans.first,ans.second);
}

int main() {
	run();
	return 0;
}