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

const ll LIM=1000000000000000000LL;

vector<ll> all;

ll solve(ll x) {
	if(x==0) return 0;
	ll ret=0;
	ll y=(ll)sqrt(1.0*x);
	ret+=y;
	int nall=upper_bound(all.begin(),all.end(),x)-all.begin();
	ret+=nall;
	return ret;
}

void run() {
	for(int p=3;;++p) {
		bool any=false;
		for(ll a=2;;++a) {
			ll cur=a; REP(i,p-1) cur=cur>LIM/a?LLONG_MAX:cur*a; if(cur>LIM) break; else any=true;
			ll b=(ll)sqrt(1.0*cur);
			if(b*b==cur) continue;
			all.PB(cur);
		}
		if(!any) break;
	}
	sort(all.begin(),all.end()); all.erase(unique(all.begin(),all.end()),all.end());
	//printf("%d\n",SZ(all));

	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		ll l,r; scanf("%lld%lld",&l,&r);
		ll ans=solve(r)-solve(l-1);
		printf("%lld\n",ans);
	}
}

int main() {
	run();
	return 0;
}