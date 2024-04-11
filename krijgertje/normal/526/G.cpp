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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXM=MAXN-1;
const int MAXLOGN=16;

int n,nq;
int fst[MAXN];
int nxt[2*MAXM];
int to[2*MAXM];
int len[MAXM];

int p[2][MAXN][MAXLOGN+1];
int d[2][MAXN];
int leafval[2][MAXN]; // leafval[z][node]=value of the node (if it is a leaf, 0 otherwise)
int leaf[2][MAXN-1],leafcnt[2]; // leaf[z][idx]=idx-th leaf
int leafidx[2][MAXN]; // leafidx[z][node]=idx (in leaf-array) of node
int fstleafidx[2][MAXN];  // fstleafidx[z][node]=idx (in leaf-array) of first descendant (in leaf-array) of node
int bestsum[2][MAXN]; // bestsum[z][cnt]=sum of values of best cnt leafs

typedef struct leafcmp {
	int z; leafcmp(int z):z(z) {}
	bool operator()(const int &a,const int &b) { return leafval[z][a]>leafval[z][b]; }
} leafcmp;

int q[MAXN],qhead,qtail;

void precalc(int z,int root) {
	REP(i,n) p[z][i][0]=-1,leafval[z][i]=0,leafidx[z][i]=-1;
	qhead=qtail=0;
	p[z][root][0]=root; d[z][root]=0; q[qhead++]=root;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=fst[at];x!=-1;x=nxt[x]) {
			if(p[z][to[x]][0]!=-1) continue;
			p[z][to[x]][0]=at; d[z][to[x]]=d[z][at]+len[x/2]; q[qhead++]=to[x];
		}
	}
	FORE(k,1,MAXLOGN) REP(i,n) p[z][i][k]=p[z][p[z][i][k-1]][k-1];
	for(int i=n-1;i>=0;--i) {
		int at=q[i];
		fstleafidx[z][at]=at;
		for(int x=fst[at];x!=-1;x=nxt[x]) {
			if(p[z][to[x]][0]!=at) continue;
			leafval[z][fstleafidx[z][to[x]]]+=len[x/2];
			if(leafval[z][fstleafidx[z][to[x]]]>leafval[z][fstleafidx[z][at]]) fstleafidx[z][at]=fstleafidx[z][to[x]];
		}
	}
	leafcnt[z]=0; REP(i,n) if(leafval[z][i]>0) leaf[z][leafcnt[z]++]=i; sort(leaf[z],leaf[z]+leafcnt[z],leafcmp(z));
	bestsum[z][0]=0; REP(i,leafcnt[z]) bestsum[z][i+1]=bestsum[z][i]+leafval[z][leaf[z][i]];
	REP(i,leafcnt[z]) leafidx[z][leaf[z][i]]=i; REP(i,n) fstleafidx[z][i]=leafidx[z][fstleafidx[z][i]];
	//printf("ROOTED AT %d:\n",root);
	//REP(i,leafcnt[z]) printf("leaf at %d: %d = %d\n",i,leaf[z][i],leafval[z][leaf[z][i]]);
	//REP(i,n) printf("node %d: par=%d, depth=%d, fst=%d\n",i,p[z][i][0],d[z][i],fstleafidx[z][i]);
}

bool been[MAXN];
priority_queue<pair<int,int> > pq;

int farthest(int root) {
	int ret=-1;
	REP(i,n) been[i]=false;
	pq.push(MP(-0,root)); been[root]=true;
	while(!pq.empty()) {
		int cur=-pq.top().first,at=pq.top().second; pq.pop();
		ret=at;
		for(int x=fst[at];x!=-1;x=nxt[x]) {
			if(been[to[x]]) continue;
			pq.push(MP(-(cur+len[x/2]),to[x])); been[to[x]]=true;
		}
	}
	return ret;
}

void precalc() {
	int x=farthest(0),y=farthest(x);
	//printf("diameter: %d..%d\n",x,y);
	precalc(0,x);
	precalc(1,y);
}

int findlca(int z,int node,int nleaf) {
	for(int k=MAXLOGN;k>=0;--k) if(fstleafidx[z][p[z][node][k]]>=nleaf) node=p[z][node][k];
	return p[z][node][0];
}

int calc(int z,int fixed,int npath) {
	int nleaf=2*npath-1; if(nleaf>leafcnt[z]) nleaf=leafcnt[z];
	if(fstleafidx[z][fixed]<nleaf) {
		//printf("q %d %d (%d) -> ok -> %d\n",fixed,npath,z,bestsum[z][nleaf]);
		return bestsum[z][nleaf];
	} else {
		int fixedleaf=leaf[z][fstleafidx[z][fixed]];
		int lastlca=findlca(z,fixed,nleaf);
		int remleaf=leaf[z][fstleafidx[z][lastlca]];
		int remval=d[z][remleaf]-d[z][lastlca];
		int addval=bestsum[z][nleaf]-bestsum[z][nleaf-1];
		int ret=bestsum[z][nleaf-1];
		ret+=d[z][fixedleaf];
		ret-=d[z][lastlca];
		if(addval>remval) ret+=addval-remval;
		//printf("q %d %d (%d) -> fixed=%d, lca=%d, rem=%d, remval=%d, addval=%d -> %d\n",fixed,npath,z,fixedleaf,lastlca,remleaf,remval,addval,ret);
		return ret;
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d%d",&a,&b,&len[i]); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	if(n>=2) precalc();
	int ret=0;
	REP(qi,nq) {
		int fixed,npath; scanf("%d%d",&fixed,&npath); fixed=(fixed+ret-1)%n; npath=(npath+ret-1)%n+1;
		ret=0;
		if(n>=2) REP(i,2) { int cur=calc(i,fixed,npath); if(cur>ret) ret=cur; }
		printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}