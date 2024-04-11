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

const int MAXQ = 200000;
const int MAXVAL = 200000;
const int MAXS = 4 * MAXVAL;

int nq, dist;
int q[MAXQ];
ll qans[MAXQ];

bool have[MAXVAL + 1];

ll curans;
ll sa[MAXS], sb[MAXS], sc[MAXS]; // sa=sum(v[i]*(v[i]-1)), sb=sum(2*v[i]-1),sc=sum(1)
int slazy[MAXS];

void sapply(int x, int delta) {
	slazy[x] += delta;
	sa[x] += sb[x] * delta + sc[x] * delta * delta;
	sb[x] += 2 * sc[x] * delta;
}
void spush(int x) {
	if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0;
}
void spull(int x) {
	sa[x] = sa[2 * x + 1] + sa[2 * x + 2];
	sb[x] = sb[2 * x + 1] + sb[2 * x + 2];
	sc[x] = sc[2 * x + 1] + sc[2 * x + 2];
}

void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sa[x] = sb[x] = sc[x] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int DELTA) {
	if (L <= l && r <= R) {
		curans -= sa[x];
		sapply(x, DELTA);
		curans += sa[x];
	} else {
		int m = l + (r - l) / 2;
		spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, DELTA);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, DELTA);
		spull(x);
	}
}
void stoggle(int x, int l, int r, int IDX, int CNT) {
	if (l == r) {
		if (sc[x] == 0) {
			sa[x] = (ll)CNT * (CNT - 1), sb[x] = 2 * CNT - 1, sc[x] = 1;
			curans += sa[x];
		} else {
			curans -= sa[x];
			sa[x] = sb[x] = sc[x] = 0;
		}
	} else {
		int m = l + (r - l) / 2;
		spush(x);
		if (IDX <= m) stoggle(2 * x + 1, l, m, IDX, CNT); else stoggle(2 * x + 2, m + 1, r, IDX, CNT);
		spull(x);
	}
}
ll sgetcsum(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sc[x];
	} else {
		int m = l + (r - l) / 2;
		spush(x);
		ll ret = 0;
		if (L <= m) ret += sgetcsum(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) ret += sgetcsum(2 * x + 2, m + 1, r, L, R);
		spull(x);
		return ret;
	}
}

void solve() {
	FORE(i, 1, MAXVAL) have[i] = false;
	curans = 0;
	sinit(0, 1, MAXVAL);
	REP(i, nq) {
		int val = q[i];
		int delta = have[val] ? -1 : +1;
		//printf("q%d=%d (%d)\n", i, val, delta);
		int lo = max(1, val - dist), hi = val - 1;
		if (lo <= hi) smod(0, 1, MAXVAL, lo, hi, delta);
		int lo2 = val + 1, hi2 = min(MAXVAL, val + dist);
		ll cnt = lo2 <= hi2 ? sgetcsum(0, 1, MAXVAL, lo2, hi2) : 0;
		//printf("\tcnt=%lld [%d..%d]\n", cnt, lo2, hi2);
		stoggle(0, 1, MAXVAL, val, cnt);
		have[val] = !have[val];
		qans[i] = curans / 2;
	}
}

void run() {
	scanf("%d%d", &nq, &dist);
	REP(i, nq) scanf("%d", &q[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}