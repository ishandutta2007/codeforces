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

const int EVEN = 0;
const int ODD = 1;
const int ALWAYS = 2;

struct Range {
	ll l, r; int when;
	Range() {} Range(ll l, ll r, int when) :l(l), r(r), when(when) {}
	bool get(ll x) const { assert(x >= l && x <= r); if (when == ALWAYS) return true; if (when == EVEN) return x % 2 == 0; if (when == ODD) return x % 2 == 1; assert(false); return false; }
};


int getparitywhen(ll x, bool win) { if (win) return x % 2 == 0 ? EVEN : ODD; else return x % 2 == 0 ? ODD : EVEN; }
vector<Range> calc(ll lim, int prefixwhen, int suffixwhen) {
	vector<Range> ret;
	ll x = 1; while (2 * x <= lim) x *= 2;
	ll y = lim;
	ret.PB(Range(x, y, prefixwhen));
	while (x > 1) {
		ll nx = x / 2;
		ll ny = y / 2;
		int nprefixwhen = -1, nsuffixwhen = -1;
		if (ny + 1 <= x - 1) {
			if (suffixwhen == ALWAYS || suffixwhen == EVEN) {
				nsuffixwhen = getparitywhen(x - 1, !ret.back().get(x));
			} else if (suffixwhen == ODD) {
				nsuffixwhen = ALWAYS;
			} else {
				assert(false);
			}
			ret.PB(Range(ny + 1, x - 1, nsuffixwhen));
		}
		if (prefixwhen == ALWAYS || prefixwhen == EVEN) {
			nprefixwhen = getparitywhen(ny, !ret.back().get(ny + 1));
		} else if (prefixwhen == ODD) {
			nprefixwhen = ALWAYS;
		} else {
			assert(false);
		}
		ret.PB(Range(nx, ny, nprefixwhen));
		x = nx, y = ny, prefixwhen = nprefixwhen, suffixwhen = nsuffixwhen;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

vector<Range> calcwin(ll lim) {
	if (lim % 2 == 1) return vector<Range>(1, Range(1, lim, EVEN));
	return calc(lim, ODD, ALWAYS);
}
vector<Range> calclose(ll lim) {
	return calc(lim, ALWAYS, ODD);
}

const int MAXROUND = 100000;

int nround;
ll s[MAXROUND], lim[MAXROUND];

bool get(const vector<Range>& ranges, ll x) {
	REPSZ(i, ranges) if (x >= ranges[i].l && x <= ranges[i].r) return ranges[i].get(x);
	assert(false); return false;
}

int solve(int wantturn) {
	for (int i = nround - 1; i >= 0; --i) {
		if (wantturn == 0) {
			vector<Range> ranges = calclose(lim[i]);
			wantturn = get(ranges, s[i]) ? 0 : 1;
		} else {
			vector<Range> ranges = calcwin(lim[i]);
			wantturn = get(ranges, s[i]) ? 0 : 1;
		}
	}
	return wantturn == 0;
}

int solvewin() {
	return solve(1);
}

int solvelose() {
	return solve(0);
}

void run() {
	scanf("%d", &nround);
	REP(i, nround) scanf("%lld%lld", &s[i], &lim[i]);
	printf("%d %d\n", solvewin(), solvelose());
}

void research() {
	// try to win
	/*REPE(lim, 10000) {
		//if (lim % 2 != 0) continue;
		vector<bool> win(lim + 1, false);
		for (int i = lim; i >= 1; --i) {
			if (i + 1 <= lim && !win[i + 1]) win[i] = true;
			if (2 * i <= lim && !win[2 * i]) win[i] = true;
		}
		vector<Range> ranges = calcwin(lim);
		bool ok = true; REPSZ(i, ranges) FORE(j, ranges[i].l, ranges[i].r) if (ranges[i].get(j) != win[j]) ok = false;
		if (ok) { printf("."); continue; }
		// for lim%2==1: REPE(i, lim) assert(win[i] == (i % 2 == 0));
		printf("\nwant %3d: ", lim); FORE(i, 1, lim) printf("%d", win[i] ? 1 : 0); puts("");
		vector<bool> have(lim + 1, false); REPSZ(i, ranges) FORE(j, ranges[i].l, ranges[i].r) have[j] = ranges[i].get(j);
		printf("have %3d: ", lim); FORE(i, 1, lim) printf("%d", have[i] ? 1 : 0); puts("");
		break;
	}*/
	// try to lose
	/*REPE(lim, 10000) {
		vector<bool> lose(lim + 1, false);
		for (int i = lim; i >= 1; --i) {
			if (i + 1 > lim || !lose[i + 1]) lose[i] = true;
			if (2 * i > lim || !lose[2 * i]) lose[i] = true;
		}
		vector<Range> ranges = calclose(lim);
		bool ok = true; REPSZ(i, ranges) FORE(j, ranges[i].l, ranges[i].r) if (ranges[i].get(j) != lose[j]) ok = false;
		if (ok) { printf("."); continue; }
		// for lim%2==1: REPE(i, lim) assert(win[i] == (i % 2 == 0));
		printf("\nwant %3d: ", lim); FORE(i, 1, lim) printf("%d", lose[i] ? 1 : 0); puts("");
		vector<bool> have(lim + 1, false); REPSZ(i, ranges) FORE(j, ranges[i].l, ranges[i].r) have[j] = ranges[i].get(j);
		printf("have %3d: ", lim); FORE(i, 1, lim) printf("%d", have[i] ? 1 : 0); puts("");
		break;
	}*/
}

int main() {
	//research();
	run();
	return 0;
}