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

const int MAXN = 500000;

int n;
int a[MAXN];

struct Options {
	int sgn; ll delta;
	set<pair<ll, ll>> ranges; // if x is in one of ranges then actual value is sgn*x+delta <=> if actual value is y then sgn*(y-delta) is in one of ranges

	void flip(int a) { sgn = -sgn; delta = a - delta; } // every point x becomes a-x
	void trim(int l, int r) { // keep only points in [l..r]
		if (l > r) return; 
		ll xl = sgn * (l - delta), xr = sgn * (r - delta); 
		if (sgn == -1) swap(xl, xr);
		while (!ranges.empty()) {
			pair<ll, ll> cur = *ranges.begin();
			if (cur.first >= xl) break;
			ranges.erase(ranges.begin());
			if (cur.second < xl) continue;
			ranges.insert(MP(xl, cur.second));
		}
		while (!ranges.empty()) {
			pair<ll, ll> cur = *ranges.rbegin();
			if (cur.second <= xr) break;
			ranges.erase(prev(ranges.end()));
			if (cur.first > xr) continue;
			ranges.insert(MP(cur.first, xr));
		}
	} 
	bool empty() { return ranges.empty(); }
	void add(int l, int r) { ll xl = sgn * (l - delta), xr = sgn * (r - delta); if (sgn == -1) swap(xl, xr); ranges.insert(MP(xl, xr)); }
	void add(int y) { ll x = sgn * (y - delta); ranges.insert(MP(x, x)); }
	void clear() { ranges.clear(); sgn = +1; delta = 0; }
	bool contains(int y) { ll x = sgn * (y - delta); auto it = ranges.upper_bound(MP(x, LLONG_MAX)); if (it == ranges.begin()) return false; --it; return x <= it->second; }
	void print() { for (auto it = ranges.begin(); it != ranges.end(); ++it) printf(" [%lld..%lld]", sgn * it->first + delta, sgn * it->second + delta);	}
};



int solve() {
	int save = 0;
	Options options;
	options.clear();
	REP(i, n) {
		options.trim(1, a[i] - 1);
		if (options.empty()) {
			options.add(1, a[i] - 1);
		} else {
			++save;
		}
		options.flip(a[i]);
		if (a[i] % 2 == 0) {
			int half = a[i] / 2;
			if (options.contains(half)) {
				++save;
				options.clear();
			}
			options.add(half);
		}
		//printf("after %d: save=%d options=", a[i], save); options.print(); puts("");
	}
	return 2 * n - save;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}