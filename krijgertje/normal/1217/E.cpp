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

const int MAXN=200000;
const int MAXQ=200000;
const int MAXS=4*MAXN;
const int MAXDIG=9;
struct Res { 
	int best[MAXDIG][2]; 
	void clear() { memset(best,-1,sizeof(best)); }
	void upd(int d,int val) { if(best[d][0]==-1||val<best[d][0]) best[d][1]=best[d][0],best[d][0]=val; else if(best[d][1]==-1||val<best[d][1]) best[d][1]=val; }
	void upd(const Res &oth) { REP(d,MAXDIG) REP(i,2) if(oth.best[d][i]!=-1) upd(d,oth.best[d][i]); }
	int calc() { int ret=-1; REP(d,MAXDIG) { int u=best[d][0],v=best[d][1]; if(u==-1||v==-1) continue; int cur=u+v; if(ret==-1||cur<ret) ret=cur; } return ret; }
};

int n,nq;
int a[MAXN];
int qkind[MAXQ],qidx[MAXQ],qval[MAXQ],ql[MAXQ],qr[MAXQ],qans[MAXQ];

Res sres[MAXS];

void scalc(int x,int idx) {
	sres[x].clear();
	int val=a[idx];
	REP(d,MAXDIG) {
		int cur=val%10; val/=10;
		if(cur!=0) sres[x].upd(d,a[idx]);
	}
}
void spull(int x) {
	sres[x]=sres[2*x+1];
	sres[x].upd(sres[2*x+2]);
}
void sinit(int x,int l,int r) {
	if(l==r) {
		scalc(x,l);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void supd(int x,int l,int r,int IDX) {
	if(l==r) {
		scalc(x,l);
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) supd(2*x+1,l,m,IDX); else supd(2*x+2,m+1,r,IDX);
		spull(x);
	}
}
Res sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sres[x];
	} else {
		Res ret; ret.clear();
		int m=l+(r-l)/2;
		if(L<=m) { Res cur=sget(2*x+1,l,m,L,R); ret.upd(cur); }
		if(m+1<=R) { Res cur=sget(2*x+2,m+1,r,L,R); ret.upd(cur); }
		return ret;
	}
}


void solve() {
	sinit(0,0,n-1);
	REP(i,nq) {
		if(qkind[i]==1) {
			a[qidx[i]]=qval[i];
			supd(0,0,n-1,qidx[i]);
		}
		if(qkind[i]==2) {
			qans[i]=sget(0,0,n-1,ql[i],qr[i]).calc();
		}
	}
}


void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nq) { scanf("%d",&qkind[i]); if(qkind[i]==1) scanf("%d%d",&qidx[i],&qval[i]),--qidx[i]; if(qkind[i]==2) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i]; }
	solve();
	REP(i,nq) if(qkind[i]==2) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}