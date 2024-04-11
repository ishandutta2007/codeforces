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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXH=2000;
const int MAXW=2000;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { if((a-=b)<0) a+=MOD; }

int h,w;
char g[MAXH][MAXW+1];

int cntrt[MAXH][MAXW];
int cntdn[MAXH][MAXW];


int dpdn[MAXH][MAXW]; // dpdn[x][y] = #ways to reach (x,y) with the block originally at (x,y) if any pushed down and all other blocks down and right still in its original places
int dprt[MAXH][MAXW];



int solve() {
	REP(x,h) { for(int y=w-1;y>=0;--y) cntrt[x][y]=(g[x][y]=='R'?1:0)+(y+1<w?cntrt[x][y+1]:0); }
	REP(y,w) { for(int x=h-1;x>=0;--x) cntdn[x][y]=(g[x][y]=='R'?1:0)+(x+1<h?cntdn[x+1][y]:0); }

	REP(x,h) REP(y,w) dpdn[x][y]=dprt[x][y]=0;
	inc(dprt[0][0],1); if(1<h) dec(dprt[1][0],1);
	REP(x,h) REP(y,w) {
		if(y-1>=0) inc(dpdn[x][y],dpdn[x][y-1]);
		if(x-1>=0) inc(dprt[x][y],dprt[x-1][y]);
		//printf("(%d,%d) -> dn=%d rt=%d\n",x,y,cntdn[x][y]<=h-x-1?dpdn[x][y]:0,cntrt[x][y]<=w-y-1?dprt[x][y]:0);
		if(dprt[x][y]!=0&&x+1<h&&cntrt[x][y]<=w-y-1) {
			int nr=cntrt[x][y];
			inc(dpdn[x+1][y],dprt[x][y]);
			if(nr!=0) dec(dpdn[x+1][w-nr],dprt[x][y]);
			//FOR(yy,y,w-nr) inc(dpdn[x+1][yy],dprt[x][y]);
		}
		if(dpdn[x][y]!=0&&y+1<w&&cntdn[x][y]<=h-x-1) {
			int nd=cntdn[x][y];
			inc(dprt[x][y+1],dpdn[x][y]);
			if(nd!=0) dec(dprt[h-nd][y+1],dpdn[x][y]);
			//FOR(xx,x,h-nd) inc(dprt[xx][y+1],dpdn[x][y]);
		}
	}
	int ret=0;
	REP(x,h) REP(y,w) {
		if(dprt[x][y]!=0&&x==h-1&&cntrt[x][y]==0) inc(ret,dprt[x][y]);
		if(dpdn[x][y]!=0&&y==w-1&&cntdn[x][y]==0) inc(ret,dpdn[x][y]);
	}
	return ret;
}


void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}