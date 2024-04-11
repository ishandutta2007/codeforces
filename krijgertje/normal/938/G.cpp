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
const int MAXM=200000;
const int MAXQ=200000;
const int MAXE=MAXM+MAXQ;
const int MAXSOLVEDEP=19;
const int NBITS=30;

int n,m,nq;
int ea[MAXE],eb[MAXE],ed[MAXE],es[MAXE],et[MAXE],ne;
int qkind[MAXQ],qx[MAXQ],qy[MAXQ],qd[MAXQ],qe[MAXQ],qans[MAXQ];


int nodecnt[MAXSOLVEDEP+1];
int nodelst[MAXSOLVEDEP+1][MAXN];
int nodeval[MAXSOLVEDEP+1][MAXN];
int compcnt[MAXSOLVEDEP+1];
int nodecomp[MAXSOLVEDEP+1][MAXN];
int edgecnt[MAXSOLVEDEP+1];
int edgelst[MAXSOLVEDEP+1][MAXE];
int valscnt[MAXSOLVEDEP+1];
int valslst[MAXSOLVEDEP+1][NBITS];

bool keepnode[MAXN];
int rows[NBITS+MAXE],nrows;
int ufpar[MAXN],ufsz[MAXN],ufd[MAXN];
int compmp[MAXN];
pair<int,int> uffind(int x) { if(ufpar[x]==x) return MP(x,0); pair<int,int> cur=uffind(ufpar[x]); ufpar[x]=cur.first; ufd[x]^=cur.second; return MP(ufpar[x],ufd[x]); }
int gaussjord() {
	//printf("gaussjord:"); REP(i,nrows) printf(" %d",rows[i]);
	int ret=0;
	for(int j=NBITS-1;j>=0;--j) {
		int idx=ret; while(idx<nrows&&(rows[idx]&(1<<j))==0) ++idx; if(idx>=nrows) continue; if(idx!=ret) swap(rows[idx],rows[ret]);
		FOR(i,ret+1,nrows) if(rows[i]&(1<<j)) rows[i]^=rows[ret];
		++ret;
	}
	//printf(" ->"); REP(i,ret) printf(" %d",rows[i]); puts("");
	return ret;
}
void compress(int sdep,int ql,int qr) {
	edgecnt[sdep]=0; nrows=0;
	REP(i,valscnt[sdep-1]) rows[nrows++]=valslst[sdep-1][i];
	REP(i,compcnt[sdep-1]) ufpar[i]=i,ufsz[i]=1,ufd[i]=0;
	REP(i,edgecnt[sdep-1]) {
		int ei=edgelst[sdep-1][i];
		if(es[ei]<=ql&&qr<=et[ei]) { // always
			pair<int,int> a=uffind(nodecomp[sdep-1][ea[ei]]); a.second^=nodeval[sdep-1][ea[ei]];
			pair<int,int> b=uffind(nodecomp[sdep-1][eb[ei]]); b.second^=nodeval[sdep-1][eb[ei]];
			int c=ed[ei];
			//printf("%d-%d -> (%d,%d) (%d,%d) %d\n",ea[ei]+1,eb[ei]+1,a.first,a.second,b.first,b.second,c);
			if(a.first==b.first) {
				rows[nrows++]=a.second^b.second^c;
			} else {
				if(ufsz[a.first]<ufsz[b.first]) swap(a,b);
				ufpar[b.first]=a.first; ufsz[a.first]+=ufsz[b.first]; ufd[b.first]=a.second^b.second^c;
			}
		} else if(!(et[ei]<ql||es[ei]>qr)) { // sometimes
			edgelst[sdep][edgecnt[sdep]++]=ei;
		}
	}
	compcnt[sdep]=0; REP(i,compcnt[sdep-1]) if(ufpar[i]==i) compmp[i]=compcnt[sdep]++; else compmp[i]=-1;
	valscnt[sdep]=gaussjord(); REP(i,valscnt[sdep]) valslst[sdep][i]=rows[i];

	REP(i,nodecnt[sdep-1]) { int at=nodelst[sdep-1][i]; keepnode[at]=false; }
	FORE(i,ql,qr) keepnode[qx[i]]=keepnode[qy[i]]=true;
	nodecnt[sdep]=0;
	REP(i,nodecnt[sdep-1]) {
		int at=nodelst[sdep-1][i]; if(!keepnode[at]) continue;
		nodelst[sdep][nodecnt[sdep]++]=at;
		pair<int,int> cur=uffind(nodecomp[sdep-1][at]); nodecomp[sdep][at]=compmp[cur.first]; nodeval[sdep][at]=nodeval[sdep-1][at]^cur.second;
	}
}
void print(int sdep,int ql,int qr) {
	printf("solving(%d..%d):\n",ql,qr);
	REP(i,nodecnt[sdep]) { int at=nodelst[sdep][i]; printf("%d: val=%d comp=%d\n",at+1,nodeval[sdep][at],nodecomp[sdep][at]); }
	REP(i,edgecnt[sdep]) { int ei=edgelst[sdep][i]; printf("%d-%d (%d): %d..%d\n",ea[ei]+1,eb[ei]+1,ed[ei],es[ei],et[ei]); }
}
int calc(int sdep,int val) {
	//printf("calc(%d):",val); REP(i,valscnt[sdep]) printf(" %d",valslst[sdep][i]); puts("");
	int ret=val; REP(i,valscnt[sdep]) { int cur=ret^valslst[sdep][i]; if(cur<ret) ret=cur; } return ret;
}
void solve(int sdep,int ql,int qr) {
	compress(sdep,ql,qr);
	//print(sdep,ql,qr);
	if(ql==qr) {
		int qi=ql;
		if(qkind[qi]==3) {
			assert(nodecomp[sdep][qx[qi]]==nodecomp[sdep][qy[qi]]);
			qans[qi]=calc(sdep,nodeval[sdep][qx[qi]]^nodeval[sdep][qy[qi]]);
		}
	} else {
		int qm=ql+(qr-ql)/2;
		solve(sdep+1,ql,qm);
		solve(sdep+1,qm+1,qr);
	}
}

