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

const int MAXOP = 200000;
const int MAXQ = 200000;
struct Res {
	int delta, lo, hi; 
	void update() { lo = min(lo, delta); hi = max(hi, delta); }
};

int nop, nq;
char op[MAXOP + 1];
int ql[MAXQ], qr[MAXQ], qans[MAXQ];

Res pref[MAXOP + 1];
Res suff[MAXOP + 1];

void solve() {
	pref[0].delta = pref[0].lo = pref[0].hi = 0;
	REP(i, nop) {
		pref[i + 1] = pref[i];
		if (op[i] == '+') ++pref[i + 1].delta; else --pref[i + 1].delta;
		pref[i + 1].update();
	}
	suff[nop].delta = suff[nop].lo = suff[nop].hi = 0;
	for (int i = nop - 1; i >= 0; --i) {
		suff[i] = suff[i + 1];
		if (op[i] == '-') ++suff[i].delta; else --suff[i].delta;
		suff[i].update();
	}
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		Res a = pref[l], b = suff[r + 1];
		int lo = min(a.lo, a.delta - b.delta + b.lo);
		int hi = max(a.hi, a.delta - b.delta + b.hi);
		//printf("a:(%d,%d,%d) b:(%d,%d,%d) -> %d..%d\n", a.delta, a.lo, a.hi, b.delta, b.lo, b.hi, lo, hi);
		qans[i] = hi - lo + 1;
	}
}

void run() {
	scanf("%d%d", &nop, &nq);
	scanf("%s", op); assert(strlen(op) == nop);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}