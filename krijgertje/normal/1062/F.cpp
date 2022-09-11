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
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=300000;

int n,m;
vector<int> out[MAXN];
vector<int> in[MAXN];

bool been[MAXN];
int top[MAXN],ntop;
int mxlen[MAXN],nxt[MAXN];
int path[MAXN],npath;
int pathidx[MAXN];

int q[MAXN],qhead,qtail;
int lidx[MAXN],ridx[MAXN];
int cand[MAXN];
int candidx[MAXN];

int numout[MAXN];
int numin[MAXN];

void dfstop(int at) {
	assert(!been[at]); been[at]=true;
	REPSZ(i,out[at]) { int to=out[at][i]; if(!been[to]) dfstop(to); }
	top[ntop++]=at;
}


int solve() {
	ntop=0; REP(i,n) been[i]=false;
	REP(i,n) if(!been[i]) dfstop(i);
	assert(ntop==n); reverse(top,top+ntop);
	//printf("top:"); REP(i,n) printf(" %d",top[i]+1); puts("");

	for(int i=n-1;i>=0;--i) {
		int at=top[i];
		mxlen[at]=1,nxt[at]=-1;
		REPSZ(j,out[at]) { int to=out[at][j]; if(mxlen[to]+1>mxlen[at]) mxlen[at]=mxlen[to]+1,nxt[at]=to; }
	}
	int mxgloblen=0,fst=-1; REP(i,n) if(mxlen[i]>mxgloblen) mxgloblen=mxlen[i],fst=i;
	npath=0; for(int at=fst;at!=-1;at=nxt[at]) path[npath++]=at;
	REP(i,n) pathidx[i]=-1; REP(i,npath) pathidx[path[i]]=i;
	//printf("path:"); REP(i,npath) printf(" %d",path[i]+1); puts("");

	qhead=qtail=0; REP(i,n) lidx[i]=-1;
	for(int i=npath-1;i>=0;--i) {
		q[qhead++]=path[i];
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(j,out[at]) {
				int to=out[at][j]; if(pathidx[to]!=-1||lidx[to]!=-1) continue;
				lidx[to]=i; q[qhead++]=to;
			}
		}
	}
	qhead=qtail=0; REP(i,n) ridx[i]=-1;
	REP(i,npath) {
		q[qhead++]=path[i];
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(j,in[at]) {
				int to=in[at][j]; if(pathidx[to]!=-1||ridx[to]!=-1) continue;
				ridx[to]=i; q[qhead++]=to;
			}
		}
	}
	REP(i,npath) cand[i]=-1;
	REP(i,n) if(pathidx[i]==-1) {
		int opt=-1;
		if(lidx[i]==-1&&ridx[i]==1) opt=0;
		if(ridx[i]==-1&&lidx[i]==npath-2) opt=npath-1;
		if(lidx[i]!=-1&&ridx[i]!=-1&&lidx[i]+2==ridx[i]) opt=lidx[i]+1;
		if(opt==-1) continue;
		if(cand[opt]==-1) cand[opt]=i; else cand[opt]=-2;
	}
	REP(i,npath) if(cand[i]==-2) cand[i]=-1;
	REP(i,n) candidx[i]=-1; REP(i,npath) if(cand[i]!=-1) candidx[cand[i]]=i;
	//REP(i,n) if(pathidx[i]==-1) printf("%d: lidx=%d ridx=%d candidx=%d\n",i+1,lidx[i],ridx[i],candidx[i]);

	REP(i,n) numout[i]=numin[i]=-1;
	qhead=qtail=0; REP(i,n) been[i]=false;
	for(int i=npath-1;i>=0;--i) {
		if(cand[i]!=-1) {
			int qold=qhead;
			assert(!been[cand[i]]); been[cand[i]]=true; q[qhead++]=cand[i];
			while(qtail<qhead) {
				int at=q[qtail++];
				REPSZ(j,out[at]) {
					int to=out[at][j]; if(been[to]) continue;
					been[to]=true; q[qhead++]=to;
				}
			}
			numout[cand[i]]=qhead;
			FOR(j,qold,qhead) { int at=q[j]; been[at]=false; }
			qtail=qhead=qold;
		}
		assert(!been[path[i]]); been[path[i]]=true; q[qhead++]=path[i];
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(j,out[at]) {
				int to=out[at][j]; if(been[to]) continue;
				been[to]=true; q[qhead++]=to;
			}
		}
		numout[path[i]]=qhead;
	}
	qhead=qtail=0; REP(i,n) been[i]=false;
	REP(i,npath) {
		if(cand[i]!=-1) {
			int qold=qhead;
			assert(!been[cand[i]]); been[cand[i]]=true; q[qhead++]=cand[i];
			while(qtail<qhead) {
				int at=q[qtail++];
				REPSZ(j,in[at]) {
					int to=in[at][j]; if(been[to]) continue;
					been[to]=true; q[qhead++]=to;
				}
			}
			numin[cand[i]]=qhead;
			FOR(j,qold,qhead) { int at=q[j]; been[at]=false; }
			qtail=qhead=qold;
		}
		assert(!been[path[i]]); been[path[i]]=true; q[qhead++]=path[i];
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(j,in[at]) {
				int to=in[at][j]; if(been[to]) continue;
				been[to]=true; q[qhead++]=to;
			}
		}
		numin[path[i]]=qhead;
	}
	//REP(i,n) printf("%d: numin=%d numout=%d\n",i+1,numin[i],numout[i]);

	int ret=0;
	REP(i,n) if((pathidx[i]!=-1||candidx[i]!=-1)&&numin[i]+numout[i]>=n) ++ret;
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; out[a].PB(b); in[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}