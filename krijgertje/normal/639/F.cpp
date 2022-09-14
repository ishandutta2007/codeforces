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

const int MAXN=300000;
const int MAXLOGN=19;
const int MAXM=600000;

typedef struct G {
	int n,m;
	int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
	int c[MAXN];
	int cn,cm;
	int chead[MAXN],cnxt[2*MAXM],cto[2*MAXM];
	int anc[MAXN][MAXLOGN+1];
	int tid[MAXN],d[MAXN],ntid;
	int mrk[MAXN+2*MAXM],nmrk;
	void init(int _n) { n=_n; m=0; REP(i,n) ghead[i]=-1; }
	int addnode() { ghead[n]=-1; return n++; }
	int addedge(int a,int b) { gnxt[2*m+0]=ghead[a]; ghead[a]=2*m+0; gto[2*m+0]=b; gnxt[2*m+1]=ghead[b]; ghead[b]=2*m+1; gto[2*m+1]=a; return m++; }
	int addcnode() { chead[cn]=-1; return cn++; }
	int addcedge(int a,int b) { cnxt[2*cm+0]=chead[a]; chead[a]=2*cm+0; cto[2*cm+0]=b; cnxt[2*cm+1]=chead[b]; chead[b]=2*cm+1; cto[2*cm+1]=a; return cm++; }
	void printgraph() {
		printf("graph [%d,%d]\n",n,m); REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }
	}
	int gid[MAXN],gminid[MAXN],ngid,stck[MAXN],nstck;
	void tarjan(int at,int px) {
		gid[at]=gminid[at]=ngid++,stck[nstck++]=at;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(px!=-1&&((x>>1)==(px>>1))) continue;
			if(gid[to]==-1) {
				tarjan(to,x);
				if(gminid[to]<gminid[at]) gminid[at]=gminid[to];
			} else {
				if(gid[to]<gminid[at]) gminid[at]=gid[to];
			}
		}
		if(gminid[at]>=gid[at]) {
			int cidx=addcnode();
			while(c[at]==-1) c[stck[--nstck]]=cidx;
		}
	}
	void calccomps() {
		REP(i,n) gid[i]=c[i]=-1; ngid=cn=cm=nstck=0;
		REP(i,n) if(gid[i]==-1) tarjan(i,-1);
		REP(i,m) { int a=gto[2*i+1],b=gto[2*i+0]; if(c[a]!=c[b]) addcedge(c[a],c[b]); }
	}
	void printcomps() {
		printf("comps\n"); REP(i,cn) { printf("%d:",i); for(int x=chead[i];x!=-1;x=cnxt[x]) printf(" %d",cto[x]); printf(" ["); REP(j,n) if(c[j]==i) printf("%d,",j); printf("]\n"); }
	}
	void dfs(int at,int par) {
		tid[at]=ntid++,d[at]=par==-1?0:d[par]+1,anc[at][0]=par==-1?at:par;
		REP(k,MAXLOGN) anc[at][k+1]=anc[anc[at][k]][k];
		for(int x=chead[at];x!=-1;x=cnxt[x]) {
			int to=cto[x]; if(to==par) continue;
			dfs(to,at);
		}
	}
	void calctree() {
		REP(i,cn) tid[i]=-1; ntid=0;
		REP(i,cn) if(tid[i]==-1) dfs(i,-1);
	}
	void printtree() {
		printf("tree\n"); REP(i,cn) printf("%d: %d\n",i,anc[i][0]);
	}
	void unmark() {
		nmrk=0;
	}
	void mark(int cidx) {
		mrk[nmrk++]=cidx;
	}
	typedef struct tcmp { const G *g; tcmp(const G *g):g(g) {}  bool operator()(const int &a,const int &b) { return g->tid[a]<g->tid[b]; }  } tcmp;
	int lca(int a,int b) {
		if(d[a]<d[b]) swap(a,b);
		for(int k=MAXLOGN;k>=0;--k) if(d[a]-(1<<k)>=d[b]) a=anc[a][k];
		if(a==b) return a;
		for(int k=MAXLOGN;k>=0;--k) if(anc[a][k]!=anc[b][k]) a=anc[a][k],b=anc[b][k];
		return anc[a][0];
	}
	void buildmarked(G &g,int* mp) {
		g.init(0);
		sort(mrk,mrk+nmrk,tcmp(this)); nmrk=unique(mrk,mrk+nmrk)-mrk; //REP(i,nmrk) printf("mrk %d: %d %d\n",mrk[i],tid[mrk[i]],anc[mrk[i]][MAXLOGN]);
		for(int at=0,to=0;at<nmrk;at=to) {
			int root=anc[mrk[at]][MAXLOGN]; while(to<nmrk&&anc[mrk[to]][MAXLOGN]==root) ++to;
			nstck=0; mp[root]=g.addnode(),stck[nstck++]=root;
			FOR(i,at,to) {
				int u=mrk[i],v=lca(stck[nstck-1],u);
				while(nstck>=2&&d[stck[nstck-2]]>=d[v]) g.addedge(mp[stck[nstck-1]],mp[stck[nstck-2]]),--nstck;
				if(stck[nstck-1]!=v) mp[v]=g.addnode(),g.addedge(mp[stck[nstck-1]],mp[v]),--nstck,stck[nstck++]=v;
				if(u!=v) mp[u]=g.addnode(),stck[nstck++]=u;
			}
			while(nstck>=2) g.addedge(mp[stck[nstck-1]],mp[stck[nstck-2]]),--nstck;
		}
	}
} G;

G gorig,gq;
int mp[MAXN];

int qn,qm;
int qx[MAXN];
int qa[MAXM],qb[MAXM];

void run() {
	int n,m,nq; scanf("%d%d%d",&n,&m,&nq);
	gorig.init(n); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; gorig.addedge(a,b); }
	gorig.calccomps();
	//REP(i,n) printf("%d->%d ",i,gorig.c[i]); puts(""); gorig.printcomps();
	gorig.calctree();
	//gorig.printtree();
	int R=0;
	REP(qi,nq) {
		scanf("%d%d",&qn,&qm); 
		gorig.unmark();
		REP(i,qn) { scanf("%d",&qx[i]); --qx[i]; qx[i]=(qx[i]+R)%n; qx[i]=gorig.c[qx[i]]; gorig.mark(qx[i]); }
		REP(i,qm) { scanf("%d%d",&qa[i],&qb[i]); --qa[i],--qb[i]; qa[i]=(qa[i]+R)%n,qb[i]=(qb[i]+R)%n; qa[i]=gorig.c[qa[i]],qb[i]=gorig.c[qb[i]]; gorig.mark(qa[i]),gorig.mark(qb[i]); }
		//printf("q%d [%d,%d,R=%d]:",qi,qn,qm,R); REP(i,qn) printf(" %d",qx[i]); REP(i,qm) printf(" %d-%d",qa[i],qb[i]); puts("");
		gorig.buildmarked(gq,mp);
		REP(i,qn) qx[i]=mp[qx[i]]; REP(i,qm) qa[i]=mp[qa[i]],qb[i]=mp[qb[i]];
		REP(i,qm) gq.addedge(qa[i],qb[i]);
		//gq.printgraph();
		gq.calccomps();
		//gq.printcomps();
		bool same=true; FOR(i,1,qn) if(gq.c[qx[i]]!=gq.c[qx[0]]) same=false; printf("%s\n",same?"YES":"NO");
		if(same) R=(R+qi+1)%n;
	}
}

int main() {
	run();
	return 0;
}