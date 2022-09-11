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

const int MAXN=100000;
const int MAXS=4*MAXN;
struct P { int x,r,iq; };
bool operator<(const P &a,const P &b) { return a.x<b.x; }

int n,iqlim;
P p[MAXN];

vector<int> rem[MAXN];

vector<int> siq[MAXS];
vector<int> sl[MAXS],sr[MAXS]; // sl[z][i] is first index in siq[2*z+1] that is greater than or equal to siq[z][i]
vector<int> scnt[MAXS];

void sinit(int z,int l,int r) {
	siq[z].clear(); sl[z].clear(); sr[z].clear(); scnt[z].clear();
	if(l==r) {
		siq[z].PB(p[l].iq);
	} else {
		int m=l+(r-l)/2;
		sinit(2*z+1,l,m);
		sinit(2*z+2,m+1,r);
		siq[z]=vector<int>(SZ(siq[2*z+1])+SZ(siq[2*z+2]),-1);
		sl[z]=vector<int>(SZ(siq[2*z+1])+SZ(siq[2*z+2]),-1);
		sr[z]=vector<int>(SZ(siq[2*z+1])+SZ(siq[2*z+2]),-1);
		int a=0,b=0,c=0;
		while(a<SZ(siq[2*z+1])||b<SZ(siq[2*z+2])) {
			int cur=INT_MAX; if(a<SZ(siq[2*z+1])) cur=min(cur,siq[2*z+1][a]); if(b<SZ(siq[2*z+2])) cur=min(cur,siq[2*z+2][b]);
			siq[z][c]=cur,sl[z][c]=a,sr[z][c]=b,++c;
			if(a<SZ(siq[2*z+1])&&siq[2*z+1][a]==cur) ++a; if(b<SZ(siq[2*z+2])&&siq[2*z+2][b]==cur) ++b;
		}
		siq[z].resize(c),sl[z].resize(c),sr[z].resize(c);
		//printf("%d..%d:",l,r); REPSZ(i,siq[z]) printf(" %d(%d,%d)",siq[z][i],sl[z][i],sr[z][i]); puts("");

	}
	scnt[z]=vector<int>(SZ(siq[z]),0);
}
void smod(int z,int l,int r,int IDX,int POS,int BY) {
	scnt[z][POS]+=BY;
	if(l!=r) {
		int m=l+(r-l)/2;
		if(IDX<=m) smod(2*z+1,l,m,IDX,sl[z][POS],BY);
		else smod(2*z+2,m+1,r,IDX,sr[z][POS],BY);
	}
}
int sget(int z,int l,int r,int L,int R,int POS,int LIM) {
	if(POS>=SZ(siq[z])||siq[z][POS]>LIM) return 0;
	if(L<=l&&r<=R) {
		int ret=0; for(int i=POS;i<SZ(siq[z])&&siq[z][i]<=LIM;++i) ret+=scnt[z][i]; return ret;
	} else {
		int m=l+(r-l)/2,ret=0;
		if(L<=m) ret+=sget(2*z+1,l,m,L,R,sl[z][POS],LIM);
		if(m+1<=R) ret+=sget(2*z+2,m+1,r,L,R,sr[z][POS],LIM);
		return ret;
	}
}

void upd(int idx,int by) {
	int pos=lower_bound(siq[0].begin(),siq[0].end(),p[idx].iq)-siq[0].begin(); assert(0<=pos&&pos<SZ(siq[0])&&siq[0][pos]==p[idx].iq);
	smod(0,0,n-1,idx,pos,by);
}

int calc(int lidx,int ridx,int liq,int riq) {
	int pos=lower_bound(siq[0].begin(),siq[0].end(),liq)-siq[0].begin();
	return sget(0,0,n-1,lidx,ridx,pos,riq);
}

ll solve() {
	REP(i,n) rem[i].clear();
	sort(p,p+n);
	sinit(0,0,n-1);

	ll ret=0;
	REP(i,n) {
		int lo=-1,hi=i; /*(lo,hi]*/ while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(p[mi].x>=p[i].x-p[i].r) hi=mi; else lo=mi; }
		ret+=calc(hi,n-1,p[i].iq-iqlim,p[i].iq+iqlim);
		upd(i,+1);
		lo=i,hi=n; /*[lo,hi)*/ while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(p[mi].x<=p[i].x+p[i].r) lo=mi; else hi=mi; }
		rem[lo].PB(i);
		REPSZ(j,rem[i]) upd(rem[i][j],-1);
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&iqlim); REP(i,n) scanf("%d%d%d",&p[i].x,&p[i].r,&p[i].iq);
	printf("%lld\n",solve());
}

ll bf() {
	ll ret=0; REP(i,n) FOR(j,i+1,n) if(abs(p[i].x-p[j].x)<=min(p[i].r,p[j].r)&&abs(p[i].iq-p[j].iq)<=iqlim) ++ret; return ret;
}

int myrand() { return rand()%1000*1000000+rand()%1000*1000+rand()%1001; }
//int myrand() { return rand()%1001; }
void stress() {
	REP(rep,100000) {
		n=100; iqlim=20; REP(i,n) p[i].x=myrand(),p[i].r=myrand(),p[i].iq=myrand();
		//printf("%d: %d %d\n",rep,n,iqlim); REP(i,n) printf("%d %d %d\n",p[i].x,p[i].r,p[i].iq);
		ll have=solve();
		ll want=bf();
		if(have==want) { printf("."); continue; }
		printf("err have=%lld want=%lld\n",have,want);
		printf("%d: %d %d\n",rep,n,iqlim); REP(i,n) printf("%d %d %d\n",p[i].x,p[i].r,p[i].iq);
		return;
	}
}

int main() {
	run();
	//stress();
	return 0;
}