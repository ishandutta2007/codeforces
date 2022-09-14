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

const int MAXN=200000;
const int MAXLOGN=18;
const int MAXM=200000;

typedef struct T {
	int n,m;
	int head[MAXN];
	int nxt[2*MAXM],to[2*MAXM];
	void addedge(int a,int b) { nxt[m]=head[a]; head[a]=m; to[m++]=b; nxt[m]=head[b]; head[b]=m; to[m++]=a; }
	void print() { REP(i,n) { printf("%d:",i); for(int x=head[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); } }

	int val[MAXN];

	int depth[MAXN];
	int par[MAXN][MAXLOGN+1];
	int q[MAXN],nq;
	void dfs(int at) {
		for(int x=head[at];x!=-1;x=nxt[x]) if(par[at][0]!=to[x]) {
			par[to[x]][0]=at; depth[to[x]]=depth[at]+1;
			dfs(to[x]);
		}
		q[nq++]=at;
	}
	void precalc() {
		nq=0;
		REP(i,n) par[i][0]=depth[i]=-1,val[i]=0;
		REP(i,n) if(par[i][0]==-1) {
			par[i][0]=i; depth[i]=0;
			dfs(i);
		}
		FORE(j,1,MAXLOGN) REP(i,n) par[i][j]=par[par[i][j-1]][j-1];
		//REP(i,n) printf("%d: par=%d, depth=%d\n",i,par[i][0],depth[i]);
	}
	int lca(int a,int b) {
		if(depth[a]<depth[b]) swap(a,b);
		for(int k=MAXLOGN;k>=0;--k) if(depth[a]-(1<<k)>=depth[b]) a=par[a][k];
		for(int k=MAXLOGN;k>=0;--k) if(par[a][k]!=par[b][k]) a=par[a][k],b=par[b][k];
		if(a==b) return a;
		if(par[a][0]==par[b][0]) return par[a][0];
		return -1;
	}
	bool set(int at,int v) {
		if(v>0) if(val[at]<0) return false; else if(v>val[at]) val[at]=v;
		if(v<0) if(val[at]>0) return false; else if(v<val[at]) val[at]=v;
		return true;
	}
	bool check() {
		REP(i,n) {
			int at=q[i];
			if(val[at]>0&&!set(par[at][0],val[at]-1)) return false;
			if(val[at]<0&&!set(par[at][0],val[at]+1)) return false;
		}
		return true;
	}
} T;
typedef struct G {
	int n,m;
	int head[MAXN];
	int nxt[2*MAXM],to[2*MAXM];

	int comp[MAXN],ncomp;
	int chead[MAXN],cnxt[MAXN];

	bool been[MAXN];
	int depth[MAXN];
	int mindepth[MAXN];
	int stck[MAXN],nstck;
	void dfs(int at,int parx,int d) {
		stck[nstck++]=at; been[at]=true;
		depth[at]=mindepth[at]=d;
		for(int x=head[at];x!=-1;x=nxt[x]) if(parx==-1||(x>>1)!=(parx>>1)) {
			if(!been[to[x]]) {
				dfs(to[x],x,d+1);
				if(mindepth[to[x]]>depth[at]) { while(stck[nstck-1]!=to[x]) comp[stck[--nstck]]=ncomp; comp[stck[--nstck]]=ncomp++; }
				if(mindepth[to[x]]<mindepth[at]) mindepth[at]=mindepth[to[x]];
			} else {
				if(depth[to[x]]<mindepth[at]) mindepth[at]=depth[to[x]];
			}
		}
	}
	int e[MAXM],ne;
	void ebiconnect(T &t) {
		ncomp=0;
		REP(i,n) been[i]=false,comp[i]=-1;
		REP(i,n) if(!been[i]) {
			nstck=0;
			dfs(i,-1,0);
			while(nstck>0) comp[stck[--nstck]]=ncomp; ncomp++;
		}
		REP(i,ncomp) chead[i]=-1;
		REP(i,n) { cnxt[i]=chead[comp[i]]; chead[comp[i]]=i; }
		t.n=ncomp,t.m=0;
		REP(i,t.n) t.head[i]=-1;
		REP(i,ncomp) {
			ne=0;
			for(int x=chead[i];x!=-1;x=cnxt[x]) for(int y=head[x];y!=-1;y=nxt[y]) if(comp[to[y]]!=i)  e[ne++]=comp[to[y]];
			//sort(e,e+ne); ne=unique(e,e+ne)-e;
			REP(j,ne) if(i<e[j]) t.addedge(i,e[j]);
		}
	}
	void printcomp() { REP(i,ncomp) { printf("%d:",i); for(int x=chead[i];x!=-1;x=cnxt[x]) printf(" %d",x); puts(""); } }
} G;

G g;
T t;
int nq;




void run() {
	scanf("%d%d%d",&g.n,&g.m,&nq);
	REP(i,g.n) g.head[i]=-1;
	REP(i,g.m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		g.nxt[2*i+0]=g.head[a]; g.head[a]=2*i+0; g.to[2*i+0]=b;
		g.nxt[2*i+1]=g.head[b]; g.head[b]=2*i+1; g.to[2*i+1]=a;
	}
	g.ebiconnect(t);
	//g.printcomp();
	//t.print();
	t.precalc();
	bool ok=true;
	REP(qi,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b; a=g.comp[a],b=g.comp[b];
		int c=t.lca(a,b);
		//printf("%d->%d->%d\n",a,c,b);
		if(c==-1) { ok=false; continue; }
		if(!t.set(a,t.depth[c]-t.depth[a])) ok=false;
		if(!t.set(b,t.depth[b]-t.depth[c])) ok=false;
	}
	if(!t.check()) ok=false;
	printf("%s\n",ok?"Yes":"No");
}

int main() {
	run();
	return 0;
}