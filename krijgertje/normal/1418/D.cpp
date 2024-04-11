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

const int MAXN = 100000;
const int MAXQ = 100000;

int n, nq;
int sx[MAXN];
int qkind[MAXQ], qx[MAXQ], qans[MAXQ + 1];

void solve() {
	set<int> have;
	multiset<int> diff;
	auto toggle = [&](const int x) {
		auto it = have.find(x);
		if (it == have.end()) {
			it = have.insert(x).first;
			if (it != have.begin() && next(it) != have.end()) diff.erase(diff.find(*next(it) - *prev(it)));
			if (it != have.begin()) diff.insert(x - *prev(it));
			if (next(it) != have.end()) diff.insert(*next(it) - x);
		} else {
			if (it != have.begin() && next(it) != have.end()) diff.insert(*next(it) - *prev(it));
			if (it != have.begin()) diff.erase(diff.find(x - *prev(it)));
			if (next(it) != have.end()) diff.erase(diff.find(*next(it) - x));
			have.erase(it);
		}
	};
	auto calc = [&]() {
		if (SZ(have) <= 2) return 0;
		assert(SZ(diff) >= 1);
		return *prev(have.end()) - *have.begin() - *prev(diff.end());
	};
	REP(i, n) toggle(sx[i]);
	REPE(i, nq) {
		qans[i] = calc();
		if (i < nq) toggle(qx[i]);
	}
}


void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &sx[i]);
	REP(i, nq) scanf("%d%d", &qkind[i], &qx[i]);
	solve();
	REPE(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}