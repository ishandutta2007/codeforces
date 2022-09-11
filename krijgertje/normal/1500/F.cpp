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

const int MAXN = 1000000;

int n; ll wlim;
ll w[MAXN - 2];
ll ans[MAXN];


struct State {
	ll offset; int dir;
	set<pair<ll, ll>> ranges;

	void init(ll x) { offset = 0; dir = +1; ranges.clear(); ranges.insert(MP(0LL, x)); }
	bool has(ll x) {
		ll y = offset + dir * x;
		auto it = ranges.upper_bound(MP(y, LLONG_MAX));
		if (it == ranges.begin()) return false;
		it = prev(it);
		return it->first <= y && y <= it->second;
	}
	bool empty() {
		return SZ(ranges) == 0;
	}
	void reduce(ll x) {
		ll y = offset + dir * x;
		if (dir == +1) {
			auto it = ranges.upper_bound(MP(y, LLONG_MAX));
			while (it != ranges.end()) ranges.erase(it++);
			if (it == ranges.begin()) return;
			it = prev(it);
			if (it->second <= y) return;
			ll from = it->first;
			ranges.erase(it);
			ranges.insert(MP(from, y));
		} else {
			auto it = ranges.lower_bound(MP(y, LLONG_MIN));
			if (it == ranges.begin()) return;
			it = prev(it);
			ll to = it->second;
			while (it != ranges.begin()) ranges.erase(it--);
			ranges.erase(it);
			if (to >= y) ranges.insert(MP(y, to));
		}
	}
	void flip(ll x) { offset += dir * x; dir = -dir; }
	void add(ll x) {
		if (has(x)) return;
		ll y = offset + dir * x;
		ranges.insert(MP(y, y));
	}
	ll smallest() {
		assert(!empty());
		if (dir == +1) {
			return ranges.begin()->first - offset;
		} else {
			return offset - ranges.rbegin()->second;
		}
	}
};

bool solve() {
	assert(n >= 3);

	State state;
	state.init(w[0]);
	vector<bool> onleft(n - 2, false);
	vector<ll> smallest(n - 2);
	onleft[0] = true;
	smallest[0] = state.smallest();
	FOR(i, 1, n - 2) {
		if (state.has(w[i])) {
			onleft[i] = true;
			state.init(w[i]);
		} else {
			state.reduce(w[i]);
			if (state.empty()) return false;
			state.flip(w[i]);
			state.add(w[i]);
		}
		smallest[i] = state.smallest();
		//printf("\t%d:", i); FORE(k, -50, +50) if (state.has(k)) printf(" %d", k); puts("");
	}
	//printf("onleft: "); REP(i, n - 2) printf("%c", onleft[i] ? 'V' : '.'); puts("");
	//printf("smallest:"); REP(i, n - 2) printf(" %lld", smallest[i]); puts("");

	vector<ll> d(n - 1);
	d[n - 2] = smallest[n - 3];
	int sgn = +1;
	for (int i = n - 3; i >= 0; --i) {
		if (onleft[i]) {
			sgn = -sgn;
			d[i] = sgn * w[i];
		} else {
			ll nxt = abs(d[i + 1]);
			if (nxt == w[i]) {
				sgn = -sgn;
				d[i] = sgn * smallest[i - 1];
			} else {
				d[i] = sgn * (w[i] - nxt);
			}
		}
	}
	//printf("d:"); REP(i, n - 1) printf(" %lld", d[i]); puts("");

	ans[0] = 0; REP(i, n - 1) ans[i + 1] = ans[i] + d[i];
	ll mn = ans[0]; FOR(i, 1, n) mn = min(mn, ans[i]);
	REP(i, n) ans[i] -= mn;


	return true;
}


void run() {
	scanf("%d%lld", &n, &wlim);
	REP(i, n - 2) scanf("%lld", &w[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

void stress() {
	int mxn = 20, mxlim = 200;
	REP(rep, 10000) {
		n = rnd() % (mxn - 3 + 1) + 3; wlim = rnd() % mxlim;
		REP(i, n - 2) w[i] = rnd() % (wlim + 1);
		if (solve()) {
			vector<ll> have(n - 2);
			REP(i, n - 2) { ll a = ans[i], b = ans[i + 1], c = ans[i + 2]; have[i] = max({ a, b, c }) - min({ a, b, c }); }
			bool ok = true; REP(i, n - 2) if (have[i] != w[i]) ok = false;
			if (ok) { printf("."); continue; }
			printf("err\n");
			printf("%d %lld\n", n, wlim);
			REP(i, n - 2) { if (i != 0) printf(" "); printf("%lld", w[i]); } puts("");
			printf("ans:"); REP(i, n) printf(" %lld", ans[i]); puts("");
			printf("have:"); REP(i, n - 2) printf(" %lld", have[i]); puts("");
			break;
		}
	}
}

int main() {
	run();
	//stress();
	return 0;
}