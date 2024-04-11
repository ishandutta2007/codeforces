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

char g[9][9];
int px,py;

void run() {
	REP(x,9) REP(y,9) scanf(" %c",&g[x][y]); scanf("%d%d",&px,&py); --px,--py;
	int sx=px%3,sy=py%3; bool any=false;
	REP(dx,3) REP(dy,3) if(g[sx*3+dx][sy*3+dy]=='.') { g[sx*3+dx][sy*3+dy]='!'; any=true; }
	if(!any) REP(x,9) REP(y,9) if(g[x][y]=='.') g[x][y]='!';

	REP(x,9) { if(x!=0&&x%3==0) puts(""); REP(y,9) { if(y!=0&&y%3==0) printf(" "); printf("%c",g[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}