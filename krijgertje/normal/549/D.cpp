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

const int MAXH=100;
const int MAXW=100;

int h,w;
char g[MAXH][MAXW];

int a[MAXH][MAXW];

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	REP(x,h) REP(y,w) a[x][y]=0;
	int ret=0;
	for(int x=h-1;x>=0;--x) for(int y=w-1;y>=0;--y) {
		int have=0;
		if(x+1<h) have+=a[x+1][y];
		if(y+1<w) have+=a[x][y+1];
		if(x+1<h&&y+1<w) have-=a[x+1][y+1];
		int want=g[x][y]=='W'?+1:-1;
		int now=want-have;
		if(now!=0) ++ret;
		a[x][y]=have+now;
	}
	//REP(x,h) { REP(y,w) printf("%5d",a[x][y]); puts(""); } puts("");
	printf("%d\n",ret);
}


int main() {
	run();
	return 0;
}