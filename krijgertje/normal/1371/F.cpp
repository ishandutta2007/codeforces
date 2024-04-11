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

const int MAXN = 500000;
const int MAXQ = 100000;
const int MAXS = 4 * MAXN;
struct Val { int sz, prefl, prefr, suffl, suffr, preflr, prefrl, sufflr, suffrl, insidelr, insiderl; };

int n, nq;
char s[MAXN + 1];
int ql[MAXQ], qr[MAXQ], qans[MAXQ];

Val smake(char c) {
	Val ret; ret.sz = 1, ret.preflr = ret.prefrl = ret.sufflr = ret.suffrl = ret.insidelr = ret.insiderl = 1;
	if (c == '<') ret.prefl = 1, ret.prefr = 0, ret.suffl = 1, ret.suffr = 0; else if (c == '>') ret.prefl = 0, ret.prefr = 1, ret.suffl = 0, ret.suffr = 1; else assert(false);
	return ret;
}
Val smerge(const Val& a, const Val& b) {
	Val ret; ret.sz = a.sz + b.sz;
	ret.prefl = a.prefl + (a.prefl == a.sz ? b.prefl : 0);
	ret.prefr = a.prefr + (a.prefr == a.sz ? b.prefr : 0);
	ret.suffl = b.suffl + (b.suffl == b.sz ? a.suffl : 0);
	ret.suffr = b.suffr + (b.suffr == b.sz ? a.suffr : 0);
	ret.preflr = a.preflr + (a.preflr == a.sz ? a.prefl == a.sz ? b.preflr : b.prefr : 0);
	ret.prefrl = a.prefrl + (a.prefrl == a.sz ? a.prefr == a.sz ? b.prefrl : b.prefl : 0);
	ret.sufflr = b.sufflr + (b.sufflr == b.sz ? b.suffr == b.sz ? a.sufflr : a.suffl : 0);
	ret.suffrl = b.suffrl + (b.suffrl == b.sz ? b.suffl == b.sz ? a.suffrl : a.suffr : 0);
	ret.insidelr = max(max(a.insidelr, b.insidelr), max(a.sufflr + b.prefr, a.suffl + b.preflr));
	ret.insiderl = max(max(a.insiderl, b.insiderl), max(a.suffrl + b.prefl, a.suffr + b.prefrl));
	return ret;
}
void sinvert(Val &a) {
	swap(a.prefl, a.prefr); swap(a.suffl, a.suffr); swap(a.preflr, a.prefrl); swap(a.sufflr, a.suffrl); swap(a.insidelr, a.insiderl);
}

bool slazy[MAXS];
Val sval[MAXS];

void sapply(int x) { sinvert(sval[x]); slazy[x] = !slazy[x]; }
void spush(int x) { if (slazy[x]) sapply(2 * x + 1), sapply(2 * x + 2), slazy[x] = false; }
void spull(int x) { sval[x] = smerge(sval[2 * x + 1], sval[2 * x + 2]); }
void sinit(int x, int l, int r) {
	slazy[x] = false;
	if (l == r) {
		sval[x] = smake(s[l]);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void stoggle(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		sapply(x);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) stoggle(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) stoggle(2 * x + 2, m + 1, r, L, R);
		spull(x);
	}
}
Val sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L > m) return sget(2 * x + 2, m + 1, r, L, R);
		if (m + 1 > R) return sget(2 * x + 1, l, m, L, R);
		return smerge(sget(2 * x + 1, l, m, L, R), sget(2 * x + 2, m + 1, r, L, R));
	}
}

void solve() {
	sinit(0, 0, n - 1);
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		stoggle(0, 0, n - 1, l, r);
		Val val = sget(0, 0, n - 1, l, r);
		qans[i] = val.insiderl;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	scanf("%s", s); assert(strlen(s) == n);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}