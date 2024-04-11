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

const int MAXN=1<<19; // round up to power of 2
const int MAXM=1<<19; // round up to power of 2
const int MAXQ=1<<19; // round up to power of 2
const int MAXQLOG=19;
const int MAXCSUM=2*MAXQ+8*MAXQ;
const int MAXCSINGLE=2*MAXQ;
const int MAXQSUM=2*MAXQ;
const int MAXESUM=MAXM+MAXQ;

int cs[MAXQLOG+2],qs[MAXQLOG+2],es[MAXQLOG+2]; // start of components/queries/edges for given depth

int cmatch[MAXCSUM]; // connected node of same color (in same depth)
int cnxt[MAXCSUM]; // colored node id in next depth (-1=needed, -2=unneeded)

int qe[MAXQSUM],qa[MAXQSUM],qb[MAXQSUM]; // edgeid and colored nodes for each query (in same depth)
int qnxt[MAXQSUM]; // query in next depth

int ea[MAXESUM],eb[MAXESUM]; // start+end of colored edge nodes (in same depth)
int enxt[MAXESUM]; // id of edge in next depth (-1==unprocessed, -2==nonexistant)

int mm; int chead[MAXCSUM]; int eenxt[MAXCSINGLE]; int eeto[MAXCSINGLE];
int cq[MAXCSINGLE],cqhead,cqtail;

void indent(int d) { REP(i,d) printf("  "); }
void prepare(int l,int r,int L,int R,int d) { // prepare processing [l..r) with edges from [L..R)
	es[d+2]=es[d+1];
	FOR(ei,es[d],es[d+1]) enxt[ei]=-1;
	FOR(qi,l,r) if(enxt[qe[qi]]==-1) enxt[qe[qi]]=es[d+2]++;

	mm=0;
	FOR(ci,cs[d],cs[d+1]) chead[ci]=-1;
	FOR(ci,cs[d],cs[d+1]) if(cmatch[ci]!=-1) { eenxt[mm]=chead[ci]; chead[ci]=mm; eeto[mm]=cmatch[ci]; ++mm; }
	FOR(qi,L,R) if(enxt[qe[qi]]==-1&&ea[qe[qi]]!=-1&&eb[qe[qi]]!=-1) {
		enxt[qe[qi]]=-2; int a=ea[qe[qi]],b=eb[qe[qi]];
		eenxt[mm]=chead[a]; chead[a]=mm; eeto[mm]=b; ++mm;
		eenxt[mm]=chead[b]; chead[b]=mm; eeto[mm]=a; ++mm;
	}

	//indent(d); printf("-ee"); FOR(ci,cs[d],cs[d+1]) for(int x=chead[ci];x!=-1;x=eenxt[x]) printf(" %d-%d",ci-cs[d],eeto[x]-cs[d]); puts("");

	cs[d+2]=cs[d+1];
	FOR(ci,cs[d],cs[d+1]) cnxt[ci]=-2;
	FOR(qi,l,r) if(ea[qe[qi]]!=-1) cnxt[ea[qe[qi]]]=-1;
	FOR(qi,l,r) if(eb[qe[qi]]!=-1) cnxt[eb[qe[qi]]]=-1;
	FOR(qi,l,r) cnxt[qa[qi]]=cnxt[qb[qi]]=-1;
	FOR(ci,cs[d],cs[d+1]) if(cnxt[ci]==-1) {
		cnxt[ci]=cs[d+2]++; cmatch[cnxt[ci]]=-1;
		cqhead=cqtail=0; cq[cqhead++]=ci;
		while(cqtail<cqhead) {
			int at=cq[cqtail++];
			for(int x=chead[at];x!=-1;x=eenxt[x]) if(cnxt[eeto[x]]==-1||cnxt[eeto[x]]==-2) {
				if(cmatch[cnxt[at]]==-1) { cmatch[cnxt[at]]=cs[d+2]++; cmatch[cmatch[cnxt[at]]]=cnxt[at]; }
				cnxt[eeto[x]]=cmatch[cnxt[at]]; cq[cqhead++]=eeto[x];
			}
		}
	}
	
	//indent(d); printf("-cc"); FOR(ci,cs[d],cs[d+1]) printf(" %d",cnxt[ci]-cs[d+1]); puts("");

	FOR(qi,l,r) ea[enxt[qe[qi]]]=ea[qe[qi]]==-1?-1:cnxt[ea[qe[qi]]];
	FOR(qi,l,r) eb[enxt[qe[qi]]]=eb[qe[qi]]==-1?-1:cnxt[eb[qe[qi]]];

	qs[d+2]=qs[d+1];
	FOR(qi,l,r) qnxt[qi]=qs[d+2]++,qe[qnxt[qi]]=enxt[qe[qi]],qa[qnxt[qi]]=cnxt[qa[qi]],qb[qnxt[qi]]=cnxt[qb[qi]];
}
void propagate(int l,int r,int d) {
	FOR(qi,l,r) if(ea[enxt[qe[qi]]]==qa[qnxt[qi]]&&eb[enxt[qe[qi]]]==qb[qnxt[qi]]) ea[qe[qi]]=qa[qi],eb[qe[qi]]=qb[qi];
	//indent(d); printf("-ne:"); FOR(ei,es[d],es[d+1]) if(ea[ei]!=-1&&eb[ei]!=-1) printf(" %d-%d",ea[ei]-cs[d],eb[ei]-cs[d]); else printf(" X"); puts("");
}


