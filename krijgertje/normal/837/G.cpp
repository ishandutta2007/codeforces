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

const int NX=200002;
const int MAXLG=18;
const int MAXN=75000;
const int MAXS=8*MAXLG*MAXN+4*NX;

int ns;
ll sa[MAXS],sb[MAXS];
int sl[MAXS],sr[MAXS];

int smake(ll a,ll b) { assert(ns<MAXS); sa[ns]=a,sb[ns]=b,sl[ns]=-1,sr[ns]=-1; return ns++; }
int smake(ll a,ll b,int nl,int nr) { int ret=smake(a,b); sl[ret]=nl,sr[ret]=nr; return ret; }
int sbuild(int l,int r) {
	int ret=smake(0,0);
	if(l==r) return ret;
	int m=l+(r-l)/2;
	sl[ret]=sbuild(l,m),sr[ret]=sbuild(m+1,r);
	return ret;
}
int smod(int x,int l,int r,int X1,int X2,int Y1,int Y2,int A,int B) {
	//printf("smod(%d,%d,%d %d,%d,%d,%d,%d,%d)\n",x,l,r,X1,X2,Y1,Y2,A,B);
	if(r<=X1) return smake(sa[x],sb[x]+Y1,sl[x],sr[x]);
	if(l>X2) return smake(sa[x],sb[x]+Y2,sl[x],sr[x]);
	if(X1<l&&r<=X2) return smake(sa[x]+A,sb[x]+B,sl[x],sr[x]);
	int m=l+(r-l)/2;
	int ret=smake(sa[x],sb[x]);
	sl[ret]=smod(sl[x],l,m,X1,X2,Y1,Y2,A,B);
	sr[ret]=smod(sr[x],m+1,r,X1,X2,Y1,Y2,A,B);
	return ret;
}
pair<ll,ll> squery(int x,int l,int r,int X) {
	//printf("squery(%d,%d,%d %d)\n",x,l,r,X);
	if(l==r) return MP(sa[x],sb[x]);
	int m=l+(r-l)/2;
	pair<ll,ll> cur=X<=m?squery(sl[x],l,m,X):squery(sr[x],m+1,r,X);
	return MP(cur.first+sa[x],cur.second+sb[x]);
}


int n,nq;

int root[MAXN+1];


void run() {
	ns=0;
	root[0]=sbuild(0,NX-1);
	scanf("%d",&n); REP(i,n) { int x1,x2,y1,y2,a,b; scanf("%d%d%d%d%d%d",&x1,&x2,&y1,&a,&b,&y2); root[i+1]=smod(root[i],0,NX-1,x1,x2,y1,y2,a,b); }
	scanf("%d",&nq); ll last=0;
	REP(i,nq) {
		int l,r,x; scanf("%d%d%d",&l,&r,&x); --l,--r,x=min((int)((x+last)%1000000000),NX-1);
		pair<ll,ll> qr=squery(root[r+1],0,NX-1,x),ql=squery(root[l],0,NX-1,x);
		ll a=qr.first-ql.first,b=qr.second-ql.second;
		//printf("a=%lld b=%lld\n",a,b);
		ll ans=a*x+b;
		printf("%lld\n",ans);
		last=ans;
	}
}

int main() {
	run();
	return 0;
}