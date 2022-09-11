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

const int MAXN = 300000;

int n;
ll hp[MAXN], dmg[MAXN];

ll need[MAXN];

ll solve() {
	REP(i, n) {
		int prv = i == 0 ? n - 1 : i - 1;
		need[i] = max(0LL, hp[i] - dmg[prv]);
	}
	ll ret = LLONG_MAX;
	ll sumneed = 0; REP(i, n) sumneed += need[i];
	REP(i, n) ret = min(ret, sumneed - need[i] + hp[i]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld%lld", &hp[i], &dmg[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}