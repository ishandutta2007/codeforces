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

const int MAXN=50;

int n;
ll a[MAXN];
int b[MAXN];

ll c[MAXN]; int nc;

vector<int> who[MAXN];

vector<ll> vals[MAXN];
ll dp[MAXN+1][MAXN+1];


bool ok(ll x) {
	REP(i,nc) vals[i].clear();
	REP(i,nc) REPSZ(j,who[i]) { int id=who[i][j]; vals[nc-i-1].PB(a[id]-x*b[id]); }
	REP(i,nc) sort(vals[i].begin(),vals[i].end());

	REPE(i,nc) REPE(j,n) dp[i][j]=LLONG_MAX; dp[0][0]=0;
	REP(i,nc) REPE(j,n) if(dp[i][j]!=LLONG_MAX) REPE(k,min(j,SZ(vals[i]))) {
		int ni=i+1,nj=j-k+SZ(vals[i])-k; ll ndp=dp[i][j]; REP(l,SZ(vals[i])-k) ndp+=vals[i][l];
		dp[ni][nj]=min(dp[ni][nj],ndp);
	}
	ll ans=LLONG_MAX; REPE(j,n) ans=min(ans,dp[nc][j]);
	//printf("%lld -> %lld\n",x,ans);
	return ans<=0;
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld",&a[i]),a[i]*=1000; REP(i,n) scanf("%d",&b[i]);

	nc=0; REP(i,n) c[nc++]=a[i]; sort(c,c+nc); nc=unique(c,c+nc)-c;
	REP(i,n) { int idx=lower_bound(c,c+nc,a[i])-c; who[idx].PB(i); }

	ll l=0,h=0; REP(i,n) h=max(h,a[i]);
	while(l+1<h) {
		ll m=l+(h-l)/2;
		if(ok(m)) h=m; else l=m;
	}
	printf("%lld\n",h);
}

int main() {
	run();
	return 0;
}