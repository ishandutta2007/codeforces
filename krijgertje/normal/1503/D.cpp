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

const int MAXCARD = 200000;
const int MAXNUM = 2 * MAXCARD;

int ncard;
int a[MAXCARD][2];

int nnum;
int side[MAXNUM];
int other[MAXNUM];

bool done[MAXNUM];

int solve() {
	nnum = 2 * ncard;
	REP(i, ncard) REP(j, 2) side[a[i][j]] = j, other[a[i][j]] = a[i][1 - j];

	int ret = 0;
	int l = 0, r = nnum - 1;
	REP(i, nnum) done[i] = false;
	while (l <= r) {
		if (done[l]) { ++l; continue; }
		if (done[r]) { --r; continue; }
		int ltop = INT_MIN, lbot = INT_MAX, rtop = INT_MAX, rbot = INT_MIN, curcards = 0, curflipped = 0;
		auto place = [&](int v, bool ontop) -> bool {
			//printf("place(%d,%s) [%d] (%d,%d)\n", v + 1, ontop ? "top" : "bot", other[v] + 1, done[v] ? 1 : 0, done[other[v]] ? 1 : 0);
			assert(!done[v] && !done[other[v]]);
			done[v] = done[other[v]] = true;
			if (v <= ltop || v >= lbot || other[v] >= rtop || other[v] <= rbot) return false;
			++curcards;
			if (side[v] == 1) ++curflipped;
			if (ontop) ltop = v, rtop = other[v]; else lbot = v, rbot = other[v];
			return true;
		};
		place(l, true);
		while (l <= r && (r >= rtop || l <= rbot)) {
			if (r >= rtop) {
				if (done[r]) --r; else if (!place(r, false)) return -1;
			} else if (l <= rbot) {
				if (done[l]) ++l; else if (!place(l, true)) return -1;
			}
		}
		ret += min(curflipped, curcards - curflipped);
		//printf("block (l=%d r=%d)\n", l + 1, r + 1);
	}
	return ret;
}

void run() {
	scanf("%d", &ncard);
	REP(i, ncard) REP(j, 2) scanf("%d", &a[i][j]), --a[i][j];
	printf("%d\n", solve());
}

void stress() {
	REP(rep, 1000) {
		ncard = rnd() % 8 + 1;
		vector<int> perm(2 * ncard); REPSZ(i, perm) perm[i] = i; shuffle(perm.begin(), perm.end(), rnd);
		REP(i, ncard) REP(j, 2) a[i][j] = perm[2 * i + j];
		//printf("%d\n", ncard); REP(i, ncard) printf("%d %d\n", a[i][0] + 1, a[i][1] + 1);
		printf("%d\n", solve());
	}
}

int main() {
	run();
	//stress();
	return 0;
}