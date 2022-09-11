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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

struct Func { int l,r; Func():l(INT_MIN),r(INT_MAX) {} Func(int l,int r):l(l),r(r) {} int val() { assert(l==r); return l; } };
void merge(Func &a,const Func &b) { a=Func(max(a.l,min(a.r,b.l)),max(a.l,min(a.r,b.r))); }

struct ColorCalculator {
	int id,deg;
	vector<int> chcnt; int chsum;
	int cur,bal; // cur is maximum value such that #(childs>=cur)-#(childs<cur)=bal>=cur
	
	void init(int _id,int _deg) { id=_id,deg=_deg; chcnt=vector<int>(2*deg+1,0); chsum=0; cur=0,bal=0; }
	void addchild(int k) { ++chsum; k=max(-deg,min(+deg,k)); /*printf("adding child with value %d to %d\n",k,id+1);*/ ++chcnt[deg+k]; if(k>=cur) ++bal; else --bal; upd(); }
	void remchild(int k) { --chsum; k=max(-deg,min(+deg,k)); /*printf("removing child with value %d from %d\n",k,id+1);*/ --chcnt[deg+k]; if(k>=cur) --bal; else ++bal; upd(); }
	void upd() { while(bal<cur) --cur,bal+=2*chcnt[deg+cur]; while(bal-2*chcnt[deg+cur]>=cur+1) bal-=2*chcnt[deg+cur],++cur; }
	Func func() { if(chsum==deg) return Func(cur,cur); if(chsum==deg-1) return Func(cur-(bal==cur?1:0),cur+(bal-2*chcnt[deg+cur]==cur?1:0)); return Func(0,0); }
};

struct LinkCutNode {
	int par,ch[2];
	ColorCalculator midcol;
	Func pathfunc;
};
struct LinkCutTree {
	void updatepath(LinkCutNode &x,LinkCutNode *l,LinkCutNode *r) { x.pathfunc=Func(); if(l!=nullptr) merge(x.pathfunc,l->pathfunc); merge(x.pathfunc,x.midcol.func()); if(r!=nullptr) merge(x.pathfunc,r->pathfunc); }
	void removemiddle(LinkCutNode &x,LinkCutNode *y) { /*printf("removing middle child %d from %d\n",y->midcol.id+1,x.midcol.id+1);*/ x.midcol.remchild(y->pathfunc.val()); }
	void addmiddle(LinkCutNode &x,LinkCutNode *y) { /*printf("adding middle child %d to %d\n",y->midcol.id+1,x.midcol.id+1);*/ x.midcol.addchild(y->pathfunc.val()); }

	vector<LinkCutNode> nodes;
	void init(int n) { nodes=vector<LinkCutNode>(n); REPSZ(x,nodes) { nodes[x].par=nodes[x].ch[0]=nodes[x].ch[1]=-1; } }

	bool isroot(int x) { return nodes[x].par==-1||nodes[nodes[x].par].ch[0]!=x&&nodes[nodes[x].par].ch[1]!=x; }
	int side(int x,int y) { return nodes[y].ch[0]==x?0:nodes[y].ch[1]==x?1:-1; }
	void updatepath(int x) { updatepath(nodes[x],nodes[x].ch[0]==-1?nullptr:&nodes[nodes[x].ch[0]],nodes[x].ch[1]==-1?nullptr:&nodes[nodes[x].ch[1]]); }
	void removemiddle(int x,int y) { if(y!=-1) removemiddle(nodes[x],&nodes[y]); }
	void addmiddle(int x,int y) { if(y!=-1) addmiddle(nodes[x],&nodes[y]); }
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
	void link(int x,int y) { splay(x); assert(nodes[x].par==-1&&nodes[x].ch[0]==-1); access(y); splay(y); assert(nodes[y].par==-1&&nodes[y].ch[1]==-1); nodes[x].ch[0]=y,nodes[y].par=x; updatepath(x); }
	void cut(int x) { access(x); splay(x); assert(nodes[x].par==-1&&nodes[x].ch[0]!=-1); int y=nodes[x].ch[0]; nodes[y].par=-1; nodes[x].ch[0]=-1; updatepath(x); }
};

const int MAXN=100000;
const int MAXQ=100000;

int n,skglob;
vector<int> adj[MAXN];
int scol[MAXN];
int nq;
int qkind[MAXQ],qidx[MAXQ],qval[MAXQ],qans[MAXQ];

int par[MAXN],deg[MAXN];
LinkCutTree tree;
int kglob;
int col[MAXN];
bool isleaf[MAXN];
int pre[MAXN],npre;

void dfsinit(int at) {
	pre[npre++]=at; deg[at]=0; isleaf[at]=scol[at]!=-1;
	REPSZ(i,adj[at]) { int to=adj[at][i]; if(to==par[at]) continue; ++deg[at]; par[to]=at; dfsinit(to); }
}

bool query(int x) {
	if(isleaf[x]) return col[x]==1;
	tree.access(x); tree.splay(x); return tree.nodes[x].midcol.func().val()>=kglob;
}
void update(int x,int c) {
	if(col[x]==c) return;
	assert(isleaf[x]);
	int y=par[x];
	if(y!=-1) tree.access(y),tree.splay(y);
	if(y!=-1) tree.nodes[y].midcol.remchild(col[x]==1?INT_MAX:INT_MIN);
	col[x]=c;
	if(y!=-1) tree.nodes[y].midcol.addchild(col[x]==1?INT_MAX:INT_MIN);
	if(y!=-1) tree.updatepath(y);
}

void solve() {
	par[0]=-1; npre=0; dfsinit(0);
	tree.init(n);
	REP(i,n) if(!isleaf[i]) tree.nodes[i].midcol.init(i,deg[i]);
	REP(i,n) if(isleaf[i]&&par[i]!=-1) tree.nodes[par[i]].midcol.addchild(scol[i]==1?INT_MAX:INT_MIN);
	REP(i,n) {
		int at=pre[n-i-1];
		if(isleaf[at]) continue;
		tree.updatepath(at);
		if(par[at]==-1) continue;
		//printf("linking %d to %d\n",at+1,par[at]+1);
		tree.link(at,par[at]);
	}
	
	kglob=skglob;
	REP(i,n) col[i]=scol[i];
	REP(i,nq) {
		//printf("processing q%d\n",i);
		if(qkind[i]==1) qans[i]=query(qidx[i])?1:0;
		if(qkind[i]==2) update(qidx[i],qval[i]);
		if(qkind[i]==3) kglob=qval[i];
	}
}

void run() {
	scanf("%d%d",&n,&skglob);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b),adj[b].PB(a); }
	REP(i,n) scanf("%d",&scol[i]);
	scanf("%d",&nq);
	REP(i,nq) { scanf("%d",&qkind[i]); if(qkind[i]==1) scanf("%d",&qidx[i]),--qidx[i]; if(qkind[i]==2) scanf("%d%d",&qidx[i],&qval[i]),--qidx[i]; if(qkind[i]==3) scanf("%d",&qval[i]); }
	solve();
	REP(i,nq) if(qkind[i]==1) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}