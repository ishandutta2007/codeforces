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

struct Op { ll a, b; char kind; Op() {} Op(ll a, ll b, char kind) :a(a), b(b), kind(kind) {} };

int x;
vector<Op> ans;

vector<int> calcmult() {
	auto upd = [&](vector<ll>& have, int& nhave, int& mxbit, ll y) {
		while ((2LL << mxbit) <= y) ++mxbit;
		for (int bit = 0; (1LL << bit) <= y; ++bit) if (y & (1LL << bit)) {
			while (bit >= SZ(have)) have.PB(0);
			if (have[bit] == 0) { have[bit] = y; ++nhave; break; }
			y ^= have[bit];
		}
		return nhave == mxbit + 1;
	};

	vector<int> ret;
	vector<ll> use;
	int nuse = 0;
	int mxbituse = 0;
	bool done = upd(use, nuse, mxbituse, x);
	int need = 1;
	ret.PB(1);
	while (!done) {
		vector<ll> have = use;
		int nhave = nuse;
		int mxbit = mxbituse;
		for (int i = 1;; ++i) {
			ll y = (ll)i * x;
			if (upd(have, nhave, mxbit, y)) {
				done = upd(use, nuse, mxbituse, y);
				++need;
				ret.PB(i);
				break;
			}
		}
	}
	//printf("use:"); REPSZ(i, use) printf(" %llx", use[i]); puts("");
	return ret;
}

void solve() {
	vector<int> mult = calcmult();
	//printf("mult:"); REPSZ(i, mult) printf(" %d", mult[i]); puts("");

	set<ll> have;
	have.insert(x);
	ans.clear();

	auto doadd = [&](const ll a, const ll b) {
		if (have.count(a + b)) return;
		assert(have.count(a));
		assert(have.count(b));
		have.insert(a + b);
		ans.PB(Op(a, b, '+'));
	};
	auto doxor = [&](const ll a, const ll b) {
		if (have.count(a ^ b)) return;
		assert(have.count(a));
		assert(have.count(b));
		have.insert(a ^ b);
		ans.PB(Op(a, b, '^'));
	};

	int mxbit = 0;
	REPSZ(i, mult) {
		while ((2LL << mxbit) <= mult[i]) ++mxbit;
	}
	FORE(i, 1, mxbit) {
		ll a = (1LL << (i - 1)) * x;
		doadd(a, a);
	}
	REPSZ(i, mult) {
		int cur = 0;
		REPE(k, mxbit) if (mult[i] & (1 << k)) {
			if (cur == 0) { cur |= 1 << k; continue; }
			doadd((ll)cur * x, (1LL << k) * x);
			cur |= 1 << k;
		}
		assert(have.count((ll)mult[i] * x));
	}

	vector<ll> base;
	REPSZ(i, mult) {
		ll y = (ll)mult[i] * x;
		for (int bit = 0; (1LL << bit) <= y; ++bit) if (y & (1LL << bit)) {
			while (bit >= SZ(base)) base.PB(0);
			if (base[bit] == 0) { base[bit] = y; break; }
			doxor(y, base[bit]);
			y ^= base[bit];
		}
	}
	for (int i = SZ(base) - 1; i >= 0; --i) REP(j, i) if (base[j] & (1LL << i)) { doxor(base[j], base[i]); base[j] ^= base[i]; }
	REPSZ(i, base) assert(base[i] == (1LL << i));
	assert(have.count(1));
}

void run() {
	scanf("%d", &x);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%lld %c %lld\n", ans[i].a, ans[i].kind, ans[i].b);
}

int main() {
	run();
	return 0;
}