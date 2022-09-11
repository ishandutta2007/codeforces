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

const int MAXH=100;
const int MAXW=100;

int h,w;
int r[MAXH];
int c[MAXW];
int g[MAXH][MAXW];

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%d",&r[x]);
	REP(y,w) scanf("%d",&c[y]);

	int rsum=0; REP(x,h) rsum^=r[x];
	int csum=0; REP(y,w) csum^=c[y];
	if(rsum!=csum) { printf("NO\n"); return; }
	printf("YES\n");
	
	REP(x,h) REP(y,w) g[x][y]=0;
	g[0][0]=rsum^c[0]^r[0];
	FOR(x,1,h) g[x][0]=r[x];
	FOR(y,1,w) g[0][y]=c[y];
	REP(x,h) { REP(y,w) { if(y!=0) printf(" "); printf("%d",g[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}