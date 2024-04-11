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

const int MAXQ=200000;
const int MAXN=200000;
typedef struct Q { int p,cap; } Q;
bool operator<(const Q &a,const Q &b) { if(a.p!=b.p) return a.p<b.p; return a.cap>=b.cap; }

int nq,n,s,t;
Q q[MAXQ];
int x[MAXN];

bool ok(int cap) {
	int left=t;
	REPE(i,n) {
		ll d=(i==n?s:x[i])-(i==0?0:x[i-1]);
		// normal+accel=d, normal+2*accel<=cap, min 2*normal+accel -> accel=cap-d, normal=2*d-cap -> 3*d-cap
		if(d>cap) return false;
		ll need=2*d<=cap?d:3*d-cap;
		if(need>left) return false; else left-=need;
	}
	return true;
}

void run() {
	scanf("%d%d%d%d",&nq,&n,&s,&t);
	REP(i,nq) scanf("%d%d",&q[i].p,&q[i].cap);
	REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	{ sort(q,q+nq); int m=0; REP(i,nq) if(m==0||q[i].cap>q[m-1].cap) q[m++]=q[i]; nq=m; }
	//REP(i,nq) printf("p=%d cap=%d\n",q[i].p,q[i].cap);

	int l=-1,h=nq;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(ok(q[m].cap)) h=m; else l=m;
	}
	printf("%d\n",h==nq?-1:q[h].p);
}

int main() {
	run();
	return 0;
}