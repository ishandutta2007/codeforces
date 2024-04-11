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

const int MAXN = 1000000;
const int MAXBIT = 60;

int n;
ll a[MAXN];

int bc[MAXN];
int ord[MAXN];
int pos[MAXN];

int mx[MAXN], mn[MAXN]; // index into ord

vector<int> who[MAXBIT + 1];
int lat[MAXBIT + 1], rat[MAXBIT + 1];

ll rec(int lo, int hi) {
	if (hi - lo == 1) return 1;
	int mi = lo + (hi - lo) / 2;
	ll ret = 0;
	ret += rec(lo, mi);
	ret += rec(mi, hi);

	mx[mi - 1] = mn[mi - 1] = pos[mi - 1];
	for (int i = mi - 2; i >= lo; --i) mx[i] = max(mx[i + 1], pos[i]), mn[i] = min(mn[i + 1], pos[i]);
	mx[mi] = mn[mi] = pos[mi];
	FOR(i, mi + 1, hi) mx[i] = max(mx[i - 1], pos[i]), mn[i] = min(mn[i - 1], pos[i]);
	//printf("mn:"); FOR(i, lo, hi) printf(" %d", mn[i]); puts("");
	//printf("mx:"); FOR(i, lo, hi) printf(" %d", mx[i]); puts("");

	// both on left
	{
		int l = mi, r = mi;
		for (int i = mi - 1; i >= lo; --i) {
			int lidx = ord[mn[i]], hidx = ord[mx[i]];
			if (bc[lidx] != bc[hidx]) continue;
			while (r<hi && mn[r]>mn[i] && mx[r] < mx[i]) ++r;
			ret += r - l;
		}
	}
	// both on right
	{
		int l = mi - 1, r = mi - 1;
		FOR(i, mi, hi) {
			int lidx = ord[mn[i]], hidx = ord[mx[i]];
			if (bc[lidx] != bc[hidx]) continue;
			while (l >= lo && mn[l] > mn[i] && mx[l] < mx[i]) --l;
			ret += r - l;
		}
	}
	// mx on left, mn on right
	{
		FOR(i, mi, hi) who[bc[ord[mn[i]]]].PB(i);
		for (int i = mi - 1; i >= lo; --i) lat[bc[ord[mx[i]]]] = rat[bc[ord[mx[i]]]] = 0;
		for (int i = mi - 1; i >= lo; --i) {
			int k = bc[ord[mx[i]]];
			while (lat[k] < SZ(who[k]) && mn[who[k][lat[k]]] > mn[i]) ++lat[k];
			while (rat[k] < SZ(who[k]) && mx[who[k][rat[k]]] < mx[i]) ++rat[k];
			if (lat[k] <= rat[k]) ret += rat[k] - lat[k];
		}
		FOR(i, mi, hi) who[bc[ord[mn[i]]]].pop_back();
	}
	// mn on left, mx on right
	{
		for (int i = mi - 1; i >= lo; --i) who[bc[ord[mn[i]]]].PB(i);
		FOR(i, mi, hi) lat[bc[ord[mx[i]]]] = rat[bc[ord[mx[i]]]] = 0;
		FOR(i, mi, hi) {
			int k = bc[ord[mx[i]]];
			while (lat[k] < SZ(who[k]) && mn[who[k][lat[k]]] > mn[i]) ++lat[k];
			while (rat[k] < SZ(who[k]) && mx[who[k][rat[k]]] < mx[i]) ++rat[k];
			if (lat[k] <= rat[k]) ret += rat[k] - lat[k];
		}
		for (int i = mi - 1; i >= lo; --i) who[bc[ord[mn[i]]]].pop_back();
	}


	return ret;
}

ll solve() {
	REP(i, n) {
		ll x = a[i];
		bc[i] = 0;
		while (x > 0) bc[i] += x & 1, x >>= 1;
	}
	REP(i, n) ord[i] = i;
	sort(ord, ord + n, [&](int i, int j) { if (a[i] != a[j]) return a[i] < a[j]; return i < j; });
	REP(i, n) pos[ord[i]] = i;
	//printf("ord:"); REP(i, n) printf(" %d", ord[i]); puts("");
	//printf("pos:"); REP(i, n) printf(" %d", pos[i]); puts("");

	REPE(k, MAXBIT) who[k].clear();
	return rec(0, n);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld", &a[i]);
	printf("%lld\n", solve());
}

ll solvestupid() {
	REP(i, n) {
		ll x = a[i];
		bc[i] = 0;
		while (x > 0) bc[i] += x & 1, x >>= 1;
	}
	ll ret = 0;
	REP(i, n) {
		int mnidx = i, mxidx = i;
		FOR(j, i, n) {
			if (a[j] < a[mnidx]) mnidx = j;
			if (a[j] > a[mxidx]) mxidx = j;
			if (bc[mnidx] == bc[mxidx]) ++ret;
		}
	}
	return ret;
}

void stress() {
	int mxn = 100;
	REP(rep, 100000) {
		n = rnd() % mxn + 1;
		REP(i, n) a[i] = rnd() % (1 << 10);
		ll have = solve();
		ll want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err rep=%d have=%lld want=%lld\n", rep, have, want);
		printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%lld", a[i]); } puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}