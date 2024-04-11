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

const int MAXH=3,MAXW=100;

int h=3,w,n;
char g[MAXH][MAXW];

void run() {
	scanf("%d%d",&w,&n);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);

	REP(y,w-1) REP(x,h) if(g[x][y]=='s') {
		FORE(dx,-1,+1) {
			if(dx!=0&&y%3!=0) continue;
			int ny=y+1,nx=x+dx; if(nx<0||nx>=h||isupper(g[x][ny])||g[nx][ny]!='.') continue;
			g[nx][ny]='s';
		}
	}
	//REP(x,h) { REP(y,w) printf("%c",g[x][y]); puts(""); } puts("");
	bool ret=false; REP(x,h) if(g[x][w-1]=='s') ret=true; printf("%s\n",ret?"YES":"NO");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}