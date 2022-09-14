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

int n;
int a[1000];

char g[2000][1001];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	memset(g,' ',sizeof(g));
	int x=0,y=999;
	REP(i,n) REP(j,a[i]) {
		if(i%2==0) {
			g[y][x]='/'; ++x; --y;
		} else {
			g[y+1][x]='\\'; ++x; ++y;
		}
//		printf("%d,%d\n",x,y);
	}
	int len=x;

	REP(y,2000) {
		bool empty=true; REP(x,1000) if(g[y][x]!=' ') empty=false; if(empty) continue;
		g[y][len]='\0';
		printf("%s\n",g[y]);
	}
}

int main() {
	run();
	return 0;
}