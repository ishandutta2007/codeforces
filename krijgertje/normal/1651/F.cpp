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

const int MAXTOWER = 200000;
const int MAXS = 4 * MAXTOWER;
const int MAXMONSTER = 200000;
struct Eq { ll a, b; Eq() {} Eq(ll a, ll b) :a(a), b(b) {} ll eval(int t) { return a * t + b; } }; // a*t+b
Eq operator+(const Eq &p, const Eq &q) { return Eq(p.a + q.a, p.b + q.b); }

int ntower;
int cap[MAXTOWER], regen[MAXTOWER];
int nmonster;
int tspawn[MAXMONSTER]; ll hp[MAXMONSTER];

vector<pair<int, Eq>> sval[MAXS];
vector<int> lidx[MAXS];
vector<int> ridx[MAXS];

void sinit(int x, int l, int r) {
	sval[x].clear();
	lidx[x].clear();
	ridx[x].clear();
	if (l == r) {
		int t = (cap[l] + regen[l] - 1) / regen[l];
		sval[x].PB(MP(0, Eq(regen[l], 0)));
		sval[x].PB(MP(t, Eq(0, cap[l])));
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		int clidx = 0, cridx = 0;
		const auto &L = sval[2 * x + 1];
		const auto &R = sval[2 * x + 2];
		while (true) {
			int t = max(L[clidx].first, R[cridx].first);
			sval[x].PB(MP(t, L[clidx].second + R[cridx].second));
			lidx[x].PB(clidx);
			ridx[x].PB(cridx);
			int nt = min(clidx + 1 >= SZ(L) ? INT_MAX : L[clidx + 1].first, cridx + 1 >= SZ(R) ? INT_MAX : R[cridx + 1].first);
			if (nt == INT_MAX) break;
			if (clidx + 1 < SZ(L) && L[clidx + 1].first == nt) ++clidx;
			if (cridx + 1 < SZ(R) && R[cridx + 1].first == nt) ++cridx;
		}
	}
	//printf("%d..%d:", l, r); for (const auto &z : sval[x]) printf(" %d:%lld*t+%lld", z.first, z.second.a, z.second.b); puts("");
}

pair<int, ll> sget(int x, int l, int r, int L, int R, int T, int IDX, ll LIM) {
	//printf("\tsget(%d,%d..%d,%d..%d,t=%d,idx=%d,lim=%lld)\n", x, l, r, L, R, T, IDX, LIM);
	if (L <= l && r <= R) {
		ll cur = sval[x][IDX].second.eval(T);
		if (cur <= LIM) return MP(r - l + 1, sval[x][IDX].second.eval(T));
		if (l == r) return MP(0, 0LL);
	}
	int m = l + (r - l) / 2;
	pair<int, ll> ret = MP(0, 0LL);
	if (L <= m) {
		ret = sget(2 * x + 1, l, m, L, R, T, lidx[x][IDX], LIM - ret.second);
		if (ret.first != min(R - L + 1, m - L + 1)) return ret;
	}
	if (m + 1 <= R) {
		pair<int, ll> sub = sget(2 * x + 2, m + 1, r, L, R, T, ridx[x][IDX], LIM - ret.second);
		ret.first += sub.first;
		ret.second += sub.second;
	}
	return ret;
}

pair<int, ll> sget(int L, int R, int T, ll LIM) {
	int lo = 0, hi = SZ(sval[0]);
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (sval[0][mi].first <= T) lo = mi; else hi = mi;
	}
	//printf("getting towers %d..%d at t=%d with limit %lld -> idx=%d\n", L, R, T, LIM, lo);
	pair<int, ll> ret = sget(0, 0, ntower - 1, L, R, T, lo, LIM);
	//printf("getting towers %d..%d at t=%d with limit %lld: cnt=%d sum=%lld\n", L, R, T, LIM, ret.first, ret.second);
	return ret;
}

ll solve() {
	sinit(0, 0, ntower - 1);
	vector<pair<pair<int, int>, pair<int,int>>> stck;
	stck.PB(MP(MP(0, ntower - 1), MP(INT_MIN, 0)));
	ll ret = 0;
	REP(i, nmonster) {
		ll rem = hp[i];
		int t = tspawn[i];
		while (true) {
			if (SZ(stck) == 0) {
				ret += rem;
				stck.PB(MP(MP(0, ntower - 1), MP(t, 0)));
				break;
			}
			int l = stck.back().first.first;
			int r = stck.back().first.second;
			int tt = stck.back().second.first;
			int v = stck.back().second.second;
			if (rem == 0) {
				if (l != 0) stck.PB(MP(MP(0, l - 1), MP(t, 0)));
				break;
			}
			stck.pop_back();
			int dt = tt == INT_MIN ? INT_MAX : t - tt;
			if (l == r) {
				int idx = l;
				int vv = min(v + (ll)dt * regen[idx], (ll)cap[idx]);
				int use = min((ll)vv, rem);
				rem -= vv;
				if (use < vv) {
					stck.PB(MP(MP(idx, idx), MP(t, vv - use)));
					if (idx != 0) stck.PB(MP(MP(0, idx - 1), MP(t, 0)));
					break;
				}
			} else {
				assert(v == 0);
				pair<int, ll> cur = sget(l, r, dt, rem);
				rem -= cur.second;
				if (cur.first != r - l + 1) {
					if (cur.first != r - l) stck.PB(MP(MP(l + cur.first + (rem == 0 ? 0 : 1), r), MP(tt, 0)));
					if (rem != 0) stck.PB(MP(MP(l + cur.first, l + cur.first), MP(tt, 0)));
				}
			}
		}
		//printf("after %d monsters:", i + 1); for (int j = SZ(stck) - 1; j >= 0; --j) printf(" [%d..%d: %d at %d]", stck[j].first.first + 1, stck[j].first.second + 1, stck[j].second.second, stck[j].second.first); puts("");
	}

	return ret;
}

void run() {
	scanf("%d", &ntower);
	REP(i, ntower) scanf("%d%d", &cap[i], &regen[i]);
	scanf("%d", &nmonster);
	REP(i, nmonster) scanf("%d%lld", &tspawn[i], &hp[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}