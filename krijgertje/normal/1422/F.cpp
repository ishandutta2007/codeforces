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
const int MAXQ = 100000;
const int MAXVAL = 200000;
const int MOD = 1000000007;

int n;
int a[MAXN];
int nq;
int qx[MAXQ], qy[MAXQ], qans[MAXQ];

int pmn[MAXVAL + 1];
vector<pair<int, int>> factors[MAXN];
int last[MAXVAL + 1];
vector<vector<int>> nxt[MAXN];

int bsz;
int nb;
vector<vector<int>> lcmpref; // lcmpref[i][j]==lcm(k==i*bsz..i*bsz+j,a[k])

void solve() {
	REPE(i, MAXVAL) pmn[i] = -1; FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;
	REP(i, n) factors[i].clear();
	REP(i, n) {
		int x = a[i];
		while (x != 1) {
			int p = pmn[x], cnt = 0;
			while (x % p == 0) x /= p, ++cnt;
			factors[i].PB(MP(p, cnt));
		}
	}
	REPE(i, MAXVAL) last[i] = n;
	for (int i = n - 1; i >= 0; --i) {
		nxt[i] = vector<vector<int>>(SZ(factors[i]));
		REPSZ(j, factors[i]) {
			int p, cnt; tie(p, cnt) = factors[i][j];
			nxt[i][j] = vector<int>(cnt);
			int x = 1; REP(k, cnt) { x *= p; nxt[i][j][k] = last[x]; last[x] = i; }
		}
	}
	bsz = max(1, (int)sqrt(n));
	nb = (n + bsz - 1) / bsz;
	lcmpref = vector<vector<int>>(nb);
	REPE(i, MAXVAL) last[i] = -1;
	REP(b, nb) {
		int s = b * bsz;
		lcmpref[b] = vector<int>(n - s, -1);
		int cur = 1;
		FOR(i, s, n) {
			REPSZ(j, factors[i]) {
				int p, cnt; tie(p, cnt) = factors[i][j];
				int x = 1; REP(k, cnt) { x *= p; if (last[x] != b) cur = (ll)cur * p % MOD; last[x] = b; }
			}
			lcmpref[b][i - s] = cur;
		}
	}
	int lastans = 0;
	REPE(i, MAXVAL) last[i] = -1;
	REP(i, nq) {
		int l = (lastans + qx[i]) % n, r = (lastans + qy[i]) % n; if (l > r) swap(l, r);
		int b = (l + bsz - 1) / bsz;
		if (b * bsz <= r) {
			int cur = lcmpref[b][r - b * bsz];
			for (int i = b * bsz - 1; i >= l; --i) {
				REPSZ(j, factors[i]) {
					int p, cnt; tie(p, cnt) = factors[i][j];
					REP(k, cnt) if (nxt[i][j][k] > r) cur = (ll)cur * p % MOD;
				}
			}
			qans[i] = cur;
		} else {
			int cur = 1;
			FORE(i, l, r) {
				REPSZ(j, factors[i]) {
					int p, cnt; tie(p, cnt) = factors[i][j];
					REP(k, cnt) if (nxt[i][j][k] > r) cur = (ll)cur * p % MOD;
				}
			}
			qans[i] = cur;
		}
		lastans = qans[i];
	}
}


void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int qansstupid[MAXQ];

void solvestupid() {
	int lastans = 0;
	REP(i, nq) {
		int l = (lastans + qx[i]) % n, r = (lastans + qy[i]) % n; if (l > r) swap(l, r);
		map<int, int> have;
		FORE(j, l, r) {
			int x = a[j];
			for (int k = 2; k <= x; ++k) if (x % k == 0) {
				int cnt = 0; while (x % k == 0) x /= k, ++cnt;
				have[k] = max(have[k], cnt);
			}
		}
		qansstupid[i] = 1; for (auto it = have.begin(); it != have.end(); ++it) REP(j, it->second) qansstupid[i] = (ll)qansstupid[i] * it->first % MOD;
		lastans = qansstupid[i];
	}
}

void stress() {
	vector<int> p; p.PB(2); p.PB(3); p.PB(5); p.PB(7);
	REP(rep, 1000) {
		n = rnd() % 100 + 1;
		REP(i, n) {
			int cur = 1;
			while (true) { cur = 1; REPSZ(j, p) { int lim = 0; int tmp = cur; while (tmp * p[j] <= MAXVAL) tmp *= p[j], ++lim; int cnt = rnd() % (rnd() % (lim + 1) + 1); REP(k, cnt) if (cur * p[j] <= MAXVAL) cur *= p[j]; } if (cur <= MAXVAL) break; }
			a[i] = cur;
		}
		nq = rnd() % 100 + 1;
		REP(i, nq) qx[i] = rnd() % n, qy[i] = rnd() % n;
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
		printf("%d\n", nq); REP(i, nq) printf("%d %d\n", qx[i], qy[i]);
		printf("have:"); REP(i, nq) printf(" %d", qans[i]); puts("");
		printf("want:"); REP(i, nq) printf(" %d", qansstupid[i]); puts("");
	}
}

void stresstime() {
	vector<int> p; p.PB(2); p.PB(3); p.PB(5); p.PB(7); p.PB(11); p.PB(13); p.PB(17); p.PB(19);
	REP(rep, 10) {
		n = MAXN;
		REP(i, n) {
			ll cur = 1;
			while (true) { cur = 1; REPSZ(j, p) { int lim = 0; int tmp = cur; while (tmp * p[j] <= MAXVAL) tmp *= p[j], ++lim; int cnt = rnd() % (rnd() % (lim + 1) + 1); REP(k, cnt) if (cur * p[j] <= MAXVAL) cur *= p[j]; } if (cur <= MAXVAL) break; }
			a[i] = cur;
		}
		nq = MAXQ;
		REP(i, nq) qx[i] = rnd() % n, qy[i] = rnd() % n;
		solve();
		printf(".");
	}
}

int main() {
	//stress();
	//stresstime();
	run();
	return 0;
}