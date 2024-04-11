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
int x[100000],y[100000];
int cntx[100001],cnty[100001];
int fstx[100001],fsty[100001];
int nxtx[100001],nxty[100001];

const int hmod=15485863;
int h[15485863];

int calc(int x,int y) {
	return (x*7919LL+y)%hmod;
}

bool exists(int cx,int cy) {
	int hh=calc(cx,cy);
	while(h[hh]!=-1) {
		int i=h[hh];
		if(x[i]==cx&&y[i]==cy) return true;
		if(++hh>=hmod) hh=0;
	}
	return false;
}

void add(int i) {
	int hh=calc(x[i],y[i]);
	while(h[hh]!=-1) if(++hh>=hmod) hh=0;
	h[hh]=i;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&x[i],&y[i]);
	memset(fstx,-1,sizeof(fstx)); memset(cntx,0,sizeof(cntx));
	memset(fsty,-1,sizeof(fsty)); memset(cnty,0,sizeof(cnty));
	REP(i,n) {
		nxtx[i]=fstx[x[i]]; fstx[x[i]]=i; cntx[x[i]]++;
		nxty[i]=fsty[y[i]]; fsty[y[i]]=i; cnty[y[i]]++;
	}
	memset(h,-1,sizeof(h));
	REP(i,n) add(i);
	int ret=0;
	REP(i,n) {
		if(cntx[x[i]]<=cnty[y[i]]) {
			for(int j=fstx[x[i]];j!=-1;j=nxtx[j]) if(y[i]<y[j]) {
				int sz=y[j]-y[i];
				if(exists(x[i]+sz,y[i])&&exists(x[i]+sz,y[j])) ++ret;
			}
		} else {
			for(int j=fsty[y[i]];j!=-1;j=nxty[j]) if(x[i]<x[j]) {
				int sz=x[j]-x[i];
				if(exists(x[i],y[i]+sz)&&exists(x[j],y[i]+sz)) ++ret;
			}
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}