void go(int d) {
	//indent(d); printf("c:"); FOR(ci,cs[d],cs[d+1]) if(cmatch[ci]!=-1) printf(" %d",cmatch[ci]-cs[d]); else printf(" -"); puts("");
	//indent(d); printf("q: "); FOR(qi,qs[d],qs[d+1]) printf("(%d:%d-%d)",qe[qi]-es[d],qa[qi]-cs[d],qb[qi]-cs[d]); puts("");
	//indent(d); printf("e:"); FOR(ei,es[d],es[d+1]) if(ea[ei]!=-1&&eb[ei]!=-1) printf(" %d-%d",ea[ei]-cs[d],eb[ei]-cs[d]); else printf(" X"); puts("");

	if(qs[d]+1==qs[d+1]) {
		if(qa[qs[d]]!=qb[qs[d]]) {
			printf("YES\n");
			ea[qe[qs[d]]]=qa[qs[d]],eb[qe[qs[d]]]=qb[qs[d]];
		} else {
			printf("NO\n");
		}
	} else {
		int m=qs[d]+(qs[d+1]-qs[d])/2;
		prepare(qs[d],m,m,qs[d+1],d);
		go(d+1);
		propagate(qs[d],m,d);
		prepare(m,qs[d+1],qs[d],m,d);
		go(d+1);
		propagate(m,qs[d+1],d);
	}
}


int n,m,ncol,nq;

int cchead[MAXN];
int ccnxt[2*MAXQ];
int xs[MAXN+1];
int xc[2*MAXQ],nx;
int getx(int i,int c) {	int l=xs[i],h=xs[i+1]; /* [l,h) */ while(l+1<h) { int m=l+(h-l)/2; if(c<xc[m]) h=m; else l=m; } assert(xc[l]==c); return l; }

int a[MAXM],b[MAXM];
int qqe[MAXQ],qqc[MAXQ];

void run() {
	scanf("%d%d%d%d",&n,&m,&ncol,&nq);
	REP(i,m) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
	REP(i,nq) scanf("%d%d",&qqe[i],&qqc[i]),--qqe[i],--qqc[i];

	REP(i,n) cchead[i]=-1;
	REP(i,nq) {
		ccnxt[2*i+0]=cchead[a[qqe[i]]]; cchead[a[qqe[i]]]=2*i+0;
		ccnxt[2*i+1]=cchead[b[qqe[i]]]; cchead[b[qqe[i]]]=2*i+1;
	}
	nx=0;
	REP(i,n) {
		xs[i]=nx;
		for(int z=cchead[i];z!=-1;z=ccnxt[z]) xc[nx++]=qqc[z>>1];
		sort(xc+xs[i],xc+nx);
		nx=unique(xc+xs[i],xc+nx)-xc;
	}
	xs[n]=nx;

	cs[0]=0; cs[1]=nx; REP(i,nx) cmatch[i]=-1;
	es[0]=0; es[1]=m; REP(i,m) ea[i]=eb[i]=-1;
	qs[0]=0; qs[1]=nq; REP(i,nq) qe[i]=qqe[i],qa[i]=getx(a[qqe[i]],qqc[i]),qb[i]=getx(b[qqe[i]],qqc[i]);

	go(0);
}


int main() {
	run();
	return 0;
}