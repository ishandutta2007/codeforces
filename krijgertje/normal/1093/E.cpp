#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXN=200000;
const int MAXQ=200000;
const int MAXS=4*MAXN;
const int BSZ=1000;
const int MAXB=(MAXN+BSZ-1)/BSZ;

int n,nq;
int a[MAXN];
int b[MAXN];
int qkind[MAXQ],qla[MAXQ],qra[MAXQ],qlb[MAXQ],qrb[MAXQ],qidx1[MAXQ],qidx2[MAXQ],qans[MAXQ];

int mp[MAXN];
int c[MAXN];
int d[MAXN];
int pos[MAXN];

int nb;
int blockval[MAXB][BSZ],blockcnt[MAXB];
bool islazy[MAXN];
int lazy[MAXN],nlazy;

int calc(int lidx,int ridx,int lval,int rval) {
	//int ret=0; FORE(j,lidx,ridx) if(lval<=c[j]&&c[j]<=rval) ++ret; return ret;
	int olidx=lidx,oridx=ridx;
	int ret=0; ++ridx;
	while(lidx<ridx&&lidx%BSZ!=0) { if(lval<=c[lidx]&&c[lidx]<=rval) ++ret; ++lidx; }
	while(lidx<ridx&&ridx%BSZ!=0) { --ridx; if(lval<=c[ridx]&&c[ridx]<=rval) ++ret; }
	int lb=lidx/BSZ,rb=ridx/BSZ;
	//printf("ret=%d lidx=%d ridx=%d\n",ret,lidx,ridx);
	while(lb<rb) {
		int bidx=lb++;
		int lpos=lower_bound(blockval[bidx],blockval[bidx]+blockcnt[bidx],lval)-blockval[bidx];
		int rpos=lower_bound(blockval[bidx],blockval[bidx]+blockcnt[bidx],rval+1)-blockval[bidx];
		ret+=rpos-lpos;
	}
	lidx=olidx,ridx=oridx;
	REP(i,nlazy) {
		int idx=lazy[i];
		if(idx<lidx||idx>ridx) continue;
		if(lval<=c[idx]&&c[idx]<=rval) --ret;
		if(lval<=d[idx]&&d[idx]<=rval) ++ret;
	}
	return ret;
}

void recalc() {
	nlazy=0; REP(i,n) c[i]=d[i],islazy[i]=false;
	REP(i,nb) blockcnt[i]=0;
	REP(i,n) pos[c[i]]=i;
	REP(i,n) {
		int idx=pos[i],bidx=idx/BSZ;
		blockval[bidx][blockcnt[bidx]++]=i;
	}
}

void solve() {
	REP(i,n) mp[a[i]]=i;
	REP(i,n) d[i]=mp[b[i]];

	nb=(n+BSZ-1)/BSZ;
	recalc();

	REP(i,nq) {
		if(qkind[i]==1) {
			if(nlazy>=2*BSZ) recalc();
			int lval=qla[i],rval=qra[i],lidx=qlb[i],ridx=qrb[i];
			qans[i]=calc(lidx,ridx,lval,rval);
		}
		if(qkind[i]==2) {
			int x=qidx1[i],y=qidx2[i];
			swap(d[x],d[y]);
			if(!islazy[x]) islazy[x]=true,lazy[nlazy++]=x;
			if(!islazy[y]) islazy[y]=true,lazy[nlazy++]=y;
		}
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	REP(i,n) scanf("%d",&b[i]),--b[i];
	REP(i,nq) {
		scanf("%d",&qkind[i]);
		if(qkind[i]==1) scanf("%d%d%d%d",&qla[i],&qra[i],&qlb[i],&qrb[i]),--qla[i],--qra[i],--qlb[i],--qrb[i];
		if(qkind[i]==2) scanf("%d%d",&qidx1[i],&qidx2[i]),--qidx1[i],--qidx2[i];
	}
	solve();
	REP(i,nq) if(qkind[i]==1) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}