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

bool local = false;
ll locneed, loclast; int nq; set<ll> locseen;

ll n;

bool query(ll x) {
	++nq;
	if (!local) {
		printf("? %lld\n", x + 1); fflush(stdout);
		int res; scanf("%d", &res); return res == 1;
	} else {
		assert(x >= 0 && x < n && !locseen.count(x)); locseen.insert(x);
		ll have = abs(loclast - x); loclast = x;
		return have >= locneed;
	}
}

struct Strat {
	ll cnt;
	int l = -1, r = -1;
	ll start, jump;
	Strat(ll cnt) :cnt(cnt) {}
};


vector<Strat> strat;
int ensure(ll cnt) { assert(SZ(strat) >= 1); int lastidx = SZ(strat) - 1; ll lastcnt = strat[lastidx].cnt; assert(cnt <= lastcnt); if (cnt == lastcnt) return lastidx; strat.PB(Strat(cnt)); return SZ(strat) - 1; }

ll solve() {
	strat.clear();
	strat.PB(Strat(n));
	REPSZ(i, strat) {
		ll cnt = strat[i].cnt;
		if (cnt == 1) continue;
		int r = ensure((cnt + 1) / 2);
		int l = ensure(cnt / 2);
		strat[i].r = r;
		strat[i].l = l;
	}
	for (int i = SZ(strat) - 1; i >= 0; --i) {
		ll cnt = strat[i].cnt;
		if (cnt == 1) { strat[i].start = 0; strat[i].jump = -1; continue; }
		strat[i].jump = cnt / 2; strat[i].start = cnt - 1 - strat[i].jump - strat[strat[i].r].start;
	}
	//REPSZ(i, strat) printf("%d: cnt=%lld sub=(%d,%d) start=%lld jump=%lld\n", i, strat[i].cnt, strat[i].l, strat[i].r, strat[i].start, strat[i].jump);
	int dir = +1; int at = 0; ll last = strat[at].start, extrajump = 0;
	query(last);
	while (strat[at].cnt != 1) {
		ll next = last + dir*(extrajump + strat[at].jump);
		bool notice = query(next);
		if (notice) {
			at = strat[at].l;
		} else {
			extrajump += strat[at].jump;
			at = strat[at].r;
		}
		last = next; dir = -dir;
	}
	return extrajump + 1;
}

void run() {
	scanf("%lld", &n);
	printf("= %lld\n", solve()); fflush(stdout);
}

void stress() {
	local = true; int mxq = -1;
	/*for (n = 1; n <= 1000; ++n) {
		for (locneed = 1; locneed <= n; ++locneed) {
			nq = 0; locseen.clear();
			ll ans = solve();
			assert(ans == locneed);
			if (nq > mxq) printf("mxq %lld/%lld -> %d\n", n, locneed, nq), mxq = nq;
		}
		if(n%100==0) printf("done %lld\n", n);
	}*/
	REP(rep, 10000) {
		n = rnd() % 1000000000 + 1;
		locneed = rnd() % n + 1;
		nq = 0; locseen.clear();
		ll ans = solve();
		assert(ans == locneed);
		printf(".");
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}