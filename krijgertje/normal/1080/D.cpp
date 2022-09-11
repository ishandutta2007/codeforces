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

ll n,k;

ll safeadd(ll a,ll b) { if(a>LLONG_MAX-b) return LLONG_MAX; else return a+b; }
ll dup(ll x) { return safeadd(x,x); }


ll calcextrasingle(ll n) {
	ll ret=0;
	while(n>0&&ret!=LLONG_MAX) {
		ret=safeadd(1,dup(dup(ret)));
		--n;
	}
	return ret;
}
ll calcextraduo(ll n,ll sz) {
	if(n==sz) return 0;
	ll ret=0;
	ret=safeadd(ret,dup(calcextrasingle(n-1)));
	if(ret!=LLONG_MAX) ret=safeadd(ret,dup(calcextraduo(n-1,sz)));
	return ret;
}
ll calcextratri(ll n,ll sz) {
	if(n==sz) return 0;
	ll ret=0;
	ret=safeadd(ret,calcextrasingle(n-1));
	if(ret!=LLONG_MAX) ret=safeadd(ret,dup(calcextraduo(n-1,sz)));
	if(ret!=LLONG_MAX) ret=safeadd(ret,calcextratri(n-1,sz));
	return ret;
}

ll solve() {
	ll ret=n,nsquares=1,ncuts=0;
	vector<ll> opt;
	while(ret>=0&&ncuts<=k) {
		ll need=k-ncuts,have=calcextratri(n,ret);
		//printf("\tret=%lld nsquares=%lld ncuts=%lld need=%lld have=%lld\n",ret,nsquares,ncuts,need,have);
		if(need<=have) opt.PB(ret);
		--ret; ncuts+=nsquares; nsquares=2*nsquares+1;
	}
	//if(SZ(opt)>=2) { printf("opt:"); REPSZ(i,opt) printf(" %lld",opt[i]); puts(""); }
	return SZ(opt)==0?-1:opt.back();
}

void run() {
	scanf("%lld%lld",&n,&k);
	ll ans=solve();
	if(ans==-1) printf("NO\n"); else printf("YES %lld\n",ans);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}