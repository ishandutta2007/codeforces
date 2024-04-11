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

int n,base;
int a[100000],b[100000];
int anext[100000],bnext[100000];
int aprev[100000],bprev[100000];

int c[100000];

int calc(int ai,int bi) { int ret=a[ai]+b[bi]; if(ret>=base) ret-=base; return ret; }

void run(int casenr) {
	scanf("%d%d",&n,&base);
	REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]);
	sort(a,a+n); sort(b,b+n);
	REP(i,n-1) anext[i]=bnext[i]=i+1; anext[n-1]=bnext[n-1]=-1;
	aprev[0]=bprev[0]=-1; FOR(i,1,n) aprev[i]=bprev[i]=i-1;
	int ai=n-1,bi=n-1,aj=0,bj=0;
	REP(i,n) {
		while(bnext[bj]!=-1&&a[ai]+b[bnext[bj]]<base) bj=bnext[bj];
		while(anext[aj]!=-1&&b[bi]+a[anext[aj]]<base) aj=anext[aj];
		int ax=ai,bx=bi,best=calc(ax,bx);
		{ int cur=calc(ai,bj); if(cur>best) { best=cur; ax=ai; bx=bj; } }
		{ int cur=calc(aj,bi); if(cur>best) { best=cur; ax=aj; bx=bi; } }
		c[i]=best;
		if(ax==ai) ai=aprev[ai]; if(ax==aj) aj=aprev[aj]!=-1?aprev[aj]:anext[aj];
		if(bx==bi) bi=bprev[bi]; if(bx==bj) bj=bprev[bj]!=-1?bprev[bj]:bnext[bj];
		if(aprev[ax]!=-1) anext[aprev[ax]]=anext[ax];
		if(anext[ax]!=-1) aprev[anext[ax]]=aprev[ax];
		if(bprev[bx]!=-1) bnext[bprev[bx]]=bnext[bx];
		if(bnext[bx]!=-1) bprev[bnext[bx]]=bprev[bx];
	}
	sort(c,c+n); REP(i,n) { if(i!=0) printf(" "); printf("%d",c[n-i-1]); } puts("");
	
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}