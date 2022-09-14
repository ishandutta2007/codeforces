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
const int MAXM=MAXN-1;
const int MAXQ=100000;
const int MAXLOGN=16;
const int MAXSEG=1<<18;

int n,nq;
int pval[MAXN];
int fst[MAXN],nxt[2*MAXM],to[2*MAXM],len[MAXM];

int qa[MAXQ],qb[MAXQ],qlen[MAXQ];
int ret[MAXQ];

int evt[MAXM+MAXQ],nevt;
bool evtcmp(const int &a,const int &b) {
	int alen=a>0?len[a-1]:qlen[-a-1];
	int blen=b>0?len[b-1]:qlen[-b-1];
	if(alen!=blen) return alen<blen;
	if((a>0)!=(b>0)) return a<0;
	if(a>0) return a<b; else return -a<-b;
}

int sz[MAXN],d[MAXN];
int par[MAXN];
int up[MAXN][MAXLOGN+1];
int heavy[MAXN];
int hroot[MAXN];
int sidx[MAXN];

void dfs(int at) {
	up[at][0]=par[at]!=-1?par[at]:at; FORE(i,1,MAXLOGN) up[at][i]=up[up[at][i-1]][i-1];
	sz[at]=1;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par[at]) continue;
		par[to[x]]=at; d[to[x]]=d[at]+1;
		dfs(to[x]);
		sz[at]+=sz[to[x]];
	}
	heavy[at]=-1;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par[at]) continue;
		if(2*sz[to[x]]>=sz[at]) heavy[at]=to[x];
	}
}

int lca(int a,int b) {
	if(d[b]>d[a]) swap(a,b);
	for(int k=MAXLOGN;k>=0;--k) if(d[a]-(1<<k)>=d[b]) a=up[a][k];
	for(int k=MAXLOGN;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return a==b?a:par[a];
}

typedef struct Res { int pre,suf,sum; bool all; } Res;
Res rev(const Res &a) { Res b; b.pre=a.suf,b.suf=a.pre,b.sum=a.sum,b.all=a.all; return b; }
Res combine(const Res &a,const Res &b) { Res c; c.pre=a.pre+(a.all?b.pre:0),c.suf=b.suf+(b.all?a.suf:0),c.sum=a.sum+b.sum+(!a.all&!b.all?pval[a.suf+b.pre]:0),c.all=a.all&b.all; return c; }

Res single[MAXN];
Res seg[MAXSEG]; int nseg;

void dfs2(int at) {
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par[at]||to[x]==heavy[at]) continue;
		dfs2(to[x]);
	}
	if(par[at]!=-1) {
		single[at].pre=single[at].suf=1,single[at].sum=0,single[at].all=true;
	}
	if(hroot[at]==-1) hroot[at]=at;
	if(heavy[at]!=-1) {
		hroot[heavy[at]]=hroot[at];
		dfs2(heavy[at]);
		sidx[at]=nseg++;
	}
}

void sinit(int x,int l,int r) {
	if(l==r) { seg[x].pre=seg[x].suf=1,seg[x].sum=0,seg[x].all=true; return; }
	int m=l+(r-l)/2;
	sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
	seg[x]=combine(seg[2*x+1],seg[2*x+2]);
	//printf("init %d..%d = (%d,%d,%d,%d)\n",l,r,seg[x].pre,seg[x].suf,seg[x].sum,seg[x].all);
}

Res sget(int x,int l,int r,int L,int R) {
	//printf("\tsget(%d..%d)\n",l,r);
	if(L<=l&&r<=R) return seg[x];
	int m=l+(r-l)/2;
	if(R<=m) return sget(2*x+1,l,m,L,R);
	if(m+1<=L) return sget(2*x+2,m+1,r,L,R);
	return combine(sget(2*x+1,l,m,L,R),sget(2*x+2,m+1,r,L,R));
}

