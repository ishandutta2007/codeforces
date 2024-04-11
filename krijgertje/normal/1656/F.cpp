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
#include <functional>
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
ll ans;

bool solve() {
	sort(a, a + n);
	ll sum = 0; REP(i, n) sum += a[i];
	if (sum + (ll)(n - 2) * a[0] > 0) return false;
	if (sum + (ll)(n - 2) * a[n - 1] < 0) return false;
	vector<int> neg, pos; int zero = 0;
	REP(i, n) if (a[i] < 0) neg.PB(-a[i]); else if (a[i] > 0) pos.PB(+a[i]); else ++zero;
	reverse(neg.begin(), neg.end());
	if (zero == n) { ans = 0; return true; }
	assert(SZ(neg) >= 1);
	assert(SZ(pos) >= 1);
	int useneg = neg.back(); neg.pop_back();
	int usepos = pos.back(); pos.pop_back();
	ll init = 0;
	init -= (ll)useneg * usepos;
	for (int x : neg) init -= (ll)x * usepos;
	for (int x : pos) init -= (ll)x * useneg;
	ans = init;
	{
		ll cur = init;
		ll delta = 0;
		delta += usepos - useneg;
		for (int x : neg) delta += usepos - x;
		for (int x : pos) delta += x - useneg;
		delta -= (ll)zero * useneg;
		//printf("0: %lld + t*%lld\n", cur, delta);
		REPSZ(i, neg) {
			int x = neg[i];
			int t = x;
			cur += (ll)x * usepos;
			cur += (ll)x * useneg;
			delta -= usepos - x;
			delta += -x - useneg;
			if (i + 1 >= SZ(neg) || neg[i + 1] != neg[i]) {
				//printf("%d: %lld + t*%lld\n", t, cur, delta);
				ans = max(ans, cur + (ll)t * delta);
			}
		}
	}
	{
		ll cur = init;
		ll delta = 0;
		delta += usepos - useneg;
		for (int x : neg) delta += usepos - x;
		for (int x : pos) delta += x - useneg;
		delta += (ll)zero * usepos;
		//printf("0: %lld + t*%d\n", cur, delta);
		REPSZ(i,pos) {
			int x = pos[i];
			int t = -x;
			cur += (ll)x * useneg;
			cur += (ll)x * usepos;
			delta -= x - useneg;
			delta += usepos + x;
			if (i + 1 >= SZ(pos) || pos[i + 1] != pos[i]) {
				//printf("%d: %lld + t*%lld\n", t, cur, delta);
				ans = max(ans, cur + (ll)t * delta);
			}
		}
	}

	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("INF\n"); return; }
	printf("%lld\n", ans);
}

ll ansstupid;
bool solvestupid() {
	vector<pair<int, int>> e;
	REP(i, n) FOR(j, i + 1, n) e.PB(MP(i, j));
	int m = SZ(e);
	vector<pair<int, int>> opt;
	REP(mask, 1 << m) {
		vector<pair<int, int>> use;
		REP(i, m) if (mask & (1 << i)) use.PB(e[i]);
		if (SZ(use) != n - 1) continue;
		vector<int> col(n); REP(i, n) col[i] = i;
		bool ok = true;
		int cnst = 0, var = 0;
		for (auto z : use) {
			int x = z.first, y = z.second;
			cnst += a[x] * a[y], var += a[x] + a[y];
			if (col[x] == col[y]) { ok = false; break; }
			int c = col[y];
			REP(i, n) if (col[i] == c) col[i] = col[x];
		}
		if (!ok) continue;
		opt.PB(MP(-var, cnst));
	}
	sort(opt.begin(), opt.end());
	REPSZ(i, opt) opt[i].first = -opt[i].first;
	//printf("opt:"); REPSZ(i, opt) printf(" %d*t+%d", opt[i].first, opt[i].second); puts("");
	vector<pair<int, int>> hull;
	auto good = [&](const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) {
		// t=(a.second-b.second)/(b.first-a.first) and (b.second-c.second)/(c.first-b.first)
		return (ll)(a.second - b.second) * (c.first - b.first) < (ll)(b.second - c.second) * (b.first - a.first);
	};
	REPSZ(i, opt) {
		if (SZ(hull) >= 1 && opt[i].first == hull[SZ(hull) - 1].first) continue;
		while (SZ(hull) >= 2 && !good(hull[SZ(hull) - 2], hull[SZ(hull) - 1], opt[i])) hull.pop_back();
		hull.PB(opt[i]);
	}
	//printf("hull:"); REPSZ(i, hull) printf(" %d*t+%d", hull[i].first, hull[i].second); puts("");
	assert(SZ(hull) >= 1);
	if (hull[0].first < 0) return false;
	if (hull[SZ(hull) - 1].first > 0) return false;
	if (SZ(hull) == 1) { 
		assert(hull[0].first == 0);
		ansstupid = hull[0].second;
	} else {
		ansstupid = LLONG_MIN;
		FORSZ(i, 1, hull) {
			auto a = hull[i - 1]; auto b = hull[i];
			ll num = a.second - b.second, den = b.first - a.first;
			// a.first*num/den+a.second
			num = a.first * num + a.second * den;
			assert(num % den == 0);
			ll cur = num / den;
			ansstupid = max(ansstupid, cur);
		}
	}
	return true;
}

void stress() {
	std::mt19937 rnd(2131);
	int mxn = 6, mxabsval = 100;
	REP(rep, 1000) {
		n = rnd() % (mxn - 2 + 1) + 2;
		REP(i, n) a[i] = rnd() % (2 * mxabsval + 1) - mxabsval;
		bool have = solve();
		bool want = solvestupid();
		bool ok = have == want && (!have || ans == ansstupid);
		if (ok) { printf("."); continue; }
		printf("err rep=%d have=%s want=%s\n", rep, (have ? to_string(ans) : "INF").c_str(), (want ? to_string(ansstupid) : "INF").c_str());
		printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
	}
}

int main() {
	//stress();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}