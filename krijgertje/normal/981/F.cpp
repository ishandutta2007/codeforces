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

int n; ll len;
ll a[MAXN];
ll b[MAXN];

ll c[3*MAXN];

int l[MAXN],r[MAXN];

bool can(ll mxdst) {
	if(2*mxdst>=len) return true;
	//printf("testing %lld\n",mxdst);

	r[0]=0; while(r[0]<3*n&&c[r[0]]<=a[0]+mxdst) ++r[0]; --r[0];
	l[0]=3*n-1; while(l[0]>=0&&c[l[0]]>=a[0]-mxdst) --l[0]; ++l[0];
	//printf("0: %d..%d\n",l[0],r[0]);
	if(l[0]>r[0]) return false;

	FOR(i,1,n) {
		l[i]=l[i-1]; while(c[l[i]]<a[i]-mxdst) ++l[i];
		r[i]=r[i-1]; while(r[i]+1<3*n&&c[r[i]+1]<=a[i]+mxdst) ++r[i];
	}
	int lb=INT_MIN,ub=INT_MAX;
	REP(i,n) lb=max(lb,l[i]-i),ub=min(ub,r[i]-i);
	//printf("ranges:"); REP(i,n) printf(" %d..%d",l[i],r[i]); printf(" -> lb=%d ub=%d\n",lb,ub);
	return lb<=ub;
}

ll solve() {
	sort(a,a+n); sort(b,b+n);
	REP(i,n) c[i]=b[i]-len,c[i+n]=b[i],c[i+2*n]=b[i]+len;

	ll l=-1,r=len;
	while(l+1<r) {
		ll m=l+(r-l)/2;
		if(can(m)) r=m; else l=m;
	}
	return r;
}

void run() {
	scanf("%d%lld",&n,&len); REP(i,n) scanf("%lld",&a[i]); REP(i,n) scanf("%lld",&b[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}