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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN=500000;
const int MAXLG=18;
const int MAXQ=500000;
const int MAXS=4*MAXN;

int n,nq;
int par[MAXN],parlen[MAXN];
int qx[MAXQ],ql[MAXQ],qr[MAXQ]; ll qans[MAXQ];

bool isleaf[MAXN];
int firstleafonorafter[MAXN],lastleafonorbefore[MAXN];
int firstnodeinsubtree[MAXN],lastnodeinsubtree[MAXN];
int dep[MAXN]; ll dist[MAXN];
ll mnleafdistinsubtree[MAXN],tmp[MAXN],sibval[MAXN][2];
int up[MAXN][MAXLG+1];
ll upval[MAXN][2][MAXLG+1];

int calclca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return a==b?a:up[a][0];
}
int calcup(int a,int steps) {
	for(int k=MAXLG;k>=0;--k) if(steps&(1<<k)) a=up[a][k];
	return a;
}
ll calcupval(int kind,int a,int steps) {
	ll ret=LLONG_MAX;
	for(int k=MAXLG;k>=0;--k) if(steps&(1<<k)) { ret=min(ret,upval[a][kind][k]); a=up[a][k]; }
	return ret;
}

ll sval[MAXS];
void sinit(int x,int l,int r) { if(l==r) sval[x]=isleaf[l]?dist[l]:LLONG_MAX; else { int m=l+(r-l)/2; sinit(2*x+1,l,m); sinit(2*x+2,m+1,r); sval[x]=min(sval[2*x+1],sval[2*x+2]); } }
ll sget(int x,int l,int r,int L,int R) { if(L<=l&&r<=R) return sval[x]; else { int m=l+(r-l)/2; ll ret=LLONG_MAX; if(L<=m) ret=min(ret,sget(2*x+1,l,m,L,R)); if(R>=m+1) ret=min(ret,sget(2*x+2,m+1,r,L,R)); return ret; } }


ll calcrmq(int l,int r,int other,int lca) {
	//printf("\tcalcrmq(%d..%d,other=%d,lca=%d)\n",l+1,r+1,other+1,lca+1);
	ll distme=sget(0,0,n-1,l,r);
	return distme==LLONG_MAX?LLONG_MAX:distme+dist[other]-2*dist[lca];
}
ll calcleftsibling(int pathleaf,int pathroot,int other) {
	//printf("\tcalcleftsibling(%d..%d,other=%d)\n",pathleaf+1,pathroot+1,other+1);
	ll bestval=calcupval(0,pathleaf,dep[pathleaf]-dep[pathroot]);
	return bestval==LLONG_MAX?LLONG_MAX:bestval+dist[other];
}
ll calcrightsibling(int pathleaf,int pathroot,int other) {
	//printf("\tcalcrightsibling(%d..%d,other=%d)\n",pathleaf+1,pathroot+1,other+1);
	ll bestval=calcupval(1,pathleaf,dep[pathleaf]-dep[pathroot]);
	return bestval==LLONG_MAX?LLONG_MAX:bestval+dist[other];
}


