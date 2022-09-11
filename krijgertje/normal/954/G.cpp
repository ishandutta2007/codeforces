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

const int MAXN=500000;

int n,mxdst; ll have;
int a[MAXN];

ll b[MAXN];
ll c[MAXN];

void run() {
	scanf("%d%d%lld",&n,&mxdst,&have); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) b[i]=0;
	REP(i,n) { int al=max(0,i-mxdst),ar=min(n-1,i+mxdst); b[al]+=a[i]; if(ar+1<n) b[ar+1]-=a[i]; }
	REP(i,n-1) b[i+1]+=b[i];
	//printf("b:"); REP(i,n) printf(" %lld",b[i]); puts("");

	ll bmn=b[0]; FOR(i,1,n) bmn=min(bmn,b[i]);
	ll l=bmn,r=bmn+have+1;
	while(l+1<r) {
		ll m=l+(r-l)/2;
		REP(i,n) c[i]=0;
		ll csum=0; ll need=0;
		REP(i,n) {
			csum+=c[i];
			if(b[i]+csum<m) {
				ll extra=m-(b[i]+csum);
				int at=min(n-1,i+mxdst);
				int al=max(0,at-mxdst),ar=min(n-1,at+mxdst); assert(al<=i&&ar>=i);
				c[al]+=extra; csum+=extra; if(ar+1<n) c[ar+1]-=extra; need+=extra; if(need>have) break;
			}
		}
		if(need<=have) l=m; else r=m;
	}
	printf("%lld\n",l);
}

int main() {
	run();
	return 0;
}