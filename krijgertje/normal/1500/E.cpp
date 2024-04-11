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


const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXS = 4 * (MAXN + MAXQ);
struct S {
	int cnt;
	ll sum;
	ll sumpref;
	S() :cnt(0), sum(0), sumpref(0) {}
};


int n, nq;
ll init[MAXN];
int qkind[MAXQ]; ll qval[MAXQ];
ll ans[MAXQ + 1];

ll v[MAXN + MAXQ]; int nv;

int havecnt;
vector<bool> have;


S sval[MAXS];

void spull(int x) {
	sval[x].cnt = sval[2 * x + 1].cnt + sval[2 * x + 2].cnt;
	sval[x].sum = sval[2 * x + 1].sum + sval[2 * x + 2].sum;
	sval[x].sumpref = sval[2 * x + 1].sumpref + sval[2 * x + 1].cnt * sval[2 * x + 2].sum + sval[2 * x + 2].sumpref;
}

void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = S();
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}

void sflip(int x, int l, int r, int IDX) {
	if (l == r) {
		sval[x].cnt = 1 - sval[x].cnt;
		sval[x].sum = sval[x].sumpref = sval[x].cnt == 0 ? 0 : v[l];
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) sflip(2 * x + 1, l, m, IDX);
		else sflip(2 * x + 2, m + 1, r, IDX);
		spull(x);
	}
	//printf("\t%lld..%lld cnt=%d sum=%lld sumpref=%lld\n", v[l], v[r], sval[x].cnt, sval[x].sum, sval[x].sumpref);
}

S sget(int x, int l, int r, int K) {
	if (sval[x].cnt <= K) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2;
		S ret;
		if (K > 0) {
			S cur = sget(2 * x + 1, l, m, K);
			ret.cnt += cur.cnt;
			ret.sum += cur.sum;
			ret.sumpref += cur.sumpref;
			K -= cur.cnt;
		}
		if (K > 0) {
			S cur = sget(2 * x + 2, m + 1, r, K);
			ret.cnt += cur.cnt;
			ret.sum += cur.sum;
			ret.sumpref += sval[2 * x + 1].cnt * cur.sum + cur.sumpref;
			K -= cur.cnt;
		}
		return ret;
	}
}


void flip(int idx) {
	int delta = have[idx] ? -1 : +1;
	//printf("v=%lld: idx=%d delta=%d\n", v[idx], idx, delta);
	havecnt += delta;
	have[idx] = !have[idx];
	sflip(0, 0, nv - 1, idx);
}

bool overlap(int k) { // sum of largest k elements is greater than sum of smallest k+1 elements
	ll sumsmallest = sget(0, 0, nv - 1, k + 1).sum;
	ll sumlargest = sval[0].sum - sget(0, 0, nv - 1, havecnt - k).sum;
	return sumlargest > sumsmallest;
}

ll calc() {
	if (havecnt <= 1) return 0;
	int lo = 0, hi = (havecnt - 1) / 2;
	if (!overlap(hi)) {
		S all = sval[0];
		ll rhs = all.sumpref;
		ll lhs = (all.cnt + 1) * all.sum - all.sumpref;
		//printf("rhs=%lld lhs=%lld (sumpref=%lld sum=%lld)\n", rhs, lhs, sval[0].sumpref, sval[0].sum);
		return rhs - lhs;
	} else {
		while (lo + 1 < hi) {
			int mi = lo + (hi - lo) / 2;
			if (!overlap(mi)) lo = mi; else hi = mi;
		}
		int k = hi;
		//printf("k=%d\n", k);
		ll ret = 0;
		ret += sval[0].sum - 2 * sget(0, 0, nv - 1, k).sum;
		//printf("inside=%lld\n", ret);
		S all = sval[0], first = sget(0, 0, nv - 1, k - 1), before = sget(0, 0, nv - 1, havecnt - (k - 1));
		ret += 2 * ((all.sumpref - before.sumpref - before.cnt * (all.sum - before.sum)) - ((first.cnt + 1) * first.sum - first.sumpref));
		//printf("(%lld-%lld-%d*(%lld-%lld)) - (%d*%lld-%lld)\n", all.sumpref, before.sumpref, before.cnt, all.sum, before.sum, first.cnt + 1, first.sum, first.sumpref);
		return ret;
	}
}

void solve() {
	nv = 0;
	REP(i, n) v[nv++] = init[i];
	REP(i, nq) v[nv++] = qval[i];
	sort(v, v + nv);
	nv = unique(v, v + nv) - v;
	havecnt = 0;
	have = vector<bool>(nv, false);

	/*{
		vector<ll> a(n);
		REP(i, n) a[i] = init[i];
		sort(a.begin(), a.end());
		vector<pair<ll, ll>> ranges;
		REPE(i, n) { ll lsum = 0, rsum = 0; REP(j, i) lsum += a[j], rsum += a[n - 1 - j]; ranges.PB(MP(lsum, rsum)); }
		printf("ranges:"); REPSZ(i, ranges) printf(" [%lld..%lld)", ranges[i].first, ranges[i].second); puts("");
	}*/

	sinit(0, 0, nv - 1);
	REP(i, n) flip(lower_bound(v, v + nv, init[i]) - v);
	ans[0] = calc();
	REP(i, nq) {
		flip(lower_bound(v, v + nv, qval[i]) - v);
		ans[i + 1] = calc();
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%lld", &init[i]);
	REP(i, nq) scanf("%d%lld", &qkind[i], &qval[i]);
	solve();
	REPE(i, nq) printf("%lld\n", ans[i]);
}

ll ansstupid[MAXQ + 1];

void solvestupid() {
	assert(nq == 0);
	vector<ll> a(n);
	REP(i, n) a[i] = init[i];
	sort(a.begin(), a.end());
	vector<pair<ll, ll>> ranges;
	REPE(i, n) { ll lsum = 0, rsum = 0; REP(j, i) lsum += a[j], rsum += a[n - 1 - j]; ranges.PB(MP(lsum, rsum)); }
	FORSZ(i, 1, ranges) assert(ranges[i].first > ranges[i - 1].first&& ranges[i].second > ranges[i - 1].second);
	ll ret = 0;
	REPSZ(i, ranges) ret += ranges[i].second - (i == 0 ? ranges[i].first : max(ranges[i - 1].second, ranges[i].first));
	ansstupid[0] = ret;
}

void stress() {
	int mxn = 20;
	REP(rep, 10000) {
		n = rnd() % mxn + 1, nq = 0;
		set<int> seen;
		REP(i, n) while (true) { init[i] = rnd() % 100 + 1; if (seen.count(init[i])) continue; seen.insert(init[i]); break; }
		solve();
		solvestupid();
		if (ans[0] == ansstupid[0]) { printf("."); continue; }
		printf("err have=%lld want=%lld\n", ans[0], ansstupid[0]);
		printf("%d %d\n", n, nq); REP(i, n) { if (i != 0) printf(" "); printf("%lld", init[i]); } puts(""); REP(i, nq) printf("%d %lld\n", qkind[i], qval[i]); break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}