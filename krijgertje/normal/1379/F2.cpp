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

const int MAXH = 200000;
const int MAXW = 200000;
const int MAXQ = 200000;
const int MAXS = 4 * MAXW;

int h, w, nq;
int qx[MAXQ], qy[MAXQ]; bool qans[MAXQ];


set<int> abyy[MAXW];
set<int> bbyy[MAXW];
int aval[MAXW], bval[MAXW];

int sval[MAXS][2];
int ssum[MAXS];

void spull(int x) {
	REP(kind, 2) sval[x][kind] = max(sval[2 * x + 1][kind], sval[2 * x + 2][kind]);
	ssum[x] = max(max(ssum[2 * x + 1], ssum[2 * x + 2]), sval[2 * x + 1][1] + sval[2 * x + 2][0]);
}

void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x][0] = sval[x][1] = ssum[x] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}

void smod(int x, int l, int r, int IDX, int KIND, int VAL) {
	if (l == r) {
		sval[x][KIND] = VAL;
		ssum[x] = sval[x][0] + sval[x][1];
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(2 * x + 1, l, m, IDX, KIND, VAL); else smod(2 * x + 2, m + 1, r, IDX, KIND, VAL);
		spull(x);
	}
}


void update(int y) {
	int wantaval = SZ(abyy[y]) == 0 ? 0 : *abyy[y].rbegin() + 1;
	if (wantaval != aval[y]) {
		aval[y] = wantaval;
		//printf("setting %c%d to %d\n", 'A', y, aval[y]);
		smod(0, 0, w - 1, y, 0, aval[y]);
	}
	int wantbval = SZ(bbyy[y]) == 0 ? 0 : h - *bbyy[y].begin();
	if (wantbval != bval[y]) {
		bval[y] = wantbval;
		//printf("setting %c%d to %d\n", 'B', y, bval[y]);
		smod(0, 0, w - 1, y, 1, bval[y]);
	}
}


void solve() {
	REP(y, w) abyy[y].clear(), bbyy[y].clear(), aval[y] = 0, bval[y] = 0;
	REP(i, nq) {
		int x = qx[i], y = qy[i];
		assert(x % 2 == y % 2);
		int col = x % 2;
		x /= 2; y /= 2;
		if (col == 1) {
			if (!abyy[y].count(x)) {
				abyy[y].insert(x);
				update(y);
			} else {
				abyy[y].erase(x);
				update(y);
			}
		} else {
			if (!bbyy[y].count(x)) {
				bbyy[y].insert(x);
				update(y);
			} else {
				bbyy[y].erase(x);
				update(y);
			}
		}
		//printf("done %d\n", i);
		qans[i] = ssum[0] <= h;
	}
}

void run() {
	scanf("%d%d%d", &h, &w, &nq);
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}