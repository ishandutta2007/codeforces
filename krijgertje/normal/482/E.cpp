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

typedef struct Tree {
	int n;
	int* par;
	int* fst;
	int* lst;
	int* nxt;
	int* prv;
	int* val;
	int* sz;
	ll* cnt;
	int* others;
	ll* outside;

	Tree(int n):n(n) {
		par=new int[n]; REP(i,n) par[i]=-1;
		val=new int[n];
		sz=new int[n];
		outside=new ll[n];
		cnt=new ll[n];
		others=new int[n];
		fst=new int[n]; REP(i,n) fst[i]=-1;
		lst=new int[n]; REP(i,n) lst[i]=-1;
		nxt=new int[n]; REP(i,n) nxt[i]=-1;
		prv=new int[n]; REP(i,n) fst[i]=-1;
	}

	void setPar(int v,int p) { assert(par[v]==-1); par[v]=p; nxt[v]=-1; prv[v]=lst[p]; lst[p]=v; if(prv[v]!=-1) nxt[prv[v]]=v; else fst[p]=v; }
	void clearPar(int v) { assert(par[v]!=-1); int p=par[v]; par[v]=-1; if(nxt[v]!=-1) prv[nxt[v]]=prv[v]; else lst[p]=prv[v]; if(prv[v]!=-1) nxt[prv[v]]=nxt[v]; else fst[p]=nxt[v]; prv[v]=nxt[v]=-1; }
	bool isdesc(int v,int p) { while(v!=-1&&v!=p) v=par[v]; return v==p; }

} Tree;

Tree *full,*small;

ll total;
void dfscalcsz(int at,int p) {
	full->sz[at]=1;
	for(int to=full->fst[at];to!=-1;to=full->nxt[to]) { dfscalcsz(to,at); full->sz[at]+=full->sz[to]; }
}
void dfscalcoutside(int at,int p) {
	full->cnt[at]=(ll)full->sz[at]*full->sz[at];
	full->others[at]=p==-1?0:full->sz[p]-full->sz[at];
	full->outside[at]=p==-1?0:full->outside[p]+(ll)full->val[p]*(full->sz[p]-full->sz[at]);
	for(int to=full->fst[at];to!=-1;to=full->nxt[to]) { dfscalcoutside(to,at); full->cnt[at]-=(ll)full->sz[to]*full->sz[to]; }
}


bool insmall[50000];
int smallid[50000];
bool dfsinsmall(int at) {
	int ret=0;
	for(int to=full->fst[at];to!=-1;to=full->nxt[to]) ret+=dfsinsmall(to)?1:0;
	if(ret>=2) insmall[at]=true;
	return insmall[at]||ret>=1;
}
void dfsinitsmall(int at,int p,int others,int &N) {
	if(insmall[at]) {
		int id=smallid[at]=N++;
		if(p!=-1) small->setPar(id,p);
		small->val[id]=full->val[at];
		small->sz[id]=full->sz[at];
		small->cnt[id]=full->cnt[at];
		small->others[id]=others;
		small->outside[id]=full->outside[at];
		for(int to=full->fst[at];to!=-1;to=full->nxt[to]) dfsinitsmall(to,id,full->sz[at]-full->sz[to],N);
	} else {
		for(int to=full->fst[at];to!=-1;to=full->nxt[to]) dfsinitsmall(to,p,others,N);
	}
}

void updatesmalltree(int at,ll delta) {
//	printf("updating smalltree(%d,%lld)\n",at,delta);
	small->outside[at]+=delta;
	for(int to=small->fst[at];to!=-1;to=small->nxt[to]) updatesmalltree(to,delta);
}
void updatesmallpath(int at,int from,int delta) {
	while(at!=-1) {
//		printf("updating smallpath(%d,%d,%d)\n",at,from,delta);
		small->sz[at]+=delta;
		small->cnt[at]+=(ll)2*delta*small->others[from];
		for(int to=small->fst[at];to!=-1;to=small->nxt[to]) if(to!=from) {
			small->others[to]+=delta;
			updatesmalltree(to,(ll)delta*small->val[at]);
		}
		from=at; at=small->par[at];
	}
}

