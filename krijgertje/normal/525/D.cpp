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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int h,w;
int g[2000][2000];

int qx[4000000],qy[4000000],qhead,qtail;

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) { char c; scanf(" %c",&c); g[x][y]=c=='*'?1:0; }

	qhead=qtail=0;
	REP(x,h) REP(y,w) if(g[x][y]==0) qx[qhead]=x,qy[qhead]=y,++qhead;
	while(qtail<qhead) {
		int x=qx[qtail],y=qy[qtail]; ++qtail;
		//printf("%d %d\n",x,y);
		FORE(dx,-1,+1) FORE(dy,-1,+1) {
			int nx=x+dx,ny=y+dy; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]!=1) continue;
			bool ok=false;
			if(x==nx) {
				if(x-1>=0) ok=ok||g[x-1][y]+g[x-1][ny]==0;
				if(x+1<h) ok=ok||g[x+1][y]+g[x+1][ny]==0;
			} else if(y==ny) {
				if(y-1>=0) ok=ok||g[x][y-1]+g[nx][y-1]==0;
				if(y+1<w) ok=ok||g[x][y+1]+g[nx][y+1]==0;
			} else {
				ok=ok||g[x][ny]+g[nx][y]==0;
			}
			if(ok) g[nx][ny]=0,qx[qhead]=nx,qy[qhead]=ny,++qhead;
		}
	}
	REP(x,h) { REP(y,w) printf("%c",g[x][y]==1?'*':'.'); puts(""); }
}

int main() {
	run();
	return 0;
}