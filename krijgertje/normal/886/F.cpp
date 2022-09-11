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

const int MAXN=2000;
typedef struct P { ll x,y; P() {} P(ll x,ll y):x(x),y(y) {} } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
bool operator==(const P &a,const P &b) { return a.x==b.x&&a.y==b.y; }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator*(const P &a,const P &b) { return a.x*b.x+a.y*b.y; }

int n;
P p[MAXN];
P c; int mlt;

ll v[MAXN];

bool ok(const P &dir) {
	//printf("testing (%lld,%lld)\n",dir.x,dir.y);
	REP(i,n) v[i]=p[i]*dir; sort(v,v+n);
	//printf("v:"); REP(i,n) printf(" %lld",v[i]); puts("");
	ll sum=v[0]+v[n-1]; REP(i,n) if(v[i]+v[n-i-1]!=sum) return false;
	return true;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld%lld",&p[i].x,&p[i].y);
	
	mlt=n; c.x=c.y=0; REP(i,n) c.x+=p[i].x,c.y+=p[i].y;
	
	set<P> have;
	REP(i,n) {
		P cur=P(mlt*p[i].x,mlt*p[i].y);
		P opp=c-(cur-c);
		if(cur==opp) continue; else if(have.count(opp)) have.erase(opp); else have.insert(cur);
	}
	n=0; for(auto it=have.begin();it!=have.end();++it) p[n++]=P(it->x/mlt,it->y/mlt);
	if(n==0) { printf("-1\n"); return; }
	//printf("prem:"); REP(i,n) printf(" (%lld,%lld)",p[i].x,p[i].y); printf(" c=(%lld,%lld) mlt=%d\n",c.x,c.y,mlt);

	set<P> ptest;
	REP(j,n) {
		P a=P(2*c.x,2*c.y),b=P(mlt*(p[0].x+p[j].x),mlt*(p[0].y+p[j].y));
		P dir=P((b-a).y,-(b-a).x); if(dir.x<0||dir.x==0&&dir.y<0) dir.x=-dir.x,dir.y=-dir.y; ll g=gcd(dir.x,abs(dir.y)); dir.x/=g,dir.y/=g;
		ptest.insert(dir);
		//printf("test dir=(%lld,%lld)\n",dir.x,dir.y);
	}

	int ret=0;
	for(auto it=ptest.begin();it!=ptest.end();++it) if(ok(*it)) ++ret;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}