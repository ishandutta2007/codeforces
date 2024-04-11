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

struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };

P a[4];
P b[4];

bool inside(const P &p) {
	int lx=INT_MAX,ly=INT_MAX,hx=INT_MIN,hy=INT_MIN;
	REP(i,4) lx=min(lx,b[i].x),ly=min(ly,b[i].y),hx=max(hx,b[i].x),hy=max(hy,b[i].y);
	assert((hx-lx)%2==0); assert((hy-ly)%2==0); assert(hx-lx==hy-ly); int mx=(lx+hx)/2,my=(ly+hy)/2,sz=(hx-lx)/2;
	int dst=abs(p.x-mx)+abs(p.y-my);
	//printf("dia: [%d..%d..%d] [%d..%d..%d] (%d): (%d,%d) -> %d\n",lx,mx,hx,ly,my,hy,sz,p.x,p.y,dst);
	return dst<=sz;
}

bool solve() {
	int lx=INT_MAX,ly=INT_MAX,hx=INT_MIN,hy=INT_MIN;
	REP(i,4) lx=min(lx,a[i].x),ly=min(ly,a[i].y),hx=max(hx,a[i].x),hy=max(hy,a[i].y);
	//printf("sq: [%d..%d] [%d..%d]\n",lx,hx,ly,hy);
	bool ret=false;
	FORE(x,lx,hx) FORE(y,ly,hy) if(inside(P(x,y))) ret=true;
	return ret;
}

void run() {
	REP(i,4) scanf("%d%d",&a[i].x,&a[i].y);
	REP(i,4) scanf("%d%d",&b[i].x,&b[i].y);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}