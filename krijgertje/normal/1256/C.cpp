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

const int MAXCELL=1000;
const int MAXPLATFORM=1000;

int ncell,nplatform,mxjump;
int w[MAXPLATFORM];
int ans[MAXCELL];



bool solve() {
	int wsum=0; REP(i,nplatform) wsum+=w[i];
	int njump=nplatform+1;
	if(wsum>ncell||njump*(mxjump-1)+wsum<ncell) return false;
	int wrem=wsum;
	int at=0;
	REP(i,ncell) ans[i]=-1;
	REP(i,nplatform) {
		int remjump=nplatform+1-i;
		int remcell=ncell-at;
		//(remjump-1)*(mxjump-1)+wrem>=remcell-x

		int skip=max(0,remcell-(remjump-1)*(mxjump-1)-wrem);
		//printf("remcell=%d remjump=%d mxjump=%d wrem=%d -> skip=%d\n",remcell,remjump,mxjump,wrem,skip);
		at+=skip;
		wrem-=w[i];
		REP(j,w[i]) ans[at++]=i;
	}
	return true;
}

void run() {
	scanf("%d%d%d",&ncell,&nplatform,&mxjump);
	REP(i,nplatform) scanf("%d",&w[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,ncell) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	//int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	run();
	return 0;
}