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

int n;
int a[MAXN];
char allowed[3 + 1];
char op[MAXN - 1];

void calc(int l, int r) {
	while (l < r && a[l] == 1) op[l++] = '+';
	while (l < r && a[r] == 1) op[--r] = '+';
	if (l == r) return;
	//printf("calc(%d..%d)\n", l, r);

	int prod = 1;
	int sum = 0; FORE(i, l, r) sum += a[i];
	bool big = false;
	FORE(i, l, r) {
		if (prod * a[i] >= prod + sum + a[i]) { big = true; break; }
		prod *= a[i];
		sum += a[i];
	}
	if (big) { FOR(i, l, r) op[i] = '*'; return; }
	vector<int> pos;
	FORE(i, l, r) if (a[i] != 1) pos.PB(i);
	int ngap = SZ(pos) - 1;
	int bestmask = -1, bestval = -1;
	REP(mask, 1 << ngap) {
		int curval = 0;
		REP(i, ngap) if (mask & (1 << i)) curval += pos[i + 1] - pos[i] - 1;
		REPSZ(i, pos) if (i == 0 || (mask & (1 << (i - 1))) != 0) {
			int curprod = a[pos[i]];
			int j = i;
			while (j + 1 < SZ(pos) && (mask & (1 << j)) == 0) curprod *= a[pos[++j]];
			curval += curprod;
		}
		//printf("%x: %d\n", mask, curval);
		if (curval > bestval) bestval = curval, bestmask = mask;
	}
	FOR(j, l, r) op[j] = '*';
	REP(i, ngap) if (bestmask & (1 << i)) FOR(j, pos[i], pos[i + 1]) op[j] = '+';
}

void solve() {
	bool canadd = false, cansub = false, canmult = false;
	int nallowed = strlen(allowed); REP(i, nallowed) if (allowed[i] == '+') canadd = true; else if (allowed[i] == '-') cansub = true; else if (allowed[i] == '*') canmult = true;
	REP(i, n - 1) op[i] = '?';
	if (canadd && canmult) {
		REP(i, n) if (a[i] == 0) {
			if (i != 0) op[i - 1] = '+';
			if (i != n - 1) op[i] = '+';
		}
		REP(i, n) if (a[i] != 0 && (i == 0 || a[i - 1] == 0)) {
			int j = i;
			while (j + 1 < n && a[j + 1] != 0) ++j;
			calc(i, j);
		}
	} else if (canadd) {
		REP(i, n - 1) op[i] = '+';
	} else if (cansub && canmult) {
		int fstzero = 0; while (fstzero < n && a[fstzero] != 0) ++fstzero;
		REP(i, n - 1) op[i] = '*';
		if (fstzero < n && fstzero != 0) op[fstzero - 1] = '-';
	} else if (cansub) {
		REP(i, n - 1) op[i] = '-';
	} else if (canmult) {
		REP(i, n - 1) op[i] = '*';
	} else {
		assert(false);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%s", allowed);
	solve();
	REP(i, n) { if (i != 0) printf("%c", op[i - 1]); printf("%d", a[i]); } puts("");
}

int main() {
	run();
	return 0;
}