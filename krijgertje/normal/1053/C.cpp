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

const int MAXN=200000;
const int MAXQ=200000;
const int MOD=1000000007;
const int MAXS=4*MAXN;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n,nq;
int a[MAXN];
int w[MAXN];
int qa[MAXQ],qb[MAXQ],qans[MAXQ];

ll ssum[MAXS]; int ssum2[MAXS];

void spull(int x) {
	ssum[x]=ssum[2*x+1]+ssum[2*x+2];
	ssum2[x]=(ssum2[2*x+1]+ssum2[2*x+2])%MOD;
}

void sinit(int x,int l,int r) {
	if(l==r) {
		int idx=l;
		ssum[x]=w[idx];
		ssum2[x]=(ll)(a[idx]-idx)*w[idx]%MOD;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void sset(int x,int l,int r,int IDX,int VAL) {
	if(l==r) {
		ssum[x]=VAL;
		ssum2[x]=(ll)(a[IDX]-IDX)*VAL%MOD;
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) sset(2*x+1,l,m,IDX,VAL);
		if(m+1<=IDX) sset(2*x+2,m+1,r,IDX,VAL);
		spull(x);
	}
}
pair<ll,int> sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return MP(ssum[x],ssum2[x]);
	} else {
		int m=l+(r-l)/2; pair<ll,int> ret=MP(0LL,0);
		if(L<=m) { pair<ll,int> cur=sget(2*x+1,l,m,L,R); ret.first+=cur.first; inc(ret.second,cur.second); }
		if(m+1<=R) { pair<ll,int> cur=sget(2*x+2,m+1,r,L,R); ret.first+=cur.first; inc(ret.second,cur.second); }
		return ret;
	}
}
int sfind(int x,int l,int r,int L,int R,ll &want) {
	//printf("sfind(%d,%d..%d,%d..%d,%lld) [%lld]\n",x,l,r,L,R,want,ssum[x]);
	if(l==r&&want<=ssum[x]) {
		return l;
	} else if(L<=l&&r<=R&&ssum[x]<want) {
		want-=ssum[x];
		return -1;
	} else {
		int m=l+(r-l)/2;
		if(L<=m) { int cur=sfind(2*x+1,l,m,L,R,want); if(cur!=-1) return cur; }
		if(m+1<=R) { int cur=sfind(2*x+2,m+1,r,L,R,want); if(cur!=-1) return cur; }
		return -1;
	}
}

void solve() {
	sinit(0,0,n-1);
	REP(i,nq) {
		if(qa[i]<0) {
			int idx=-qa[i]-1,nw=qb[i];
			sset(0,0,n-1,idx,nw);
		} else {
			int l=qa[i]-1,r=qb[i]-1;
			ll wsum=sget(0,0,n-1,l,r).first;
			ll want=(wsum+1)/2;
			int mid=sfind(0,0,n-1,l,r,want); assert(mid!=-1);
			pair<ll,int> lres=sget(0,0,n-1,l,mid);
			pair<ll,int> rres=sget(0,0,n-1,mid,r);
			qans[i]=(((ll)(a[mid]-mid)*(lres.first%MOD)-lres.second+(mid-a[mid])*(rres.first%MOD)+rres.second)%MOD+MOD)%MOD;
			//printf("%d..%d: wsum=%lld owant=%lld mid=%d lres=(%lld,%d) rres=(%lld,%d)\n",l+1,r+1,wsum,(wsum+1)/2,mid,lres.first,lres.second,rres.first,rres.second);
		}
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&w[i]);
	REP(i,nq) scanf("%d%d",&qa[i],&qb[i]);
	solve();
	REP(i,nq) if(qa[i]>0) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}