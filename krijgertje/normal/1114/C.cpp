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

ll n,b;

vector<pair<ll,int>> factorize(ll x) { vector<pair<ll,int>> ret; for(int i=2;(ll)i*i<=x;++i) if(x%i==0) { int cnt=0; while(x%i==0) ++cnt,x/=i; ret.PB(MP((ll)i,cnt)); } if(x!=1) ret.PB(MP(x,1)); return ret; }

ll calc(ll p) { // count how many times n! is divisible by p
	ll ret=0;
	for(ll x=n;x>=p;x/=p) ret+=x/p;
	return ret;
}

ll solve() {
	vector<pair<ll,int>> factors=factorize(b);
	//printf("factors:"); REPSZ(i,factors) printf(" (%lld,%d)",factors[i].first,factors[i].second); puts("");
	ll ret=LLONG_MAX;
	REPSZ(i,factors) ret=min(ret,calc(factors[i].first)/factors[i].second);
	return ret;
}

void run() {
	scanf("%lld%lld",&n,&b);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}