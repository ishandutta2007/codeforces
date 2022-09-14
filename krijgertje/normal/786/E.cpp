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

const int MAXN=20000;
const int MAXM=MAXN-1;
const int MAXQ=10000;
const int MAXLGN=14;
const int MAXID=MAXN*(MAXLGN+1)+MAXQ+2;
const int MAXE=MAXQ+MAXN-1+2*MAXN*MAXLGN+2*MAXLGN*MAXQ;

int n,nq,nid;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int d[MAXN];
int sid,tid,qid[MAXQ];
int up[MAXN][MAXLGN+1]; int upid[MAXN][MAXLGN+1];

void dfs(int at,int par) {
	up[at][0]=par; d[at]=par==-1?0:d[par]+1; for(int k=1;(1<<k)<=d[at];++k) up[at][k]=up[up[at][k-1]][k-1],upid[at][k]=nid++;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(to==par) continue; dfs(to,at); }
}
vector<int> getpath(int a,int b) {
	vector<int> ret;
	if(d[a]<d[b]) swap(a,b);
	{ int k=0; while(d[a]-(1<<k)>=d[b]) ++k; for(--k;k>=0;--k) if(d[a]-(1<<k)>=d[b]) ret.PB(upid[a][k]),a=up[a][k]; }
	{ int k=0; while((1<<k)<=d[a]) ++k; for(--k;k>=0;--k) if(up[a][k]!=up[b][k]) ret.PB(upid[a][k]),ret.PB(upid[b][k]),a=up[a][k],b=up[b][k]; }
	if(a!=b) { assert(d[a]>=1&&up[a][0]==up[b][0]); ret.PB(upid[a][0]),ret.PB(upid[b][0]); }
	return ret;
}

typedef struct MF {
	int n,m;
	int ghead[MAXID],gnxt[2*MAXE],gto[2*MAXE],gcap[2*MAXE];
	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1; /*printf("MAXID=%d MAXE=%d\n",MAXID,MAXE);*/ }
	void addedge(int a,int b,int c) { gnxt[2*m+0]=ghead[a],ghead[a]=2*m+0,gto[2*m+0]=b,gcap[2*m+0]=c; gnxt[2*m+1]=ghead[b],ghead[b]=2*m+1,gto[2*m+1]=a,gcap[2*m+1]=0; ++m; /*printf("addedge(%d,%d)\n",a,b);*/ }
	
	int d[MAXID];
	int q[MAXID],qhead,qtail;
	int cur[MAXID];
	int solve(int s,int t) {
		int ret=0;
		while(true) {
			REP(i,n) d[i]=INT_MAX; qhead=qtail=0; d[s]=0,q[qhead++]=s;
			while(qtail<qhead) { int at=q[qtail++];for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(gcap[x]==0||d[to]!=INT_MAX) continue; d[to]=d[at]+1; q[qhead++]=to; } }
			if(d[t]==INT_MAX) return ret;
			REP(i,n) cur[i]=ghead[i];
			ret+=dfs(s,t,INT_MAX);
		}
	}
	int dfs(int at,int t,int rem) {
		int ret=0; if(at==t) return rem;
		if(d[at]>=d[t]) return 0;
		for(;cur[at]!=-1;cur[at]=gnxt[cur[at]]) {
			int to=gto[cur[at]],cap=gcap[cur[at]]; if(d[to]!=d[at]+1||cap==0) continue;
			int now=dfs(to,t,min(cap,rem));
			rem-=now; ret+=now; gcap[cur[at]]-=now; gcap[cur[at]^1]+=now; if(rem==0) return ret;
		}
		return ret;
	}
	void print() { REP(i,m) if(gcap[2*i+0]==0) printf("used %d->%d\n",gto[2*i+1],gto[2*i+0]); }
} MF;
MF mf;



void run() {
	scanf("%d%d",&n,&nq); nid=0;
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }
	memset(up,-1,sizeof(up)); memset(upid,-1,sizeof(up)); sid=nid++; tid=nid++; REP(i,nq) qid[i]=nid++; FORE(i,1,n) upid[i][0]=nid++;
	dfs(0,-1);
	//printf("%d\n",nid); REP(i,n) { printf("%d:",i); for(int k=0;(1<<k)<=d[i];++k) printf(" %d",upid[i][k]); puts(""); }
	mf.init(nid);
	REP(i,nq) mf.addedge(sid,qid[i],1);
	FOR(i,1,n) mf.addedge(upid[i][0],tid,1);
	REP(i,n) for(int k=1;(1<<k)<=d[i];++k) mf.addedge(upid[i][k],upid[i][k-1],nq+1),mf.addedge(upid[i][k],upid[up[i][k-1]][k-1],nq+1);
	REP(i,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		vector<int> path=getpath(a,b); REPSZ(j,path) mf.addedge(qid[i],path[j],nq+1);
	}
	int ret=mf.solve(sid,tid);
	//mf.print();
	printf("%d\n",ret);
	vector<int> citizen,guardian;
	REP(i,nq) if(mf.d[qid[i]]==INT_MAX) citizen.PB(i);
	FOR(i,1,n) if(mf.d[upid[i][0]]!=INT_MAX) for(int x=ghead[i];x!=-1;x=gnxt[x]) if(gto[x]==up[i][0]) guardian.PB(x>>1);
	printf("%d",SZ(citizen)); REPSZ(i,citizen) printf(" %d",citizen[i]+1); puts("");
	printf("%d",SZ(guardian)); REPSZ(i,guardian) printf(" %d",guardian[i]+1); puts("");

}

int main() {
	run();
	return 0;
}