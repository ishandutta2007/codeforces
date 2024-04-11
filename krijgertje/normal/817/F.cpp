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

const ll MAXVAL=1000000000000000000LL;
const int MAXBIT=60;
const int MAXQ=100000;
const int MAXZ=1+3*MAXQ*MAXBIT;

typedef struct Z { int l,r; char val; bool inv; } Z;

Z z[MAXZ]; int nz;
int createnode(int val) { assert(nz<MAXZ); z[nz].l=z[nz].r=-1,z[nz].val=val,z[nz].inv=false; return nz++; }

void spush(int at) {
	if(z[at].val!=-1) {
		if(z[at].l==-1) z[at].l=createnode(z[at].val); else z[z[at].l].val=z[at].val,z[z[at].l].inv=false;
		if(z[at].r==-1) z[at].r=createnode(z[at].val); else z[z[at].r].val=z[at].val,z[z[at].r].inv=false;
		z[at].val=-1;
	} else if(z[at].inv) {
		if(z[z[at].l].val>=0) z[z[at].l].val=1-z[z[at].l].val; else z[z[at].l].inv=!z[z[at].l].inv;
		if(z[z[at].r].val>=0) z[z[at].r].val=1-z[z[at].r].val; else z[z[at].r].inv=!z[z[at].r].inv;
		z[at].inv=false;
	}
}
void spull(int at) {
	z[at].val=z[z[at].l].val==z[z[at].r].val?z[z[at].l].val:-1;
}

void update(int at,ll l,ll r,ll L,ll R,int val) {
	//printf("update(%lld..%lld,%lld..%lld,%d) [%d]\n",l,r,L,R,val,z[at].val);
	if(L<=l&&r<=R) { z[at].val=val,z[at].inv=false; return; }
	spush(at);
	ll m=l+(r-l)/2;
	if(L<=m) update(z[at].l,l,m,L,R,val);
	if(m+1<=R) update(z[at].r,m+1,r,L,R,val);
	spull(at);
	//printf("update(%lld..%lld,%lld..%lld,%d) -> %d\n",l,r,L,R,val,z[at].val);
}
void invert(int at,ll l,ll r,ll L,ll R) {
	//printf("invert(%lld..%lld,%lld..%lld)\n",l,r,L,R);
	if(L<=l&&r<=R) { if(z[at].val>=0) z[at].val=1-z[at].val; else z[at].inv=!z[at].inv; return; }
	spush(at);
	ll m=l+(r-l)/2;
	if(L<=m) invert(z[at].l,l,m,L,R);
	if(m+1<=R) invert(z[at].r,m+1,r,L,R);
	spull(at);
}
ll query(int at,ll l,ll r) {
	//printf("query(%lld..%lld) [%d%c]\n",l,r,z[at].val,z[at].inv?'!':' ');
	assert(z[at].val!=1);
	if(l==r) return l;
	if(z[at].l==-1||z[at].r==-1) { assert(z[at].val==0); return l; }
	spush(at);
	ll m=l+(r-l)/2;
	ll ret;
	if(z[z[at].l].val!=1) ret=query(z[at].l,l,m);
	else if(z[z[at].r].val!=1) ret=query(z[at].r,m+1,r);
	else assert(false);
	spull(at);
	return ret;
}



void run() {
	nz=0; int rt=createnode(0);
	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int kind; ll l,r; scanf("%d%lld%lld",&kind,&l,&r);
		if(kind==1) update(rt,1,MAXVAL+1,l,r,1);
		if(kind==2) update(rt,1,MAXVAL+1,l,r,0);
		if(kind==3) invert(rt,1,MAXVAL+1,l,r);
		ll ret=query(rt,1,MAXVAL+1); printf("%lld\n",ret);
	}
}

int main() {
	run();
	return 0;
}