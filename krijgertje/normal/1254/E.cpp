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

const int MAXN=500000;
const int MAXLG=18;
const int MOD=1000000007;

int n;
vector<int> adj[MAXN];
int val[MAXN];

int par[MAXN];
int dep[MAXN];
int up[MAXN][MAXLG+1];

int valup[MAXN];
int valdn[MAXN];

void dfsinit(int at) {
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	up[at][0]=par[at]==-1?at:par[at]; REP(k,MAXLG) up[at][k+1]=up[up[at][k]][k];
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		par[to]=at; dfsinit(to);
	}
}
int lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
	if(a==b) return a;
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return par[a];
}

vector<int> seen;
int id[MAXN],nid;
int enterfrom[MAXN];
int leaveto[MAXN];
int head,prv[MAXN],nxt[MAXN],tail;
bool done[MAXN];


int solve() {
	par[0]=-1; dfsinit(0);
	REP(i,n) valup[i]=valdn[i]=-1;
	REP(i,n) if(val[i]!=-1) {
		int b=i,a=val[i],c=lca(a,b); if(a==b) return 0;
		for(int x=a;x!=c;x=par[x]) { if(valup[x]!=-1) return 0; valup[x]=val[i]; }
		for(int x=b;x!=c;x=par[x]) { if(valdn[x]!=-1) return 0; valdn[x]=val[i]; }
	}
	//REP(i,n) printf("%d: %d %d\n",i+1,valup[i]+1,valdn[i]+1);
	int ret=1;
	REP(i,n) id[i]=-1;
	REP(at,n) {
		nid=0;
		REPSZ(i,adj[at]) {
			int to=adj[at][i];
			int enter=to==par[at]?valdn[at]:valup[to];
			int leave=to==par[at]?valup[at]:valdn[to];
			if(enter!=-1) { if(id[enter]==-1) { enterfrom[nid]=leaveto[nid]=-1; id[enter]=nid++; seen.PB(enter); } enterfrom[id[enter]]=i; }
			if(leave!=-1) { if(id[leave]==-1) { enterfrom[nid]=leaveto[nid]=-1; id[leave]=nid++; seen.PB(leave); } leaveto[id[leave]]=i; }
		}

		int m=SZ(adj[at]);
		head=tail=-1; REP(i,m) prv[i]=nxt[i]=-1,done[i]=false;
		REP(i,nid) {
			int a=enterfrom[i],b=leaveto[i]; //printf("%d: %d->%d\n",id[i]+1,a,b);
			if(a!=-1&&b!=-1) { assert(nxt[a]==-1&&prv[b]==-1&&a!=tail&&b!=head); nxt[a]=b,prv[b]=a; }
			if(a==-1&&b!=-1) { assert(head==-1&&prv[b]==-1); head=b; }
			if(a!=-1&&b==-1) { assert(tail==-1&&nxt[a]==-1); tail=a; }
		}
		//printf("processing %d: head=%d tail=%d prv=",at+1,head,tail); REP(i,m) printf("%d ",prv[i]); printf("nxt="); REP(i,m) printf("%d ",nxt[i]); puts("");
		int nparts=0; bool headtailpath=false;
		REP(i,m) if(!done[i]&&prv[i]==-1) {
			++nparts;
			int at=i; while(at!=-1) { assert(!done[at]); done[at]=true; if(i==head&&at==tail) headtailpath=true; at=nxt[at]; }
		}
		REP(i,m) if(!done[i]) return 0;
		if(headtailpath&&nparts!=1) return 0;
		int nfreeparts=nparts-(head!=-1?1:0)-(tail!=-1?1:0)+(headtailpath?1:0);
		FORE(i,1,nfreeparts) ret=(ll)ret*i%MOD;

		REPSZ(i,seen) { int x=seen[i]; id[x]=-1; }
		seen.clear();
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	REP(i,n) scanf("%d",&val[i]),--val[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}