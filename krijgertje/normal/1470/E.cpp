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

const int MAXN = 30000;
const int MAXCOST = 4;
const int MAXQ = 300000;

int n, mxcost, nq;
int p[MAXN];
int qpos[MAXQ]; ll qperm[MAXQ]; int qans[MAXQ];

vector<int> opt[MAXCOST + 1][MAXN];
ll ways[MAXCOST + 1][MAXN + 1];
ll offset[MAXCOST + 1][MAXN + 1];
map<ll, pair<int, int>> nxt[MAXCOST + 1];


void safeinc(ll& a, ll b) { if (a > LLONG_MAX - b) a = LLONG_MAX; else a += b; }

void solve() {
	REPE(c,mxcost) REP(i, n) {
		opt[c][i].clear();
		for (int j = i; j < n && j <= i + c; ++j) opt[c][i].PB(j);
		sort(opt[c][i].begin(), opt[c][i].end(), [&](const int& a, const int& b) { return p[a] < p[b]; });
	}
	REPE(c, mxcost) {
		ways[c][n] = 1;
		for (int i = n - 1; i >= 0; --i) {
			ways[c][i] = 0;
			for (int j : opt[c][i]) safeinc(ways[c][i], ways[c - (j - i)][j + 1]);
		}
		//printf("ways%d:", c); REP(i, n) printf(" %lld", ways[c][i]); puts("");
	}
	REPE(c, mxcost) {
		nxt[c].clear();
		ll at = 0;
		REP(i, n) {
			offset[c][i] = at;
			ll to = -1;
			for (int j : opt[c][i]) {
				if (j == i) {
					to = at;
				} else {
					nxt[c][at] = MP(i, j);
				}
				safeinc(at, ways[c - (j - i)][j + 1]);
			}
			assert(to != -1); at = to;
		}
		offset[c][n] = at;
		nxt[c][at] = MP(n, n);
		nxt[c][ways[c][0]] = MP(-1, -1);
		//printf("nxt%d:", c); for (auto it = nxt[c].begin(); it != nxt[c].end(); ++it) printf(" %lld:%d/%d", it->first, it->second.first, it->second.second); puts("");
	}

	REP(i, nq) {
		int c = mxcost; ll want = qperm[i]; int pos = qpos[i];
		//printf("processing %d: %lld\n", i, want);
		if (want >= ways[c][0]) { qans[i] = -1; continue; }
		vector<pair<int, int>> revs;
		while (true) {
			auto it = prev(nxt[c].upper_bound(want));
			int at = it->second.first, to = it->second.second;
			want -= it->first;
			if (at == n && to == n) { assert(want == 0); break; }
			//printf("\t(%d,%d)\n", at, to);
			revs.PB(MP(at, to));
			int nc = c - (to - at);
			assert(offset[nc][to + 1] != LLONG_MAX);
			c = nc, want += offset[nc][to + 1];
		}
		if (SZ(revs) == 0) { qans[i] = p[pos]; continue; }
		if (pos < revs[0].first) qans[i] = p[pos];
		FORSZ(j, 1, revs) if (pos > revs[j - 1].second && pos < revs[j].first) qans[i] = p[pos];
		if (pos > revs[SZ(revs) - 1].second) qans[i] = p[pos];
		REPSZ(j, revs) { int a = revs[j].first, b = revs[j].second; if (a <= pos && pos <= b) qans[i] = p[a + (b - pos)]; }
	}

}

void run() {
	scanf("%d%d%d", &n, &mxcost, &nq);
	REP(i, n) scanf("%d", &p[i]), --p[i];
	REP(i, nq) scanf("%d%lld", &qpos[i], &qperm[i]), --qpos[i], --qperm[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i] == -1 ? -1 : qans[i] + 1);
}

void stress() {
	REP(rep, 10000) {
		n = MAXN;
		mxcost = MAXCOST; // rnd() % (MAXCOST + 1);
		nq = MAXQ;
		REP(i, n) p[i] = i;
		//REP(i, n) { int idx = rnd() % (i + 1); swap(p[i], p[idx]); }
		REP(i, nq) qpos[i] = rnd() % n, qperm[i] = (ll)(rnd() % 1000000000) * 1000000000 + rnd() % 1000000000;
		solve();
		printf(".");
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}