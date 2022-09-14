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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

struct mycmp {
	int *v;
	mycmp(int *v):v(v) {}
	bool operator()(const int &p,const int &q) { if(v[p]!=v[q]) return v[p]<v[q]; return p<q; }
};

typedef struct {
	int n;
	int prv[200000]; // idx->idx
	int nxt[200000]; // idx->idx
	int cnt[200000]; // idx->int

	int fm[200000]; // idx->tidx
	int to[200000]; // idx->tidx

	int *v; // nidx->val
	int nt;
	int t[100000]; // tidx->nidx
	int r[100000]; // nidx->idx

	int gfst; // idx
	int gnxt[200000]; // idx->idx
	int gprv[200000]; // idx->idx

	void init() {
		n=0; gfst=-1;
		sort(t,t+nt,mycmp(v));
		REP(tidx,nt) {
			if(n!=0&&v[t[tidx]]>=v[t[fm[n-1]]]+2) {
				nxt[n-1]=n; prv[n]=n-1; nxt[n]=-1; cnt[n]=0; fm[n]=to[n]=-1; addgap(n); ++n;
				nxt[n-1]=n; prv[n]=n-1; nxt[n]=-1; cnt[n]=1; fm[n]=to[n]=tidx; r[t[tidx]]=n; ++n; 
			} else if(n==0||v[t[tidx]]==v[t[fm[n-1]]]+1) {
				if(n!=0) nxt[n-1]=n; prv[n]=n-1; nxt[n]=-1; cnt[n]=1; fm[n]=to[n]=tidx; r[t[tidx]]=n; ++n;
			} else {
				++cnt[n-1]; to[n-1]=tidx; r[t[tidx]]=n-1; 
			}
		}
	}

	void print() {
		printf("nt=%d\n",nt);
		REP(i,nt) if(r[t[i]]!=-1) printf("%d->%d->%d = %d\n",i,t[i],r[t[i]],v[t[i]]);
		printf("n=%d\n",n);
		int fst=0; while(fst<n&&cnt[fst]==0) ++fst;
		if(fst<n) for(int at=fst;at!=-1;at=nxt[at]) printf("%d: (%d)-%d-(%d) %d..%d\n",at,prv[at],cnt[at],nxt[at],fm[at],to[at]); else printf("nothing left\n");
		printf("gaps:"); for(int i=gfst;i!=-1;i=gnxt[i]) printf(" %d",i); puts("");
	}

	void addgap(int idx) { gprv[idx]=-1; gnxt[idx]=gfst; if(gnxt[idx]!=-1) gprv[gnxt[idx]]=idx; gfst=idx; }
	void remgap(int idx) { if(gprv[idx]!=-1) gnxt[gprv[idx]]=gnxt[idx]; else gfst=gnxt[idx]; if(gnxt[idx]!=-1) gprv[gnxt[idx]]=gprv[idx]; }

	void dec(int idx) {
		if(--cnt[idx]>0) return;
		if(prv[idx]==-1&&nxt[idx]==-1) return;
		if(prv[idx]==-1&&cnt[nxt[idx]]==0) { remgap(nxt[idx]); prv[nxt[nxt[idx]]]=-1; return; }
		if(prv[idx]==-1) { prv[nxt[idx]]=-1; return; }
		if(nxt[idx]==-1&&cnt[prv[idx]]==0) { remgap(prv[idx]); nxt[prv[prv[idx]]]=-1; return; }
		if(nxt[idx]==-1) { nxt[prv[idx]]=-1; return; }
		bool merged=false;
		if(cnt[prv[idx]]==0) { if(merged) remgap(idx); nxt[prv[idx]]=nxt[idx]; prv[nxt[idx]]=prv[idx]; idx=prv[idx]; merged=true; }
		if(cnt[nxt[idx]]==0) { if(merged) remgap(idx); prv[nxt[idx]]=prv[idx]; nxt[prv[idx]]=nxt[idx]; idx=nxt[idx]; merged=true; }
		if(!merged) addgap(idx);
	}

	void rem(int nidx) {
		dec(r[nidx]); r[nidx]=-1;
	}

	int smallside(int idx) {
		int l=prv[idx],lcnt=cnt[l],r=nxt[idx],rcnt=cnt[r];
		while(true) {
			if(lcnt>=rcnt) { r=nxt[r]; if(r==-1||cnt[r]==0) return +1; rcnt+=cnt[r]; }
					  else { l=prv[l]; if(l==-1||cnt[l]==0) return -1; lcnt+=cnt[l]; }
		}
	}
} LST;

