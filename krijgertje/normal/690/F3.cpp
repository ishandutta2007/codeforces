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

const int MAXF=2;
const int MAXN=1000;
const int MAXM=MAXN-2;
const int MAXTN=MAXN-1;
const int MAXTM=MAXTN-1;
const int MAXRT=MAXN-1+2*MAXM;
const int MAXRTN=10+MAXTN;
const int MAXRTNSUM=MAXF*MAXRT*MAXRTN+2*MAXTN;


typedef struct RT {
	int root,u,v,vv;
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
	int wantdeg;

	void input(int _n) { n=_n; adj=vector<vector<int> >(n,vector<int>()); scanf("%d",&m); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); } }
	void buildTree(int at,int idx) {
		done[at]=true; REPSZ(i,adj[at]) { int to=adj[at][i]; if(done[to]) continue; int nidx=t.addNode(idx,to); buildTree(to,nidx); }
	}
	int calcncomp() {
		REP(i,n) done[i]=false;
		int ret=0; REP(i,n) if(!done[i]) { t.init(i); buildTree(i,t.root); ++ret; } return ret;
	}
	// ( ((u+)) ((uv)()) ((v+)()()) )
	RT createCanonical(int u,int v,int vv,bool swp) {
		//dbg=false; if(!swp&&u==3&&v==4&&vv==2) dbg=true; if(swp&u==4&&v==3&&vv==1) dbg=true;
		RT ret; ret.u=u; ret.v=v; ret.vv=vv; ret.root=rf.addNode(-1,-1);
		int rt=ret.root,a=rf.addNode(rt,-1),b=rf.addNode(rt,-1),c=rf.addNode(rt,-1);
		a=rf.addNode(a,-1); rf.addNode(b,-1),b=rf.addNode(b,-1); rf.addNode(c,-1),rf.addNode(c,-1),c=rf.addNode(c,-1);
		REP(i,n) done[i]=false; done[u]=true; done[v]=true;
		REPSZ(i,adj[v]) {
			//if(swp&&u==0&&v==3&&vv==2) printf("building %d\n",adj[v][i]);
			t.init(adj[v][i]); buildTree(adj[v][i],t.root);
			vector<int> centers=t.calcCenters(t.root);
			//if(swp&&u==0&&v==3&&vv==2) { REPSZ(j,centers) printf("\t%d\n",t->orig[centers[j]]); }
			int par=adj[v][i]==vv?b:swp?a:c,bj=0;
			FORSZ(j,1,centers) {
				int on=rf.n;
				RT a; a.root=rf.addNode(-1,centers[bj]); t.appendTo(centers[bj],-1,a.root);
				RT b; b.root=rf.addNode(-1,centers[j]); t.appendTo(centers[j],-1,b.root);
				vector<RT> c; c.PB(a); c.PB(b); vector<int> id=rf.calcids(c); if(id[1]<id[0]) bj=j;
				rf.n=on;
			}
			{ int ridx=rf.addNode(par,t.orig[centers[bj]]); t.appendTo(centers[bj],-1,ridx); }
		}
		REP(i,n) if(!done[i]) {
			//if(!swp&&u==3&&v==0&&vv==1) printf("building %d\n",i);
			t.init(i); buildTree(i,t.root);
			vector<int> centers=t.calcCenters(t.root);
			int par=swp?c:a,bj=0;
			FORSZ(j,1,centers) {
				int on=rf.n;
				RT a; a.root=rf.addNode(-1,centers[bj]); t.appendTo(centers[bj],-1,a.root);
				RT b; b.root=rf.addNode(-1,centers[j]); t.appendTo(centers[j],-1,b.root);
				vector<RT> c; c.PB(a); c.PB(b); vector<int> id=rf.calcids(c); if(id[1]<id[0]) bj=j;
				rf.n=on;
			}
			{ int ridx=rf.addNode(par,t.orig[centers[bj]]); t.appendTo(centers[bj],-1,ridx); }
		}
		return ret;
	}
	vector<RT> createAll(bool swp) {
		int u=-1; REP(i,n) if(SZ(adj[i])==0) { u=i; break; } assert(u!=-1);
		vector<RT> ret; ret.reserve(n-1+2*m);
		REP(v,n) if(v!=u) {
			//if(!swp&&(u!=8||v!=3)) continue;
			//if(swp&&(u!=1||v!=5)) continue;
			if(SZ(adj[v])+1==wantdeg) ret.PB(createCanonical(u,v,-1,swp));
			if(SZ(adj[v])==wantdeg) REPSZ(i,adj[v]) ret.PB(createCanonical(u,v,adj[v][i],swp));
		}
		return ret;
	}
	void print(RT a,RT b,F &fb) {
		queue<pair<int,int> > q; q.push(MP(a.root,b.root));
		vector<int> ab(n,-1),ba(n,-1); ab[a.u]=b.v,ba[b.v]=a.u; ab[a.v]=b.u,ba[b.u]=a.v;
		while(!q.empty()) {
			int ai=q.front().first,bi=q.front().second; q.pop(); //printf("%d=%d\n",ai,bi); if(ai==0&&bi==0) exit(1);
			if(rf.orig[ai]!=-1&&rf.orig[bi]!=-1) ab[rf.orig[ai]]=rf.orig[bi],ba[rf.orig[bi]]=rf.orig[ai];
			REP(k,rf.ccnt[ai]) q.push(MP(rf.cidx[rf.coff[ai]+k],rf.cidx[rf.coff[bi]+k]));
		}
		//REP(i,n) printf("%d->%d\n",i,ab[i]);
		//REP(i,n) printf("%d<-%d\n",ba[i],i);
		REP(i,n) REPSZ(j,adj[i]) if(i<adj[i][j]) printf("%d %d\n",i+1,adj[i][j]+1);
		int x=ab[a.u]; REPSZ(j,fb.adj[x]) { int y=fb.adj[x][j]; printf("%d %d\n",a.u+1,ba[y]+1); }
		if(a.vv==-1) printf("%d %d\n",a.u+1,a.v+1);
	}
} F;

