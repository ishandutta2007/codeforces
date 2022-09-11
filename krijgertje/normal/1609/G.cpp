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

const int MAXA = 100;
const int MAXB = 100000;
const int MAXQ = 100000;
const int MAXS = 4 * (MAXB - 1);

int na, nb, nq;
ll a[MAXA];
ll b[MAXB];
int qkind[MAXQ], qlen[MAXQ], qval[MAXQ];
ll qans[MAXQ];
struct SRes { int cnt; ll sum, sumprod; SRes() {} SRes(int cnt, ll sum, ll sumprod) :cnt(cnt), sum(sum), sumprod(sumprod) {} };
SRes operator+(const SRes &a, const SRes &b) { return SRes(a.cnt + b.cnt, a.sum + b.sum, a.sumprod + b.sumprod); }

ll fixedval;
ll adelta[MAXA - 1];
ll bdelta[MAXB - 1];

ll slazy[MAXS];
ll smx[MAXS];
ll ssum[MAXS];
ll ssumprod[MAXS];

void sapply(int x, int l, int r, ll by) {
	slazy[x] += by;
	smx[x] += by;
	ssum[x] += (r - l + 1) * by;
	ssumprod[x] -= (ll)(r - l + 1) * (l + r) / 2 * by;
}
void spush(int x, int l, int m, int r) {
	if (slazy[x] != 0) sapply(2 * x + 1, l, m, slazy[x]), sapply(2 * x + 2, m + 1, r, slazy[x]), slazy[x] = 0;
}
void spull(int x) {
	smx[x] = max(smx[2 * x + 1], smx[2 * x + 2]);
	ssum[x] = ssum[2 * x + 1] + ssum[2 * x + 2];
	ssumprod[x] = ssumprod[2 * x + 1] + ssumprod[2 * x + 2];
}
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		smx[x] = ssum[x] = bdelta[l];
		ssumprod[x] = bdelta[l] * (-l);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	if (L <= l && r <= R) {
		sapply(x, l, r, BY);
	} else {
		int m = l + (r - l) / 2; spush(x, l, m, r);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
SRes sget(int x, int l, int r, ll LIM) {
	//printf("\t\t%d..%d mx=%lld\n", l, r, smx[x]);
	if (smx[x] <= LIM) {
		return SRes(r - l + 1, ssum[x], ssumprod[x]);
	} else if (l == r) {
		return SRes(0, 0, 0);
	} else {
		int m = l + (r - l) / 2; spush(x, l, m, r);
		SRes ret(0, 0, 0);
		ret = ret + sget(2 * x + 1, l, m, LIM);
		if (smx[2 * x + 1] <= LIM) ret = ret + sget(2 * x + 2, m + 1, r, LIM);
		return ret;
	}
}

ll calc() {
	ll ret = fixedval * (na + nb - 1);
	SRes prv(0, 0, 0);
	REP(i, na) {
		ll lim = i < na - 1 ? adelta[i] : LLONG_MAX;
		SRes nxt = sget(0, 0, nb - 2, lim);
		SRes delta = nxt;
		delta.cnt -= prv.cnt;
		delta.sum -= prv.sum;
		delta.sumprod -= prv.sumprod;
		int have = -prv.cnt;
		int want = na + nb - 2 - prv.cnt - i;
		//printf("\tlim=%lld delta=(%d,%lld,%lld) have=%d want=%d\n", lim, delta.cnt, delta.sum, delta.sumprod, have, want);
		ret += delta.sumprod + delta.sum * (want - have);
		want -= delta.cnt;
		if (i < na - 1) {
			ret += want * adelta[i];
		}
		prv = nxt;
	}
	return ret;
}

void solve() {
	fixedval = a[0] + b[0];
	REP(i, na - 1) adelta[i] = a[i + 1] - a[i];
	REP(i, nb - 1) bdelta[i] = b[i + 1] - b[i];

	sinit(0, 0, nb - 2);
	REP(i, nq) {
		//printf("processing %d\n", i);
		int len = qlen[i], val = qval[i];
		if (qkind[i] == 1) {
			if (len == na) fixedval += val, --len;
			REP(j, len) adelta[na - 2 - j] += val;
		}
		if (qkind[i] == 2) {
			if (len == nb) fixedval += val, --len;
			smod(0, 0, nb - 2, nb - len - 1, nb - 2, val);
		}
		qans[i] = calc();
	}
}

void run() {
	scanf("%d%d%d", &na, &nb, &nq);
	REP(i, na) scanf("%lld", &a[i]);
	REP(i, nb) scanf("%lld", &b[i]);
	REP(i, nq) scanf("%d%d%d", &qkind[i], &qlen[i], &qval[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}