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

int h,w;
char g[MAXH][MAXW+1];

void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);

	int ax=-1,by=-1;
	REP(x,h) REP(y,w) if(ax==-1&&by==-1&&g[x][y]=='*') ax=x,by=y;
	if(ax==-1&&by==-1) { printf("YES\n%d %d\n",1,1); return; }
	int ay=-1,bx=-1;
	REP(x,h) REP(y,w) if(g[x][y]=='*') {
		if(x!=ax) { if(ay==-1) ay=y; if(y!=ay) ay=-2; }
		if(y!=by) { if(bx==-1) bx=x; if(x!=bx) bx=-2; }
	}
	if(ay==-1) ay=0; if(bx==-1) bx=0;
	if(ay!=-2) { printf("YES\n%d %d\n",ax+1,ay+1); return; }
	if(bx!=-2) { printf("YES\n%d %d\n",bx+1,by+1); return; }
	printf("NO\n");
}

int main() {
	run();
	return 0;
}