void solve() {
	REP(i,n) isleaf[i]=true; REP(i,n) if(par[i]!=-1) isleaf[par[i]]=false;
	for(int i=n-1;i>=0;--i) firstleafonorafter[i]=isleaf[i]?i:i+1<n?firstleafonorafter[i+1]:-1;
	REP(i,n) lastleafonorbefore[i]=isleaf[i]?i:i-1>=0?lastleafonorbefore[i-1]:-1;
	REP(i,n) firstnodeinsubtree[i]=lastnodeinsubtree[i]=i;
	for(int i=n-1;i>=0;--i) if(par[i]!=-1) lastnodeinsubtree[par[i]]=max(lastnodeinsubtree[par[i]],lastnodeinsubtree[i]);
	REP(i,n) if(par[i]==-1) dep[i]=0,dist[i]=0; else dep[i]=dep[par[i]]+1,dist[i]=dist[par[i]]+parlen[i];
	REP(i,n) mnleafdistinsubtree[i]=isleaf[i]?dist[i]:LLONG_MAX; for(int i=n-1;i>=0;--i) if(par[i]!=-1) mnleafdistinsubtree[par[i]]=min(mnleafdistinsubtree[par[i]],mnleafdistinsubtree[i]);
	REP(i,n) tmp[i]=sibval[i][0]=LLONG_MAX; REP(i,n) if(par[i]!=-1) { sibval[i][0]=tmp[par[i]]; tmp[par[i]]=min(tmp[par[i]],mnleafdistinsubtree[i]-2*dist[par[i]]); }
	REP(i,n) tmp[i]=sibval[i][1]=LLONG_MAX; for(int i=n-1;i>=0;--i) if(par[i]!=-1) { sibval[i][1]=tmp[par[i]]; tmp[par[i]]=min(tmp[par[i]],mnleafdistinsubtree[i]-2*dist[par[i]]); }
	REP(i,n) { up[i][0]=par[i]==-1?i:par[i]; REP(k,MAXLG) up[i][k+1]=up[up[i][k]][k]; }
	REP(i,n) REP(j,2) { upval[i][j][0]=sibval[i][j]; REP(k,MAXLG) upval[i][j][k+1]=min(upval[i][j][k],upval[up[i][k]][j][k]); }
	sinit(0,0,n-1);
	//REP(i,n) printf("%d: leaf(nxt=%d,prv=%d) tree(fst=%d,lst=%d) leafdst=%lld sibval=%lld/%lld\n",i+1,firstleafonorafter[i]+1,lastleafonorbefore[i]+1,firstnodeinsubtree[i]+1,lastnodeinsubtree[i]+1,mnleafdistinsubtree[i],sibval[i][0]==LLONG_MAX?-1111:sibval[i][0],sibval[i][1]==LLONG_MAX?-1111:sibval[i][1]);
	
	REP(i,nq) {
		qans[i]=LLONG_MAX;
		int x=qx[i],l=ql[i],r=qr[i];
		//printf("processing %d: x=%d l=%d r=%d\n",i+1,x+1,l+1,r+1);
		l=firstleafonorafter[l]; if(l==-1||l>r) continue;
		r=lastleafonorbefore[r]; if(r==-1||r<l) continue;
		int lx=calclca(l,x),rx=calclca(r,x);
		int plx=lx==x?-1:calcup(x,dep[x]-dep[lx]-1),prx=rx==x?-1:calcup(x,dep[x]-dep[rx]-1);
		if(plx!=-1&&l<plx) {
			int upto=min(firstnodeinsubtree[plx]-1,r);
			qans[i]=min(qans[i],calcrmq(l,upto,x,lx));
			if(upto==r) continue; else l=lx=plx;
		}
		if(prx!=-1&&r>lastnodeinsubtree[prx]) {
			int from=max(lastnodeinsubtree[prx]+1,l);
			qans[i]=min(qans[i],calcrmq(from,r,x,rx));
			if(from==l) continue; else r=rx=prx;
		}
		//printf("\tlx=%d l=%d rx=%d r=%d (plx=%d prx=%d)\n",lx+1,l+1,rx+1,r+1,plx+1,prx+1);
		if(lx!=x&&lx!=l) {
			assert(rx==r);
			qans[i]=min(qans[i],calcrmq(firstnodeinsubtree[l],lastnodeinsubtree[lx],x,lx));
			qans[i]=min(qans[i],calcrightsibling(lx,r,x));
			continue;
		}
		if(rx!=x&&rx!=r) {
			assert(lx==l);
			qans[i]=min(qans[i],calcrmq(firstnodeinsubtree[rx],lastnodeinsubtree[r],x,rx));
			qans[i]=min(qans[i],calcleftsibling(rx,l,x));
			continue;
		}
		if(lx!=x) qans[i]=min(qans[i],calcleftsibling(x,l,x));
		if(rx!=x) qans[i]=min(qans[i],calcrightsibling(x,r,x));
		qans[i]=min(qans[i],calcrmq(max(firstnodeinsubtree[x],firstnodeinsubtree[l]),min(lastnodeinsubtree[x],lastnodeinsubtree[r]),x,x));
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	par[0]=-1,parlen[0]=0; FOR(i,1,n) scanf("%d%d",&par[i],&parlen[i]),--par[i];
	REP(i,nq) scanf("%d%d%d",&qx[i],&ql[i],&qr[i]),--qx[i],--ql[i],--qr[i];
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}

ll bfans[MAXQ];

void solvestupid() {
	vector<bool> isleaf(n,true); REP(i,n) if(par[i]!=-1) isleaf[par[i]]=false;
	REP(i,nq) {
		vector<ll> d(n,LLONG_MAX); queue<int> q; bfans[i]=LLONG_MAX;
		d[qx[i]]=0,q.push(qx[i]);
		while(!q.empty()) {
			int at=q.front(); q.pop(); if(isleaf[at]&&ql[i]<=at&&at<=qr[i]) bfans[i]=min(bfans[i],d[at]);
			if(par[at]!=-1&&d[par[at]]==LLONG_MAX) d[par[at]]=d[at]+parlen[at],q.push(par[at]);
			REP(to,n) if(par[to]==at&&d[to]==LLONG_MAX) d[to]=d[at]+parlen[to],q.push(to);
		}
	}
}

void dfsgen(const vector<vector<int>> &adj,int at,int par,vector<int> &preidx,int &npre) { preidx[at]=npre++; ::par[preidx[at]]=par==-1?-1:preidx[par]; REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par) continue; dfsgen(adj,to,at,preidx,npre); } }
void stress() {
	REP(rep,1000000) {
		n=100; nq=100;
		vector<vector<int>> adj(n,vector<int>()); int root=rand()%n;
		vector<int> comp(n); REP(i,n) comp[i]=i; REP(i,n-1) while(true) { int a=rand()%n,b=rand()%n; if(comp[a]==comp[b]) continue; int old=comp[b]; REP(j,n) if(comp[j]==old) comp[j]=comp[a]; adj[a].PB(b),adj[b].PB(a); break; }
		vector<int> preidx(n,-1); int npre=0; dfsgen(adj,root,-1,preidx,npre); assert(npre==n); REP(i,n) parlen[i]=par[i]==-1?0:rand()%10+1;
		REP(i,nq) { qx[i]=rand()%n,ql[i]=rand()%n,qr[i]=rand()%n; if(ql[i]>qr[i]) swap(ql[i],qr[i]); }
		//if(rep!=3) continue;
		solve();
		solvestupid();
		bool ok=true; REP(i,nq) if(qans[i]!=bfans[i]) ok=false;
		if(ok) { if(rep%1000==999) printf("."); continue; }
		printf("err in rep %d\n",rep);
		printf("%d %d\n",n,nq);
		FOR(i,1,n) printf("%d %d\n",par[i]+1,parlen[i]);
		REP(i,nq) printf("%d %d %d\n",qx[i]+1,ql[i]+1,qr[i]+1);
		printf("want:"); REP(i,nq) printf(" %lld",bfans[i]); puts("");
		printf("have:"); REP(i,nq) printf(" %lld",qans[i]); puts("");
		break;
		
	}
}

int main() {
	run();
	//stress();
	return 0;
}