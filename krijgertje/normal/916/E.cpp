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
const int MAXQ=100000;
const int MAXBIT=16;

int n,nq;
int sval[MAXN];
vector<int> adj[MAXN];
int root;

int dep[MAXN];
int lid[MAXN],rid[MAXN],nid;
int up[MAXN][MAXBIT+1];
void dfsinit(int at,int par) {
	dep[at]=par==-1?0:dep[par]+1;
	lid[at]=nid++;
	up[at][0]=par==-1?at:par; FORE(k,1,MAXBIT) up[at][k]=up[up[at][k-1]][k-1];
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfsinit(to,at);
	}
	rid[at]=nid-1;
}

bool insubtree(int a,int b) { // is a in subtree of b
	return lid[b]<=lid[a]&&rid[a]<=rid[b];
}
int calcup(int a,int steps) {
	int ret=a; for(int k=MAXBIT;k>=0;--k) if(steps&(1<<k)) ret=up[ret][k]; return ret;
}
int lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	a=calcup(a,dep[a]-dep[b]);
	if(a==b) return a;
	for(int k=MAXBIT;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return up[a][0];
}

ll bit1[MAXN+1],bit2[MAXN+1];
void bmod(int idx,ll by1,ll by2) { ++idx; while(idx<=n) { bit1[idx]+=by1; bit2[idx]+=by2; idx+=idx&-idx; } }
ll bget(int idx) { int oidx=idx; ll ret1=0,ret2=0; ++idx; while(idx>0) { ret1+=bit1[idx]; ret2+=bit2[idx]; idx-=idx&-idx; } return ret1*oidx+ret2; }
void modrange(int l,int r,int by) { bmod(l,+by,-(ll)(l-1)*by); bmod(r,-by,(ll)r*by); }
ll getrange(int l,int r) { ll ret=bget(r); if(l!=0) ret-=bget(l-1); return ret; }

int qkind[MAXQ],qa[MAXQ],qb[MAXQ],qc[MAXQ]; ll ans[MAXQ]; int nans;

void solve() {
	root=0;
	nid=0; dfsinit(0,-1);
	memset(bit1,0,sizeof(bit1)); memset(bit2,0,sizeof(bit2));
	REP(i,n) modrange(lid[i],lid[i],sval[i]);
	//REP(i,n) printf("%d: %d..%d (%lld)\n",i+1,lid[i],rid[i],getrange(lid[i],rid[i]));

	nans=0;
	REP(i,nq) {
		if(qkind[i]==1) {
			root=qa[i];
		}
		if(qkind[i]==2) {
			int a=qa[i],b=qb[i],delta=qc[i];
			if(!insubtree(a,root)&&insubtree(b,root)) swap(a,b);
			if(insubtree(b,root)) {
				int c=lca(a,b);
				if(c==root) {
					modrange(0,n-1,delta);
				} else {
					modrange(lid[c],rid[c],delta);
				}
			} else if(insubtree(a,root)) {
				modrange(0,n-1,delta);
			} else {
				int c=lca(a,b);
				if(!insubtree(root,c)) {
					modrange(lid[c],rid[c],delta);
				} else {
					int aa=lca(a,root),bb=lca(b,root);
					if(dep[aa]<dep[bb]) swap(a,b),swap(aa,bb);
					assert(aa!=root);
					int d=calcup(root,dep[root]-dep[aa]-1);
					modrange(0,n-1,delta);
					modrange(lid[d],rid[d],-delta);
				}
			}
		}
		if(qkind[i]==3) {
			int a=qa[i];
			if(a==root) {
				ans[nans++]=getrange(0,n-1);
			} else if(insubtree(a,root)||!insubtree(root,a)) {
				ans[nans++]=getrange(lid[a],rid[a]);
			} else {
				int d=calcup(root,dep[root]-dep[a]-1);
				ans[nans++]=getrange(0,n-1)-getrange(lid[d],rid[d]);
			}
		}
	}
}

void input() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&sval[i]);
	REP(i,n) adj[i].clear(); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	REP(i,nq) {
		scanf("%d",&qkind[i]);
		if(qkind[i]==1) scanf("%d",&qa[i]),--qa[i];
		if(qkind[i]==2) scanf("%d%d%d",&qa[i],&qb[i],&qc[i]),--qa[i],--qb[i];
		if(qkind[i]==3) scanf("%d",&qa[i]),--qa[i];
	}
}

void run() {
	input();
	solve();
	REP(i,nans) printf("%lld\n",ans[i]);
}

ll cval[MAXN];

void dfsmod(int at,int par,int delta) {
	cval[at]+=delta;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfsmod(to,at,delta);
	}
}
int dfssearch(int at,int par,int a,int b,int delta) {
	int ret=0; if(at==a) ret|=1; if(at==b) ret|=2;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		int sub=dfssearch(to,at,a,b,delta);
		if(sub==3) return sub;
		ret|=sub;
	}
	if(ret==3) dfsmod(at,par,delta);
	return ret;
}
ll dfssum(int at,int par) {
	ll ret=cval[at];
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		ret+=dfssum(to,at);
	}
	return ret;
}
ll dfscalc(int at,int par,int a) {
	if(at==a) return dfssum(at,par);
	ll ret=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		ret+=dfscalc(to,at,a);
	}
	return ret;
}

ll bfans[MAXQ]; int nbfans;

void bf() {
	REP(i,n) cval[i]=sval[i];
	int root=0; nbfans=0;
	REP(i,nq) {
		if(qkind[i]==1) root=qa[i];
		if(qkind[i]==2) {
			int a=qa[i],b=qb[i],delta=qc[i];
			assert(dfssearch(root,-1,a,b,delta)==3);
		}
		if(qkind[i]==3) bfans[nbfans++]=dfscalc(root,-1,qa[i]);
	}
}

void stress() {
	REP(rep,1000) {
		n=1000; nq=1000;
		REP(i,n) sval[i]=rand()%10;
		REP(i,n) adj[i].clear(); REP(i,n-1) { int a=i+1,b=rand()%(i+1); adj[a].PB(b); adj[b].PB(a); }
		REP(i,nq) {
			qkind[i]=rand()%3+1;
			if(qkind[i]==1) qa[i]=rand()%n;
			if(qkind[i]==2) qa[i]=rand()%n,qb[i]=rand()%n,qc[i]=rand()%1000;
			if(qkind[i]==3) qa[i]=rand()%n;
		}
		solve();
		bf();
		assert(nbfans==nans);
		bool diff=false; REP(i,nans) if(ans[i]!=bfans[i]) diff=true; if(diff) printf("err\n"); else printf(".");
		if(diff) {
			printf("%d %d\n",n,nq);
			REP(i,n) { if(i!=0) printf(" "); printf("%d",sval[i]); } puts("");
			REP(i,n) REPSZ(j,adj[i]) { int k=adj[i][j]; if(i>k) printf("%d %d\n",k+1,i+1); }
			REP(i,nq) { printf("%d %d",qkind[i],qa[i]+1); if(qkind[i]==2) printf(" %d %d",qb[i]+1,qc[i]); puts(""); }
			REP(i,nans) printf("%lld vs %lld\n",ans[i],bfans[i]);
		}
	}
}

int main() {
	run();
	//stress();
	return 0;
}