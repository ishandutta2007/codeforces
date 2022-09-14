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
const int MAXM=MAXN-1;
const int MAXQ=200000;
const ll MAXVAL=1000000000000000000LL;

int n,nq;
int head[MAXN],nxt[2*MAXM],to[2*MAXM]; ll val[MAXM];

int q[MAXN],qhead,qtail;
int up[MAXN],d[MAXN],sz[MAXN],heavy[MAXN]; // up:node->dedge, d:node->int, heavy:node->dedge
int sidx[MAXM],ns; // sidx: edge->sidx
int hroot[MAXN]; // hroot:node->node

ll s[2*MAXM];
ll mult(ll a,ll b) { if(a>MAXVAL/b) return MAXVAL+1; else return a*b; }
void sinit() {
	REP(i,n-1) if(sidx[i]!=-1) s[ns+sidx[i]]=val[i];
	for(int idx=ns-1;idx>=1;--idx) s[idx]=mult(s[idx<<1],s[idx<<1|1]);
}
void sset(int idx,ll val) {
	s[idx+=ns]=val;
	for(idx>>=1;idx!=0;idx>>=1) s[idx]=mult(s[idx<<1],s[idx<<1|1]);
}
ll sget(int lidx,int hidx) {
	ll ret=1;
	for(lidx+=ns,hidx+=ns+1;lidx<hidx;lidx>>=1,hidx>>=1) {
		if(lidx&1) ret=mult(ret,s[lidx++]);
		if(hidx&1) ret=mult(ret,s[--hidx]);
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) head[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d%I64d",&a,&b,&val[i]); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	//REP(i,n) { printf("%d:",i); for(int x=head[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }

	qhead=qtail=0; up[0]=-1,d[0]=0,q[qhead++]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=head[at];x!=-1;x=nxt[x]) if(x!=up[at]) up[to[x]]=x^1,d[to[x]]=d[at]+1,q[qhead++]=to[x];
	}
	REP(i,n) sz[i]=1,heavy[i]=-1; ns=0;
	REP(i,n-1) sidx[i]=-1;
	for(int i=n-1;i>=1;--i) sz[to[up[q[i]]]]+=sz[q[i]];
	for(int i=n-1;i>=1;--i) if(2*sz[q[i]]>=sz[to[up[q[i]]]]) heavy[to[up[q[i]]]]=up[q[i]]^1;
	REP(i,n) if(up[q[i]]==-1||heavy[to[up[q[i]]]]==-1||to[heavy[to[up[q[i]]]]]!=q[i]) { hroot[q[i]]=q[i]; for(int x=heavy[q[i]];x!=-1;x=heavy[to[x]]) hroot[to[x]]=q[i],sidx[x>>1]=ns++; }
	sinit();
	//REP(i,n) printf("%d: up=%d->%d(=%d), d=%d, sz=%d, hroot=%d, heavy=%d->%d\n",i,up[i]==-1?-1:up[i]>>1,up[i]==-1?-1:to[up[i]],up[i]==-1||heavy[to[up[i]]]==-1||to[heavy[to[up[i]]]]!=i?-1:sidx[heavy[to[up[i]]]>>1],d[i],sz[i],hroot[i],heavy[i]==-1?-1:heavy[i]>>1,heavy[i]==-1?-1:to[heavy[i]]);

	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int a,b; ll y; scanf("%d%d%I64d",&a,&b,&y); --a,--b;
			while(hroot[a]!=hroot[b]) {
				if(d[hroot[a]]<d[hroot[b]]) swap(a,b);
				if(a!=hroot[a]) y/=sget(sidx[heavy[hroot[a]]>>1],sidx[up[a]>>1]),a=hroot[a];
				y/=val[up[a]>>1],a=to[up[a]];
			}
			if(d[a]<d[b]) swap(a,b);
			if(a!=b) y/=sget(sidx[heavy[b]>>1],sidx[up[a]>>1]),a=b;
			printf("%I64d\n",y);
		}
		if(type==2) {
			int idx; ll nval; scanf("%d%I64d",&idx,&nval); --idx;
			val[idx]=nval; if(sidx[idx]!=-1) sset(sidx[idx],nval);
		}
	}
}

int main() {
	run();
	return 0;
}