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

typedef struct X { int a,b,id; } X;
bool operator<(const X &p,const X &q) {
	if(p.a!=q.a) return p.a>q.a;
	if(p.b!=q.b) return p.b<q.b;
	return p.id<q.id;
}

bool ok(const X &p,const X &q,const X &r) {
	// ((1/q.a,1/q.b)-(1/p.a,1/p.b))^((1/r.a,1/r.b)-(1/p.a,1/p.b))>=0
	// (1/q.a-1/p.a)*(1/r.b-1/p.b)-(1/q.b-1/p.b)*(1/r.a-1/p.a)>=0
	// ((pa-qa)/(pa*qa))*((pb-rb)/(pb*rb))-((pb-qb)/(pb*qb))*((pa-ra)/(pa*ra))>=0
	// (pa-qa)*(pb-rb)*(ra*qb)>=(pb-qb)*(pa-ra)*(qa*rb)
	ll lhs=(ll)(p.a-q.a)*(p.b-r.b)*r.a*q.b,rhs=(ll)(p.b-q.b)*(p.a-r.a)*q.a*r.b;
	//printf("checking (%d,%d)-(%d,%d)-(%d,%d) -> %lld>=%lld\n",p.a,p.b,q.a,q.b,r.a,r.b,lhs,rhs);
	return lhs>=rhs;
}

int n;
X x[MAXN];

int h[MAXN],nh;
int ret[MAXN],nret;

void run() {
	scanf("%d",&n);
	REP(i,n) { scanf("%d%d",&x[i].a,&x[i].b); x[i].id=i; }
	//n=MAXN; REP(i,n) x[i].a=rand()%10000+1,x[i].b=rand()%10000+1,x[i].id=i;
	sort(x,x+n);
	//REP(i,n) printf("%d %d (%lf %lf)\n",x[i].a,x[i].b,1000.0/x[i].a,1000.0/x[i].b);

	nh=0;
	REP(i,n) {
		if(i>0&&x[i].a==x[i-1].a&&x[i].b==x[i-1].b) continue;
		if(nh>0&&x[i].b<x[h[nh-1]].b) continue;
		while(nh>=2&&!ok(x[h[nh-2]],x[h[nh-1]],x[i])) --nh;
		h[nh++]=i;
	}
	int lh=0,rh=nh-1;
	while(lh+1<=rh&&x[h[lh]].a==x[h[lh+1]].a) ++lh;
	while(rh-1>=lh&&x[h[rh]].b==x[h[rh-1]].b) --rh;
	//FORE(i,lh,rh) printf("%d %d (%lf %lf)\n",x[h[i]].a,x[h[i]].b,1000.0/x[h[i]].a,1000.0/x[h[i]].b);
	FORE(i,lh,rh-2) assert(ok(x[h[i]],x[h[i+1]],x[h[i+2]]));
	nret=0;
	FORE(i,lh,rh) for(int j=h[i];j<n&&x[h[i]].a==x[j].a&&x[h[i]].b==x[j].b;++j) ret[nret++]=x[j].id;
	sort(ret,ret+nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}