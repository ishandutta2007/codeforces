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

int h,w,nq;
int g[MAXH][MAXW];
int score[MAXH],ret;

int calc(int x) { int ret=0,cur=0; REP(y,w) if(g[x][y]==0) cur=0; else if(++cur>ret) ret=cur; return ret; }

void run() {
	scanf("%d%d%d",&h,&w,&nq);
	REP(x,h) REP(y,w) scanf("%d",&g[x][y]);
	REP(x,h) score[x]=calc(x);
	REP(qi,nq) {
		int x,y; scanf("%d%d",&x,&y); --x,--y;
		g[x][y]=1-g[x][y];
		score[x]=calc(x);
		int ret=0; REP(x,h) if(score[x]>ret) ret=score[x];
		printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}