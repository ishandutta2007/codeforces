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

const int MAXN = 300000;
const int MAXS = 4 * (MAXN + 1);
struct SVal { 
	ll ways;
	bool isalt; // isalt -> odd positions are pos (or zero), even positions are neg (or zero)
	int suff; // suff -> # suffixes of zero and alternating
	int pref; // pref -> # prefixes of alternating and zero
};

int n;
int a[MAXN];

ll b[MAXN + 1];
int ord[MAXN + 1];

SVal s[MAXS];

SVal merge(const SVal &a, const SVal &b) {
	SVal ret;
	ret.ways = a.ways + b.ways + (ll)a.suff * b.pref;
	ret.isalt = a.isalt && b.isalt;
	ret.suff = b.suff + (b.isalt ? a.suff : 0);
	ret.pref = a.pref + (a.isalt ? b.pref : 0);
	return ret;
}
SVal create(int val, int par) {
	SVal ret;
	ret.ways = 0;
	ret.isalt = par == 0 && val <= 0 || par == 1 && val >= 0;
	ret.suff = ret.pref = val == 0 ? 1 : 0;
	return ret;
}

void sinit(int x, int l, int r) {
	if (l == r) {
		s[x] = create(+1, l % 2);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		s[x] = merge(s[2 * x + 1], s[2 * x + 2]);
	}
}
void smod(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		s[x] = create(VAL, l % 2);
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(2 * x + 1, l, m, IDX, VAL);
		else smod(2 * x + 2, m + 1, r, IDX, VAL);
		s[x] = merge(s[2 * x + 1], s[2 * x + 2]);
	}
}

ll solve() {
	b[0] = 0;
	REP(i, n) b[i + 1] = b[i] + (i % 2 == 0 ? +a[i] : -a[i]);
	//printf("b:"); REP(i, n + 1) printf(" %lld", b[i]); puts("");
	REP(i, n + 1) ord[i] = i;
	sort(ord, ord + n + 1, [&](int i, int j) { return b[i] < b[j]; });
	sinit(0, 0, n);
	ll ret = 0;
	string cur(n + 1, '+');
	for (int l = 0, r = l; l < n + 1; l = r) {
		while (r < n + 1 && b[ord[r]] == b[ord[l]]) ++r;
		FOR(i, l, r) smod(0, 0, n, ord[i], 0);
		FOR(i, l, r) cur[ord[i]] = '0';
		ret += s[0].ways;
		//printf("%lld: %s -> %lld\n", b[ord[l]], cur.c_str(), s[0].ways);
		FOR(i, l, r) smod(0, 0, n, ord[i], -1);
		FOR(i, l, r) cur[ord[i]] = '+';
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}