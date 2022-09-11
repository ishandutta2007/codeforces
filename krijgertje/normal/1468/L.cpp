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

const int MAXN = 1000;
const int MAXP = 1000000;

int n, want;
ll a[MAXN];
ll ans[MAXN];

bool isprime[MAXP + 1];
vector<int> primes;

bool testprime(int x) {
	if (x <= 1) return false;
	for (int p : primes) {
		if (x == p) return true;
		if (x % p == 0) return false;
		if (p * p > x) break;
	}
	return true;
}

bool solve() {
	// for each prime in values taken, we also have to take at least two p^k
	// so these are either p and p^2 (and both must exist in the list) or one of them has k>=3, so has p<=MAXP

	REPE(i, MAXP) isprime[i] = true;
	isprime[0] = isprime[1] = false;
	FORE(i, 2, MAXP) if (isprime[i]) for (int j = i + i; j <= MAXP; j += i) isprime[j] = false;
	primes.clear(); REPE(i, MAXP) if (isprime[i]) primes.PB(i);

	map<int, int> pcnt; // number of k such that we have p^k
	set<int> have; REP(i, n) have.insert(a[i]);
	REPE(p, MAXP) if (isprime[p]) {
		ll cur = 1;
		for (int k = 1;; ++k) {
			if (cur > LLONG_MAX / p) break;
			cur *= p;
			if (k >= 3 && have.count(cur)) ++pcnt[p];
		}
	}
	REP(i, n) {
		int p = sqrt(1.0 * a[i]);
		if ((ll)p * p != a[i]) continue;
		if (!testprime(p)) continue;
		++pcnt[p];
	}
	vector<int> pany;
	for (auto kvp : pcnt) pany.PB(kvp.first);
	for (int p : pany) {
		if (have.count(p)) ++pcnt[p];
	}
	vector<int> pvalid;
	for (auto kvp : pcnt) if (kvp.second >= 2) pvalid.PB(kvp.first);
	//printf("pvalid:"); for (int p : pvalid) printf(" %d", p); puts("");

	vector<vector<int>> ppow(SZ(pvalid));
	vector<pair<int, vector<int>>> oth;
	REP(i, n) {
		ll x = a[i];
		vector<int> need;
		REPSZ(j, pvalid) if (x % pvalid[j] == 0) {
			need.PB(j);
			while (x % pvalid[j] == 0) x /= pvalid[j];
		}
		if (x != 1) continue;
		assert(SZ(need) >= 1);
		if (SZ(need) == 1) {
			ppow[need[0]].PB(i);
		} else {
			oth.PB(MP(i, need));
		}
	}
	//printf("ppow:"); for (auto lst : ppow) printf(" %d", SZ(lst)); puts("");
	//REPSZ(i, oth) { printf("oth%d: %d = %d\n", i, oth[i].first, SZ(oth[i].second)); }

	vector<int> big, two;
	REPSZ(i, pvalid) {
		assert(SZ(ppow[i]) >= 2);
		if (SZ(ppow[i]) >= 3) big.PB(i); else two.PB(i);
	}
	vector<int> use;
	int rem = want;
	if (SZ(big) >= 1 || rem % 2 == 0) {
		for (int idx : big) {
			if (rem == 1) {
				if (SZ(use) == 0) return false;
				use.erase(use.begin()), ++rem;
			}
			for (int at : ppow[idx]) if (rem != 0) {
				use.PB(at), --rem;
			}
		}
		for (int idx : two) {
			if (rem == 1) {
				assert(SZ(use) >= 1);
				use.erase(use.begin()), ++rem;
			}
			for (int at : ppow[idx]) if (rem != 0) {
				use.PB(at), --rem;
			}
		}
		for (auto kvp : oth) if (rem != 0) {
			use.PB(kvp.first), --rem;
		}
	} else {
		int best = -1;
		REPSZ(i, oth) if (best == -1 || SZ(oth[i].second) < SZ(oth[best].second)) best = i;
		//printf("best=%d\n", best);
		if (best == -1 || want < 2 * SZ(oth[best].second) + 1) return false;
		vector<bool> done(SZ(pvalid), false);
		for (int idx : oth[best].second) {
			done[idx] = true;
			for (int at : ppow[idx]) {
				assert(rem >= 1), use.PB(at), --rem;
			}
		}
		assert(rem >= 1), use.PB(oth[best].first), --rem;
		for (int idx : two) {
			if (done[idx]) continue;
			if (rem == 0) continue;
			for (int at : ppow[idx]) {
				assert(rem >= 1), use.PB(at), --rem;
			}
		}
		for (auto kvp : oth) if (rem != 0) {
			if (kvp.first == oth[best].first) continue;
			use.PB(kvp.first), --rem;
		}
	}
	if (rem != 0) return false;
	REPSZ(i, use) ans[i] = a[use[i]];
	return true;
}

void run() {
	scanf("%d%d", &n, &want);
	REP(i, n) scanf("%lld", &a[i]);
	if (!solve()) { printf("0\n"); return; }
	REP(i, want) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}