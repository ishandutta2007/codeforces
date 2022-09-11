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

const int MAXN=500000;
const int MAXQ=500000;
const int MAXVAL=500000;
struct Q { int l,r,id; };
bool operator<(const Q &a,const Q &b) { return a.r<b.r; }

int n;
int a[MAXN];
int nq;
Q q[MAXQ];
int qans[MAXQ];

pair<int,int> o[MAXN];
int prv[MAXN],nxt[MAXN];

pair<int,int> sval[4*MAXN];

void sinit(int x,int l,int r) {
	sval[x]=MP(0,0);
	int m=l+(r-l)/2;
	sinit(2*x+1,l,m);
	sinit(2*x+2,m+1,r);
}
void smod(int x,int l,int r,int L,int R,pair<int,int> VAL) {
	//printf("smod(%d,%d..%d,%d..%d,%d=%d)\n",x,l,r,L,R,VAL.first,VAL.second);
	if(L<=l&&r<=R) {
		sval[x]=max(sval[x],VAL);
	} else {
		int m=l+(r-l)/2;
		if(L<=m) smod(2*x+1,l,m,L,R,VAL);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,VAL);
	}
}
pair<int,int> sget(int x,int l,int r,int IDX) {
	if(l==r) {
		return sval[x];
	} else {
		int m=l+(r-l)/2;
		pair<int,int> ret=sval[x];
		if(IDX<=m) ret=max(ret,sget(2*x+1,l,m,IDX));
		if(m+1<=IDX) ret=max(ret,sget(2*x+2,m+1,r,IDX));
		return ret;
	}
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq); REP(i,nq) scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,--q[i].r,q[i].id=i;

	REP(i,n) o[i]=MP(a[i],i);
	sort(o,o+n);
	REP(i,n) prv[o[i].second]=i==0||o[i-1].first!=o[i].first?-1:o[i-1].second;
	REP(i,n) nxt[o[i].second]=i==n-1||o[i+1].first!=o[i].first?n:o[i+1].second;

	//printf("rng:"); REP(i,n) printf(" %d..%d",prv[i]+1,nxt[i]-1); puts("");

	sort(q,q+nq);
	int qat=0;
	REP(i,n) {
		smod(0,0,n-1,prv[i]+1,i,MP(nxt[i]-1,a[i]));
		while(qat<nq&&q[qat].r==i) {
			pair<int,int> res=sget(0,0,n-1,q[qat].l);
			//printf("q%d: %d=%d\n",q[qat].id,res.first,res.second);
			qans[q[qat].id]=res.first>=q[qat].r?res.second:0;
			++qat;
		}
	}

	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}