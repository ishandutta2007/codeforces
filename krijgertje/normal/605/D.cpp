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

const int MAXN=100000;
const int MAXX=2*MAXN;
typedef struct R { int sx,sy,tx,ty; } R;


int n;
R r[MAXN];
int x[MAXX],nx;

int d[MAXN],p[MAXN];
int q[MAXN],qhead,qtail;
int ret[MAXN],nret;

int idx[MAXN];
int fst[MAXX+1],pos[MAXX];
bool ycmp(const int &a,const int &b) { return r[a].sy<r[b].sy; }

int sval[2*MAXX],sidx[2*MAXX];;
void sset(int idx,int val) {
	//printf("setting %d = %d\n",idx,val);
	sval[idx+=nx]=val;
	for(idx>>=1;idx>0;idx>>=1) if(sval[idx<<1]<=sval[idx<<1|1]) sval[idx]=sval[idx<<1],sidx[idx]=sidx[idx<<1]; else sval[idx]=sval[idx<<1|1],sidx[idx]=sidx[idx<<1|1];
}
void supdate(int &res,int &ret,int idx) { if(sval[idx]<res) res=sval[idx],ret=sidx[idx]; }
int sget(int lidx,int ridx) {
	int res=INT_MAX,ret=-1;
	for(lidx+=nx,ridx+=nx+1;lidx<ridx;lidx>>=1,ridx>>=1) {
		if(lidx&1) supdate(res,ret,lidx++);
		if(ridx&1) supdate(res,ret,--ridx);
	}
	return ret;
}

void process(int x,int y,int dd,int pp) {
	//printf("processing %d %d = %d\n",x,y,dd);
	while(true) {
		int cx=sget(0,x);
		//printf("\tfound %d\n",cx);
		if(cx==-1||pos[cx]>=fst[cx+1]||r[idx[pos[cx]]].sy>y) break;
		int to=idx[pos[cx]++];
		d[to]=dd+1; p[to]=pp; q[qhead++]=to;
		sset(cx,pos[cx]<fst[cx+1]?r[idx[pos[cx]]].sy:INT_MAX);
	}
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d%d%d",&r[i].sx,&r[i].sy,&r[i].tx,&r[i].ty);
	nx=0; REP(i,n) x[nx++]=r[i].sx,x[nx++]=r[i].tx; sort(x,x+nx); nx=unique(x,x+nx)-x;
	REP(i,n) r[i].sx=lower_bound(x,x+nx,r[i].sx)-x,r[i].tx=lower_bound(x,x+nx,r[i].tx)-x;
	memset(fst,0,sizeof(fst)); memset(idx,-1,sizeof(idx)); REP(i,n) fst[r[i].sx+1]++; REP(i,nx) fst[i+1]+=fst[i]; REP(i,nx) pos[i]=fst[i]; REP(i,n) idx[pos[r[i].sx]++]=i; REP(i,nx) pos[i]=fst[i];
	REP(i,nx) sort(idx+fst[i],idx+fst[i+1],ycmp);
	REP(i,nx) sidx[nx+i]=i;
	REP(i,nx) sset(i,pos[i]<fst[i+1]?r[idx[pos[i]]].sy:INT_MAX);
	//REP(i,nx) { printf("%d(%d):",i,x[i]); FOR(j,fst[i],fst[i+1]) printf(" [%d,%d->%d,%d]",r[idx[j]].sx,r[idx[j]].sy,r[idx[j]].tx,r[idx[j]].ty); puts(""); }

	memset(d,-1,sizeof(d)); qhead=qtail=0;
	process(0,0,0,-1);
	while(qtail<qhead) { int at=q[qtail++]; process(r[at].tx,r[at].ty,d[at],at); }
	if(d[n-1]==-1) { printf("-1\n"); return; }
	printf("%d\n",d[n-1]);
	nret=0; for(int at=n-1;at!=-1;at=p[at]) ret[nret++]=at; reverse(ret,ret+nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}