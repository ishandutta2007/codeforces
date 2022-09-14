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

const int MAXH=300;
const int MAXW=300;
const int MAXVAL=300*300;
const int MAXD=MAXH+MAXW-2;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w,nval,dmx;
int t[MAXH][MAXW];

int dst[MAXH][MAXW];

int cnt[MAXVAL];
int xhead[MAXVAL],yhead[MAXVAL],xnxt[MAXH][MAXW],ynxt[MAXH][MAXW];

int qxhead[MAXD+1],qyhead[MAXD+1],qxnxt[MAXH][MAXW],qynxt[MAXH][MAXW];
int dp[MAXH][MAXW];

void calc(int z) {
	if(cnt[z]*cnt[z-1]<=5*h*w) {
		for(int cx=xhead[z],cy=yhead[z],tc;cx!=-1&&cy!=-1;tc=xnxt[cx][cy],cy=ynxt[cx][cy],cx=tc) {
			dst[cx][cy]=INT_MAX;
			for(int px=xhead[z-1],py=yhead[z-1],tp;px!=-1&&py!=-1;tp=xnxt[px][py],py=ynxt[px][py],px=tp) {
				int cur=dst[px][py]+abs(cx-px)+abs(cy-py); if(cur<dst[cx][cy]) dst[cx][cy]=cur;
			}
		}
	} else {
		int mn=INT_MAX; REP(x,h) REP(y,w) if(t[x][y]==z-1&&dst[x][y]<mn) mn=dst[x][y];
		REPE(d,dmx) qxhead[d]=qyhead[d]=-1; REP(x,h) REP(y,w) dp[x][y]=INT_MAX;
		REP(x,h) REP(y,w) if(t[x][y]==z-1) { int d=dst[x][y]-mn; assert(d<=dmx); qxnxt[x][y]=qxhead[d],qynxt[x][y]=qyhead[d],qxhead[d]=x,qyhead[d]=y; dp[x][y]=dst[x][y]; }
		REPE(d,dmx) for(int x=qxhead[d],y=qyhead[d],tmp;x!=-1&&y!=-1;tmp=qxnxt[x][y],y=qynxt[x][y],x=tmp) REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||dp[nx][ny]<=dp[x][y]+1) continue; assert(d+1<=dmx);
			qxnxt[nx][ny]=qxhead[d+1],qynxt[nx][ny]=qyhead[d+1],qxhead[d+1]=nx,qyhead[d+1]=ny; dp[nx][ny]=dp[x][y]+1;
		}
		REP(x,h) REP(y,w) if(t[x][y]==z) dst[x][y]=dp[x][y];
	}
}

void run() {
	scanf("%d%d%d",&h,&w,&nval); dmx=h+w-2;
	REP(x,h) REP(y,w) scanf("%d",&t[x][y]),--t[x][y];

	REP(i,nval) cnt[i]=0,xhead[i]=-1,yhead[i]=-1;
	REP(x,h) REP(y,w) xnxt[x][y]=xhead[t[x][y]],ynxt[x][y]=yhead[t[x][y]],xhead[t[x][y]]=x,yhead[t[x][y]]=y,++cnt[t[x][y]];

	REP(x,h) REP(y,w) dst[x][y]=t[x][y]==0?x+y:-2;
	FOR(i,1,nval) calc(i);
	REP(x,h) REP(y,w) if(t[x][y]==nval-1) { printf("%d\n",dst[x][y]); return; }
	printf("-1\n");
}

int main() {
	run();
	return 0;
}