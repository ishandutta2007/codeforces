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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=500000;
const int MAXS=4*2*MAXN;

int n;
int x[MAXN],y[MAXN],v[MAXN];

int zz[2*MAXN],nzz;

pair<ll,int> sval[MAXS]; ll slazy[MAXS];
void sapply(int x,ll by) { sval[x].first+=by; slazy[x]+=by; }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }
void spull(int x) { sval[x]=max(sval[2*x+1],sval[2*x+2]); }
void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		sval[x]=MP(zz[l],l);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void smod(int x,int l,int r,int L,int R,ll BY) {
	//if(x==0) printf("smod(%d..%d,%lld)\n",L,R,BY);
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2; spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}
pair<ll,int> sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2; spush(x); pair<ll,int> ret=MP(LLONG_MIN,-1);
		if(L<=m) ret=max(ret,sget(2*x+1,l,m,L,R));
		if(m+1<=R) ret=max(ret,sget(2*x+2,m+1,r,L,R));
		return ret;
	}
}


pair<int,int> o[MAXN];

ll ansval;
int ansl,ansr;

void solve() {
	REP(i,n) if(y[i]>x[i]) swap(x[i],y[i]);
	nzz=0; REP(i,n) zz[nzz++]=x[i],zz[nzz++]=y[i]; sort(zz,zz+nzz); nzz=unique(zz,zz+nzz)-zz; REP(i,n) x[i]=lower_bound(zz,zz+nzz,x[i])-zz,y[i]=lower_bound(zz,zz+nzz,y[i])-zz;

	REP(i,n) o[i]=MP(x[i],i);
	sort(o,o+n);
	ansval=0,ansl=ansr=2000000000;
	sinit(0,0,nzz-1);
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&o[r].first==o[l].first) ++r;
		int cx=o[l].first;
		FOR(i,l,r) { int at=o[i].second; smod(0,0,nzz-1,0,y[at],v[at]); }
		pair<ll,int> cur=sget(0,0,nzz-1,0,cx); cur.first-=zz[cx];
		//printf("%d: %lld (%d)\n",zz[cx],cur.first,zz[cur.second]);
		if(cur.first>ansval) ansval=cur.first,ansl=zz[cur.second],ansr=zz[cx];
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&x[i],&y[i],&v[i]);
	solve();
	printf("%lld\n%d %d %d %d\n",ansval,ansl,ansl,ansr,ansr);
}

int main() {
	run();
	return 0;
}