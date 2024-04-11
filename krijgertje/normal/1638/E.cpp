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

struct BIT {
	int n; vector<ll> val;
	void init(int _n) { n = _n; val = vector<ll>(n + 1, 0); }
	void modprefix(int idx, ll by) { ++idx; while (idx > 0) { val[idx] += by; idx -= idx & -idx; } };
	void modrange(int lidx, int ridx, ll by) { modprefix(ridx, +by); modprefix(lidx - 1, -by); }
	ll get(int idx) { ++idx; ll ret = 0; while (idx <= n) { ret += val[idx]; idx += idx & -idx; } return ret; }
};

const int MAXN = 1000000;
const int MAXQ = 1000000;
struct Range { int l, r, col; ll oval; Range() {} Range(int l, int r, int col, ll oval) :l(l), r(r), col(col), oval(oval) {} };

const int COLORKIND = 0;
const int ADDKIND = 1;
const int QUERYKIND = 2;

int n, nq;
int qkind[MAXQ], ql[MAXQ], qr[MAXQ], qcol[MAXQ], qval[MAXQ], qidx[MAXQ];
ll qans[MAXQ];

ll cval[MAXN];

void solve() {
	REP(i, n) cval[i] = 0;
	map<int, Range> ranges;
	ranges[0] = Range(0, n, 0, cval[0]);
	auto ensure = [&](int x) {
		if (x == n) return;
		auto it = ranges.lower_bound(x);
		if (it == ranges.end() || it->first > x) { assert(it != ranges.begin()); it = prev(it); }
		Range z = it->second;
		//printf("ranges:"); for (auto q : ranges) printf(" %d:[%d..%d]", q.first, q.second.l, q.second.r); puts("");
		//printf("ensuring %d: %d..%d\n", x, z.l, z.r);
		assert(z.l <= x && z.r > x);
		if (z.l == x) return;
		it->second.r = x;
		ranges[x] = Range(x, z.r, z.col, z.oval);
	};
	BIT bit;
	bit.init(n);
	auto push = [&](Range &z) {
		bit.modrange(z.l, z.r - 1, cval[z.col] - z.oval);
		z.oval = cval[z.col];
	};
	REP(i, nq) {
		if (qkind[i] == COLORKIND) {
			int l = ql[i], r = qr[i], col = qcol[i];
			ensure(l);
			ensure(r);
			auto it = ranges.find(l);
			assert(it != ranges.end());
			while (it != ranges.end() && it->first != r) {
				push(it->second);
				auto pit = it;
				it = next(it);
				ranges.erase(pit);
			}
			ranges[l] = Range(l, r, col, cval[col]);
		}
		if (qkind[i] == ADDKIND) {
			cval[qcol[i]] += qval[i];
		}
		if (qkind[i] == QUERYKIND) {
			int idx = qidx[i];
			auto it = ranges.lower_bound(idx);
			if (it == ranges.end() || it->first > idx) { assert(it != ranges.begin()); it = prev(it); }
			Range z = it->second;
			assert(z.l <= idx && idx < z.r);
			push(it->second);
			qans[i] = bit.get(idx);
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, nq) {
		char s[10];
		scanf("%s", s);
		if (strcmp(s, "Color") == 0) qkind[i] = COLORKIND; else if (strcmp(s, "Add") == 0) qkind[i] = ADDKIND; else if (strcmp(s, "Query") == 0) qkind[i] = QUERYKIND; else assert(false);
		if (qkind[i] == COLORKIND) scanf("%d%d%d", &ql[i], &qr[i], &qcol[i]), --ql[i], --qcol[i];
		if (qkind[i] == ADDKIND) scanf("%d%d", &qcol[i], &qval[i]), --qcol[i];
		if (qkind[i] == QUERYKIND) scanf("%d", &qidx[i]), --qidx[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == QUERYKIND) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}