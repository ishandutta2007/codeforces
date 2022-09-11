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

const int MAXN=100000;

int n,nshop;
vector<pair<int,int> > e[MAXN];

int d[MAXN],prv[MAXN],q[MAXN],qhead,qtail;
int mark[MAXN],curmark;
int farthest(int s,int skip) {
	++curmark; qhead=qtail=0;
	d[s]=0,prv[s]=-1,q[qhead++]=s,mark[s]=curmark;
	int ret=s;
	while(qtail<qhead) { int at=q[qtail++]; if(d[at]>d[ret]) ret=at; REPSZ(i,e[at]) { int to=e[at][i].first,nd=d[at]+e[at][i].second; if(to!=skip&&mark[to]!=curmark) d[to]=nd,prv[to]=at,q[qhead++]=to,mark[to]=curmark; } }
	return ret;
}

int path[MAXN],npath;
int dpath[MAXN];
int pathidx[MAXN];

int c[MAXN];
int l[MAXN],r[MAXN];

void run() {
	scanf("%d%d",&n,&nshop); REP(i,n-1) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[a].PB(MP(b,c)); e[b].PB(MP(a,c)); }

	memset(mark,-1,sizeof(mark)); curmark=-1;
	int u=farthest(0,-1);
	int v=farthest(u,-1);

	npath=0; for(int x=v;x!=-1;x=prv[x]) path[npath++]=x; reverse(path,path+npath);
	REP(i,n) pathidx[i]=-1; REP(i,npath) pathidx[path[i]]=i;
	REP(i,npath-1) { int at=path[i]; bool found=false; REPSZ(j,e[at]) if(e[at][j].first==path[i+1]) { assert(!found); found=true; dpath[i]=e[at][j].second; } assert(found); }
	//printf("path:"); REP(i,npath) printf(" %d",path[i]+1); puts("");

	REP(i,npath) { c[i]=0; int at=path[i]; REPSZ(j,e[at]) if(pathidx[e[at][j].first]==-1) { int cur=farthest(e[at][j].first,at); c[i]=max(c[i],e[at][j].second+d[cur]); } }
	REP(i,npath) l[i]=i==0?0:dpath[i-1]+max(c[i-1],l[i-1]);
	for(int i=npath-1;i>=0;--i) r[i]=i==npath-1?0:dpath[i]+max(c[i+1],r[i+1]);
	//printf("c:"); REP(i,npath) printf(" %2d",c[i]); puts("");
	//printf("l:"); REP(i,npath) printf(" %2d",l[i]); puts("");
	//printf("r:"); REP(i,npath) printf(" %2d",r[i]); puts("");

	int ret=INT_MAX;
	if(npath<nshop) ret=0; else REPE(i,npath-nshop) ret=min(ret,max(l[i],r[i+nshop-1]));
	REP(i,npath) ret=max(ret,c[i]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}