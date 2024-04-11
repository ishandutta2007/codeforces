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

const int MAXQ=300000;
const int MAXN=2*MAXQ;

int nq;
int qx[MAXQ],qy[MAXQ]; ll qans[MAXQ];

int allx[MAXQ],nallx;
int ally[MAXQ],nally;
int qmatch[MAXQ];

vector<int> changes;
int par[MAXN],lsz[MAXN],rsz[MAXN];
ll sum;

int uffind(int x) { while(x!=par[x]) x=par[x]; return x; }

void addedge(int idx) {
	int a=qx[idx],b=nallx+qy[idx];
	a=uffind(a),b=uffind(b);
	if(a==b) return;
	if(lsz[a]+rsz[a]<lsz[b]+rsz[b]) swap(a,b);
	changes.PB(b);
	sum-=(ll)lsz[a]*rsz[a]+(ll)lsz[b]*rsz[b];
	lsz[a]+=lsz[b],rsz[a]+=rsz[b],par[b]=a;
	sum+=(ll)lsz[a]*rsz[a];
}
void rollback(int upto) {
	while(SZ(changes)>upto) {
		int b=changes.back(),a=par[b]; changes.pop_back();
		sum-=(ll)lsz[a]*rsz[a];
		lsz[a]-=lsz[b],rsz[a]-=rsz[b],par[b]=b;
		sum+=(ll)lsz[a]*rsz[a]+(ll)lsz[b]*rsz[b];
	}
}

void rec(int ql,int qr) {
	if(ql==qr) {
		qans[ql]=sum;
	} else {
		int qm=ql+(qr-ql)/2;

		int loldchanges=SZ(changes);
		FORE(i,qm+1,qr) if(qmatch[i]!=-1&&qmatch[i]<=ql) addedge(i);
		rec(ql,qm);
		rollback(loldchanges);

		int roldchanges=SZ(changes);
		FORE(i,ql+1,qm+1) if(qmatch[i]==-1||qmatch[i]>qr) addedge(i);
		rec(qm+1,qr);
		rollback(roldchanges);
	}
}

void solve() {
	nallx=0; REP(i,nq) allx[nallx++]=qx[i]; sort(allx,allx+nallx); nallx=unique(allx,allx+nallx)-allx; REP(i,nq) qx[i]=lower_bound(allx,allx+nallx,qx[i])-allx;
	nally=0; REP(i,nq) ally[nally++]=qy[i]; sort(ally,ally+nally); nally=unique(ally,ally+nally)-ally; REP(i,nq) qy[i]=lower_bound(ally,ally+nally,qy[i])-ally;
	
	map<pair<int,int>,int> mp;
	REP(i,nq) { pair<int,int> key=MP(qx[i],qy[i]); if(!mp.count(key)) { qmatch[i]=-1; mp[key]=i; } else { qmatch[i]=mp[key]; mp.erase(key); qmatch[qmatch[i]]=i; } }
	//printf("qmatch:"); REP(i,nq) printf(" %d",qmatch[i]); puts("");

	sum=0; REP(i,nallx+nally) par[i]=i,lsz[i]=i<nallx?1:0,rsz[i]=i<nallx?0:1;
	if(qmatch[0]==-1) addedge(0);
	rec(0,nq-1);
}

void run() {
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&qx[i],&qy[i]);
	solve();
	REP(i,nq) { if(i!=0) printf(" "); printf("%lld",qans[i]); } puts("");
}

int main() {
	run();
	return 0;
}