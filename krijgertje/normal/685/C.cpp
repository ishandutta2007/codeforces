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
typedef struct P { ll x,y,z; } P;

int n;
P p[MAXN];
ll x,y,z;

ll divdn(ll p,ll q) { return p>=0?p/q:(p-q+1)/q; }
ll divup(ll p,ll q) { return p>=0?(p+q-1)/q:p/q; }
bool ok(ll D) {
	//printf("\t testing %llu\n",D);

	// |x-px|+|y-py|+|z-pz|<=D

	// -D+px+py+pz<=+x+y+z<=D+px+py+pz
	// -D-px+py+pz<=-x+y+z<=D-px+py+pz
	// -D+px-py+pz<=+x-y+z<=D+px-py+pz
	// -D+px+py-pz<=+x+y-z<=D+px+py-pz

	// a=-x+y+z, b=x-y+z, c=x+y-z -> x+y+z=a+b+c -> x=(b+c)/2, y=(a+c)/2, z=(a+b)/2
	// -D+px+py+pz<=a+b+c<=D+px+py+pz
	// -D-px+py+pz<=a<=D-px+py+pz
	// -D+px-py+pz<=b<=D+px-py+pz
	// -D+px+py-pz<=c<=D+px+py-pz

	// a=2A+par, b=2B+par, c=2C+par -> x=B+C+par, y=A+C+par, z=A+B+par
	// -D+px+py+pz<=2A+2B+2C+3par<=D+px+py+pz
	// -D-px+py+pz<=2A+par<=D-px+py+pz
	// -D+px-py+pz<=2B+par<=D+px-py+pz
	// -D+px+py-pz<=2C+par<=D+px+py-pz
	ll sl=LLONG_MIN,su=LLONG_MAX;
	ll al=LLONG_MIN,au=LLONG_MAX;
	ll bl=LLONG_MIN,bu=LLONG_MAX;
	ll cl=LLONG_MIN,cu=LLONG_MAX;
	REP(i,n) {
		sl=max(sl,-D+p[i].x+p[i].y+p[i].z);
		al=max(al,-D-p[i].x+p[i].y+p[i].z);
		bl=max(bl,-D+p[i].x-p[i].y+p[i].z);
		cl=max(cl,-D+p[i].x+p[i].y-p[i].z);
		su=min(su,+D+p[i].x+p[i].y+p[i].z);
		au=min(au,+D-p[i].x+p[i].y+p[i].z);
		bu=min(bu,+D+p[i].x-p[i].y+p[i].z);
		cu=min(cu,+D+p[i].x+p[i].y-p[i].z);
	}
	REP(par,2) {
		ll SL=divup(sl-3*par,2),SU=divdn(su-3*par,2);
		ll AL=divup(al-par,2),AU=divdn(au-par,2);
		ll BL=divup(bl-par,2),BU=divdn(bu-par,2);
		ll CL=divup(cl-par,2),CU=divdn(cu-par,2);
		if(SL>SU||AL>AU||BL>BU||CL>CU) continue;
		ll A=AL,B=BL,C=CL;
		if(A+B+C<SL) {
			ll need=SL-A-B-C;
			ll DA=min(need,AU-AL); A+=DA; need-=DA;
			ll DB=min(need,BU-BL); B+=DB; need-=DB;
			ll DC=min(need,CU-CL); C+=DC; need-=DC;
		}
		if(A+B+C<SL||A+B+C>SU) continue;
		x=B+C+par,y=A+C+par,z=A+B+par;
		return true;
	}
	return false;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].z);

	ll l=-1,h=0; //[l,h]
	REP(i,n) h=max(h,abs(p[i].x)+abs(p[i].y)+abs(p[i].z));
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(ok(m)) h=m; else l=m;
	}
	assert(ok(h));
	//printf("D=%lld\n",h);
	printf("%lld %lld %lld\n",x,y,z);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n)
	run();
	return 0;
}