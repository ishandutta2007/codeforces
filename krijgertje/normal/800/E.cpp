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
#include <random>
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

const int MAXVAL=1000;
const int MAXN=2*MAXVAL-1;
const int MAXM=MAXN-1;

int nval;

typedef struct Loc {
	int root;
	int par[MAXN],d[MAXN];
	int chead[MAXN],cnxt[MAXN];
	
	int leafs[MAXN],ints[MAXN],nleafs,nints;
	void gen() {
		do {
			nleafs=0; REP(i,nval) leafs[nleafs++]=i;
			nints=0; REP(i,nval-1) ints[nints++]=nval+i;
			while(nleafs>=2) {
				int a,b; do { a=rand()%nleafs,b=rand()%nleafs; } while(a==b); if(a>b) swap(a,b); int c=rand()%nints;
				par[leafs[a]]=ints[c],par[leafs[b]]=ints[c];
				leafs[a]=ints[c]; swap(leafs[nleafs-1],leafs[b]); --nleafs; swap(ints[nints-1],ints[c]); --nints;
			}
			par[leafs[0]]=-1;
		} while(leafs[0]<nval);
		REP(i,2*nval-1) chead[i]=-1,cnxt[i]=-1; REP(i,2*nval-1) if(par[i]==-1) root=i; else cnxt[i]=chead[par[i]],chead[par[i]]=i;
		dfs(root);
	}
	void genchain() {
		do {
			nleafs=0; REP(i,nval) leafs[nleafs++]=i;
			nints=0; REP(i,nval-1) ints[nints++]=nval+i;
			while(nleafs>=2) {
				int a=0,b=rand()%(nleafs-1)+1; int c=rand()%nints;
				par[leafs[a]]=ints[c],par[leafs[b]]=ints[c];
				leafs[a]=ints[c]; swap(leafs[nleafs-1],leafs[b]); --nleafs; swap(ints[nints-1],ints[c]); --nints;
			}
			par[leafs[0]]=-1;
		} while(leafs[0]<nval);
		REP(i,2*nval-1) chead[i]=-1,cnxt[i]=-1; REP(i,2*nval-1) if(par[i]==-1) root=i; else cnxt[i]=chead[par[i]],chead[par[i]]=i;
		dfs(root);
	}
	void dfs(int at) { d[at]=par[at]==-1?0:d[par[at]]+1; for(int to=chead[at];to!=-1;to=cnxt[to]) dfs(to); }
	int lca(int a,int b) { if(d[a]<d[b]) swap(a,b); while(d[a]>d[b]) a=par[a]; while(a!=b) a=par[a],b=par[b]; return a; }
	char query(int a,int b,int c) { int x=d[lca(a,b)],y=d[lca(b,c)],z=d[lca(c,a)]; if(x>y&&x>z) return 'X'; if(y>x&&y>z) return 'Y'; if(z>x&&z>y) return 'Z'; printf("err (%d,%d,%d)->(%d,%d,%d)\n",a,b,c,x,y,z); exit(0); }
	void print() { printf("%d\n",nval); REP(i,2*nval-1) { if(i!=0) printf(" "); printf("%d",par[i]==-1?-1:par[i]+1); } puts(""); }
} Loc;
Loc loc;

bool local=false; int nq;
char query(int a,int b,int c) {
	++nq;
	if(local) {
		return loc.query(a,b,c);
	} else {
		printf("%d %d %d\n",a+1,b+1,c+1); fflush(stdout); char ret; scanf(" %c",&ret); return ret;
	}
}

int n,m;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gpar[MAXN],id[MAXN];
bool dead[MAXN];

