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

const int MAXN=50000;
const int MAXQ=5000;
const int MAXLG=19;
const int MAXNODE=2*(1+(MAXLG+1)*MAXN);

typedef struct Node {
	int c[2],mx;
} Node;

Node nodes[MAXNODE]; int nnodes,root[2];
int addnode() { nodes[nnodes].c[0]=nodes[nnodes].c[1]=-1,nodes[nnodes].mx=INT_MIN; return nnodes++; }
void clear() { /*printf("clear\n");*/ nnodes=0; root[0]=addnode(); root[1]=addnode(); }
void add(int val,int key,int type) {
	//printf("add(%x,%d,%d)\n",val,key,type);
	int at=root[type];
	if(key>nodes[at].mx) nodes[at].mx=key;
	for(int k=MAXLG;k>=0;--k) {
		int x=(val>>k)&1;
		if(nodes[at].c[x]==-1) nodes[at].c[x]=addnode();
		at=nodes[at].c[x];
		if(key>nodes[at].mx) nodes[at].mx=key;
	}
}
int find(int val,int mn,int type) {
	//printf("find(%x,%d,%d)",val,mn,type); fflush(stdout);
	int at=root[type];
	if(nodes[at].mx<mn) { /*printf("->X\n");*/ return -1; }
	int ret=val;
	for(int k=MAXLG;k>=0;--k) {
		int x=(val>>k)&1; bool found=false;
		REP(yy,2) {
			int y=x^yy^1;
			if(nodes[at].c[y]!=-1&&nodes[nodes[at].c[y]].mx>=mn) { ret^=y<<k; at=nodes[at].c[y]; found=true; break; }
		}
		assert(found);
	}
	//printf("->%d\n",ret);
	return ret;
}

typedef struct Q { int l,r,idx,lb; } Q;
bool operator<(const Q &a,const Q &b) { if(a.lb!=b.lb) return a.lb<b.lb; if(a.r!=b.r) return a.r<b.r; return a.idx<b.idx; }
int n,nq,BSZ;
int val[MAXN];
Q q[MAXQ];
int ret[MAXQ];

int calc(int x) { switch(x%4) { case 0: return x; case 1: return 1; case 2: return x+1; case 3: return 0; } assert(false); return -1; }
void sol(int i,int res) { if(res>ret[q[i].idx]) ret[q[i].idx]=res; }
void solve(int L,int H) {
	clear();
	int nxt=(q[L].lb+1)*BSZ,at=nxt,cur=-1,now;
	FOR(i,L,H) {
		while(at<q[i].r) {
			add(calc(val[at]),val[at],0);
			now=find(calc(val[at]-1),val[at],0); if(now>cur) cur=now;
			add(calc(val[at]-1),-val[at],1);
			now=find(calc(val[at]),-val[at],1); if(now>cur) cur=now;
			++at;
		}
		sol(i,cur);
		FOR(j,q[i].l,min(nxt,q[i].r)) {
			sol(i,find(calc(val[j]-1),val[j],0));
			sol(i,find(calc(val[j]),-val[j],1));
		}
	}
	FOR(i,L,H) {
		clear();
		FOR(j,q[i].l,min(nxt,q[i].r)) {
			add(calc(val[j]),val[j],0);
			sol(i,find(calc(val[j]-1),val[j],0));
			add(calc(val[j]-1),-val[j],1);
			sol(i,find(calc(val[j]),-val[j],1));
		}
	}
}

void run() {
	scanf("%d%d",&n,&nq); BSZ=(int)ceil(sqrt(1/3.0*n*n/nq)); //fprintf(stderr,"BSZ: %d\n",BSZ);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,nq) scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,q[i].idx=i,q[i].lb=q[i].l/BSZ,ret[i]=-1; sort(q,q+nq);

	for(int at=0,to=0;at<nq;at=to) {
		while(to<nq&&q[to].lb==q[at].lb) ++to;
		solve(at,to);
	}
	REP(i,nq) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}