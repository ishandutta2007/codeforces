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

const int MAXH=500;
const int MAXW=500;
const int MAXSTEP=(MAXH+MAXW+1)/2;
const int MOD=1000000007;

int h,w;
char g[MAXH][MAXW];

int ways[2][MAXSTEP+1][MAXSTEP+1]; // ways[.][a][b] = #ways after a certain of steps from both ends, a of which were down from start and b of which were up from finish

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	int at=0,len=h+w-1,hlen=(len+1)/2;
	REPE(ax,hlen-1) REPE(bx,hlen-1) {
		int ay=hlen-1-ax,by=hlen-1-bx;
		if(ax>=h||ay>=w||bx>=h||by>=w||g[ax][ay]!=g[h-bx-1][w-by-1]) {
			ways[at][ax][bx]=0;
		} else {
			ways[at][ax][bx]=abs(h-ax-bx-1)+abs(w-ay-by-1)==(len%2==0?1:0)?1:0;
		}
	}
	for(int step=hlen-2;step>=0;--step) {
		at=1-at;
		REPE(ax,step) REPE(bx,step) {
			int ay=step-ax,by=step-bx;
			if(ax>=h||ay>=w||bx>=h||by>=w||g[ax][ay]!=g[h-bx-1][w-by-1]) {
				ways[at][ax][bx]=0;
			} else {
				ways[at][ax][bx]=((ll)ways[1-at][ax][bx]+ways[1-at][ax][bx+1]+ways[1-at][ax+1][bx]+ways[1-at][ax+1][bx+1])%MOD;
			}
		}
	}
	printf("%d\n",ways[at][0][0]);

	
}


int main() {
	run();
	return 0;
}