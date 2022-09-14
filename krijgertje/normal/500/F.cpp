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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }


int nitem,tshow;
int cost[4000],val[4000],st[4000];

int nq;
int qt[20000],qhave[20000],qret[20000];

int fst[30001],nxt[4000];
int qfst[20001][2],qnxt[20000];

int pval[5001][4001];
int sval[5001][4001];


void run() {
	scanf("%d%d",&nitem,&tshow); REP(i,nitem) scanf("%d%d%d",&cost[i],&val[i],&st[i]);
	scanf("%d",&nq); REP(i,nq) scanf("%d%d",&qt[i],&qhave[i]);

	int bsize=min(5000,tshow);
	memset(fst,-1,sizeof(fst)); REP(i,nitem) { nxt[i]=fst[st[i]]; fst[st[i]]=i; }
	memset(qfst,-1,sizeof(qfst)); REP(i,nq) { int blck=qt[i]/bsize,nfull=(blck*bsize+tshow-qt[i]-1)/bsize; qnxt[i]=qfst[blck][nfull]; qfst[blck][nfull]=i; }
	REP(i,nq) qret[i]=-1;

	for(int blck=0;blck*bsize<=20000;++blck) REP(nfull,2) if(qfst[blck][nfull]!=-1) {
		REPE(j,4000) pval[0][j]=sval[0][j]=0;
		if(blck>0&&nfull>0) REP(i,bsize) for(int x=fst[blck*bsize-i-1];x!=-1;x=nxt[x]) for(int j=4000-cost[x];j>=0;--j) if(sval[0][j]+val[x]>sval[0][j+cost[x]]) sval[0][j+cost[x]]=sval[0][j]+val[x];
		REP(i,bsize) {
			REPE(j,4000) pval[i+1][j]=pval[i][j],sval[i+1][j]=sval[i][j];
			for(int x=fst[blck*bsize+i];x!=-1;x=nxt[x]) {
				//printf("prefix | blck=%d, offset=%d -> item=%d\n",blck,i,x);
				for(int j=4000-cost[x];j>=0;--j) if(pval[i+1][j]+val[x]>pval[i+1][j+cost[x]]) pval[i+1][j+cost[x]]=pval[i+1][j]+val[x];
			}
			if(blck-nfull>0) for(int x=fst[(blck-nfull)*bsize-i-1];x!=-1;x=nxt[x]) {
				//printf("suffix | blck=%d, offset=%d -> item=%d\n",blck,i,x);
				for(int j=4000-cost[x];j>=0;--j) if(sval[i+1][j]+val[x]>sval[i+1][j+cost[x]]) sval[i+1][j+cost[x]]=sval[i+1][j]+val[x];
			}
		}
		//FORE(i,1,bsize) { printf("s%d",i); REPE(j,20) printf(" %d",sval[i][j]); puts(""); }
		//FORE(i,1,bsize) { printf("p%d",i); REPE(j,20) printf(" %d",pval[i][j]); puts(""); }
		for(int qi=qfst[blck][nfull];qi!=-1;qi=qnxt[qi]) {
			int pcnt=qt[qi]-blck*bsize+1,scnt=tshow-pcnt-nfull*bsize; // 
			//printf("q%d: %d / %d / %d (%d)\n",qi,scnt,nfull,pcnt,blck);
			qret[qi]=0;
			REPE(phave,qhave[qi]) {
				int shave=qhave[qi]-phave;
				int cur=sval[scnt][shave]+pval[pcnt][phave];
				if(cur>qret[qi]) qret[qi]=cur;
			}
		}
	}
	REP(qi,nq) printf("%d\n",qret[qi]);
}

int main() {
	run();
	return 0;
}