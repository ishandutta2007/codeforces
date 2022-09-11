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

const int MAXN = 300000;
const int MAXQ = 300000;
struct Opt { int l, r; ll val; Opt() {} Opt(int l, int r, ll val) :l(l), r(r), val(val) {} };

int n, nq;
int x[MAXN], w[MAXN];
int ql[MAXQ], qr[MAXQ];
ll qans[MAXQ];

int lft[MAXN], rgt[MAXN];

struct BIT {
	int n; vector<ll> val;
	void init(int _n) { n = _n; val = vector<ll>(n + 1, LLONG_MAX); }
	void mod(int idx, ll by) { ++idx; while (idx <= n) { val[idx] = min(val[idx], by); idx += idx & -idx; } }
	ll get(int idx) { ++idx; ll ret = LLONG_MAX; while (idx > 0) { ret = min(ret, val[idx]); idx -= idx & -idx; } return ret; }
};

void solve() {
	REP(i, n) lft[i] = rgt[i] = -1;
	vector<int> stck;
	REP(i, n) {
		while (true) {
			if (SZ(stck) == 0) break;
			int j = stck[SZ(stck) - 1];
			if (w[j] <= w[i]) {
				rgt[j] = i;
				break;
			}
			lft[i] = j;
			stck.pop_back();
		}
		stck.PB(i);
	}
	int root = stck[0];
	//REP(i, n) printf("%d: w=%d (%d,%d)\n", i, w[i], lft[i], rgt[i]);

	vector<Opt> opt;
	auto addopt = [&](int l, int r) { assert(l < r); opt.PB(Opt(l, r, (ll)(x[r] - x[l]) * (w[l] + w[r]))); };
	auto dfs = [&](auto self, int at, int lanc, int ranc) -> void {
		if (lanc != -1) addopt(lanc, at);
		if (ranc != -1) addopt(at, ranc);
		if (lft[at] != -1) self(self, lft[at], lanc, at);
		if (rgt[at] != -1) self(self, rgt[at], at, ranc);
	};
	dfs(dfs, root, -1, -1);
	//printf("opt:"); for (const auto &o : opt) printf(" [%d..%d]=%lld", o.l, o.r, o.val); puts("");

	vector<vector<Opt>> optbyl(n);
	for (const auto &o : opt) optbyl[o.l].PB(o);
	vector<vector<int>> qbyl(n);
	BIT bit;
	bit.init(n);
	REP(id, nq) qbyl[ql[id]].PB(id);
	for (int l = n - 1; l >= 0; --l) {
		for (const auto &o : optbyl[l]) bit.mod(o.r, o.val);
		for (int id : qbyl[l]) qans[id] = bit.get(qr[id]);
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d%d", &x[i], &w[i]);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}