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

const int NBIT = 30;
const int ALLONE = -1;
const int ALLZERO = -2;
const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXS = 4 * MAXN;

struct Res {
	int state[NBIT], cnt;
};

Res make(int x) {
	Res ret;
	REP(bit, NBIT) ret.state[bit] = (x & (1 << bit)) == 0 ? ALLZERO : ALLONE;
	ret.cnt = 1;
	return ret;
}

void add(Res &res, int x) {
	for (int bit = NBIT - 1; bit >= 0; --bit) {
		bool me = (x & (1 << bit)) != 0;
		if (res.state[bit] == ALLONE) {
			if (!me) { 
				res.state[bit] = x; 
				return; 
			}
		} else if (res.state[bit] == ALLZERO) {
			if (me) {
				if (res.cnt >= 2) return;
				assert(res.cnt == 1);
				for (int i = bit - 1; i >= 0; --i) if (res.state[i] >= 0) return;
				int y = 0; REP(i, NBIT) if (res.state[i] != ALLZERO) y |= 1 << i;
				res.state[bit] = y;
				--bit;
				for (; bit >= 0; --bit) {
					me = (x & (1 << bit)) != 0;
					res.state[bit] = !me ? ALLZERO : ALLONE;
				}
				res.cnt = 1;
				return;
			}
		} else {
			if (!me) {
				int y = res.state[bit];
				for (; bit >= 0; --bit) {
					me = (x & (1 << bit)) != 0;
					bool he = (y & (1 << bit)) != 0;
					if (!me && !he) { res.state[bit] = ALLZERO; continue; }
					if (me && he) { res.state[bit] = ALLONE; continue; }
					if (he) swap(x, y), swap(me, he);
					res.state[bit] = y;
					--bit;
					for (; bit >= 0; --bit) {
						me = (x & (1 << bit)) != 0;
						res.state[bit] = !me ? ALLZERO : ALLONE;
					}
					res.cnt = 1;
					return;
				}
				res.cnt = 2;
				return;
			}
		}
	}
	res.cnt = min(res.cnt + 1, 2);
}

void print(const Res &a) {
	for (int bit = NBIT - 1; bit >= 0; --bit) {
		if (a.state[bit] == ALLZERO) printf("0");
		else if (a.state[bit] == ALLONE) printf("1");
		else printf("(%d)", a.state[bit]);
	}
	printf("[%d]", a.cnt);
}
Res merge(const Res &a, const Res &b) {
	Res c = a;
	REP(bit, NBIT) if (b.state[bit] >= 0) add(c, b.state[bit]);
	int x = 0;
	REP(bit, NBIT) if (b.state[bit] != ALLZERO) x |= 1 << bit;
	REP(i, b.cnt) add(c, x);
	//printf("merge "); print(a); printf(" with "); print(b); printf(" -> "); print(c); puts("");
	return c;
}

int calc(const Res &a) {
	vector<int> aa;
	REP(bit, NBIT) if (a.state[bit] >= 0) aa.PB(a.state[bit]);
	int x = 0;
	REP(bit, NBIT) if (a.state[bit] != ALLZERO) x |= 1 << bit;
	REP(i, a.cnt) aa.PB(x);
	int ret = INT_MAX;
	REPSZ(i, aa) FORSZ(j, i + 1, aa) ret = min(ret, aa[i] | aa[j]);
	return ret;
}

int n;
int a[MAXN];
int nq;
int ql[MAXQ], qr[MAXQ];
int qans[MAXQ];

Res sval[MAXS];

void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = make(a[l]);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		sval[x] = merge(sval[2 * x + 1], sval[2 * x + 2]);
	}
}
Res sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2;
		Res lres; bool havelres = false;
		if (L <= m) lres = sget(2 * x + 1, l, m, L, R), havelres = true;
		Res rres; bool haverres = false;
		if (m + 1 <= R) rres = sget(2 * x + 2, m + 1, r, L, R), haverres = true;
		if (havelres && haverres) return merge(lres, rres); else if (havelres) return lres; else if (haverres) return rres; else { assert(false); return Res(); }
	}
}

void solve() {
	sinit(0, 0, n - 1);
	REP(i, nq) {
		Res cur = sget(0, 0, n - 1, ql[i], qr[i]);
		qans[i] = calc(cur);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}