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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXDISH=300000;
const int MAXPERSON=300000;
const int MAXQ=300000;
const int MAXVAL=MAXDISH+MAXPERSON+MAXQ;
const int MAXS=4*MAXVAL;

int ndish,nperson;
int initcost[MAXDISH];
int initbudget[MAXPERSON];
int nq;
int qkind[MAXQ],qidx[MAXQ],qval[MAXQ];
int qans[MAXQ];

int cost[MAXDISH],budget[MAXPERSON];
int val[MAXVAL],nval;

int slazy[MAXS],smx[MAXS];
void sapply(int x,int by) { slazy[x]+=by; smx[x]+=by; }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }
void spull(int x) { smx[x]=max(smx[2*x+1],smx[2*x+2]); }
void sinit(int x,int l,int r) {
	slazy[x]=smx[x]=0; if(l<r) { int m=l+(r-l)/2; sinit(2*x+1,l,m); sinit(2*x+2,m+1,r); }
}
void smod(int x,int l,int r,int L,int R,int BY) {
	//if(x==0) printf("smod(%d,%d..%d,%d..%d,%d)\n",x,l,r,L,R,BY);
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2; spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}
int sget(int x,int l,int r) {
	//printf("sget(%d,%d..%d) (%d,%d)\n",x,l,r,smx[x],slazy[x]);
	if(smx[x]<=0) return -1;
	if(l==r) return l;
	int m=l+(r-l)/2; spush(x);
	return smx[2*x+2]<=0?sget(2*x+1,l,m):sget(2*x+2,m+1,r);
}

void solve() {
	nval=0; REP(i,ndish) val[nval++]=initcost[i]; REP(i,nperson) val[nval++]=initbudget[i]; REP(i,nq) val[nval++]=qval[i]; sort(val,val+nval); nval=unique(val,val+nval)-val;
	//printf("val:"); REP(i,nval) printf(" %d",val[i]); puts("");
	sinit(0,0,nval-1);
	REP(i,ndish) { cost[i]=initcost[i]; int idx=lower_bound(val,val+nval,cost[i])-val; smod(0,0,nval-1,0,idx,+1); }
	REP(i,nperson) { budget[i]=initbudget[i]; int idx=lower_bound(val,val+nval,budget[i])-val; smod(0,0,nval-1,0,idx,-1); }
	REP(i,nq) {
		int oldidx=lower_bound(val,val+nval,qkind[i]==1?cost[qidx[i]]:budget[qidx[i]])-val;
		int newidx=lower_bound(val,val+nval,qval[i])-val;
		if(qkind[i]==1) cost[qidx[i]]=qval[i]; else budget[qidx[i]]=qval[i];
		smod(0,0,nval-1,0,oldidx,qkind[i]==1?-1:+1);
		smod(0,0,nval-1,0,newidx,qkind[i]==1?+1:-1);
		int ansidx=sget(0,0,nval-1);
		qans[i]=ansidx==-1?-1:val[ansidx];
	}
}

void run() {
	scanf("%d%d",&ndish,&nperson);
	REP(i,ndish) scanf("%d",&initcost[i]);
	REP(i,nperson) scanf("%d",&initbudget[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d%d",&qkind[i],&qidx[i],&qval[i]),--qidx[i];
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}