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
#include <chrono>
#include <chrono>
#include <random>
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

ll n;
vector<pair<ll,int>> fact;

void factorize(ll x) {
	fact.clear();
	for(ll i=2;i*i<=x;++i) if(x%i==0) {
		int cnt=0; while(x%i==0) x/=i,++cnt; fact.PB(MP(i,cnt));
	}
	if(x!=1) fact.PB(MP(x,1));
}

ll solve() {
	factorize(n);
	if(SZ(fact)>=2) return 1;
	if(SZ(fact)==0) return 1;
	assert(SZ(fact)==1); return fact[0].first;
}

void run() {
	scanf("%lld",&n);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}