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
const int MAXQ=200000;
const int MAXS=4*MAXN;
const int MOD=998244353;

int n,nq;
int qkind[MAXQ],ql[MAXQ],qr[MAXQ],qval[MAXQ];
int qans[MAXQ];

int slazymlt[MAXS],slazyadd[MAXS],sval[MAXS];
void sapplyadd(int x,int l,int r,int BY) {
	sval[x]=(sval[x]+(ll)(r-l+1)*BY)%MOD;
	slazyadd[x]=(slazyadd[x]+BY)%MOD;
}
void sapplymlt(int x,int BY) {
	sval[x]=(ll)sval[x]*BY%MOD;
	slazymlt[x]=(ll)slazymlt[x]*BY%MOD;
	slazyadd[x]=(ll)slazyadd[x]*BY%MOD;
}
void spush(int x,int l,int m,int r) {
	if(slazymlt[x]!=1) sapplymlt(2*x+1,slazymlt[x]),sapplymlt(2*x+2,slazymlt[x]),slazymlt[x]=1;
	if(slazyadd[x]!=0) sapplyadd(2*x+1,l,m,slazyadd[x]),sapplyadd(2*x+2,m+1,r,slazyadd[x]),slazyadd[x]=0;
}
void spull(int x) {
	sval[x]=(sval[2*x+1]+sval[2*x+2])%MOD;
}

void sinit(int x,int l,int r) {
	slazymlt[x]=1,slazyadd[x]=0,sval[x]=0;
	if(l!=r) {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
	}
}
void sinc(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		sapplyadd(x,l,r,1);
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		if(L<=m) sinc(2*x+1,l,m,L,R);
		if(m+1<=R) sinc(2*x+2,m+1,r,L,R);
		spull(x);
	}
}
void sdup(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		sapplymlt(x,2);
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		if(L<=m) sdup(2*x+1,l,m,L,R);
		if(m+1<=R) sdup(2*x+2,m+1,r,L,R);
		spull(x);
	}
}
int sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2,ret=0;
		spush(x,l,m,r);
		if(L<=m) ret+=sget(2*x+1,l,m,L,R);
		if(m+1<=R) ret+=sget(2*x+2,m+1,r,L,R);
		spull(x);
		return ret%MOD;
	}
}



set<pair<int,int> > one[MAXN+1];
vector<pair<int,int> > cur;
void calccur(int val,int l,int r) {
	cur.clear(); int nl=l,nr=r;
	auto it=one[val].lower_bound(MP(l,-1));
	if(it!=one[val].begin()) { auto pit=it; --pit; if(pit->second>=l-1) it=pit; }
	while(true) {
		if(it==one[val].end()||it->first>r+1) break;
		if(it->first<nl) nl=it->first;
		if(it->first>l) l=it->first;
		if(r<=it->second) { cur.PB(MP(l,r)); nr=it->second; one[val].erase(it); break; }
		cur.PB(MP(l,it->second));
		l=it->second+1;
		auto nit=it; ++nit; one[val].erase(it); it=nit;
	}
	one[val].insert(MP(nl,nr));
}

void upd(int val,int l,int r) {
	calccur(val,l,r);
	REPSZ(i,cur) { int l=cur[i].first,r=cur[i].second; sdup(0,0,n-1,l,r); }
	if(SZ(cur)==0) sinc(0,0,n-1,l,r);
	if(SZ(cur)>0&&l<cur[0].first) sinc(0,0,n-1,l,cur[0].first-1);
	if(SZ(cur)>0&&cur[SZ(cur)-1].second<r) sinc(0,0,n-1,cur[SZ(cur)-1].second+1,r);
	FORSZ(i,1,cur) sinc(0,0,n-1,cur[i-1].second+1,cur[i].first-1);
}

void solve() {
	REPE(i,n) one[i].clear();
	sinit(0,0,n-1);
	REP(qi,nq) {
		int kind=qkind[qi],l=ql[qi],r=qr[qi],val=qval[qi];
		if(kind==1) {
			upd(val,l,r);
		}
		if(kind==2) {
			qans[qi]=sget(0,0,n-1,l,r);
		}
	}
}


void run() {
	scanf("%d%d",&n,&nq); REP(i,nq) { scanf("%d%d%d",&qkind[i],&ql[i],&qr[i]); --ql[i],--qr[i]; if(qkind[i]==1) scanf("%d",&qval[i]); }
	solve();
	REP(i,nq) if(qkind[i]==2) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}