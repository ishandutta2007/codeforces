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

const int MAXN=100000;
const int MAXM=500000;
const int MAXQ=200000;
const int MAXTN=2*MAXN-1;


int n,m,nq;
int e[MAXM][2];
vector<pair<int,int>> adj[MAXN];
int qa[MAXQ],qb[MAXQ],qans[MAXQ];

int id[MAXN],lid[MAXN],nid;
int comp[MAXM],ncomp;
int stck[2*MAXM],nstck;



void tarjan(int at,int pareid) {
	id[at]=lid[at]=nid++;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,eid=adj[at][i].second;
		if(eid==pareid||comp[eid]!=-1) continue;
		//printf("processing %d->%d\n",at+1,to+1);
		comp[eid]=-2; assert(nstck<m); stck[nstck++]=eid;
		if(id[to]!=-1) { lid[at]=min(lid[at],id[to]); continue; }
		tarjan(to,eid); lid[at]=min(lid[at],lid[to]);
		if(lid[to]>=id[at]) { while(comp[eid]==-2) comp[stck[--nstck]]=ncomp; ++ncomp; }
	}
}

struct T {
	int n;
	vector<int> adj[MAXTN];
	vector<int> q[MAXTN];
	int dep[MAXTN];
	int lca[MAXQ];
	int ufpar[MAXTN],ufsz[MAXTN],ufleader[MAXTN];

	int find(int a) { if(ufpar[a]==a) return a; return ufpar[a]=find(ufpar[a]); }
	void unite(int a,int b) { a=find(a),b=find(b); if(a==b) return; int leader=ufleader[a]; if(ufsz[a]<ufsz[b]) swap(a,b); ufpar[b]=a,ufsz[a]+=ufsz[b],ufleader[a]=leader; }

	void normalize() {
		REP(i,n) { sort(adj[i].begin(),adj[i].end()); adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end()); }
		//REP(i,n) { printf("%d:",i); REPSZ(j,adj[i]) printf(" %d",adj[i][j]); puts(""); }
	}

	bool been[MAXTN];
	void dfs(int at,int par) {
		assert(!been[at]); been[at]=true;
		dep[at]=par==-1?0:dep[par]+1;
		REPSZ(i,adj[at]) {
			int to=adj[at][i]; if(to==par) continue;
			dfs(to,at);
			unite(at,to);
		}
		REPSZ(i,q[at]) { int id=q[at][i]; if(lca[id]==-1) lca[id]=at; else lca[id]=ufleader[find(lca[id])]; }
	}

	void init(int _n) { n=_n; REP(i,n) adj[i].clear(),q[i].clear(),ufpar[i]=i,ufsz[i]=1,ufleader[i]=i,been[i]=false; }
	void solve() { dfs(0,-1); }
};

T t;


void solve() {
	nid=0; REP(i,n) id[i]=-1; ncomp=0; REP(i,m) comp[i]=-1; nstck=0;
	tarjan(0,-1); assert(ncomp<n); REP(i,m) assert(comp[i]>=0&&comp[i]<ncomp);
	//REP(i,m) printf("%d-%d = %d\n",e[i][0]+1,e[i][1]+1,comp[i]);
	t.init(n+ncomp);
	REP(at,n) REPSZ(i,adj[at]) { int to=n+comp[adj[at][i].second]; t.adj[at].PB(to),t.adj[to].PB(at); }
	t.normalize();
	REP(i,nq) t.q[qa[i]].PB(i),t.q[qb[i]].PB(i),t.lca[i]=-1;
	t.solve();
	REP(i,nq) {
		int a=qa[i],adep=t.dep[a],b=qb[i],bdep=t.dep[b],c=t.lca[i],cdep=t.dep[c],d=adep+bdep-2*cdep; assert(d%2==0);
		//printf("q%d: %d(%d) %d(%d) %d(%d) -> %d\n",i,a,adep,b,bdep,c,cdep,d);
		qans[i]=d/2;
	}
}

void run() {
	scanf("%d%d%d",&n,&m,&nq);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; e[i][0]=a,e[i][1]=b; adj[a].PB(MP(b,i)); adj[b].PB(MP(a,i)); }
	REP(i,nq) scanf("%d%d",&qa[i],&qb[i]),--qa[i],--qb[i];
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int myrand() { return rand()%1000*1000000+rand()%1000*1000+rand()%1000; }
void stress() {
	REP(rep,1000) {
		n=MAXN; m=max(n-1,rand()%(int)min((ll)MAXM,(ll)n*(n-1)/2)); nq=MAXQ;
		REP(i,n-1) e[i][0]=rand()%(i+1),e[i][1]=i+1; set<pair<int,int>> have; REP(i,m) { if(i>=n-1) while(true) { int a=myrand()%n,b=myrand()%n; if(a>b) swap(a,b); if(a==b||have.count(MP(a,b))) continue; e[i][0]=a,e[i][1]=b; break; } have.insert(MP(e[i][0],e[i][1])); }
		REP(i,n) adj[i].clear(); REP(i,m) { int a=e[i][0],b=e[i][1]; adj[a].PB(MP(b,i)),adj[b].PB(MP(a,i)); }
		REP(i,nq) qa[i]=myrand()%n,qb[i]=myrand()%n;
		//printf("%d %d %d\n",n,m,nq); REP(i,m) printf("%d %d\n",e[i][0]+1,e[i][1]+1); REP(i,nq) printf("%d %d\n",qa[i]+1,qb[i]+1);
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}