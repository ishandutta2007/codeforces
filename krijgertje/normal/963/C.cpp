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
struct R { ll w,h,c; };
bool operator<(const R &a,const R &b) { if(a.h!=b.h) return a.h<b.h; if(a.w!=b.w) return a.w<b.w; return false; }

int n;
R r[MAXN];

ll allw[MAXN]; int nw;
ll allh[MAXN]; int nh;

vector<R> byh[MAXN];

bool prodsame(ll a,ll b,ll c,ll d) {
	ll g1=gcd(a,c); a/=g1,c/=g1;
	if(d%a!=0) return false; d/=a; a=1;
	if(b%c!=0) return false; b/=c; c=1;
	return b==d;
}
ll lcm(ll a,ll b) {
	if(a==LLONG_MAX||b==LLONG_MAX) return LLONG_MAX;
	ll g=gcd(a,b);
	b/=g;
	if(a>LLONG_MAX/b) return LLONG_MAX; else return a*b;
}

ll solve() {
	nw=0; REP(i,n) allw[nw++]=r[i].w; sort(allw,allw+nw); nw=unique(allw,allw+nw)-allw; REP(i,n) r[i].w=lower_bound(allw,allw+nw,r[i].w)-allw;
	nh=0; REP(i,n) allh[nh++]=r[i].h; sort(allh,allh+nh); nh=unique(allh,allh+nh)-allh; REP(i,n) r[i].h=lower_bound(allh,allh+nh,r[i].h)-allh;
	sort(r,r+n);
	//printf("w:"); REP(i,nw) printf(" %lld",allw[i]); puts("");
	//printf("h:"); REP(i,nh) printf(" %lld",allh[i]); puts("");
	//printf("r:"); REP(i,n) printf(" [%lld,%lld,%lld]",r[i].w,r[i].h,r[i].c); puts("");

	REP(i,n) byh[r[i].h].PB(r[i]);
	REP(i,nh) if(SZ(byh[i])!=nw) return 0;

	REP(i,nh) REP(j,nw) if(!prodsame(byh[0][0].c,byh[i][j].c,byh[0][j].c,byh[i][0].c)) return 0;


	ll grow=byh[0][0].c; FOR(j,1,nw) grow=gcd(grow,byh[0][j].c);
	ll gmult=1; FOR(i,1,nh) { ll num=byh[i][0].c,den=byh[0][0].c,g=gcd(num,den); num/=g,den/=g; gmult=lcm(gmult,den); }
	if(gmult==LLONG_MAX) return 0;
	//printf("grow=%lld gmult=%lld\n",grow,gmult);

	ll ret=0; 
	for(int i=1;(ll)i*i<=grow;++i) if(grow%i==0) {
		if(i%gmult==0) ++ret;
		if((ll)i*i!=grow&&(grow/i)%gmult==0) ++ret;
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld%lld%lld",&r[i].w,&r[i].h,&r[i].c);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}