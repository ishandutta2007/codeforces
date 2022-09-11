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

const int MAXN=100000;
const int MAXQ=100000;
const int MAXLG=16;
const int MAXS=4*MAXN;
struct Res { int mn1,mn2,mx1,mx2; Res() {} Res(int mn1,int mn2,int mx1,int mx2):mn1(mn1),mn2(mn2),mx1(mx1),mx2(mx2) {} };

int n,nq;
int par[MAXN];
int ql[MAXQ],qr[MAXQ]; pair<int,int> qans[MAXQ];


vector<int> ch[MAXN];
int dep[MAXN];
int up[MAXN][MAXLG+1];
int pre[MAXN],preidx[MAXN],npre;

void dfsinit(int at,int par) {
	pre[npre]=at,preidx[at]=npre,++npre;
	dep[at]=par==-1?0:dep[par]+1;
	up[at][0]=par==-1?at:par; FORE(k,1,MAXLG) up[at][k]=up[up[at][k-1]][k-1];
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		dfsinit(to,at);
	}
}

int lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return a==b?a:up[a][0];
}

Res sval[MAXS];

void updmn(Res &a,int idx) {
	if(a.mn1==-1||preidx[idx]<preidx[a.mn1]) a.mn2=a.mn1,a.mn1=idx; else if(a.mn2==-1||preidx[idx]<preidx[a.mn2]) a.mn2=idx;
}
void updmx(Res &a,int idx) {
	if(a.mx1==-1||preidx[idx]>preidx[a.mx1]) a.mx2=a.mx1,a.mx1=idx; else if(a.mx2==-1||preidx[idx]>preidx[a.mx2]) a.mx2=idx;
}
Res smerge(const Res &a,const Res &b) {
	Res ret=a;
	if(b.mn1!=-1) updmn(ret,b.mn1);
	if(b.mn2!=-1) updmn(ret,b.mn2);
	if(b.mx1!=-1) updmx(ret,b.mx1);
	if(b.mx2!=-1) updmx(ret,b.mx2);
	return ret;
}

void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=Res(l,-1,l,-1);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		sval[x]=smerge(sval[2*x+1],sval[2*x+2]);
	}
}

Res sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2;
		if(m+1>R) return sget(2*x+1,l,m,L,R);
		if(L>m) return sget(2*x+2,m+1,r,L,R);
		return smerge(sget(2*x+1,l,m,L,R),sget(2*x+2,m+1,r,L,R));
	}
}

void solve() {
	REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	npre=0; dfsinit(0,-1);
	sinit(0,0,n-1);
	REP(i,nq) {
		int l=ql[i],r=qr[i];
		Res res=sget(0,0,n-1,l,r);
		int x1=lca(res.mn2,res.mx1);
		int x2=lca(res.mn1,res.mx2);
		qans[i]=dep[x1]>=dep[x2]?MP(res.mn1,dep[x1]):MP(res.mx1,dep[x2]);
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	solve();
	REP(i,nq) printf("%d %d\n",qans[i].first+1,qans[i].second);
}

int main() {
	run();
	return 0;
}