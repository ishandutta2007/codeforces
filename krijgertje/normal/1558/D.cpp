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
const int MOD = 998244353;
const int MAXS = 4 * MAXN;

int n, nmove;
int moveval[MAXN],moveidx[MAXN];

int inv[2 * MAXN + 1];
int fac[2 * MAXN + 1];
int ifac[2 * MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }


int scnt[MAXS];

void sinit(int x, int l, int r) {
	if (l == r) {
		scnt[x] = 1;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		scnt[x] = scnt[2 * x + 1] + scnt[2 * x + 2];
	}
}
int sget(int x, int l, int r, int IDX) {
	assert(IDX < scnt[x]);
	if (l == r) {
		return l;
	} else {
		int m = l + (r - l) / 2;
		if (IDX < scnt[2 * x + 1]) return sget(2 * x + 1, l, m, IDX); else IDX -= scnt[2 * x + 1];
		if (IDX < scnt[2 * x + 2]) return sget(2 * x + 2, m + 1, r, IDX); else IDX -= scnt[2 * x + 2];
		assert(false); return -1;
	}
}
void sset(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		scnt[x] = VAL;
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) sset(2 * x + 1, l, m, IDX, VAL); else sset(2 * x + 2, m + 1, r, IDX, VAL);
		scnt[x] = scnt[2 * x + 1] + scnt[2 * x + 2];
	}
}

int getpos(int idx) { return sget(0, 0, MAXN - 1, idx); }
vector<int> filled;
void fill(int idx) { sset(0, 0, MAXN - 1, idx, 0); filled.PB(idx); }
void reset() { for (int idx : filled) sset(0, 0, MAXN - 1, idx, 1); filled.clear(); }

int solve() {
	vector<int> marked;
	for (int i = nmove - 1; i >= 0; --i) {
		int val = moveval[i], idx = moveidx[i];
		int mypos = getpos(idx);
		int nxtpos = getpos(idx + 1);
		//printf("\tmove %d to %d -> mypos=%d nxtpos=%d\n", val, idx, mypos, nxtpos);
		marked.PB(nxtpos);
		fill(mypos);
	}
	reset();
	sort(marked.begin(), marked.end());
	marked.erase(unique(marked.begin(), marked.end()), marked.end());
	//printf("marked:"); REPSZ(i, marked) printf(" %d", marked[i]); puts("");
	return choose(n + n - 1 - SZ(marked), n);
}

void run() {
	scanf("%d%d", &n, &nmove);
	REP(i, nmove) scanf("%d%d", &moveval[i], &moveidx[i]), --moveval[i], --moveidx[i];
	printf("%d\n", solve());
}

void precalc() {
	inv[1] = 1; FORE(i, 2, 2 * MAXN) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, 2 * MAXN) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, 2 * MAXN) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;
	sinit(0, 0, MAXN - 1);
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}