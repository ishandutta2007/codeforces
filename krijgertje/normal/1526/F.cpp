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

const int MAXN = 100000;

int n;
int perm[MAXN];
int ans[MAXN];

bool local = false;
vector<int> localx;
int nq;

int query(int a, int b, int c) {
	++nq;
	a = perm[a], b = perm[b], c = perm[c];
	assert(a != b && a != c && b != c);
	if (!local) {
		printf("? %d %d %d\n", a + 1, b + 1, c + 1); fflush(stdout);
		int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
	} else {
		vector<int> cur = { abs(localx[a] - localx[b]),abs(localx[b] - localx[c]),abs(localx[c] - localx[a]) };
		sort(cur.begin(), cur.end());
		return cur[1];
	}
}


vector<pair<int, int>> brute() {
	int k = 5;
	set<vector<pair<int, int>>> opt;
	vector<pair<int, int>> sstate(k); REP(i, k) sstate[i] = MP(i, 0); opt.insert(sstate);
	vector<vector<int>> mem;
	REP(a, k) FOR(b, a + 1, k) FOR(c, b + 1, k) {
		int res = query(a, b, c);
		mem.PB(vector<int>{a, b, c, res});
		set<vector<pair<int, int>>> nopt;
		vector<int> cur = { a,b,c };
		for (auto state : opt) {
			REPSZ(i, cur) REPSZ(j, cur) if (j != i) {
				int x = cur[i], y = cur[j];
				if (state[x].first == state[y].first) {
					if (state[y].second != state[x].second + res) continue;
					nopt.insert(state);
				} else {
					int old = state[y].first, delta = state[x].second + res - state[y].second;
					auto nstate = state;
					REPSZ(z, nstate) if (nstate[z].first == old) nstate[z].first = nstate[x].first, nstate[z].second += delta;
					nopt.insert(nstate);
				}
			}
		}
		opt.clear();
		for (auto state : nopt) {
			bool ok = true;
			for (auto old : mem) {
				int aa = old[0], bb = old[1], cc = old[2], rres = old[3];
				if (state[bb].first == state[aa].first && state[cc].first == state[aa].first) {
					int xa = state[aa].second, xb = state[bb].second, xc = state[cc].second;
					vector<int> cur = { abs(xa - xb),abs(xb - xc),abs(xc - xa) };
					sort(cur.begin(), cur.end());
					if (cur[1] != rres) { ok = false; break; }
				}
			}
			if (state[0].first == state[1].first && state[0].second >= state[1].second) ok = false;
			if (!ok) continue;
			vector<int> mp(k, -1);
			vector<int> delta(k);
			REPSZ(i, state) {
				if (mp[state[i].first] == -1) {
					mp[state[i].first] = i;
					delta[state[i].first] = -state[i].second;
				}
				state[i].second += delta[state[i].first];
				state[i].first = mp[state[i].first];
			}
			opt.insert(state);
		}
		//printf("query(%d,%d,%d)=%d\n", a, b, c, res);
		//for (auto state : opt) { printf("opt:"); REPSZ(i, state) printf(" (%d,%d)", state[i].first, state[i].second); puts(""); }
	}
	assert(SZ(opt) >= 1);
	if (SZ(opt) != 1) return vector<pair<int, int>>();
	vector<pair<int, int>> ret;
	auto state = *opt.begin();
	REP(i, k) ret.PB(MP(i, state[i].second));
	sort(ret.begin(), ret.end(), [&](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
	int d1 = ret[1].second - ret[0].second;
	int d2 = ret[k - 1].second - ret[k - 2].second;
	if (ret[1].second + d1 >= ret[k - 2].second - d2) return vector<pair<int, int>>();
	return ret;
}

void solve() {
	vector<pair<int, int>> start;
	while (true) {
		REP(i, n) perm[i] = i;
		shuffle(perm + 2, perm + n, rnd);
		start = brute();
		if (SZ(start) != 0) break;
	}
	//printf("start:"); REPSZ(i, start) printf(" (%d,%d)", perm[start[i].first], start[i].second); puts("");
	//printf("->"); REPSZ(i, start) printf(" %d", localx[perm[start[i].first]]); puts("");
	vector<bool> know(n, false);
	vector<int> rel(n);
	REPSZ(i, start) know[start[i].first] = true, rel[start[i].first] = start[i].second;
	int d1 = start[1].second - start[0].second;
	int d2 = start[SZ(start) - 1].second - start[SZ(start) - 2].second;
	REP(i, n) if (!know[i]) {
		int ares = query(start[0].first, start[1].first, i);
		int bres = query(start[SZ(start) - 2].first, start[SZ(start) - 1].first, i);
		if (ares <= d1) {
			assert(bres >= d2);
			rel[i] = start[SZ(start) - 2].second - bres;
			continue;
		}
		if (bres <= d2) {
			assert(ares >= d1);
			rel[i] = start[1].second + ares;
			continue;
		}
		map<int, int> cnt;
		++cnt[start[0].second - ares];
		++cnt[start[1].second + ares];
		++cnt[start[SZ(start) - 2].second - bres];
		++cnt[start[SZ(start) - 1].second + bres];
		int found = 0;
		for (auto p : cnt) if (p.second == 2) { rel[i] = p.first; ++found; }
		assert(found == 1);
	}
	int mn = rel[0]; FOR(i, 1, n) mn = min(mn, rel[i]);
	REP(i, n) ans[perm[i]] = rel[i] - mn;
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); REP(i, n) printf(" %d", ans[i] + 1); puts(""); fflush(stdout);
	int ok; scanf("%d", &ok); if (ok == -1) exit(0); assert(ok == 1);
}

void stress() {
	int mnn = 20, mxn = 50; local = true;
	int mxq = 0;
	REP(rep, 1) {
		n = rnd() % (mxn - mnn + 1) + mnn;
		localx = vector<int>(n);
		REP(i, n) localx[i] = i;
		while (true) { shuffle(localx.begin(), localx.end(), rnd); if (localx[0] < localx[1]) break; }
		//printf("x:"); REP(i, n) printf(" %d", localx[i]); puts("");
		nq = 0;
		solve();
		bool ok = true; REP(i, n) if (ans[i] != localx[i]) ok = false;

		int spareq = nq - 2 * n;
		if (rep % 100 == 99 || spareq > mxq) { printf("spareq=%d\n", spareq); mxq = max(mxq, spareq); }
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("want:"); REP(i, n) printf(" %d", localx[i]); puts("");
		printf("have:"); REP(i, n) printf(" %d", ans[i]); puts("");

	}
}

void research() {
	std::mt19937 rnd(123);
	// for k points (5?), perform all queries and find consistent relative positions -> hopefully always only one option

	int k = 5, lim = 1000;

	REP(rep, 100) {
		vector<int> x(k);
		REP(i, k) x[i] = rnd() % (lim + k + 1);
		sort(x.begin(), x.end());
		REP(i, k) x[i] += i;
		while (true) { shuffle(x.begin(), x.end(), rnd); if (x[0] < x[1]) break; }

		auto query = [&](int a, int b, int c) {
			vector<int> cur = { abs(x[a] - x[b]),abs(x[b] - x[c]),abs(x[c] - x[a]) };
			sort(cur.begin(), cur.end());
			return cur[1];
		};


		set<vector<pair<int, int>>> opt;
		vector<pair<int, int>> sstate(k); REP(i, k) sstate[i] = MP(i, 0); opt.insert(sstate);
		vector<vector<int>> mem;
		REP(a, k) FOR(b, a + 1, k) FOR(c, b + 1, k) {
			int res = query(a, b, c);
			mem.PB(vector<int>{a, b, c, res});
			set<vector<pair<int, int>>> nopt;
			vector<int> cur = { a,b,c };
			for (auto state : opt) {
				REPSZ(i, cur) REPSZ(j, cur) if (j != i) {
					int x = cur[i], y = cur[j];
					if (state[x].first == state[y].first) {
						if (state[y].second != state[x].second + res) continue;
						nopt.insert(state);
					} else {
						int old = state[y].first, delta = state[x].second + res - state[y].second;
						auto nstate = state;
						REPSZ(z, nstate) if (nstate[z].first == old) nstate[z].first = nstate[x].first, nstate[z].second += delta;
						nopt.insert(nstate);
					}
				}
			}
			opt.clear();
			for (auto state : nopt) {
				bool ok = true;
				for (auto old : mem) {
					int aa = old[0], bb = old[1], cc = old[2], rres = old[3];
					if (state[bb].first == state[aa].first && state[cc].first == state[aa].first) {
						int xa = state[aa].second, xb = state[bb].second, xc = state[cc].second;
						vector<int> cur = { abs(xa - xb),abs(xb - xc),abs(xc - xa) };
						sort(cur.begin(), cur.end());
						if (cur[1] != rres) { ok = false; break; }
					}
				}
				if (state[0].first == state[1].first && state[0].second >= state[1].second) ok = false;
				if (!ok) continue;
				vector<int> mp(k, -1);
				vector<int> delta(k);
				REPSZ(i, state) {
					if (mp[state[i].first] == -1) {
						mp[state[i].first] = i;
						delta[state[i].first] = -state[i].second;
					}
					state[i].second += delta[state[i].first];
					state[i].first = mp[state[i].first];
				}
				opt.insert(state);
			}
			//printf("query(%d,%d,%d)=%d\n", a, b, c, res);
			//for (auto state : opt) { printf("opt:"); REPSZ(i, state) printf(" (%d,%d)", state[i].first, state[i].second); puts(""); }
		}
		printf("x:"); REP(i, k) printf(" %d", x[i]); puts("");
		for (auto state : opt) {
			printf("opt:"); REPSZ(i, state) printf(" (%d,%d)", state[i].first, state[i].second); puts("");
		}
	}
}

int main() {
	//research();
	//stress();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}