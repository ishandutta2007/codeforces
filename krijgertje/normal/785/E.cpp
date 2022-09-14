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
const int MAXQ=50000;

int qa[MAXQ],qb[MAXQ];
ll ret[MAXQ];
int bit[MAXN+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void binc(int idx,int n) { ++idx; while(idx<=n) { ++bit[idx]; idx+=idx&-idx; } }

void go(int ql,int qr,vector<int> &p) {
	//printf("go(%d,%d)\n",ql,qr);
	//printf("\tp:"); REPSZ(i,p) printf(" %d",p[i]); puts("");
	//printf("\tq:"); FOR(j,ql,qr) printf(" (%d,%d)",qa[j],qb[j]); puts("");
	// determine fixed elements in p
	int n=SZ(p);
	vector<int> pos(n,-1); FOR(j,ql,qr) pos[qa[j]]=pos[qb[j]]=-2; int npos=0; REP(i,n) if(pos[i]!=-1) pos[i]=npos++;
	vector<int> val(n,-1); REP(i,n) if(pos[i]!=-1) val[p[i]]=-2; int nval=0; REP(i,n) if(val[i]!=-1) val[i]=nval++;
	//printf("\tpos:"); REP(i,n) printf(" %d",pos[i]); puts("");
	//printf("\tval:"); REP(i,n) printf(" %d",val[i]); puts("");
	// determine initial inversions in p using at least one fixed element
	ll ninitinv=0;
	REPE(i,n) bit[i]=0;
	for(int i=n-1;i>=0;--i) if(pos[i]==-1) { ninitinv+=bget(p[i]); binc(p[i],n); }
	REPE(i,n) bit[i]=0;
	for(int i=n-1;i>=0;--i) if(pos[i]==-1) ninitinv+=bget(p[i]); else binc(p[i],n);
	REPE(i,n) bit[i]=0;
	for(int i=n-1;i>=0;--i) if(pos[i]!=-1) ninitinv+=bget(p[i]); else binc(p[i],n);
	FOR(j,ql,qr) ret[j]+=ninitinv;
	//printf("\tninitinv: %d\n",ninitinv);
	// for each query determine how many inversions are created/removed with fixed elements
	vector<vector<pair<int,pair<int,int > > > > e(n);
	FOR(j,ql,qr) {
		int a=qa[j],b=qb[j];
		e[a].PB(MP(p[a],MP(j,-1)));
		e[a].PB(MP(p[b],MP(j,+1)));
		e[b].PB(MP(p[b],MP(j,-1)));
		e[b].PB(MP(p[a],MP(j,+1)));
		swap(p[a],p[b]);
	}
	vector<ll> dfixedinv(qr-ql+1,0);
	REPE(i,n) bit[i]=0;
	for(int i=n-1;i>=0;--i) {
		if(pos[i]==-1) { binc(p[i],n); continue; }
		REPSZ(k,e[i]) {
			int v=e[i][k].first,j=e[i][k].second.first,by=e[i][k].second.second;
			dfixedinv[j-ql]+=by*bget(v);
		}
	}
	REPE(i,n) bit[i]=0;
	REP(i,n) {
		if(pos[i]==-1) { binc(n-p[i]-1,n); continue; }
		REPSZ(k,e[i]) {
			int v=e[i][k].first,j=e[i][k].second.first,by=e[i][k].second.second;
			dfixedinv[j-ql]+=by*bget(n-v-1);
		}
	}
	//printf("\tdfixedinv:"); FOR(j,ql,qr) printf(" %d",dfixedinv[j-ql]); puts("");
	FORSZ(i,1,dfixedinv) dfixedinv[i]+=dfixedinv[i-1];
	FOR(j,ql,qr) ret[j]+=dfixedinv[j-ql];
	for(int j=qr-1;j>=ql;--j) swap(p[qa[j]],p[qb[j]]);
	// remove fixed elements
	vector<int> np(npos); REP(i,n) if(pos[i]!=-1) np[pos[i]]=val[p[i]];
	FOR(j,ql,qr) qa[j]=pos[qa[j]],qb[j]=pos[qb[j]];
	if(qr-ql<=1) {
		if(SZ(np)==2) {
			ret[ql]+=np[0]<np[1]?+1:0;
			//printf("\tswap2: %d\n",np[0]<np[1]?+1:0);
		}
	} else {
		int qm=ql+(qr-ql)/2;
		// call recursively on left part
		vector<pair<int,int> > oq; FOR(j,ql,qm) oq.PB(MP(qa[j],qb[j]));
		go(ql,qm,np);
		// perform queries in left part and call recursively on right part
		REPSZ(i,oq) swap(np[oq[i].first],np[oq[i].second]);
		go(qm,qr,np);
	}
}

int n,nq;

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,nq) scanf("%d%d",&qa[i],&qb[i]),--qa[i],--qb[i];
	REP(i,nq) ret[i]=0;
	vector<int> p(n); REP(i,n) p[i]=i;
	go(0,nq,p);
	REP(i,nq) printf("%lld\n",ret[i]);
}

int main() {
	run();
	return 0;
}