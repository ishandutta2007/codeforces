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
#include <stack>
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

const int MAXN=50000;
const int MAXQ=150000;
const int BITS=16;
const int LBITS=BITS/2-1;
const int HBITS=BITS-LBITS;
const int STEP=1<<LBITS;
const int MAXS=(2<<HBITS)-1;
typedef struct S { int c[2],mx; } S;

int n,nq;
int a[MAXN];
vector<int> adj[MAXN];
vector<pair<int,int> > q[MAXN];
int ans[MAXQ];


int d[MAXN],par[MAXN];
int stck[MAXN],nstck;

int jump[MAXN];
int bstep[MAXN][1<<HBITS];
S s[MAXS]; int ns,root;
int creates() { assert(ns<MAXS); int at=ns++; s[at].c[0]=s[at].c[1]=-1,s[at].mx=-1; return at; }
void addtotree(int val) {
	//printf("addtotree(%d)\n",val);
	int mask=val>>LBITS;
	int at=root;
	for(int i=HBITS-1;i>=0;--i) {
		int j=(mask>>i)&1;
		if(s[at].c[j]==-1) s[at].c[j]=creates();
		at=s[at].c[j];
	}
	s[at].mx=max(s[at].mx,val);
}
void walktree(int id,int off,int at,int bit) {
	//printf("walktree(%d,%d,%d,%d)\n",id,off,at,bit);
	if(bit<0) { bstep[id][off]=s[at].mx^(off<<LBITS); return; }
	REP(j,2) {
		int to=s[at].c[1-j]; if(to==-1) to=s[at].c[j]; assert(to!=-1);
		walktree(id,off+(j<<bit),to,bit-1);
	}
}
void calcstep(int at) {
	//printf("calcstep(%d)\n",at);
	ns=0; root=creates(); jump[at]=stck[nstck-STEP-1];
	REP(i,STEP) addtotree(a[stck[nstck-i-1]]^i);
	walktree(at,0,root,HBITS-1);
	//printf("%d->%d:",at,jump[at]); REP(i,1<<HBITS) printf(" %d",bstep[at][i]); puts("");
}


void dfs(int at,int p) {
	par[at]=p; d[at]=par[at]==-1?0:d[par[at]]+1; stck[nstck++]=at;
	if(nstck>STEP) calcstep(at);
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		dfs(to,at);
	}
	--nstck;
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d",&a[i]);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	REP(i,nq) { int a,b; scanf("%d%d",&a,&b); --a,--b; q[b].PB(MP(a,i)); ans[i]=-1; }

	//n=min(MAXN,1<<BITS),nq=MAXQ; REP(i,n) a[i]=rand()%min(1000,1<<BITS);
	//REP(i,n) adj[i].clear(); REP(i,n-1) adj[i].PB(i+1),adj[i+1].PB(i);
	//REP(i,n) q[i].clear(); REP(i,nq) { int a=rand()%n,b=rand()%n; if(a>b) swap(a,b); q[b].PB(MP(a,i)); ans[i]=-1; }

	nstck=0;
	dfs(0,-1);
	REP(i,n) REPSZ(j,q[i]) {
		int u=q[i][j].first,v=i,idx=q[i][j].second,dst=0;
		while(d[v]-STEP>=d[u]) {
			ans[idx]=max(ans[idx],bstep[v][dst>>LBITS]);
			v=jump[v],dst+=STEP;
		}
		while(true) {
			ans[idx]=max(ans[idx],a[v]^dst);
			if(u==v) break; else v=par[v],++dst;
		}
	}
	REP(i,nq) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}