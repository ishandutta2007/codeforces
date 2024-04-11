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

const int MAXN=100000;
typedef struct P { int x,y; } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }

int n;
P p[MAXN];
int lmny[MAXN],lmxy[MAXN],rmny[MAXN],rmxy[MAXN];

bool can(ll ret) {
	if(n==1) return ret>=0;
	int dx=p[n-1].x-p[0].x;
	if((ll)dx*dx<=ret) return true;
	int dy=max(rmxy[0],p[0].y)-min(rmny[0],p[0].y);
	if((ll)dy*dy<=ret) return true;
	for(int a=0,b=a;a<n&&p[a].x<=0;++a) {
		while(p[b].x>-p[a].x) --b;
		while(b<n&&p[b].x<=-p[a].x&&(ll)(p[b].x-p[a].x)*(p[b].x-p[a].x)<=ret) ++b;
		int mny=min(0,min(lmny[a],rmny[b-1])),mxy=max(0,max(lmxy[a],rmxy[b-1])),mxdy=max(-mny,mxy);
		ll side=(ll)p[a].x*p[a].x+(ll)mxdy*mxdy,diag=(ll)(mxy-mny)*(mxy-mny);
		if(side<=ret&&diag<=ret) {
			//printf("- %d..%d -> %d / %d [%lld,%lld,%lld]\n",a,b-1,mny,mxy,(ll)(p[b-1].x-p[a].x)*(p[b-1].x-p[a].x),side,diag);
			return true;
		}
	}
	for(int a=n-1,b=a;a>=0&&p[a].x>=0;--a) {
		while(-p[b].x>p[a].x) ++b;
		while(b>=0&&-p[b].x<=p[a].x&&(ll)(p[a].x-p[b].x)*(p[a].x-p[b].x)<=ret) --b;
		int mny=min(0,min(lmny[b+1],rmny[a])),mxy=max(0,max(lmxy[b+1],rmxy[a])),mxdy=max(-mny,mxy);
		ll side=(ll)p[a].x*p[a].x+(ll)mxdy*mxdy,diag=(ll)(mxy-mny)*(mxy-mny);
		if(side<=ret&&diag<=ret) {
			//printf("+ %d..%d -> %d / %d [%lld,%lld,%lld]\n",a+1,b,mny,mxy,(ll)(p[b].x-p[a+1].x)*(p[b].x-p[a+1].x),side,diag);
			return true;
		}
	}
	return false;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y); sort(p,p+n);
	//REP(i,n) printf("%d: (%d,%d)\n",i,p[i].x,p[i].y);
	
	lmny[0]=INT_MAX; lmxy[0]=INT_MIN;
	FOR(i,1,n) { lmny[i]=min(lmny[i-1],p[i-1].y); lmxy[i]=max(lmxy[i-1],p[i-1].y); }
	rmny[n-1]=INT_MAX; rmxy[n-1]=INT_MIN;
	for(int i=n-2;i>=0;--i) { rmny[i]=min(rmny[i+1],p[i+1].y); rmxy[i]=max(rmxy[i+1],p[i+1].y); }

	ll l=-1,h=1;
	while(!can(h)) l=h,h+=h;
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(can(m)) h=m; else l=m;
	}
	printf("%I64d\n",h);
}

int main() {
	run();
	return 0;
}