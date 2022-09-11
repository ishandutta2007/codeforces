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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXCAFE = 1024;

int ncafe, memsz;

bool local = false;
int alocal[MAXCAFE];

map<int, int> mplocal;
queue<int> qlocal;


bool visit(int idx) {
	if (!local) {
		printf("? %d\n", idx + 1); fflush(stdout);
		char c; scanf(" %c", &c); if (c == 'E') exit(0); return c == 'N';
	} else {
		int val = alocal[idx];
		bool ret = mplocal[val] == 0;
		++mplocal[val]; qlocal.push(val); if (SZ(qlocal) > memsz) { int remval = qlocal.front(); qlocal.pop(); --mplocal[remval]; }
		return ret;
	}
}
void reset() {
	if (!local) {
		printf("R\n"); fflush(stdout);
	} else {
		mplocal.clear();
		qlocal = queue<int>();
	}
}


bool alive[MAXCAFE];

int solve() {
	REP(i, ncafe) alive[i] = true;
	int nblock = ncafe / memsz;
	REP(i, nblock) {
		REP(j, memsz) {
			int x = memsz * i + j;
			if (!visit(x)) alive[x] = false;
		}
		reset();
	}
	REP(i, nblock) FOR(j, i + 1, nblock) {
		if (memsz == 1) {
			int x = memsz * i, y = memsz * j;
			if (alive[x]) {
				visit(x);
				if (!visit(y)) alive[y] = false;
			}
		} else {
			int halfsz = memsz / 2;
			int cnt1 = 0, lst1 = -1; REP(k, halfsz) { int x = memsz * i + k; if (alive[x]) ++cnt1, lst1 = x, visit(x); }
			if (cnt1 == 0) reset(); else REP(k, halfsz - cnt1) visit(lst1);
			int cnt2 = 0, lst2 = -1; REP(k, halfsz) { int y = memsz * j + k; if (alive[y]) { ++cnt2, lst2 = y; if (!visit(y)) alive[y] = false; } }
			if (cnt2 == 0) reset(); else REP(k, halfsz - cnt2) visit(lst2);
			int cnt3 = 0, lst3 = -1; REP(k, halfsz) { int x = memsz * i + halfsz + k; if (alive[x]) { ++cnt3, lst3 = x; if (!visit(x)) alive[x] = false; } }
			if (cnt3 == 0) reset(); else REP(k, halfsz - cnt3) visit(lst3);
			int cnt4 = 0, lst4 = -1; REP(k, halfsz) { int y = memsz * j + halfsz + k; if (alive[y]) { ++cnt4, lst4 = y; if (!visit(y)) alive[y] = false; } }
			if (cnt4 == 0) reset(); else REP(k, halfsz - cnt4) visit(lst4);
			int cnt5 = 0, lst5 = -1; REP(k, halfsz) { int x = memsz * i + k; if (alive[x]) { ++cnt5, lst5 = x; if (!visit(x)) alive[x] = false; } }
		}
		reset();
	}
	int ret = 0; REP(i, ncafe) if (alive[i]) ++ret; return ret;
}

void run() {
	scanf("%d%d", &ncafe, &memsz);
	int ans = solve();
	printf("! %d\n", ans); fflush(stdout);
}

void stress() {
	REP(rep, 1000) {
		local = true; reset();
		while (true) {
			int lgn = rand() % 11, lgk = rand() % (lgn + 1);
			ncafe = 1 << lgn, memsz = 1 << lgk;
			ll lim = (ll)3 * ncafe * ncafe / (2 * memsz); if (lim <= 15000) break;
		}
		int ndiff = rand() % ncafe + 1;
		REP(i, ndiff) alocal[i] = i; FOR(i, ndiff, ncafe) alocal[i] = rand() % ndiff;
		REP(i, ncafe) { int idx = rand() % (i + 1); swap(alocal[i], alocal[idx]); }
		int have = solve();
		int want = ndiff;
		if (have != want)printf("%d vs %d\n", have, want);
	}
}

int main() {
	run();
	//stress();
	return 0;
}