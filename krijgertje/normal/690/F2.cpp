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

const int MAXF=100;
const int MAXN=100;
const int MAXM=MAXN-2;
const int MAXTN=MAXN-1;
const int MAXTM=MAXTN-1;
const int MAXRT=MAXN+1;
const int MAXRTN=1+MAXN+MAXN*MAXN;
const int MAXRTNSUM=MAXRT*MAXRTN;


typedef struct RT {
	int root,u,v;
} RT;
typedef struct RF {
	int n;
	int par[MAXRTNSUM];
	int chead[MAXRTNSUM];
	int cnxt[MAXRTNSUM];
	int coff[MAXRTNSUM];
	int ccnt[MAXRTNSUM];
	int cidx[MAXRTNSUM];
	int id[MAXRTNSUM];
	int d[MAXRTNSUM];
	int q[MAXRTNSUM],qhead,qtail;
	int orig[MAXRTNSUM];

	RF() { n=0; }
	int addNode(int p,int o) { assert(n<MAXRTNSUM); int ret=n++; par[ret]=p,chead[ret]=-1,cnxt[ret]=-1,orig[ret]=o; if(p!=-1) cnxt[ret]=chead[p],chead[p]=ret; return ret; }
	void print(int at) { printf("("); for(int to=chead[at];to!=-1;to=cnxt[to]) print(to); printf(")"); }

	int cidcmp(const int &a,const int &b) {
		for(int i=0;i<ccnt[a]||i<ccnt[b];++i) {
			if(i>=ccnt[a]) return -1; if(i>=ccnt[b]) return +1;
			int aa=id[cidx[coff[a]+i]],bb=id[cidx[coff[b]+i]]; if(aa!=bb) return aa<bb?-1:+1;
		}
		return 0;
	}
	struct cidless { RF* rf; cidless(RF* rf):rf(rf) {} bool operator()(const int &a,const int &b) { return rf->cidcmp(a,b)<0; } } ;
	vector<int> calcids(vector<RT> t) {
		int nt=SZ(t); //bool dbg=true;
		qhead=qtail=0; REP(i,nt) { int at=t[i].root; d[at]=0,q[qhead++]=at; }
		while(qtail<qhead) { int at=q[qtail++]; for(int to=chead[at];to!=-1;to=cnxt[to]) d[to]=d[at]+1,q[qhead++]=to; } int nq=qtail;
		int nc=0; REP(i,nq) { int at=q[i]; coff[at]=nc,ccnt[at]=0; for(int to=chead[at];to!=-1;to=cnxt[to]) ++ccnt[at],++nc; }
		int dmx=d[q[nq-1]];
		//if(dbg) printf("nq=%d dmx=%d\n",nq,dmx);
		int c=nq,b=nq,a=nq;
		while(a>0&&d[q[a-1]]==dmx) --a;
		FOR(i,a,b) { int at=q[i]; id[at]=0; }
		for(int cd=dmx-1;cd>=0;--cd) {
			c=b,b=a; while(a>0&&d[q[a-1]]==cd) --a; //if(dbg) printf("\t%d..%d..%d\n",a,b,c);
			FOR(i,b,c) { int at=q[i]; cidx[coff[par[at]]++]=at; }
			FOR(i,a,b) { int at=q[i]; for(int to=chead[at];to!=-1;to=cnxt[to]) --coff[at]; }
			sort(q+a,q+b,cidless(this));
			FOR(i,a,b) { int at=q[i]; id[at]=i==a?0:id[q[i-1]]+(cidcmp(at,q[i-1])==0?0:1); }
			//FOR(i,a,b) { int at=q[i]; printf("%d = [",at); REP(j,ccnt[at]) printf("%d%c",id[cidx[coff[at]+j]],j+1<ccnt[at]?',':']'); if(ccnt[at]==0) printf("]"); printf(" ->  %d\n",id[at]); }
		}
		vector<int> ret(nt,-1); REP(i,nt) ret[i]=id[t[i].root]; return ret;
	}
} RF;
RF rf;

