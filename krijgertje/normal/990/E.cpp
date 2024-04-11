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

const int MAXN=1000000;

int n,nblocked,mxpow;
bool isblocked[MAXN];
int cost[MAXN+1];

int prv[MAXN+1];

ll solve() {
	if(isblocked[0]) return LLONG_MAX;
	REP(i,n) prv[i]=!isblocked[i]?i:prv[i-1];
	ll ret=LLONG_MAX;
	FORE(k,1,mxpow) {
		int cnt=0,at=0; bool ok=true;
		while(at<n) {
			++cnt; int to=at+k;
			if(to>=n) break;
			to=prv[to];
			if(at==to) { ok=false; break; }
			at=to;
		}
		if(!ok) continue;
		ll cur=(ll)cnt*cost[k];
		ret=min(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&nblocked,&mxpow);
	REP(i,n) isblocked[i]=false; REP(i,nblocked) { int x; scanf("%d",&x); isblocked[x]=true; }
	FORE(i,1,mxpow) scanf("%d",&cost[i]);

	ll ans=solve(); printf("%lld\n",ans==LLONG_MAX?-1LL:ans);
}

int main() {
	run();
	return 0;
}