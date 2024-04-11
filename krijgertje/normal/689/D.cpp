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

int n;
int a[MAXN];
int b[MAXN];

int mx[MAXN],lmx,rmx;
int mn[MAXN],lmn,rmn;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);

	ll ret=0;
	lmx=rmx=lmn=rmn=0;
	for(int at=0,to=0;at<n;++at) {
		if(to<at) to=at;
		while(lmx<rmx&&mx[lmx]<at) ++lmx;
		while(lmn<rmn&&mn[lmn]<at) ++lmn;
		while(to<n&&a[to]<=b[to]&&(at==to||a[to]<=b[mn[lmn]]&&a[mx[lmx]]<=b[to])) {
			while(lmx<rmx&&a[to]>=a[mx[rmx-1]]) --rmx; mx[rmx++]=to;
			while(lmn<rmn&&b[to]<=b[mn[rmn-1]]) --rmn; mn[rmn++]=to;
			++to;
		}
		ret+=to-at;
	}
	lmx=rmx=lmn=rmn=0;
	for(int at=0,to=0;at<n;++at) {
		if(to<at) to=at;
		while(lmx<rmx&&mx[lmx]<at) ++lmx;
		while(lmn<rmn&&mn[lmn]<at) ++lmn;
		while(to<n&&a[to]<b[to]&&(at==to||a[to]<b[mn[lmn]]&&a[mx[lmx]]<b[to])) {
			while(lmx<rmx&&a[to]>=a[mx[rmx-1]]) --rmx; mx[rmx++]=to;
			while(lmn<rmn&&b[to]<=b[mn[rmn-1]]) --rmn; mn[rmn++]=to;
			++to;
		}
		ret-=to-at;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}