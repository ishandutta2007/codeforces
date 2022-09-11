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

const int MAXN = 6000;

int n;
int a[MAXN], b[MAXN], c[MAXN];
int ansruler; ll ansfights;

bool solve() {
	vector<int> p(n);
	REP(i, n) p[i] = i;
	if (a[p[0]] > a[p[1]]) swap(p[0], p[1]);
	int at = 1;
	ll nfights = 1;
	int nadjloser = 0;
	vector<bool> loser(n, false);
	vector<bool> adjloser(n, false);
	auto updloser = [&](int idx) {
		int pidx = (idx + n - 1) % n, nidx = (idx + 1) % n;
		if (adjloser[p[idx]]) --nadjloser;
		if (adjloser[p[nidx]]) --nadjloser;
		loser[p[idx]] = a[p[idx]] < b[p[pidx]];
		adjloser[p[idx]] = loser[p[idx]] && loser[p[pidx]];
		adjloser[p[nidx]] = loser[p[nidx]] && loser[p[idx]];
		if (adjloser[p[idx]]) ++nadjloser;
		if (adjloser[p[nidx]]) ++nadjloser;
	};
	REP(i, n) updloser(i);
	//printf("start done:"); REP(i, n) { printf(" %d%c", p[i], loser[p[i]] ? 'R' : 'W'); if (i == at) printf("!"); } printf(" (%lld fights)\n", nfights);

	while (true) {
		assert(!loser[p[at]]);
		if (nadjloser == 0 && nfights != 1) break;
		int to = (at + 1) % n;
		++nfights;
		if (b[p[at]] < a[p[to]]) { at = to; continue; }
		swap(p[at], p[to]), swap(at, to);
		updloser(to);
		updloser(at);
		assert(!loser[p[at]]);
		to = (at + 1) % n;
		updloser(to);
		++nfights;
		if (c[p[at]] > a[p[to]]) { ansruler = p[at]; ansfights = nfights; return true; }
		at = to;
	}
	//printf("init done:"); REP(i, n) { printf(" %d%c", p[i], loser[p[i]] ? 'R' : 'W'); if (i == at) printf("!"); } printf(" (%lld fights)\n", nfights);

	while (true) {
		{ vector<int> np(n); REP(i, n) np[i] = p[(at + i) % n]; p = np; at = 0; }
		//printf("state:"); REP(i, n) { printf(" %d%c", p[i], loser[p[i]] ? 'R' : 'W'); if (i == at) printf("!"); } printf(" (%lld fights)\n", nfights);
		assert(!loser[p[0]]); assert(!loser[p[n - 1]]); REP(i, n - 1) if (loser[p[i]]) assert(!loser[p[i + 1]]);

		bool allwhite = true; REP(i, n) if (loser[p[i]]) allwhite = false; if (allwhite) return false;

		int bestt = INT_MAX; int bestkind = -1;

		deque<int> q;
		auto addq = [&](int idx) { while (SZ(q) != 0 && b[p[idx]] <= b[p[q.back()]]) q.pop_back(); q.push_back(idx); };
		REP(i, n) if (!loser[p[i]]) addq(i);
		vector<int> widx(n, -1); int nw = 0; REP(i, n) if (!loser[p[i]]) widx[i] = nw++;
		REP(i, n) {
			if (!loser[p[i]]) { addq(i); continue; }
			int lo = -1, hi = SZ(q);
			//printf("\t\tq: (%d)",SZ(q)); REPSZ(j, q) printf(" %d=%d", p[q[j]], b[p[q[j]]]); puts("");
			while (lo + 1 < hi) {
				int mi = lo + (hi - lo) / 2;
				if (a[p[i]] > b[p[q[mi]]]) lo = mi; else hi = mi;
			}
			if (lo == -1) continue;
			int j = q[lo];
			int t = ((widx[i - 1] - widx[j] - 1 + nw) % nw) * (n - 1) + i - 1 + 1;
			//printf("\t%d becomes white because of %d after %d\n", p[i], p[j], t);
			if (t <= bestt) bestt = t, bestkind = 0;
		}

		vector<int> nxtred(n, -1);
		for (int i = n - 2; i >= 0; --i) nxtred[i] = loser[p[i]] ? i : nxtred[i + 1];
		assert(nxtred[0] != -1);
		REP(i, n) if (nxtred[i] == -1) nxtred[i] = nxtred[0];
		REP(i, n) {
			if (loser[p[i]]) continue;
			int j = (i + 1) % n;
			if (loser[p[j]]) j = (j + 1) % n;
			assert(!loser[p[j]]);
			if (c[p[i]] < a[p[j]]) continue;
			int t = ((widx[nxtred[i] - 1] - widx[i] + nw) % nw) * (n - 1) + nxtred[i] - 1 + 1;
			//printf("\t%d wins by defeating %d after %d\n", p[i], p[j], t);
			if (t <= bestt) bestt = t, bestkind = 1;
		}

		if (bestt == INT_MAX) return false;

		vector<int> wlst; REP(i, n) if (!loser[p[i]]) wlst.PB(i);
		vector<int> np(n);
		int full = bestt / (n - 1), rem = bestt % (n - 1);
		REP(i, n) if (loser[p[i]]) np[i] = p[i]; else np[wlst[(widx[i] + full) % nw]] = p[i];
		REP(i, rem) if (loser[np[i + 1]]) swap(np[i], np[i + 1]);
		p = np, at = rem, nfights += bestt;
		if (bestkind == 0) updloser(at - 1);
		if (bestkind == 1) { ansruler = p[at]; ansfights = nfights + 1; return true; }
	}

	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	if (!solve()) { printf("-1 -1\n"); return; }
	printf("%d %lld\n", ansruler, ansfights);

}

int main() {
	run();
	return 0;
}