//bool dbg=false;
typedef struct T {
	int n,m,root;
	int ghead[MAXTN],gnxt[2*MAXTM],gto[2*MAXTM];
	int orig[MAXTN];
	int d1[MAXTN],d2[MAXTN],d3[MAXTN];
	int q[MAXTN],qhead,qtail;

	void init(int o) { n=1,m=0; root=0; ghead[0]=-1,orig[0]=o; }
	int addNode(int p,int o) { assert(n<MAXTN); int ret=n++; ghead[ret]=-1,orig[ret]=o; if(p!=-1) { gnxt[m]=ghead[ret],ghead[ret]=m,gto[m]=p,++m; gnxt[m]=ghead[p],ghead[p]=m,gto[m]=ret,++m; }  return ret; }
	vector<int> calcCenters(int rt) {
		REP(i,n) d1[i]=INT_MAX; qhead=qtail=0; d1[rt]=0,q[qhead++]=rt;
		while(qtail<qhead) { int at=q[qtail++]; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(d1[to]!=INT_MAX) continue; d1[to]=d1[at]+1; q[qhead++]=to; } }
		int u=rt; REP(i,n) if(d1[i]!=INT_MAX&&d1[i]>d1[u]) u=i;
		//if(dbg) { REP(i,n) printf("%d=%d ",orig[i],d1[i]); printf("-> %d\n",orig[u]); }
		REP(i,n) d2[i]=INT_MAX; qhead=qtail=0; d2[u]=0,q[qhead++]=u;
		while(qtail<qhead) { int at=q[qtail++]; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(d2[to]!=INT_MAX) continue; d2[to]=d2[at]+1; q[qhead++]=to; } }
		int v=u; REP(i,n) if(d2[i]!=INT_MAX&&d2[i]>d2[v]) v=i;
		//if(dbg) { REP(i,n) printf("%d=%d ",orig[i],d2[i]); printf("-> %d\n",orig[v]); }
		REP(i,n) d3[i]=INT_MAX; qhead=qtail=0; d3[v]=0,q[qhead++]=v;
		while(qtail<qhead) { int at=q[qtail++]; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(d3[to]!=INT_MAX) continue; d3[to]=d3[at]+1; q[qhead++]=to; } }
		int w=v; REP(i,n) if(d3[i]!=INT_MAX&&d3[i]>d3[w]) w=i;
		//if(dbg) { REP(i,n) printf("%d=%d ",orig[i],d3[i]); printf("-> %d\n",orig[w]); }
		vector<int> ret; REP(i,n) if(d2[i]+d3[i]==d2[v]&&d2[v]-1<=2*d2[i]&&2*d2[i]<=d2[v]+1) ret.PB(i); return ret;
	}
	void appendTo(int at,int par,int idx) {
		for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(to==par) continue; int nidx=rf.addNode(idx,orig[to]); appendTo(to,at,nidx); }
	}
} T;
T t;