int nq;
char qtype[50000]; int qa[50000],qb[50000];

void run() {
	int n; scanf("%d",&n);
	full=new Tree(n);
	FOR(i,1,n) { int p; scanf("%d",&p); --p; full->setPar(i,p); }
	REP(i,n) scanf("%d",&full->val[i]);

	scanf("%d",&nq);
	REP(i,nq) { scanf(" %c%d%d",&qtype[i],&qa[i],&qb[i]); if(qtype[i]=='P') --qa[i],--qb[i]; if(qtype[i]=='V') --qa[i]; }

	for(int a=0,b=min(nq,a+100);a<b;a=b,b=min(nq,a+100)) {
		dfscalcsz(0,-1);
		dfscalcoutside(0,-1);
		total=0; REP(i,full->n) total+=full->outside[i]+(ll)full->val[i]*full->sz[i];
		if(a==0) printf("%.9lf\n",1.0*total/full->n/full->n);
//		REP(i,n) printf("%d: par=%d, val=%d, sz=%d, outside=%lld, cnt=%d, others=%d \n",i,full->par[i],full->val[i],full->sz[i],full->outside[i],full->cnt[i],full->others[i]);

		memset(insmall,false,sizeof(insmall));
		FOR(i,a,b) { if(qtype[i]=='P') insmall[qa[i]]=insmall[qb[i]]=true; if(qtype[i]=='V') insmall[qa[i]]=true; }
		dfsinsmall(0);
		int N=0; REP(i,full->n) if(insmall[i]) ++N;
		small=new Tree(N);
		memset(smallid,-1,sizeof(smallid)); N=0;
		dfsinitsmall(0,-1,0,N);

		FOR(i,a,b) {
//			printf("processing %c %d %d\n",qtype[i],qa[i],qb[i]);
			if(qtype[i]=='P') {
				int v=qa[i],u=qb[i];
				if(small->isdesc(smallid[u],smallid[v])) swap(u,v);
				full->clearPar(v); full->setPar(v,u);
				v=smallid[v]; u=smallid[u];
				total-=(ll)2*small->sz[v]*small->outside[v];
				updatesmallpath(small->par[v],v,-small->sz[v]);
				small->clearPar(v); small->setPar(v,u);
				small->others[v]=small->sz[u];
				updatesmallpath(small->par[v],v,+small->sz[v]);
				updatesmalltree(v,small->outside[u]+(ll)small->val[u]*(small->sz[u]-small->sz[v])-small->outside[v]);
				total+=(ll)2*small->sz[v]*small->outside[v];
			}
			if(qtype[i]=='V') {
				int v=qa[i],t=qb[i];
				full->val[v]=t;
				v=smallid[v];
				total+=(ll)(t-small->val[v])*small->cnt[v];
				for(int to=small->fst[v];to!=-1;to=small->nxt[to]) updatesmalltree(to,(ll)(t-small->val[v])*small->others[to]);
				small->val[v]=t;
			}
//			REP(i,n) if(insmall[i]) printf("%d(%d): par=(%d), val=%d, sz=%d, outside=%lld, cnt=%d, others=%d \n",i,smallid[i],small->par[smallid[i]],small->val[smallid[i]],small->sz[smallid[i]],small->outside[smallid[i]],small->cnt[smallid[i]],small->others[smallid[i]]);
			printf("%.9lf\n",1.0*total/full->n/full->n);
/*		dfscalcsz(0,-1);
		dfscalcoutside(0,-1);
		total=0; REP(i,full->n) total+=full->outside[i]+(ll)full->val[i]*full->sz[i];
			printf("%.9lf\n",1.0*total/full->n/full->n);
		REP(i,n) printf("%d: par=%d, val=%d, sz=%d, outside=%lld, cnt=%d, others=%d \n",i,full->par[i],full->val[i],full->sz[i],full->outside[i],full->cnt[i],full->others[i]);
			exit(0); */
		}
	}
}

int main() {
	run();
	return 0;
}