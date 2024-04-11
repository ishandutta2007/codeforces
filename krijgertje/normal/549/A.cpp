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

const int MAXH=50;
const int MAXW=50;

int h,w;
char g[MAXH][MAXW];
int convert(char c) { if(c=='f') return 0; if(c=='a') return 1; if(c=='c') return 2; if(c=='e') return 3; return -1; }

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	int ret=0;
	REP(x,h-1) REP(y,w-1) {
		int have=0;
		REP(dx,2) REP(dy,2) { int cur=convert(g[x+dx][y+dy]); if(cur!=-1) have|=1<<cur; }
		if(have==15) ++ret;
	}
	printf("%d\n",ret);
}


int main() {
	run();
	return 0;
}