map<pair<int,int>,int> emp;
void precalc() {
	emp.clear(); REP(i,ne) { int a=ea[i],b=eb[i]; if(a>b) swap(a,b); emp[MP(a,b)]=i; es[i]=0,et[i]=nq-1; }
	REP(i,nq) {
		if(qkind[i]==1) { int a=qx[i],b=qy[i]; if(a>b) swap(a,b); qe[i]=ne++; emp[MP(a,b)]=qe[i]; ea[qe[i]]=a,eb[qe[i]]=b,ed[qe[i]]=qd[i]; es[qe[i]]=i,et[qe[i]]=nq-1; }
		if(qkind[i]==2) { int a=qx[i],b=qy[i]; if(a>b) swap(a,b); qe[i]=emp[MP(a,b)]; emp.erase(MP(a,b)); et[qe[i]]=i; }
		if(qkind[i]==3) qans[i]=-1;
	}
	nodecnt[0]=compcnt[0]=n; REP(i,n) nodelst[0][i]=i,nodeval[0][i]=0,nodecomp[0][i]=i;
	edgecnt[0]=ne; REP(i,ne) edgelst[0][i]=i;
	valscnt[0]=0;
}

void run() {
	scanf("%d%d",&n,&m);
	ne=m; REP(i,m) scanf("%d%d%d",&ea[i],&eb[i],&ed[i]),--ea[i],--eb[i];
	scanf("%d",&nq);
	REP(i,nq) { scanf("%d%d%d",&qkind[i],&qx[i],&qy[i]); --qx[i],--qy[i]; if(qkind[i]==1) scanf("%d",&qd[i]); }

	precalc();
	//print(0,-1,-1);
	solve(1,0,nq-1);
	REP(i,nq) if(qkind[i]==3) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}