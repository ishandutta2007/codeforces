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
const int MAXT=MAXN;
typedef struct R { int mn,mx,cnt,val,lazy; } Node;

template <class NODE,class VAL> struct SBBST {
	NODE root;
	NODE par[MAXT],lft[MAXT],rgt[MAXT];
	VAL (*val)(NODE);
	bool (*cmp)(NODE,VAL);
	void (*docalc)(NODE,NODE,NODE);
	void (*dopush)(NODE,NODE,NODE);
	void (*doprint)(NODE);

	void clear() { root=-1; memset(par,-1,sizeof(par)); memset(lft,-1,sizeof(lft)); memset(rgt,-1,sizeof(rgt)); }
	void calc(NODE x) { docalc(x,lft[x],rgt[x]); }
	void push(NODE x) { dopush(x,lft[x],rgt[x]); }
	void connect(NODE a,NODE b,NODE* c) { if(a!=-1) par[a]=b; if(c!=NULL) c[b]=a; }
	void rotate(NODE a) {
		NODE p=par[a],g=par[p]; bool rotlft=a==lft[p]; NODE c=rotlft?rgt[a]:lft[a]; push(p); push(a);
		connect(c,p,rotlft?lft:rgt); connect(p,a,rotlft?rgt:lft); connect(a,g,g==-1?NULL:p==lft[g]?lft:rgt); calc(p);
	}
	void splay(NODE a) { while(par[a]!=-1) { NODE p=par[a]; if(par[p]!=-1) { NODE g=par[p]; rotate((a==lft[p])==(p==lft[g])?p:a); } rotate(a); } calc(a); }
	void split(NODE x,VAL v,int &L,int &R) {
		if(x==-1) { L=R=-1; return; }
		NODE p=-1,y=-1; // smallest element in subtree of x >= v
		for(int z=x;z!=-1;) { push(z); p=z; if(cmp(z,v)) z=rgt[z]; else y=z,z=lft[z]; }
		if(p!=-1) splay(p);
		if(y==-1) { splay(x); L=x; R=-1; }
		else { splay(y); push(y); R=y; L=lft[y]; lft[y]=-1; if(L!=-1) par[L]=-1; calc(y); }
	}
	int join(NODE L,NODE R) {
		if(L==-1) return R; 
		while(rgt[L]!=-1) L=rgt[L]; splay(L); push(L); rgt[L]=R; if(R!=-1) par[R]=L; calc(L); return L;
	}
	void insert(NODE x) {
		NODE L,R; split(root,val(x),L,R); root=join(L,join(x,R));
	}
	void remove(NODE x) {
		NODE L,R; split(root,val(x),L,R); assert(x==R); push(x); R=rgt[x]; rgt[x]=-1; if(R!=-1) par[R]=-1; calc(x); root=join(L,R);
	}
	void removeval(VAL v) {
		NODE L,R; split(root,v,L,R); assert(R!=-1&&v==val(R)); NODE x=R; push(x); R=rgt[x]; rgt[x]=-1; if(R!=-1) par[R]=-1; calc(x); root=join(L,R);
	}
	void print(NODE x) { printf("["); if(lft[x]!=-1) print(lft[x]); doprint(x); if(rgt[x]!=-1) print(rgt[x]); printf("]"); }
};
SBBST<int,int> t;

Node node[MAXT]; int nnode;

int nodeval(int x) { return node[x].val; }
bool nodecmp(int x,int val) { return node[x].val<val; }
void nodecalc(int x,int l,int r) {
	node[x].mn=node[x].mx=node[x].val,node[x].cnt=1;
	if(l!=-1) node[x].mn=node[l].mn+node[x].lazy,node[x].cnt+=node[l].cnt;
	if(r!=-1) node[x].mx=node[r].mx+node[x].lazy,node[x].cnt+=node[r].cnt;
}
void nodepush(int x,int l,int r) {
	if(node[x].lazy==0) return;
	int by=node[x].lazy; node[x].lazy=0;
	if(l!=-1) node[l].mn+=by,node[l].mx+=by,node[l].val+=by,node[l].lazy+=by;
	if(r!=-1) node[r].mn+=by,node[r].mx+=by,node[r].val+=by,node[r].lazy+=by;
}
void nodeprint(int x) {
	printf("%d",node[x].val); if(node[x].lazy!=0) printf("<%d>",node[x].lazy);
}

int findnonexisting(int lb) {
	int ret;
	int L,R; t.split(t.root,lb,L,R);
	//printf("  "); t.print(L); puts("");
	//printf("  "); t.print(R); puts("");
	if(R==-1||node[R].mn!=lb) {
		ret=lb;
	} else if(node[R].cnt==node[R].mx-node[R].mn+1) {
		ret=node[R].mx+1;
	} else {
		int at=R,to=-1;
		while(true) {
			t.push(at);
			to=t.lft[at];
			if(to!=-1&&node[to].cnt!=node[to].mx-node[to].mn+1) { at=to; continue; }
			if(to!=-1&&node[to].mx+1<node[at].val) { ret=node[to].mx+1; t.splay(at); R=at; break; }
			to=t.rgt[at];
			if(to!=-1&&node[at].val+1<node[to].mn) { ret=node[at].val+1; t.splay(at); R=at; break; }
			if(to!=-1&&node[to].cnt!=node[to].mx-node[to].mn+1) { at=to; continue; }
			assert(false);
		}
	}
	t.root=t.join(L,R);
	return ret;
}
int findexisting(int lb) {
	int L,R; t.split(t.root,lb,L,R);
	int ret=R==-1?-1:node[R].mn;
	t.root=t.join(L,R);
	return ret;
}
void shift(int lb,int rb) {
	int L,M,R; t.split(t.root,lb,L,M); t.split(M,rb,M,R);
	if(M!=-1) node[M].mn++,node[M].mx++,node[M].val++,node[M].lazy++;
	t.root=t.join(L,t.join(M,R));
}
int createnode(int val) {
	node[nnode].mn=node[nnode].mx=node[nnode].val=val,node[nnode].cnt=1,node[nnode].lazy=0; return nnode++;
}

int n;
int l[MAXN],r[MAXN];

int solve() {
	nnode=0; t.clear();
	t.val=&nodeval;
	t.cmp=&nodecmp;
	t.docalc=&nodecalc;
	t.dopush=&nodepush;
	t.doprint=&nodeprint;
	REP(i,n) {
		int a=findnonexisting(l[i]);
		int b=findexisting(r[i]);
		//printf("%d %d -> %d %d\n",l[i],r[i],a,b);
		if(b!=-1&&a>=b) continue;
		if(b!=-1) t.removeval(b); // remove b from tree
		shift(a,b==-1?INT_MAX:b);	// increase all values in tree in range (a,b) by 1
		t.insert(createnode(a)); // add a to tree
		//t.print(t.root); puts("");
	}
	return node[t.root].cnt;
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&l[i],&r[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}