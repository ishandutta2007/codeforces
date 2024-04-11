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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 200000;

int n;
int a[MAXN];

int b[MAXN], nb;

ll solve() {
	ll sum = 0; for (int i = 0; i < n; i += 2) sum += a[i];
	ll extra = 0;
	REP(par, 2) {
		nb = 0;
		for (int i = par; i + 1 < n; i += 2) b[nb++] = a[i] - a[i + 1];
		if (par == 0) REP(i, nb) b[i] = -b[i];
		//printf("b:"); REP(i, nb) printf(" %d", b[i]); puts("");
		ll cur = 0;
		REP(i, nb) {
			if (cur < 0) cur = 0;
			cur += b[i];
			extra = max(extra, cur);
		}
	}
	//printf("sum=%lld extra=%lld\n", sum, extra);
	return sum + extra;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}