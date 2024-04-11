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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

vector<pair<ll, int>> factorize(ll x) {
	vector<pair<ll, int>> ret;
	for (int i = 2; (ll)i * i <= x; ++i) if (x % i == 0) {
		int cnt = 0;
		while (x % i == 0) x /= i, ++cnt;
		ret.PB(MP((ll)i, cnt));
	}
	if (x != 1) ret.PB(MP(x, 1));
	return ret;
}

ll a, mod;

ll solve() {
	ll g = gcd(a, mod);
	vector<pair<ll, int>> fac = factorize(mod / g);
	//printf("g=%lld\n", g);
	//printf("fac:"); REPSZ(i, fac) printf(" [%lld,%d]", fac[i].first, fac[i].second); puts("");
	ll ret = 1;
	REPSZ(i, fac) {
		ret *= fac[i].first - 1;
		REP(j, fac[i].second - 1) ret *= fac[i].first;
	}
	return ret;
}

void run() {
	scanf("%lld%lld", &a, &mod);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}