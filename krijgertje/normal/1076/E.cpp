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
const int MAXQ=300000;
struct E { int l,r,by; E() {} E(int l,int r,int by):l(l),r(r),by(by) {} };

int n;
vector<int> adj[MAXN];
int nq;
int qidx[MAXQ],qdep[MAXQ],qval[MAXQ]; ll qans[MAXQ];

int lid[MAXN],rid[MAXN],invid[MAXN],nid;
int dep[MAXN];

vector<E> e[MAXN+1];

void dfsinit(int at,int par) {
	dep[at]=par==-1?0:dep[par]+1;
	invid[nid]=at,lid[at]=nid++;
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par) continue; dfsinit(to,at); }
	rid[at]=nid-1;
}

ll sval[4*MAXN];
void sinit(int x,int l,int r) {
	sval[x]=0;
	if(l<r) {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
	}
}
void smod(int x,int l,int r,int L,int R,int BY) {
	if(L<=l&&r<=R) {
		sval[x]+=BY;
	} else {
		int m=l+(r-l)/2;
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
	}
}
ll sget(int x,int l,int r,int IDX) {
	ll ret=sval[x];
	if(l<r) {
		int m=l+(r-l)/2;
		if(IDX<=m) ret+=sget(2*x+1,l,m,IDX); else ret+=sget(2*x+2,m+1,r,IDX);
	}
	return ret;
}

void solve() {
	nid=0; dfsinit(0,-1);
	REP(i,nq) {
		int cidx=qidx[i],cdep=qdep[i],cval=qval[i];
		e[lid[cidx]].PB(E(dep[cidx],dep[cidx]+cdep,+cval));
		e[rid[cidx]+1].PB(E(dep[cidx],dep[cidx]+cdep,-cval));
	}
	sinit(0,0,n-1);
	REPE(i,n) {
		REPSZ(j,e[i]) smod(0,0,n-1,e[i][j].l,e[i][j].r,e[i][j].by);
		if(i<n) qans[invid[i]]=sget(0,0,n-1,dep[invid[i]]);
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d",&nq);
	REP(i,nq) { scanf("%d%d%d",&qidx[i],&qdep[i],&qval[i]); --qidx[i]; }
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",qans[i]); } puts("");
}

int main() {
	run();
	return 0;
}