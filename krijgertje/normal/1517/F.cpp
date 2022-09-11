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

const int MAXN = 300;
const int MOD = 998244353;
const int INV2 = (MOD + 1) / 2;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }
void incprod(int& a, int b, int c) { a = (a + (ll)b * c) % MOD; }

int n;
vector<int> adj[MAXN];

int par[MAXN];

void dfsinit(int at) {
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

struct Res {
	vector<int> waysblack; // waysblack[i] = nr of ways with topmost black vertex at depth i
	vector<int> wayswhite; // wayswhite[i] = nr of ways with bottommost uncovered white vertex at depth i
};

Res merge(const Res& a, const Res& b, int d) {
	Res ret;
	ret.wayswhite = vector<int>(max(SZ(a.wayswhite), SZ(b.wayswhite) + 1), 0);
	ret.waysblack = vector<int>(max(SZ(a.waysblack), SZ(b.waysblack) + 1), 0);
	vector<int> awsum = vector<int>(SZ(a.wayswhite) + 1); awsum[0] = 0; REPSZ(i, a.wayswhite) awsum[i + 1] = (awsum[i] + a.wayswhite[i]) % MOD;
	vector<int> absum = vector<int>(SZ(a.waysblack) + 1); absum[0] = 0; REPSZ(i, a.waysblack) absum[i + 1] = (absum[i] + a.waysblack[i]) % MOD;
	vector<int> bwsum = vector<int>(SZ(b.wayswhite) + 1); bwsum[0] = 0; REPSZ(i, b.wayswhite) bwsum[i + 1] = (bwsum[i] + b.wayswhite[i]) % MOD;
	vector<int> bbsum = vector<int>(SZ(b.waysblack) + 1); bbsum[0] = 0; REPSZ(i, b.waysblack) bbsum[i + 1] = (bbsum[i] + b.waysblack[i]) % MOD;
	REPSZ(i, a.wayswhite) { int l = 0, r = min(SZ(b.wayswhite) - 1, i - 1); if (l <= r) incprod(ret.wayswhite[i], a.wayswhite[i], bwsum[r + 1] + MOD - bwsum[l]); }
	REPSZ(i, a.waysblack) { int l = max(0, i - 1), r = SZ(b.waysblack) - 1; if (l <= r) incprod(ret.waysblack[i], a.waysblack[i], bbsum[r + 1] + MOD - bbsum[l]); }
	REPSZ(i, a.wayswhite) { int l = max(0, d - i), r = SZ(b.waysblack) - 1; if (l <= r) incprod(ret.wayswhite[i], a.wayswhite[i], bbsum[r + 1] + MOD - bbsum[l]); }
	REPSZ(i, a.waysblack) { int l = 0, r = min(SZ(b.wayswhite) - 1, d - i - 1); if (l <= r) incprod(ret.waysblack[i], a.waysblack[i], bwsum[r + 1] + MOD - bwsum[l]); }
	REPSZ(j, b.wayswhite) { int l = 0, r = min(SZ(a.wayswhite) - 1, j); if (l <= r) incprod(ret.wayswhite[j + 1], awsum[r + 1] + MOD - awsum[l], b.wayswhite[j]); }
	REPSZ(j, b.waysblack) { int l = j + 2, r = SZ(a.waysblack) - 1; if (l <= r) incprod(ret.waysblack[j + 1], absum[r + 1] + MOD - absum[l], b.waysblack[j]); }
	REPSZ(j, b.waysblack) { int l = 0, r = min(SZ(a.wayswhite) - 1, d - j - 1); if (l <= r) incprod(ret.waysblack[j + 1], awsum[r + 1] + MOD - awsum[l], b.waysblack[j]); }
	REPSZ(j, b.wayswhite) { int l = max(0, d - j), r = SZ(a.waysblack) - 1; if (l <= r) incprod(ret.wayswhite[j + 1], absum[r + 1] + MOD - absum[l], b.wayswhite[j]); }
	return ret;
}

Res dfsres(int at, int d) {
	Res ret;
	ret.waysblack = ret.wayswhite = { 1 };
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		Res sub = dfsres(to, d);
		ret = merge(ret, sub, d);
	}
	//printf("dfsres(%d,%d): b=[", at + 1, d); REPSZ(i, ret.waysblack) { if (i != 0) printf(","); printf("%d", ret.waysblack[i]); } printf("] w=["); REPSZ(i, ret.wayswhite) { if (i != 0) printf(","); printf("%d", ret.wayswhite[i]); } printf("]\n");
	return ret;
}

int solve() {
	vector<int> p2(n + 1); p2[0] = 1; FORSZ(i, 1, p2) p2[i] = (ll)p2[i - 1] * 2 % MOD;
	vector<int> ip2(n + 1); ip2[0] = 1; FORSZ(i, 1, ip2) ip2[i] = (ll)ip2[i - 1] * INV2 % MOD;

	par[0] = -1; dfsinit(0);
	vector<int> waysless(n + 2);
	FORE(d, 0, n) {
		Res res = dfsres(0, d);
		int cur = 0;
		REPSZ(i, res.waysblack) inc(cur, res.waysblack[i]);
		waysless[d] = cur;
	}
	waysless[n + 1] = p2[n];
	//printf("waysless:"); REPSZ(i, waysless) printf(" %d", waysless[i]); puts("");

	int ret = 0;
	REPSZ(i, waysless) {
		int cur = waysless[i];
		if (i - 1 >= 0) dec(cur, waysless[i - 1]);
		//printf("%d times %d\n", cur, i - 1);
		incprod(ret, i + MOD - 1, cur);
	}
	return (ll)ret * ip2[n] % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}