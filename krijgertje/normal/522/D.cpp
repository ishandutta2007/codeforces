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

typedef struct X { int val,pos; } X;
bool operator<(const X &p,const X &q) {
	if(p.val!=q.val) return p.val<q.val;
	return p.pos<q.pos;
}
typedef struct Q { int l,r,pos; } Q;
bool operator<(const Q &p,const Q &q) {
	if(p.r!=q.r) return p.r<q.r;
	return p.pos<q.pos;
}


int n,nq;
int a[500000];
int b[500000];
X x[500000];
Q q[500000];
int ret[500000];


int sval[1<<20];

int get(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return sval[x];
	int m=l+(r-l)/2;
	if(R<=m) return get(2*x+1,l,m,L,R);
	if(m+1<=L) return get(2*x+2,m+1,r,L,R);
	return min(get(2*x+1,l,m,L,R),get(2*x+2,m+1,r,L,R));
}
void put(int x,int l,int r,int POS,int VAL) {
	if(l==r) {
		sval[x]=VAL;
	} else {
		int m=l+(r-l)/2;
		if(POS<=m) put(2*x+1,l,m,POS,VAL);
		if(m+1<=POS) put(2*x+2,m+1,r,POS,VAL);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}
}



void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nq) { scanf("%d%d",&q[i].l,&q[i].r); q[i].l--; q[i].r--; q[i].pos=i; }

	REP(i,n) x[i].val=a[i],x[i].pos=i;
	sort(x,x+n);
	REP(i,n) b[x[i].pos]=i==0||x[i].val!=x[i-1].val?-1:x[i-1].pos;

	REP(i,1<<20) sval[i]=INT_MAX;
	sort(q,q+nq);
	int at=0;
	REP(qi,nq) {
		while(at<=q[qi].r) {
			if(b[at]!=-1) put(0,0,n-1,b[at],at-b[at]);
			++at;
		}
		ret[q[qi].pos]=get(0,0,n-1,q[qi].l,q[qi].r);
	}
	REP(i,nq) printf("%d\n",ret[i]==INT_MAX?-1:ret[i]);
}

int main() {
	run();
	return 0;
}