void sset(int x,int l,int r,int IDX,Res VAL) {
	if(l==IDX&&IDX==r) { /*printf("setting %d to (%d,%d,%d,%d)\n",IDX,VAL.pre,VAL.suf,VAL.sum,VAL.all?1:0);*/ seg[x]=VAL; return; }
	int m=l+(r-l)/2;
	if(IDX<=m) sset(2*x+1,l,m,IDX,VAL); else sset(2*x+2,m+1,r,IDX,VAL);
	seg[x]=combine(seg[2*x+1],seg[2*x+2]);
	//printf("%d..%d = (%d,%d,%d,%d)\n",l,r,seg[x].pre,seg[x].suf,seg[x].sum,seg[x].all);
}

Res calcup(int a,int b) {
	Res ret; ret.pre=0,ret.suf=0,ret.sum=0,ret.all=true;
	while(a!=b) {
		assert(par[a]!=-1);
		if(hroot[a]==a) {
			//printf("single (%d,%d,%d,%d)\n",single[a].pre,single[a].suf,single[a].sum,single[a].all?1:0);
			ret=combine(ret,single[a]); a=par[a];
		} else {
			int na=d[hroot[a]]>=d[b]?hroot[a]:b;
			assert(sidx[par[a]]!=-1&&sidx[na]!=-1);
			Res cur=sget(0,0,nseg-1,sidx[par[a]],sidx[na]);
			//printf("path %d..%d (%d..%d) -> (%d,%d,%d,%d)\n",par[a],na,sidx[par[a]],sidx[na],cur.pre,cur.suf,cur.sum,cur.all?1:0);
			ret=combine(ret,cur); a=na;
		}
	}
	return ret;
}

int calcpath(int a,int b) {
	int c=lca(a,b);
	Res ra=calcup(a,c),rb=calcup(b,c);
	Res ret=combine(ra,rev(rb));
	int res=ret.all?pval[ret.pre]:pval[ret.pre]+ret.sum+pval[ret.suf];
	//printf("-> %d -> (%d,%d,%d,%d) / (%d,%d,%d,%d) -> (%d,%d,%d,%d) -> %d\n",c,ra.pre,ra.suf,ra.sum,ra.all?1:0,rb.pre,rb.suf,rb.sum,rb.all?1:0,ret.pre,ret.suf,ret.sum,ret.all?1:0,res);
	return res;
}


void run() {
	scanf("%d%d",&n,&nq);
	pval[0]=0; FOR(i,1,n) scanf("%d",&pval[i]);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d%d",&a,&b,&len[i]); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	REP(i,nq) { scanf("%d%d%d",&qa[i],&qb[i],&qlen[i]); --qa[i],--qb[i]; }

	par[0]=-1; d[0]=0; dfs(0);
	nseg=0; REP(i,n) sidx[i]=-1,hroot[i]=-1; dfs2(0); assert(nseg<=MAXSEG/2);
	sinit(0,0,nseg-1);

	nevt=0; REP(i,n-1) evt[nevt++]=+(i+1); REP(i,nq) evt[nevt++]=-(i+1); sort(evt,evt+nevt,evtcmp);
	REP(i,nevt) {
		if(evt[i]>0) {
			int ei=evt[i]-1;
			int a=par[to[2*ei+0]]==to[2*ei+1]?to[2*ei+0]:to[2*ei+1],b=par[a];
			//if(n>1000) printf("\ndisabling %d->%d\n",a,b);
			single[a].pre=single[a].suf=single[a].sum=0,single[a].all=false;
			if(heavy[b]==a) sset(0,0,nseg-1,sidx[b],single[a]);
		}
		if(evt[i]<0) {
			int qi=-evt[i]-1;
			//if(n>1000) printf("\nquerying %d: %d->%d (%d)\n",qi,qa[qi],qb[qi],qlen[qi]);
			ret[qi]=calcpath(qa[qi],qb[qi]);
		}
	}
	REP(i,nq) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}