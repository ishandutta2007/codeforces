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
const int MAXLGN=16;
const int MAXM=MAXN-1;

typedef struct RT {
	int n,root;
	int par[MAXN],chead[MAXN],cnxt[MAXN];
	bool isimp[MAXN],isorigpar[MAXN];

	void clear() { n=0; root=-1; }
	int addnode(bool x) { /*printf("\t\tadding %d%c\n",n,x?'!':'.');*/ par[n]=chead[n]=cnxt[n]=-1; isimp[n]=x,isorigpar[n]=false; return n++; }
	void setpar(int u,int v,bool direct) { /*printf("\t\tsetting par[%d]=%d\n",u,v);*/ isorigpar[u]=direct,par[u]=v; cnxt[u]=chead[v]; chead[v]=u; }
	void printrec(int at,int d) { REP(i,d) printf("  "); printf("%c%d%c\n",isorigpar[at]?'-':'~',at,isimp[at]?'!':'.'); for(int to=chead[at];to!=-1;to=cnxt[to]) printrec(to,d+1); }
	void print() { if(root!=-1) printrec(root,0); }
	int combine(int a,int b) { return a==-1||b==-1?-1:a+b; }
	int best(int a,int b) { return a==-1?b:b==-1?a:min(a,b); }
	pair<int,int> dfs(int at) {
		int none=0,one=0,many=0;
		for(int to=chead[at];to!=-1;to=cnxt[to]) {
			pair<int,int> cur=dfs(to);
			many=combine(many,cur.second);
			one=best(combine(none,cur.second),combine(one,cur.first));
			none=combine(none,cur.first);
		}
		if(isimp[at]) one=none,none=-1; else one=best(one,combine(many,1)),none=best(none,combine(many,1));
		if(!isorigpar[at]) none=best(none,combine(one,1));
		//printf("\t%d=(%d,%d)\n",at,none,one);
		return MP(none,one);
	}
	int calc() { return dfs(root).second; }
} RT;

typedef struct G {
	int n,m;
	int ehead[MAXN],enxt[2*MAXM],eto[2*MAXM];
	int par[MAXN],chead[MAXN],cnxt[MAXN],d[MAXN];
	int anc[MAXN][MAXLGN+1];
	int tin[MAXN],t;
	int imp[MAXN],nimp;

	void init(int _n) { n=_n; m=0; REP(i,n) ehead[i]=-1; }
	void addedge(int a,int b) { enxt[m]=ehead[a],ehead[a]=m,eto[m]=b,++m; enxt[m]=ehead[b],ehead[b]=m,eto[m]=a,++m; }

	void dfs(int at) {
		chead[at]=cnxt[at]=-1,tin[at]=t++;
		for(int x=ehead[at];x!=-1;x=enxt[x]) {
			if(eto[x]==par[at]) continue;
			par[eto[x]]=at,d[eto[x]]=d[at]+1;
			dfs(eto[x]);
			cnxt[eto[x]]=chead[at]; chead[at]=eto[x];
		}
	}
	void precalc() {
		par[0]=-1,d[0]=0,t=0; dfs(0);
		REP(i,n) anc[i][0]=par[i]==-1?i:par[i];
		FORE(k,1,MAXLGN) REP(i,n) anc[i][k]=anc[anc[i][k-1]][k-1];
	}

	int lca(int u,int v) {
		if(d[u]<d[v]) swap(u,v);
		for(int k=MAXLGN;k>=0;--k) if(d[u]-(1<<k)>=d[v]) u=anc[u][k];
		if(u==v) return u;
		for(int k=MAXLGN;k>=0;--k) if(anc[u][k]!=anc[v][k]) u=anc[u][k],v=anc[v][k];
		return par[u];
	}
	void buildimptree(RT &rt) {
		static pair<int,int> tmp[MAXN]; REP(i,nimp) tmp[i]=MP(tin[imp[i]],imp[i]); sort(tmp,tmp+nimp); REP(i,nimp) imp[i]=tmp[i].second;
		static pair<int,int> stck[MAXN]; int nstck=0;
		//REP(i,nimp) printf("(%d,%d)",imp[i],d[imp[i]]); puts("");
		rt.clear();
		stck[nstck++]=MP(imp[0],rt.addnode(true));
		FOR(i,1,nimp) {
			int cur=lca(imp[i-1],imp[i]); //printf("\t(%d,%d)\n",cur,d[cur]);
			while(nstck>=2&&d[stck[nstck-2].first]>=d[cur]) rt.setpar(stck[nstck-1].second,stck[nstck-2].second,d[stck[nstck-1].first]==d[stck[nstck-2].first]+1),--nstck;
			if(d[stck[nstck-1].first]>d[cur]) { int v=rt.addnode(false); rt.setpar(stck[nstck-1].second,v,d[stck[nstck-1].first]==d[cur]+1),--nstck; stck[nstck++]=MP(cur,v); }
			stck[nstck++]=MP(imp[i],rt.addnode(true));
		}
		while(nstck>=2) rt.setpar(stck[nstck-1].second,stck[nstck-2].second,d[stck[nstck-1].first]==d[stck[nstck-2].first]+1),--nstck;
		rt.root=stck[0].second;
	}
} G;

G g;
RT rt;


void run() {
	int n; scanf("%d",&n); g.init(n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; g.addedge(a,b); }
	g.precalc();
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		scanf("%d",&g.nimp); REP(j,g.nimp) scanf("%d",&g.imp[j]),g.imp[j]--;
		g.buildimptree(rt);
		//rt.print();
		printf("%d\n",rt.calc());
	}
}

int main() {
	run();
	return 0;
}