typedef struct F {
	int n,m;
	vector<vector<int> > adj;
	bool done[MAXN];
	set<int> adjpathdone[MAXN];
	int u,v,w;

	void input(int _n) { n=_n,u=v=w=-1; adj=vector<vector<int> >(n,vector<int>()); scanf("%d",&m); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); } }
	void buildTree(int at,int idx) {
		done[at]=true; if(at!=w) REPSZ(i,adj[at]) { int to=adj[at][i]; if(done[to]||to==w) continue; int nidx=t.addNode(idx,to); buildTree(to,nidx); }
		if(u!=w&&v!=w&&at==u&&!done[v]) { int nidx=t.addNode(idx,v); buildTree(v,nidx); }
		if(u!=w&&v!=w&&at==v&&!done[u]) { int nidx=t.addNode(idx,u); buildTree(u,nidx); }
	}
	void appendTo(int idx) {
		idx=rf.addNode(idx,-1);
		REP(i,n) done[i]=false;
		REP(i,n) if(!done[i]) {
			t.init(i); buildTree(i,t.root);
			vector<int> centers=t.calcCenters(t.root);
			int bj=0;
			FORSZ(j,1,centers) {
				int on=rf.n;
				RT a; a.root=rf.addNode(-1,centers[bj]); t.appendTo(centers[bj],-1,a.root);
				RT b; b.root=rf.addNode(-1,centers[j]); t.appendTo(centers[j],-1,b.root);
				vector<RT> c; c.PB(a); c.PB(b); vector<int> id=rf.calcids(c); if(id[1]<id[0]) bj=j;
				rf.n=on;
			}
			{ int ridx=rf.addNode(idx,t.orig[centers[bj]]); t.appendTo(centers[bj],-1,ridx); }
		}
	}
	pair<int,int> findpath(int at,int par) {
		int cnt=1;
		while(SZ(adj[at])==2) { int to=adj[at][0]==par?adj[at][1]:adj[at][0]; ++cnt,par=at,at=to; }
		return MP(at,cnt);
	}
	vector<RT> createAll() {
		REP(i,n) adjpathdone[i]=set<int>();
		vector<RT> ret;
		REP(i,n) if(SZ(adj[i])==0) { u=i; break; } assert(u!=-1);
		for(v=0;v<n;++v) if(v!=u) {
			if(SZ(adj[v])==1) { pair<int,int> p=findpath(adj[v][0],v); if(adjpathdone[p.first].count(p.second)) continue; else adjpathdone[p.first].insert(p.second); }
			RT cur; cur.root=rf.addNode(-1,-1); cur.u=u,cur.v=v; ret.PB(cur);
			for(w=0;w<n;++w) appendTo(cur.root);
		}
		return ret;
	}
	void print(RT a) {
		REP(i,n) REPSZ(j,adj[i]) if(i<adj[i][j]) printf("%d %d\n",i+1,adj[i][j]+1);
		printf("%d %d\n",a.u+1,a.v+1);
	}
} F;

int n,nf;
F f[MAXF];

void input() {
	scanf("%d%d",&n,&nf);
	REP(i,nf) f[i].input(n);
}

bool solve() {
	//printf("n=%d\n",n);
	RT a; a.root=rf.addNode(-1,-1); a.u=a.v=-1; REP(i,nf) f[i].appendTo(a.root);
	int idx=-1; REP(i,nf) if(f[i].m==n-2) { idx=i; break; }
	if(idx==-1) { printf("NO\n"); rf.n=0; return false; }
	vector<RT> b=f[idx].createAll();
	vector<RT> c; c.PB(a); REPSZ(i,b) c.PB(b[i]);
	//printf("rf.n=%d\n",rf.n);
	vector<int> id=rf.calcids(c);
	//if(qq!=1) printf("ids\n");
	//REPSZ(i,c) { printf("%d %2d (%d,%d): ",i<1?0:1,i<1?i:i-1,c[i].u,c[i].v); rf.print(c[i].root); printf(" = %d\n",id[i]); }
	FORSZ(i,1,c) if(id[i]==id[0]) {
		printf("YES\n");
		f[idx].print(c[i]);
		rf.n=0; return true;
	}
	printf("NO\n"); rf.n=0; return false;
}


void run() {
	input();
	solve();
}

void test() {
	while(true) {
		n=100; nf=n;
		vector<int> par(n,-1);
		FOR(i,1,n) par[i]=rand()%i;
		int u=rand()%n,v=rand()%(n-1); if(v>=u) ++v;
		REP(i,n) {
			f[i].n=n,f[i].m=0; f[i].u=f[i].v=f[i].w=-1;
			f[i].adj=vector<vector<int> >(n);
		}
		REP(i,n) FOR(j,1,n) if(j!=i&&par[j]!=i) f[i].adj[j].PB(par[j]),f[i].adj[par[j]].PB(j),f[i].m++;
		if(!solve()) {
			printf("1\n");
			printf("%d %d\n",n,n);
			REP(i,n) {
				int m=0; REP(j,n) REPSZ(k,f[i].adj[j]) if(j<f[i].adj[j][k]) ++m;
				printf("%d\n",m); REP(j,n) REPSZ(k,f[i].adj[j]) if(j<f[i].adj[j][k]) printf("%d %d\n",j+1,f[i].adj[j][k]+1);
			}
			break;
		}
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	//printf("%d\n",MAXRTNSUM); test();
	return 0;
}