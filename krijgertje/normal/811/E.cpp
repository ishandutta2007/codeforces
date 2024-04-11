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

const int MAXH=10;
const int MAXW=100000;
const int MAXS=4*MAXW;
typedef struct S { int cnt,lid[MAXH],rid[MAXH],lval[MAXH],rval[MAXH],nid; } S;

int h,w,nq;
int g[MAXH][MAXW];

S s[MAXS];

S scol(int y) {
	S ret; ret.cnt=0; ret.nid=0; REP(x,h) ret.lval[x]=ret.rval[x]=g[x][y];
	for(int at=0,to=at;at<h;at=to) {
		while(to<h&&g[at][y]==g[to][y]) ++to;
		FOR(x,at,to) ret.lid[x]=ret.rid[x]=ret.nid; ++ret.nid; ++ret.cnt;
	}
	//printf("init(%d):",y); REP(x,h) printf(" %d",ret.lval[x]); printf(" |"); REP(x,h) printf(" %d",ret.lid[x]); printf(" |"); REP(x,h) printf(" %d",ret.rval[x]); printf(" |"); REP(x,h) printf(" %d",ret.rid[x]); printf(" -> %d %d\n",ret.cnt,ret.nid);
	return ret;
}
S smerge(S a,S b) {
	S ret; ret.cnt=a.cnt+b.cnt; REP(x,h) ret.lval[x]=a.lval[x],ret.rval[x]=b.rval[x];
	REP(x,h) b.lid[x]+=a.nid,b.rid[x]+=a.nid;
	REP(x,h) if(a.rval[x]==b.lval[x]&&a.rid[x]!=b.lid[x]) {
		--ret.cnt; int oid=b.lid[x];
		REP(xx,h) if(a.lid[xx]==oid) a.lid[xx]=a.rid[x];
		REP(xx,h) if(a.rid[xx]==oid) a.rid[xx]=a.rid[x];
		REP(xx,h) if(b.lid[xx]==oid) b.lid[xx]=a.rid[x];
		REP(xx,h) if(b.rid[xx]==oid) b.rid[xx]=a.rid[x];
	}
	REP(x,h) ret.lid[x]=a.lid[x]; REP(x,h) ret.rid[x]=b.rid[x];
	vector<int> mp(a.nid+b.nid,-1); ret.nid=0;
	REP(x,h) { if(mp[ret.lid[x]]==-1) mp[ret.lid[x]]=ret.nid++; ret.lid[x]=mp[ret.lid[x]]; }
	REP(x,h) { if(mp[ret.rid[x]]==-1) mp[ret.rid[x]]=ret.nid++; ret.rid[x]=mp[ret.rid[x]]; }
	//printf("merge:"); REP(x,h) printf(" %d",ret.lval[x]); printf(" |"); REP(x,h) printf(" %d",ret.lid[x]); printf(" |"); REP(x,h) printf(" %d",ret.rval[x]); printf(" |"); REP(x,h) printf(" %d",ret.rid[x]); printf(" -> %d %d\n",ret.cnt,ret.nid);
	return ret;
}

void sinit(int x,int l,int r) {
	if(l==r) {
		s[x]=scol(l);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		s[x]=smerge(s[2*x+1],s[2*x+2]);
	}
}

S sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return s[x];
	} else {
		int m=l+(r-l)/2;
		if(m+1>R) return sget(2*x+1,l,m,L,R);
		if(L>m) return sget(2*x+2,m+1,r,L,R);
		return smerge(sget(2*x+1,l,m,L,R),sget(2*x+2,m+1,r,L,R));
	}
}




void run() {
	scanf("%d%d%d",&h,&w,&nq);
	REP(x,h) REP(y,w) scanf("%d",&g[x][y]);
	sinit(0,0,w-1);
	REP(i,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		S res=sget(0,0,w-1,l,r);
		printf("%d\n",res.cnt);
	}
}

int main() {
	run();
	return 0;
}