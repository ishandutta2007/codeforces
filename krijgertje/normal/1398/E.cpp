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

const int MAXQ = 200000;

int nq;
int qtype[MAXQ], qval[MAXQ]; ll qans[MAXQ];

ll sum;
int cntlightning;
multiset<pair<int, int>> best;
multiset<pair<int, int>> worst;
multiset<ll> fire;
ll bestsum;
int cntlightninginbest;

void rebalance() {
	while (SZ(best) < cntlightning) {
		assert(SZ(worst) >= 1);
		auto it = prev(worst.end());
		best.insert(*it);
		bestsum += it->first;
		if (it->second == 1) ++cntlightninginbest;
		worst.erase(it);
	}
	while (SZ(best) > cntlightning) {
		assert(SZ(best) >= 1);
		auto it = best.begin();
		worst.insert(*it);
		bestsum -= it->first;
		if (it->second == 1) --cntlightninginbest;
		best.erase(it);
	}
}

ll calc() {
	ll ret = sum + bestsum;
	if (cntlightning >= 1 && cntlightninginbest == cntlightning) {
		assert(SZ(best) >= 1);
		auto it = best.begin(); ret -= it->first;
		if (SZ(fire) >= 1) {
			auto it = prev(fire.end()); ret += *it;
		}
	}
	return ret;
}

void solve() {
	sum = 0; cntlightning = 0; best.clear(); worst.clear(); fire.clear(); bestsum = 0; cntlightninginbest = 0;
	REP(i, nq) {
		int type = qtype[i], val = qval[i];
		if (val >= 1) {
			sum += val;
			if (type == 1) ++cntlightning;
			if (SZ(best) == 0 || val <= best.begin()->first) {
				worst.insert(MP(val, type));
			} else {
				best.insert(MP(val, type));
				bestsum += val;
				if (type == 1) ++cntlightninginbest;
			}
			if (type == 0) fire.insert(val);
		}
		if (val <= -1) {
			val = -val;
			sum -= val;
			if (type == 1) --cntlightning;
			pair<int, int> key = MP(val, type);
			auto it = best.find(key);
			if (it != best.end()) {
				best.erase(it);
				bestsum -= val;
				if (type == 1) --cntlightninginbest;
			} else {
				auto it = worst.find(key);
				assert(it != worst.end());
				worst.erase(it);
			}
			if (type == 0) {
				auto it = fire.find(val);
				assert(it != fire.end());
				fire.erase(it);
			}
		}
		rebalance();
		qans[i] = calc();
	}
}

void run() {
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &qtype[i], &qval[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}