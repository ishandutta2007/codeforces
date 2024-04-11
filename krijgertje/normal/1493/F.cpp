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

const int MAXVAL = 1000;

int pmn[MAXVAL + 1];

void initprime() {
	REPE(i, MAXVAL) pmn[i] = -1;
	FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;
}
vector<pair<int, int>> factorize(int x) {
	vector<pair<int, int>> ret;
	while (x != 1) { int p = pmn[x], cnt = 0; while (x % p == 0) x /= p, ++cnt; ret.PB(MP(p, cnt)); }
	return ret;
}

int h, w;

bool query(int xsz, int ysz, int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d %d %d\n", xsz, ysz, x1 + 1, y1 + 1, x2 + 1, y2 + 1); fflush(stdout);
	int ret = 0; scanf("%d", &ret); return ret == 1;
}

bool querydir(int dir, int sz, int offset) {
	if (dir == 0) {
		return query(sz, w, offset, 0, offset + sz, 0);
	} else {
		return query(h, sz, 0, offset, 0, offset + sz);
	}
}

int solve() {
	initprime();
	int ret = 1;
	REP(dir, 2) {
		int split = dir == 0 ? h : w;
		map<int, int> can;
		for (auto item : factorize(split)) {
			int p = item.first, cnt = item.second;
			int part = split;
			REP(i, cnt) {
				part /= p;
				int have = 1; bool ok = true;
				while (ok && 2 * have < p) {
					if (!querydir(dir, have*part, 0*part)) ok = false; else have *= 2;
				}
				if (ok) {
					int sz = p - have;
					if (!querydir(dir, sz * part, (have - sz) * part)) ok = false; else have = p;
				}
				if (have == p) ++can[p]; else break;
			}
		}
		int cur = 0;
		FORE(sz, 1, split) if (split % sz == 0) {
			bool ok = true;
			for (auto item : factorize(sz)) {
				int p = item.first, cnt = item.second;
				if (can[p] < cnt) ok = false;
			}
			if (ok) ++cur;
		}
		ret *= cur;
	}
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	int ans = solve();
	printf("! %d\n", ans); fflush(stdout);
}


void research() {
	initprime();

	vector<int> needarr(MAXVAL + 1);
	FORE(n, 1, MAXVAL) {
		int need = 0;
		for (auto item : factorize(n)) {
			int p = item.first, cnt = item.second;
			int lgp = 0; while ((1 << lgp) < p) ++lgp;
			need += lgp * cnt;
			//need += lgp + (cnt - 1);
		}
		//printf("%d: %d\n", n, need);
		needarr[n] = need;
	}
	double mxratio = 0;
	FORE(a, 1, MAXVAL) FORE(b, 1, MAXVAL) {
		int need = needarr[a] + needarr[b];
		int lg = 0; while ((2 << lg) <= a + b) ++lg;
		int have = 3 * lg;
		double ratio = 1.0 * need / have;
		if (ratio > mxratio) printf("(%d,%d): need=%d have=%d (%lf)\n", a, b, need, have, ratio), mxratio = ratio;

	}
}

int main() {
	//research();
	run();
	return 0;
}