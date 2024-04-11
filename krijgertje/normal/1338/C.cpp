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

ll q;

ll solve() {
	if (q == 0) return 1; else if (q == 1) return 2; else if (q == 2) return 3;
	q -= 3;
	ll x = 4; int ndig = 1; while (q >= 3 * x) q -= 3 * x, x *= 4, ++ndig;
	ll pos = q / 3; int offset = q % 3;
	//printf("\t%lld %lld %d (ndig=%d)\n", x, pos, offset, ndig);

	vector<int> d; { ll tmp = pos; REP(i, ndig) d.PB(tmp % 4), tmp /= 4;  } reverse(d.begin(), d.end());
	//printf("\td:"); REPSZ(i, d) printf(" %d", d[i]); puts("");
	
	ll a = x + pos;
	ll b = 2 * x; { ll tmp = 1; for (int i = ndig - 1; i >= 0; --i) { b += tmp * (d[i] == 0 ? 0 : d[i] == 1 ? 2 : d[i] == 2 ? 3 : 1); tmp *= 4; } }
	ll c = a ^ b;
	return offset == 0 ? a : offset == 1 ? b : offset == 2 ? c : -1;
}

void run() {
	scanf("%lld", &q), --q;
	printf("%lld\n", solve());

}

void research() {
	set<int> seen;
	vector<int> res;
	for (int i = 1;; ++i) {
		if (seen.count(i)) continue;
		if (SZ(res) >= 100) break;
		for(int j = i + 1;; ++j) {
			if (seen.count(j)) continue;
			int k = i ^ j;
			if (seen.count(k)) continue;
			res.PB(i); res.PB(j); res.PB(k);
			seen.insert(i); seen.insert(j); seen.insert(k); break;
		}
	}
	//printf("res:"); REPSZ(i, res) printf(" %d", res[i]); puts("");
	//printf("res:"); for (int i = 0; i < SZ(res); i += 3) printf(" %d", res[i]); puts("");
	//printf("res:"); for (int i = 0; i < SZ(res);) { int j = i + 3; while (j < SZ(res) && res[j] == res[j - 3] + 1) j += 3; printf(" %d..%d", res[i], res[j - 3]); i = j; }
	//printf("res:\n"); REPSZ(i, res) { printf("%4d", res[i]); if (i % 3 == 2) puts(""); }
}

int main() {
	//research();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}