int qq;
int n,nf;
F f[2];

void input() {
	scanf("%d%d",&n,&nf);
	REP(i,nf) f[i].input(n);
}

bool solve() {
	//if(qq!=1) printf("n=%d\n",n);
	f[0].wantdeg=f[1].calcncomp()-1,f[1].wantdeg=f[0].calcncomp()-1;
	vector<RT> a=f[0].createAll(false);
	vector<RT> b=f[1].createAll(true);
	vector<RT> c; REPSZ(i,a) c.PB(a[i]); REPSZ(i,b) c.PB(b[i]);
	//if(qq!=1) printf("rf.n=%d\n",rf.n);
	vector<int> id=rf.calcids(c);
	//if(qq!=1) printf("ids\n");
	//REPSZ(i,c) { printf("%d %2d (%d,%d,%2d): ",i<SZ(a)?0:1,i<SZ(a)?i:i-SZ(a),c[i].u,c[i].v,c[i].vv); rf.print(c[i].root); printf(" = %d\n",id[i]); }
	map<int,int> mp; REPSZ(i,a) if(mp.count(id[i])==0) mp[id[i]]=i;
	REPSZ(j,b) if(mp.count(id[SZ(a)+j])) {
		int i=mp[id[SZ(a)+j]]; //printf("a%d with b%d\n",i,j);
		printf("YES\n");
		//if(qq==1) 
		f[0].print(a[i],b[j],f[1]);
		rf.n=0;
		return true;
	}
	rf.n=0;
	printf("NO\n"); return false;
}


void run() {
	input();
	solve();
}

void test() {
	while(true) {
		int n=1000;
		vector<int> par(n,-1);
		FOR(i,1,n) par[i]=rand()%i;
		int u=rand()%n,v=rand()%(n-1); if(v>=u) ++v;
		REP(i,2) {
			f[i].n=n;
			f[i].adj=vector<vector<int> >(n);
		}
		FOR(j,1,n) {
			if(j!=u&&par[j]!=u) f[0].adj[j].PB(par[j]),f[0].adj[par[j]].PB(j);
			if(j!=v&&par[j]!=v) f[1].adj[j].PB(par[j]),f[1].adj[par[j]].PB(j);
		}
		if(!solve()) {
			printf("1\n");
			printf("%d %d\n",n,2);
			REP(i,2) {
				int m=0; REP(j,n) REPSZ(k,f[i].adj[j]) if(j<f[i].adj[j][k]) ++m;
				printf("%d\n",m); REP(j,n) REPSZ(k,f[i].adj[j]) if(j<f[i].adj[j][k]) printf("%d %d\n",j+1,f[i].adj[j][k]+1);
			}
			break;
		}
	}
}

int main() {
	int n; scanf("%d",&n); qq=n; FORE(i,1,n) run();
	//printf("%d\n",MAXRTNSUM); test();
	return 0;
}