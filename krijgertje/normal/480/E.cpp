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

int h,w,n;
char g[2000][2000];
int cx[2000],cy[2000];

int dp[2000][2000];
int calc() {
	REP(x,h) dp[x][w-1]=g[x][w-1]=='.'?1:0;
	REP(y,w) dp[h-1][y]=g[h-1][y]=='.'?1:0;
	for(int x=h-2;x>=0;--x) for(int y=w-2;y>=0;--y) dp[x][y]=g[x][y]=='.'?1+min(min(dp[x+1][y],dp[x][y+1]),dp[x+1][y+1]):0;
//	REP(x,h) { REP(y,w) printf("%d ",dp[x][y]); puts(""); }
	int ret=0; REP(x,h) REP(y,w) if(dp[x][y]>ret) ret=dp[x][y]; return ret;
}

int up[2000][2000];
int dn[2000][2000];
void update(int y) {
	up[0][y]=g[0][y]=='.'?1:0;
	FOR(x,1,h) up[x][y]=g[x][y]=='.'?1+up[x-1][y]:0;
	dn[h-1][y]=g[h-1][y]=='.'?1:0;
	for(int x=h-2;x>=0;--x) dn[x][y]=g[x][y]=='.'?1+dn[x+1][y]:0;
}
int u[2000],d[2000];
bool exists(int x,int sy,int want) {
	if(up[x][sy]+dn[x][sy]-1<want) return false;
	u[sy]=up[x][sy];
	for(int y=sy-1;y>=0;--y) u[y]=min(up[x][y],u[y+1]);
	for(int y=sy+1;y<w;++y) u[y]=min(up[x][y],u[y-1]);
	d[sy]=dn[x][sy];
	for(int y=sy-1;y>=0;--y) d[y]=min(dn[x][y],d[y+1]);
	for(int y=sy+1;y<w;++y) d[y]=min(dn[x][y],d[y-1]);
	int ly=sy,hy=sy;
	while(ly-1>=0&&u[ly-1]+d[ly-1]-1>=want) --ly;
	while(ly<=sy) {
		while(hy+1<w&&min(u[ly],u[hy+1])+min(d[ly],d[hy+1])-1>=want) ++hy;
		if(hy-ly+1>=want) return true;
		++ly;
	}
	return false;
}



int ans[2001];
void run() {
	scanf("%d%d%d",&h,&w,&n);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);
	REP(i,n) { scanf("%d%d",&cx[i],&cy[i]); --cx[i],--cy[i]; }

	REP(i,n) g[cx[i]][cy[i]]='X';

	ans[n]=calc();
//	printf("ans[n]=%d\n",calc());
	REP(y,w) update(y);
	for(int i=n-1;i>=0;--i) {
//		printf("calculating before(%d,%d)\n",cx[i],cy[i]);
		g[cx[i]][cy[i]]='.';
		update(cy[i]);
		ans[i]=ans[i+1];
		while(exists(cx[i],cy[i],ans[i]+1)) ++ans[i];
//		printf("=%d\n",ans[i]);
	}
	FORE(i,1,n) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}