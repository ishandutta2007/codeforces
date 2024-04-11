#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXEACH = 30;

int nraw, ncooked;
char s[2 * MAXEACH + 1];

ll C[2 * MAXEACH + 1][2 * MAXEACH + 1];
ll best;

set<ll> memfind[MAXEACH + 1][MAXEACH + 1];
void findbest(int n1, int n2, ll x1, ll x2) {
	if (x1 > x2) swap(n1, n2), swap(x1, x2);
	//printf("findbest(%d,%d,%lld,%lld)\n", n1, n2, x1, x2);
	if (n1 < nraw || n2 < nraw) { best = min(best, x2 - x1); return; }
	if (x2 - x1 - C[n1][nraw] * C[n2][nraw] >= best) return;
	if (!memfind[n1][n2].insert(x2 - x1).second) return;
	findbest(n1 - 1, n2, x1 + C[n1 - 1][nraw - 1] * C[n2][nraw], x2);
	if (n1 != n2 || x1 != x2) findbest(n1, n2 - 1, x1, x2 + C[n1][nraw] * C[n2 - 1][nraw - 1]);
}

ll findbest() {
	best = LLONG_MAX; REPE(i, MAXEACH) REPE(j, MAXEACH) memfind[i][j].clear();
	findbest(nraw + ncooked, nraw + ncooked, 0, 0);
	return best;
}

map<ll, ll> memcount[MAXEACH + 1][MAXEACH + 1];
ll countmatch(int n1, int n2, ll x1, ll x2) {
	ll diff = abs(x2 - x1);
	if (n1 < nraw || n2 < nraw) {
		if (diff != best) return 0;
		int na = 0, nb = 0;
		REP(i, n1 + n2) if (s[i] == 'A') ++na; else if (s[i] == 'B') ++nb;
		return na <= n1&&nb <= n2 ? C[n1 + n2 - na - nb][n1 - na] : 0;
	} else {
		if (diff > best + C[n1][nraw] * C[n2][nraw]) return 0;
		if (memcount[n1][n2].count(x2 - x1)) return memcount[n1][n2][x2 - x1];
		ll ret = 0; int idx = n1 + n2 - 1;
		if (s[idx] != 'B') ret += countmatch(n1 - 1, n2, x1 + C[n1 - 1][nraw - 1] * C[n2][nraw], x2);
		if (s[idx] != 'A') ret += countmatch(n1, n2 - 1, x1, x2 + C[n1][nraw] * C[n2 - 1][nraw - 1]);
		return memcount[n1][n2][x2 - x1] = ret;
	}
}

ll countmatch() {
	REPE(i, MAXEACH) REPE(j, MAXEACH) memcount[i][j].clear();
	return countmatch(nraw + ncooked, nraw + ncooked, 0, 0);
}


void run() {
	scanf("%d%d%s", &nraw, &ncooked, s);
	findbest();
	//printf("best=%lld\n", best);
	ll ans = countmatch();
	printf("%lld\n", ans);

}

void precalc() {
	REPE(i, 2 * MAXEACH) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; }
}

void stress() {
	for (nraw = 1; nraw <= 20; ++nraw) for (ncooked = 1; ncooked <= 20; ++ncooked) if (nraw + ncooked <= 30) {
		REP(i, nraw + ncooked) s[i] = '?'; s[nraw + ncooked] = '\0';
		findbest(); ll ans = countmatch();
		printf("%d %d = %lld -> %lld\n", nraw, ncooked, best, ans);
	}
}

int main() {
	precalc();
	//stress();
	run();
	return 0;
}