typedef struct {
	int ncomp;
	int fst[100000]; // cidx->nidx
	int comp[100000]; // nidx->cidx
	int nxt[100000]; // nidx->nidx
	int prv[100000]; // nidx->nidx
	int cnt[100000],totcnt;

	void set(int nidx,int cidx) {
		//if(nidx==99999||nidx==1972) printf("setting %d to %d\n",nidx,cidx);
		if(comp[nidx]!=-1) {
			--cnt[comp[nidx]]; --totcnt; if(cnt[comp[nidx]]==0) { printf("error: empty comp\n"); exit(0); }
			if(prv[nidx]!=-1) nxt[prv[nidx]]=nxt[nidx]; else fst[comp[nidx]]=nxt[nidx];
			if(nxt[nidx]!=-1) prv[nxt[nidx]]=prv[nidx];
		}
		comp[nidx]=cidx;
		if(comp[nidx]!=-1) {
			++cnt[comp[nidx]]; ++totcnt;
			prv[nidx]=-1; nxt[nidx]=fst[cidx]; if(nxt[nidx]!=-1) prv[nxt[nidx]]=nidx; fst[cidx]=nidx;
		}
	}
} COMPS;

int n;
int x[100000],y[100000];
COMPS comps;

LST xlst,ylst;
int ncur,cur[100000];
bool debug;

void process(const LST &lst,int idx) {
	FORE(tidx,lst.fm[idx],lst.to[idx]) {
		int nidx=lst.t[tidx]; if(lst.r[nidx]==-1) continue;
//		if(debug) printf("removing %d: (%d,%d) [x:%d,y:%d]\n",nidx,x[nidx],y[nidx],xlst.r[nidx],ylst.r[nidx]);
		comps.set(nidx,comps.ncomp-1);
		xlst.rem(nidx);
		ylst.rem(nidx);
	}
}

int q[100000],qhead,qtail;

void process(LST &lst) {
	assert(lst.gfst!=-1);
	++comps.ncomp;
	int side=lst.smallside(lst.gfst);
	qhead=qtail=0;
	if(side==-1) for(int idx=lst.prv[lst.gfst];idx!=-1&&lst.cnt[idx]!=0;idx=lst.prv[idx]) q[qhead++]=idx;
	if(side==+1) for(int idx=lst.nxt[lst.gfst];idx!=-1&&lst.cnt[idx]!=0;idx=lst.nxt[idx]) q[qhead++]=idx;
	while(qtail<qhead) process(lst,q[qtail++]);
}

void process(int cidx) {
	ncur=0; for(int nidx=comps.fst[cidx];nidx!=-1;nidx=comps.nxt[nidx]) cur[ncur++]=nidx;
	xlst.nt=ylst.nt=ncur; xlst.v=x; ylst.v=y; REP(i,ncur) xlst.t[i]=ylst.t[i]=cur[i]; xlst.init(); ylst.init();
//	if(debug) { sort(cur,cur+ncur); FOR(i,1,ncur) if(cur[i]==cur[i-1]) printf("!cur[%d]=cur[%d]=%d\n",i,i-1,cur[i]); }

	int tmp=0;
	while(true) {
//		if(debug) { printf("x\n"); xlst.print(); printf("y\n"); ylst.print(); puts(""); }
		if(xlst.gfst!=-1) process(xlst);
		else if(ylst.gfst!=-1) process(ylst);
		else break;
	}
}

int getrand(int l,int r) {
	int ret=(rand()*RAND_MAX+rand())*RAND_MAX+rand(); if(ret<0) ret=-ret;
	return l+ret%(r-l+1);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&x[i],&y[i]);

//	n=100000; int tmp=time(NULL); tmp=1416309648; srand(tmp); printf("%d\n",tmp);
//	REP(i,n) x[i]=getrand(-1000000000,+1000000000),y[i]=getrand(-1000000000,+1000000000);

	memset(comps.comp,-1,sizeof(comps.comp));
	memset(comps.fst,-1,sizeof(comps.fst));
	comps.ncomp=1; REP(i,n) comps.set(i,0);
	REP(i,comps.ncomp) process(i);
	printf("%d\n",comps.ncomp);
}

int main() {
	run();
	return 0;
}