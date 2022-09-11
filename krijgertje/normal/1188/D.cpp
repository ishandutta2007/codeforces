#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n;
ll a[MAXN];

ll b[MAXN];
ll dp[MAXN+1]; // dp[i] = min cost so that the first i have carry

ll c[MAXN]; int nc;
ll ndp[MAXN+1];

void upd(ll &a,ll b) { a=min(a,b); }
ll solve() {
	//REP(i,n) { ll x=a[i]; while(x!=0) printf("%d",((int)(x&1))),x/=2; puts(""); }

	REP(i,n) b[i]=a[i];
	dp[0]=0; FORE(i,1,n) dp[i]=LLONG_MAX;

	while(true) {
		//printf("b:"); REP(i,n) printf(" %lld",b[i]); puts("");
		//printf("dp:"); REPE(i,n) printf(" %lld",dp[i]); puts("");

		bool allzero=true; REP(i,n) if(b[i]!=0) { allzero=false; break; }
		if(allzero) { ll ret=dp[0]; FORE(i,1,n) if(dp[i]!=LLONG_MAX) ret=min(ret,dp[i]+n-i); return ret; }

		REPE(i,n) ndp[i]=LLONG_MAX;
		int x0=0,x1=0,y0=0,y1=0; REP(i,n) if((b[i]&1)==0) ++y0; else ++y1;
		REPE(i,n) {
			if(dp[i]!=LLONG_MAX) {
				//printf("\t%d: (%d,%d)|(%d,%d)\n",i,x0,x1,y0,y1);
				// make current bit 0
				upd(ndp[i+y1],dp[i]+x0+y1);
				// make current bit 1
				upd(ndp[x1],dp[i]+x1+y0);
			}
			if(i==n) break;
			if((b[i]&1)==0) --y0,++x0; else --y1,++x1;
		}

		nc=0; REP(i,n) if((b[i]&1)!=0) c[nc++]=b[i]; REP(i,n) if((b[i]&1)==0) c[nc++]=b[i]; REP(i,n) b[i]=c[i]>>1;
		REPE(i,n) dp[i]=ndp[i];
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld",&a[i]);
	printf("%lld\n",solve());
}

int mxn=10,mxbits=6;

ll solvestupid() {
	ll mx=a[0]; FOR(i,1,n) mx=max(mx,a[i]);
	ll ret=LLONG_MAX;
	REP(delta,1<<mxbits) {
		ll cur=0;
		REP(i,n) { ll x=mx+delta-a[i]; while(x!=0) ++cur,x-=x&-x; }
		ret=min(ret,cur);
	}
	return ret;
}

void stress() {
	REP(rep,1000) {
		n=rand()%mxn+1;
		REP(i,n) a[i]=rand()%(1<<mxbits);
		ll have=solve();
		ll want=solvestupid();
		if(have==want) { printf("."); continue; }
		printf("have=%lld want=%lld\n",have,want);
		printf("%d\n",n); REP(i,n) { if(i!=0) printf(" "); printf("%lld",a[i]); } puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}