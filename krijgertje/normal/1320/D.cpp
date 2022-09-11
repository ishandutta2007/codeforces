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
typedef long long ll; 
typedef unsigned long long ull;
typedef pair<int, int> myhash;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXS = 4 * MAXN;
const myhash zerohash = MP(0, 0);
struct SVal { 
	int len, totcntone;
	int cntblocks; // blocks of ones with odd length, not at the border of the interval
	myhash hashmidcountzero;
	int leftcountone, rightcountone;
	int leftcountzero, rightcountzero; // number of zeroes left of leftmost odd block, number of zeroes right of rightmost odd block
};

int n;
char s[MAXN + 1];
int nq;
int qa[MAXQ], qb[MAXQ], qlen[MAXQ]; bool qans[MAXQ];

const int MOD[2] = { 1000000007,999999937 };

myhash hashpw[MAXN + 1];

myhash operator+(const myhash& a, const myhash& b) {
	myhash ret;
	ret.first = a.first + b.first; if (ret.first >= MOD[0]) ret.first -= MOD[0];
	ret.second = a.second + b.second; if (ret.second >= MOD[1]) ret.second -= MOD[1];
	return ret;
}
myhash operator*(const myhash& a, const myhash& b) {
	myhash ret;
	ret.first = (ll)a.first * b.first % MOD[0];
	ret.second = (ll)a.second * b.second % MOD[1];
	return ret;
}
void prependhash(myhash& suffix, const myhash prefix, int prefixlen) {
	suffix = prefix + suffix * hashpw[prefixlen];
}
void prependhash(myhash& suffix, int val) {
	suffix = MP(val % MOD[0], val % MOD[1]) + suffix * hashpw[1];
}

SVal smake(char c) {
	SVal ret;
	ret.len = 1; ret.totcntone = c == '1' ? 1 : 0;
	ret.cntblocks = 0; ret.hashmidcountzero = zerohash;
	ret.leftcountone = ret.rightcountone = ret.totcntone;
	ret.leftcountzero = ret.rightcountzero = -1;
	return ret;
}

SVal smerge(const SVal& a, const SVal& b) {
	bool newblock = a.rightcountone != a.len && b.leftcountone != b.len && (a.rightcountone + b.leftcountone) % 2 == 1;
	SVal ret;
	ret.totcntone = a.totcntone + b.totcntone;
	ret.len = a.len + b.len;
	ret.cntblocks = a.cntblocks + (newblock ? 1 : 0) + b.cntblocks;
	ret.hashmidcountzero = zerohash;
	if (b.cntblocks >= 1) prependhash(ret.hashmidcountzero, b.hashmidcountzero, b.cntblocks - 1);
	if (newblock && b.cntblocks >= 1) prependhash(ret.hashmidcountzero, b.leftcountzero);
	if (newblock && a.cntblocks >= 1) prependhash(ret.hashmidcountzero, a.rightcountzero);
	if (!newblock && a.cntblocks >= 1 && b.cntblocks >= 1) prependhash(ret.hashmidcountzero, a.rightcountzero + b.leftcountzero);
	if (a.cntblocks >= 1) prependhash(ret.hashmidcountzero, a.hashmidcountzero, a.cntblocks - 1);
	ret.leftcountone = a.leftcountone + (a.leftcountone == a.len ? b.leftcountone : 0);
	ret.rightcountone = b.rightcountone + (b.rightcountone == b.len ? a.rightcountone : 0);
	ret.leftcountzero = a.cntblocks >= 1 ? a.leftcountzero : newblock ? a.len - a.totcntone : b.cntblocks >= 1 ? a.len - a.totcntone + b.leftcountzero : -1;
	ret.rightcountzero = b.cntblocks >= 1 ? b.rightcountzero : newblock ? b.len - b.totcntone : a.cntblocks >= 1 ? b.len - b.totcntone + a.rightcountzero : -1;
	return ret;
}



SVal sval[MAXS];
void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = smake(s[l]);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		sval[x] = smerge(sval[2 * x + 1], sval[2 * x + 2]);
	}
}
SVal sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) return sval[x];
	int m = l + (r - l) / 2;
	if (L > m) return sget(2 * x + 2, m + 1, r, L, R);
	if (m + 1 > R) return sget(2 * x + 1, l, m, L, R);
	return smerge(sget(2 * x + 1, l, m, L, R), sget(2 * x + 2, m + 1, r, L, R));
}


bool same(const SVal& a, const SVal& b) {
	assert(a.len == b.len);
	if (a.totcntone != b.totcntone) return false;
	if (a.cntblocks != b.cntblocks || a.hashmidcountzero != b.hashmidcountzero) return false;
	assert(a.leftcountone == 0 && a.rightcountone == 0 && b.leftcountone == 0 && b.rightcountone == 0);
	if (a.leftcountzero != b.leftcountzero || a.rightcountzero != b.rightcountzero) return false;
	return true;
}

std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	hashpw[0] = MP(1, 1);
	hashpw[1] = MP(1000000 + rnd() % 1000000, 1000000 + rnd() % 1000000);
	FORE(i, 2, n) hashpw[i] = hashpw[i - 1] * hashpw[1];

	sinit(0, 0, n - 1);
	SVal szero = smake('0');
	REP(i, nq) {
		int a = qa[i], b = qb[i], len = qlen[i];
		SVal va = sget(0, 0, n - 1, a, a + len - 1);
		SVal vb = sget(0, 0, n - 1, b, b + len - 1);
		va = smerge(szero, smerge(va, szero));
		vb = smerge(szero, smerge(vb, szero));
		qans[i] = same(va, vb);
	}
}

void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(strlen(s) == n);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d%d", &qa[i], &qb[i], &qlen[i]), --qa[i], --qb[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}