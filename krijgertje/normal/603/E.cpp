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
const int MAXM=300000;
const int MAXST=MAXN+MAXM;
typedef struct E { int a,b,c; } E;


typedef struct ST {
	int n;
	int par[MAXST],lft[MAXST],rgt[MAXST],val[MAXST];
	int sz[MAXST],mx[MAXST]; bool rev[MAXST];

	int addnode(int nval) { par[n]=lft[n]=rgt[n]=-1,val[n]=nval,sz[n]=1,mx[n]=nval,rev[n]=false; return n++; }
	bool isroot(int a) { return par[a]==-1||lft[par[a]]!=a&&rgt[par[a]]!=a; }
	void push(int a) { if(!rev[a]) return; swap(lft[a],rgt[a]); rev[a]=!rev[a]; if(lft[a]!=-1) rev[lft[a]]=!rev[lft[a]]; if(rgt[a]!=-1) rev[rgt[a]]=!rev[rgt[a]]; }
	void calc(int a) { mx[a]=val[a]; if(lft[a]!=-1) mx[a]=max(mx[a],mx[lft[a]]); if(rgt[a]!=-1) mx[a]=max(mx[a],mx[rgt[a]]); }
	void connect(int a,int b,int* c) { if(a!=-1) par[a]=b; if(c!=NULL) c[b]=a; }
	void rotate(int a) {
		int p=par[a],g=par[p]; push(p); push(a); bool rotlft=a==lft[p],rotroot=isroot(p); int c=rotlft?rgt[a]:lft[a];
		connect(c,p,rotlft?lft:rgt); connect(p,a,rotlft?rgt:lft); connect(a,g,rotroot?NULL:p==lft[g]?lft:rgt);
		swap(sz[a],sz[p]); sz[p]=sz[a]-sz[p]+(c==-1?0:sz[c]); calc(p);
	}
	void splay(int a) { while(!isroot(a)) { int p=par[a]; if(!isroot(p)) { int g=par[p]; push(g); push(p); rotate((a==lft[p])==(p==lft[g])?p:a); } rotate(a); calc(a); } }
	int expose(int a,int upto=-1) { int lst=-1; for(int cur=a;cur!=upto;cur=par[cur]) { splay(cur); push(cur); lft[cur]=lst; calc(cur); lst=cur; } splay(a); return lst; }
	void cut(int a) { expose(a); sz[a]-=sz[rgt[a]]; par[rgt[a]]=-1; rgt[a]=-1; calc(a); }
	void link(int a,int b) { expose(a); sz[b]+=sz[a]; par[a]=b; }
	void evert(int a) { expose(a); rev[a]=!rev[a]; }
	int nxt(int a) { splay(a); if(rgt[a]==-1) return -1; int b=rgt[a]; while(lft[b]!=-1) b=lft[b]; splay(b); return b; }
	int lca(int a,int b) { expose(a); int ret=expose(b); if(expose(a)!=ret) return -1; expose(ret); expose(a,ret); expose(b,ret); return ret; }
	void print() { REP(i,n) if(par[i]==-1) printrec(i,0,' '); }
	void printrec(int a,int d,char c) {
		printf("\t"); REP(i,d) printf(" "); printf("%c%d=[%d,%d,%d]%c{%d,%d,%d}\n",c,a,lft[a],par[a],rgt[a],rev[a]?'R':'.',val[a],sz[a],mx[a]);
		if(lft[a]!=-1) printrec(lft[a],d+1,'L');
		REP(i,n) if(par[i]==a&&isroot(i)) printrec(i,d+1,'M');
		if(rgt[a]!=-1) printrec(rgt[a],d+1,'R');
	}
} ST;

int n,m;
E e[MAXM];
int ec[MAXM]; bool ccmp(const int &p,const int &q) { if(e[p].c!=e[q].c) return e[p].c<e[q].c; return p<q; }
bool have[MAXM];
ST st;
int ret[MAXM];
int noddcomp;

void addedge(int id) {
	int a=e[id].a,b=e[id].b; have[id]=true;
	st.expose(a); st.evert(b);
	if(st.sz[a]%4==1&&st.sz[b]%4==1) noddcomp-=2;
	int ab=st.addnode(id);
	st.link(b,ab);
	st.link(ab,a);
	//printf("addedge%d=(%d,%d) after (%d oddcomp)\n",id,a,b,noddcomp); st.print();
}
void remedge(int id) {
	int a=e[id].a,b=e[id].b,lca=st.lca(a,b); have[id]=false;
	if(a==lca) swap(a,b); assert(a!=lca);
	if(b==lca) {
		if(st.sz[b]%4==3&&st.sz[a]%4==2) noddcomp+=2;
		int ab=st.nxt(a); assert(ab!=-1&&st.nxt(ab)==-1);
		st.cut(a); st.cut(ab);
	} else {
		if(st.sz[a]%4==1&&st.sz[b]%4==1) noddcomp+=2;
		int ab=lca; assert(st.nxt(a)==-1&&st.nxt(b)==-1);
		st.cut(a); st.cut(b);
	}
	//printf("remedge%d=(%d,%d) after (%d oddcomp)\n",id,a,b,noddcomp); st.print();
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),--e[i].a,--e[i].b;
	REP(i,m) ec[i]=i; sort(ec,ec+m,ccmp);
	REP(i,n) st.addnode(-1-i);

	int upto=m; noddcomp=n;
	REP(i,m) {
		int id=ec[i]; if(id>=upto) continue;
		int a=e[id].a,b=e[id].b,lca=st.lca(a,b);
		//printf("lca(%d,%d)->%d\n",a,b,lca); st.print();
		if(lca==-1) { // a and b were unconnected, a and b are roots their splay trees, which represents the paths from the roots of their actual trees to the nodes
			addedge(id);
			for(;upto>0&&noddcomp==0;--upto) {
				ret[upto-1]=e[id].c;
				if(have[upto-1]) remedge(upto-1);
			}
		} else { // a and b are the roots of their splay trees, which respresents paths from the lca (exclusive) to the nodes
			int aid=a==lca?-1:st.mx[a],bid=b==lca?-1:st.mx[b];
			if(aid==-1||bid!=-1&&bid>aid) swap(aid,bid),swap(a,b);
			if(aid==-1||id>aid) continue;
			remedge(aid);
			addedge(id);
		}
	}
	while(upto>0) ret[--upto]=-1;
	REP(i,m) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}