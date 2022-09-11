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

const int MAXDAY = 50000;
const int MAXOFFER = 100000;

int nday, noffer;
int l[MAXOFFER], r[MAXOFFER];
int ans[MAXDAY + 1];

// segtree over days
// given a limit L, each node should be able to tell the first offer that starts in one of the days it represents and starts no earlier than L
struct SegTree {
	int n, base;
	vector<set<pair<int, int>>> sval;
	int get(const set<pair<int, int>>& z, int L) {
		auto it = z.lower_bound(MP(L, INT_MIN));
		return it == z.end() ? -1 : it->second;
	}
	void add(set<pair<int, int>>& z, int IDX, int L) {
		auto it = z.lower_bound(MP(L, INT_MIN));
		if (it != z.end() && it->second <= IDX) return;
		if (it != z.end() && it->first == L) it = z.erase(it);
		while (it != z.begin()) {
			--it;
			if (it->second < IDX) break;
			it = z.erase(it);
		}
		z.insert(it, MP(L, IDX));
	}
	void init(int _n) {
		n = _n;
		base = 1; while (base < n) base *= 2;
		sval = vector<set<pair<int, int>>>(base + n);
	}
	int findfirst(int L, int R) {
		int ret = -1;
		auto upd = [&](int cur) { if (cur != -1 && (ret == -1 || cur < ret)) ret = cur; };
		for (int lidx = base + L, ridx = base + R + 1; lidx < ridx; lidx >>= 1, ridx >>= 1) {
			if (lidx & 1) upd(get(sval[lidx++], L));
			if (ridx & 1) upd(get(sval[--ridx], L));
		}
		return ret;
	}
	void add(int IDX, int L, int R) {
		int x = base + R;
		while (x >= 1) add(sval[x], IDX, L), x /= 2;
	}
};

SegTree segtree;

int go(int L, int R, int lim) {
	if (R - L + 1 < lim) return 0;
	int first = segtree.findfirst(L, R);
	if (first == -1) return 0;
	int ret = r[first] - l[first] + 1;
	if (L < l[first]) ret += go(L, l[first] - 1, lim);
	if (r[first] < R) ret += go(r[first] + 1, R, lim);
	return ret;
}

void solve() {
	segtree.init(nday);
	vector<vector<int>> bylen(nday + 1);
	REP(i, noffer) bylen[r[i] - l[i] + 1].PB(i);
	for (int d = nday; d >= 1; --d) {
		for (int i : bylen[d]) segtree.add(i, l[i], r[i]);
		ans[d] = go(0, nday - 1, d);
	}
}

void run() {
	scanf("%d%d", &nday, &noffer);
	REP(i, noffer) scanf("%d%d", &l[i], &r[i]), --l[i], --r[i];
	solve();
	FORE(i, 1, nday) printf("%d\n", ans[i]);
}

int main() {
	run();
	return 0;
}