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
ll mylcm(ll a, ll b) { return a / gcd(a, b) * b; }

const int MAXN = 100000;
const int MINL = 1;
const int MAXR = 2 * MAXN;

int n;
int ans[MAXN];

int pmn[MAXR + 1];
vector<int> primes;

bool local = false;
int alocal[MAXN];

ll query(int i, int j) {
	if (!local) {
		printf("? %d %d\n", i + 1, j + 1); fflush(stdout);
		ll ret; scanf("%lld", &ret); return ret;
	} else {
		return (ll)alocal[i] * alocal[j] / gcd(alocal[i], alocal[j]);
	}
}

void solve() {
	int k = min(30, n);
	set<int> fullset;
	while (SZ(fullset) < k) fullset.insert(rnd() % n);
	vector<int> full(fullset.begin(), fullset.end());
	vector<vector<ll>> fulllcm(k, vector<ll>(k));
	REP(i, k) FOR(j, i + 1, k) fulllcm[i][j] = fulllcm[j][i] = query(full[i], full[j]);

	if (n == 3) {
		for (int l = MINL, r = l + n - 1; r <= MAXR; ++l, ++r) {
			ll a = mylcm(l, l + 1), b = mylcm(l, l + 2), c = mylcm(l + 1, l + 2);
			vector<int> perm = { 0,1,2 };
			do {
				if (fulllcm[perm[0]][perm[1]] != a) continue;
				if (fulllcm[perm[0]][perm[2]] != b) continue;
				if (fulllcm[perm[1]][perm[2]] != c) continue;
				ans[full[perm[0]]] = l, ans[full[perm[1]]] = l + 1, ans[full[perm[2]]] = l + 2; return;
			} while (next_permutation(perm.begin(), perm.end()));
		}
		printf("Not found\n");
		exit(0);
	}

	vector<int> fullval(k, 1);
	for (auto p : primes) {
		vector<vector<int>> cur(k, vector<int>(k, 0));
		REP(i, k) FOR(j, i + 1, k) {
			ll x = fulllcm[i][j];
			int cnt = 0;
			while (x % p == 0) x /= p, ++cnt;
			cur[i][j] = cur[j][i] = cnt;
		}
		vector<int> sum(k, 0);
		REP(i, k) REP(j, k) sum[i] += cur[i][j];
		int mnidx = 0;
		FOR(i, 1, k) if (sum[i] < sum[mnidx]) mnidx = i;
		vector<int> expect(k);
		REP(i, k) expect[i] = i == mnidx ? 0 : cur[mnidx][i];
		REP(i, k) FOR(j, i + 1, k) assert(cur[i][j] == max(expect[i], expect[j]));
		REP(i, k) REP(j, expect[i]) fullval[i] *= p;
		bool any = false; REP(i, k) if (expect[i] != 0) any = true;
		//if (any) { printf("%d:", p); REP(i, k) FOR(j, i + 1, k) printf(" %d", cur[i][j]); puts(""); }
	}
	//printf("fullval:"); REP(i, k) printf(" %d", fullval[i]); puts("");
	//REP(i, k) assert(fullval[i] == alocal[full[i]]);

	REP(i, n) ans[i] = -1;
	REP(i, k) ans[full[i]] = fullval[i];

	vector<int> rem;
	REP(i, n) if (!fullset.count(i)) rem.PB(i);
	REPSZ(i, rem) { int idx = rnd() % (i + 1); swap(rem[i], rem[idx]); }
	if (SZ(rem) == 0) return;


	int best = full[0], bestval = pmn[fullval[0]];
	FOR(i, 1, k) if (pmn[fullval[i]] > bestval) best = full[i], bestval = pmn[fullval[i]];

	int a = -1, b = -1;
	REP(i, k) FOR(j, i + 1, k) if (a == -1 && b == -1 && gcd(fullval[i], fullval[j]) == 1) a = full[i], b = full[j];
	assert(a != -1 && b != -1);
	
	REPSZ(i, rem) {
		int cur = rem[i];
		if (i < 4000) {
			ll x = query(a, cur); //ll xx = x;
			ll y = query(b, cur); //ll yy = y;
			while (true) { ll g = gcd(x, ans[a]); if (g == 1) break; x /= g; }
			while (true) { ll g = gcd(y, ans[a]); if (g == 1) break; y /= g,x*=g; }
			ans[cur] = x;
			/*if (ans[cur] != alocal[cur]) {
				printf("cur=%d: ans[a]=%d ans[b]=%d -> (%lld,%lld) -> (%lld,%lld) -> %d (want %d)\n", cur, ans[a], ans[b], xx, yy, x, y, ans[cur], alocal[cur]);
				exit(0);
			}*/
			if (pmn[ans[cur]] > bestval) best = cur, bestval = pmn[ans[cur]];
		} else {
			ll x = query(best, cur);
			ans[cur] = x / ans[best];
			//assert(ans[cur] == alocal[cur]);
		}
	}
	//REP(i, n) assert(ans[i] == alocal[i]);
}

void precalc() {
	memset(pmn, -1, sizeof(pmn));
	FORE(i, 2, MAXR) if (pmn[i] == -1) for (int j = i; j <= MAXR; j += i) if (pmn[j] == -1) pmn[j] = i;
	primes.clear();
	REPE(i, MAXR) if (pmn[i] == i) primes.PB(i);
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); REP(i, n) printf(" %d", ans[i]); puts(""); fflush(stdout);
}

void stress() {
	std::mt19937 rnd(21312);
	local = true;
	REP(rep, 100000) {
		//int k = rnd() % 5 + 1;
		//n = 1; REP(i, k) n *= 10;
		n = rnd() % (MAXN - 3 + 1) + 3;
		//if (n != 3) continue;
		int l = MINL + rnd() % (MAXR - MINL + 1 - n + 1);
		REP(i, n) alocal[i] = l + i;
		REP(i, n) { int idx = rnd() % (i + 1); swap(alocal[i], alocal[idx]); }
		//if (rep != 53) continue;
		solve();
		bool ok = true; REP(i, n) if (alocal[i] != ans[i]) ok = false;
		if (ok) { if (rep % 1000 == 999) printf("."); continue; }
		printf("err %d\n", rep);
		printf("have:"); REP(i, n) printf(" %d", ans[i]); puts("");
		printf("want:"); REP(i, n) printf(" %d", alocal[i]); puts("");
		exit(0);
	}
}

void test() {
	local = true;
	int ncase;
	scanf("%d", &ncase);
	FORE(casenr, 1, ncase) {
		scanf("%d", &n);
		REP(i, n) scanf("%d", &alocal[i]);
		solve();
		bool ok = true; REP(i, n) if (alocal[i] != ans[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err %d\n", casenr);
		printf("have:"); REP(i, n) printf(" %d", ans[i]); puts("");
		printf("want:"); REP(i, n) printf(" %d", alocal[i]); puts("");
		exit(0);
	}
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	//test();
	return 0;
}