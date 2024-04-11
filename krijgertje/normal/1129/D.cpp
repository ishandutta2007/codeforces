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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXVAL=100000;
const int MAXGAP=MAXVAL+1;
const int BSZ=400;
const int MAXB=(MAXGAP+BSZ-1)/BSZ;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }

int nval,lim;
int val[MAXVAL];

pair<int,int> o[MAXVAL];
int prv[MAXVAL],nxt[MAXVAL];

int ngap;
int ways[MAXGAP];
int ones[MAXGAP];

int nb;
int blazyones[MAXB];
int bmnones[MAXB];
int bsumways[MAXB][BSZ];
int bsumvalidways[MAXB];

void bpush(int b) {
	int l=b*BSZ,r=min(ngap,(b+1)*BSZ);
	FOR(i,l,r) ones[i]+=blazyones[b];
	blazyones[b]=0;
}
void bpull(int b) {
	int l=b*BSZ,r=min(ngap,(b+1)*BSZ);
	bmnones[b]=ones[l]; FOR(i,l,r) bmnones[b]=min(bmnones[b],ones[i]);
	REP(i,BSZ) bsumways[b][i]=0; FOR(i,l,r) { int extra=ones[i]-bmnones[b]; assert(0<=extra&&extra<BSZ); inc(bsumways[b][extra],ways[i]); }
	bsumvalidways[b]=0; FOR(i,l,r) if(ones[i]<=lim) inc(bsumvalidways[b],ways[i]);
	//printf("\tpulled [%d..%d):",l,r); FOR(i,l,r) printf(" %d",ones[i]); puts("");
}

void modones(int l,int r,int by) {
	++r;
	//printf("modones [%d..%d) by %d\n",l,r,by);
	if(l<r&&l%BSZ!=0) {
		int b=l/BSZ; bpush(b);
		while(l<r&&l%BSZ!=0) ones[l++]+=by;
		bpull(b);
	}
	if(l<r&&r%BSZ!=0) {
		int b=r/BSZ; bpush(b);
		while(l<r&&r%BSZ!=0) ones[--r]+=by;
		bpull(b);
	}
	if(l<r) {
		int bl=l/BSZ,br=r/BSZ;
		FOR(b,bl,br) {
			if(by==+1) { int extra=lim-bmnones[b]-blazyones[b]; if(0<=extra&&extra<BSZ) dec(bsumvalidways[b],bsumways[b][extra]); blazyones[b]++; }
			if(by==-1) { blazyones[b]--; int extra=lim-bmnones[b]-blazyones[b]; if(0<=extra&&extra<BSZ) inc(bsumvalidways[b],bsumways[b][extra]); }
		}
	}
}

void incways(int idx,int val) {
	//printf("incways(%d,%d)\n",idx,val);
	inc(ways[idx],val);
	int b=idx/BSZ,extra=ones[idx]-bmnones[b]; assert(0<=extra&&extra<BSZ);
	inc(bsumways[b][extra],val);
	if(ones[idx]+blazyones[b]<=lim) inc(bsumvalidways[b],val);
}
int sumways() {
	int ret=0; REP(b,nb) inc(ret,bsumvalidways[b]); return ret;
}

int solve() {
	REP(i,nval) o[i]=MP(val[i],i); sort(o,o+nval);
	REP(i,nval) prv[o[i].second]=i-1>=0&&o[i-1].first==o[i].first?o[i-1].second:-1;
	REP(i,nval) nxt[o[i].second]=i+1<nval&&o[i+1].first==o[i].first?o[i+1].second:-1;
	
	ngap=nval+1,nb=(ngap+BSZ-1)/BSZ;
	REP(i,ngap) ways[i]=ones[i]=0;
	REP(b,nb) blazyones[b]=0,bpull(b);
	incways(0,1);
	REP(i,nval) {
		if(prv[i]!=-1) modones(prv[prv[i]]+1,prv[i],-1);
		modones(prv[i]+1,i,+1);
		incways(i+1,sumways());
	}
	return ways[ngap-1];
}

void run() {
	scanf("%d%d",&nval,&lim);
	REP(i,nval) scanf("%d",&val[i]);
	printf("%d\n",solve());
	
}

int main() {
	run();
	return 0;
}