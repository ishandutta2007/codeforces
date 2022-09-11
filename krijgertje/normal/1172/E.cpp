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

ll globans;

struct LinkCutNode {
	int par,ch[2];
	int totcnt,midcnt; ll midans;
};
struct LinkCutTree {
	void updatepath(LinkCutNode &x,LinkCutNode *l,LinkCutNode *r) { x.totcnt=1+x.midcnt; if(l!=nullptr) x.totcnt+=l->totcnt; if(r!=nullptr) x.totcnt+=r->totcnt; }
	void removemiddle(LinkCutNode &x,LinkCutNode *y) { x.midcnt-=y->totcnt; x.midans-=(ll)y->totcnt*y->totcnt; }
	void addmiddle(LinkCutNode &x,LinkCutNode *y) { x.midcnt+=y->totcnt; x.midans+=(ll)y->totcnt*y->totcnt; }
	void removeglobal(LinkCutNode &x) { assert(x.par==-1&&x.ch[0]==-1); globans-=x.midans+(ll)(x.totcnt-x.midcnt-1)*(x.totcnt-x.midcnt-1); }
	void addglobal(LinkCutNode &x) { assert(x.par==-1&&x.ch[0]==-1); globans+=x.midans+(ll)(x.totcnt-x.midcnt-1)*(x.totcnt-x.midcnt-1); }

	vector<LinkCutNode> nodes;
	void init(int n) { nodes=vector<LinkCutNode>(n); REPSZ(x,nodes) { nodes[x].par=nodes[x].ch[0]=nodes[x].ch[1]=-1; } }

	bool isroot(int x) { return nodes[x].par==-1||nodes[nodes[x].par].ch[0]!=x&&nodes[nodes[x].par].ch[1]!=x; }
	int side(int x,int y) { return nodes[y].ch[0]==x?0:nodes[y].ch[1]==x?1:-1; }
	void updatepath(int x) { updatepath(nodes[x],nodes[x].ch[0]==-1?nullptr:&nodes[nodes[x].ch[0]],nodes[x].ch[1]==-1?nullptr:&nodes[nodes[x].ch[1]]); /*printf("updated %d -> %d (%d,%d)[%d]\n",x,nodes[x].totcnt,nodes[x].ch[0],nodes[x].ch[1],nodes[x].midcnt);*/ }
	void removemiddle(int x,int y) { if(y!=-1) removemiddle(nodes[x],&nodes[y]); }
	void addmiddle(int x,int y) { if(y!=-1) addmiddle(nodes[x],&nodes[y]); }
	void removeglobal(int x) { removeglobal(nodes[x]); }
	void addglobal(int x) { addglobal(nodes[x]); }
	void rotate(int x) { 
		assert(!isroot(x)); 
		int y=nodes[x].par,z=nodes[y].par,k=side(x,y); assert(k==0||k==1); assert(y!=-1);
		nodes[x].par=z; if(!isroot(y)) nodes[z].ch[side(y,z)]=x;
		nodes[y].ch[k]=nodes[x].ch[1-k]; if(nodes[y].ch[k]!=-1) nodes[nodes[y].ch[k]].par=y;
		nodes[x].ch[1-k]=y,nodes[y].par=x;
		updatepath(y),updatepath(x);
	}
	void splay(int x) { while(!isroot(x)) { int y=nodes[x].par,z=nodes[y].par; if(!isroot(y)) rotate(side(x,y)!=side(y,z)?x:y); rotate(x); } }
	void access(int x) { for(int y=-1;x!=-1;y=x,x=nodes[x].par) { splay(x); removemiddle(x,y); addmiddle(x,nodes[x].ch[1]); nodes[x].ch[1]=y; updatepath(x); } }
	int treetop(int x) { access(x); splay(x); while(nodes[x].ch[0]!=-1) x=nodes[x].ch[0]; splay(x); return x; }
	void link(int x,int y) { removeglobal(treetop(x)),removeglobal(treetop(y)); splay(x); assert(nodes[x].par==-1&&nodes[x].ch[0]==-1); access(y); splay(y); assert(nodes[y].par==-1&&nodes[y].ch[1]==-1); nodes[x].ch[0]=y,nodes[y].par=x; updatepath(x); addglobal(treetop(x)); }
	void cut(int x) { removeglobal(treetop(x)); access(x); splay(x); assert(nodes[x].par==-1&&nodes[x].ch[0]!=-1); int y=nodes[x].ch[0]; nodes[y].par=-1; nodes[x].ch[0]=-1; updatepath(x); addglobal(treetop(x)),addglobal(treetop(y)); }
};

const int MAXN=400000;
const int MAXQ=400000;
const int MAXCOL=MAXN;

int n,nq,ncol;
int initcol[MAXN];
vector<int> adj[MAXN];
int qidx[MAXQ],qcol[MAXQ];
ll ans[MAXQ+1];

int par[MAXN];
LinkCutTree lct;
int ccol[MAXN];
vector<pair<int,pair<int,bool>>> when[MAXCOL];

void dfsinit(int at) { REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par[at]) continue; par[to]=at; dfsinit(to); } }

void solve() {
	par[0]=-1; dfsinit(0);
	lct.init(n+1);
	globans=0; REP(i,n+1) lct.nodes[i].midcnt=0,lct.updatepath(i),lct.addglobal(i);
	REP(at,n) lct.link(at,par[at]==-1?n:par[at]);

	REP(i,ncol) when[i].clear();
	REP(i,n) { int ncol=initcol[i]; ccol[i]=ncol; when[ncol].PB(MP(0,MP(i,false))); }
	REP(i,nq) { int at=qidx[i],ocol=ccol[at],ncol=qcol[i]; ccol[at]=ncol; if(ncol==ocol) continue; when[ocol].PB(MP(i+1,MP(at,true))); when[ncol].PB(MP(i+1,MP(at,false))); }


	REP(c,ncol) {
		sort(when[c].begin(),when[c].end());
		ll last=0;
		REPSZ(i,when[c]) {
			int t=when[c][i].first,at=when[c][i].second.first; bool val=when[c][i].second.second;
			//printf("col %c: t=%d at=%d val=%s before globans=%lld\n",'a'+c,t,at+1,!val?"cut":"link",globans);
			if(!val) lct.cut(at); else lct.link(at,par[at]==-1?n:par[at]);
			//printf("col %c: t=%d at=%d val=%s after globans=%lld\n",'a'+c,t,at+1,!val?"cut":"link",globans);
			if(i+1>=SZ(when[c])||when[c][i+1].first>t) { ll cur=(ll)n*n-globans; ans[t]+=cur-last; last=cur; }
		}
		for(int i=SZ(when[c])-1;i>=0;--i) {
			int t=when[c][i].first,at=when[c][i].second.first; bool val=when[c][i].second.second;
			if(val) lct.cut(at); else lct.link(at,par[at]==-1?n:par[at]);
		}
	}
	REP(i,nq) ans[i+1]+=ans[i];
}

void run() {
	scanf("%d%d",&n,&nq); ncol=n;
	REP(i,n) scanf("%d",&initcol[i]),--initcol[i];
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	REP(i,nq) scanf("%d%d",&qidx[i],&qcol[i]),--qidx[i],--qcol[i];
	solve();
	REPE(i,nq) printf("%lld\n",ans[i]);
}


int main() {
	run();
	return 0;
}