int addnode(int cid) { int ret=n++; ghead[ret]=-1,gpar[ret]=-1,id[ret]=cid; return ret; }
void createedge(int a,int b) { gnxt[m]=ghead[a],ghead[a]=m,gto[m]=b,++m; gnxt[m]=ghead[b],ghead[b]=m,gto[m]=a,++m; }
void setpar(int a,int b) {
	if(gpar[a]==-1) { gpar[a]=b; if(b!=-1) createedge(a,b); return; }
	int c=gpar[a];
	int m1=-1; while(ghead[c]!=-1&&gto[ghead[c]]==a) { assert(m1==-1); m1=ghead[c]; ghead[c]=gnxt[ghead[c]]; } for(int x=ghead[c];x!=-1;x=gnxt[x]) while(gnxt[x]!=-1&&gto[gnxt[x]]==a) { assert(m1==-1); m1=gnxt[x]; gnxt[x]=gnxt[gnxt[x]]; } assert(m1!=-1);
	int m2=-1; while(ghead[a]!=-1&&gto[ghead[a]]==c) { assert(m2==-1); m2=ghead[a]; ghead[a]=gnxt[ghead[a]]; } for(int x=ghead[a];x!=-1;x=gnxt[x]) while(gnxt[x]!=-1&&gto[gnxt[x]]==c) { assert(m2==-1); m2=gnxt[x]; gnxt[x]=gnxt[gnxt[x]]; } assert(m2!=-1);
	gnxt[m1]=ghead[a],ghead[a]=m1,gto[m1]=b; gnxt[m2]=ghead[b],ghead[b]=m2,gto[m2]=a; gpar[a]=b;
}
int findid(int at) { if(id[at]!=-1) return id[at]; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(to==gpar[at]) continue; int ret=findid(to); if(ret!=-1) return ret; } return -1; }

int sz[MAXN];
void dfs1(int at,int par) {
	sz[at]=1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(to==par||dead[to]) continue; dfs1(to,at); sz[at]+=sz[to]; }
}
int dfs2(int at,int par,int totsz) {
	for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(to==par||dead[to]) continue; if(2*sz[to]>totsz) return dfs2(to,at,totsz); }
	assert(2*(totsz-sz[at])<=totsz); return at;
}
int centroid(int at) {
	dfs1(at,-1);
	return dfs2(at,-1,sz[at]);
}

void place(int cur,int at) {
	//printf("place(%d,%d)\n",cur,at);
	if(id[at]!=-1||dead[at]) {
		int a=addnode(cur);
		int c=addnode(-1);
		setpar(a,c); setpar(c,gpar[at]); setpar(at,c);
	} else {
		int root=centroid(at);
		//printf("%d->%d\n",at,root);
		int a=-1,b=-1; for(int x=ghead[root];x!=-1;x=gnxt[x]) { int to=gto[x]; if(to==gpar[root]) continue; if(a==-1) a=to; else if(b==-1) b=to; else assert(false); } assert(a!=-1&&b!=-1);
		int aid=findid(a),bid=findid(b); assert(aid!=-1&&bid!=-1);
		char res=query(aid,bid,cur);
		//printf("query(%d,%d,%d)=%c\n",aid+1,bid+1,cur+1,res);
		dead[root]=true;
		if(res=='Z') place(cur,a);
		if(res=='Y') place(cur,b);
		if(res=='X') place(cur,gpar[root]==-1||dead[gpar[root]]?root:gpar[root]);
	}
}
void printrec(int at,int d) {
	REP(i,d) printf(" "); if(id[at]!=-1) printf("%d",id[at]+1); else printf("X"); printf(" [%d]\n",at);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(to==gpar[at]) continue; printrec(to,d+1); }
}
void printtree(int at) {
	while(gpar[at]!=-1) at=gpar[at];
	printrec(at,0); puts("");
}


void solve() {
	n=0,m=0;
	int a=addnode(0);
	int b=addnode(1);
	int c=addnode(-1);
	setpar(a,c); setpar(b,c);
	FOR(x,2,nval) {
		memset(dead,false,sizeof(dead));
		place(x,c);
		//printtree(c);
	}

}

void output() {
	printf("-1\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",gpar[i]==-1?-1:gpar[i]+1); } puts("");
}


void run() {
	scanf("%d",&nval);
	solve();
	output();
}

void stress() {
	REP(x,100) {
		nval=MAXVAL; local=true; nq=0;
		//loc.gen();
		loc.genchain();
		//loc.print();
		solve();
		//output();
		printf("nq=%d\n",nq);
		//break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}