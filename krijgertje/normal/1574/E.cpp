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

const int MAXQ = 300000;
const int MAXDIM = 1000000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int h, w, nq;
int qx[MAXQ], qy[MAXQ], qval[MAXQ];
int qans[MAXQ];

int rowcnt[MAXDIM][2];
int colcnt[MAXDIM][2];
int checkercnt[2];
int impossiblerowcnt;
int impossiblecolcnt;
int freerowcnt;
int freecolcnt;
map<pair<int, int>, int> have;

int p2[MAXDIM + 1];

void solve() {
	REP(x, h) REP(z, 2) rowcnt[x][z] = 0;
	REP(y, w) REP(z, 2) colcnt[y][z] = 0;
	REP(z, 2) checkercnt[z] = 0;
	impossiblerowcnt = 0;
	impossiblecolcnt = 0;
	freerowcnt = h;
	freecolcnt = w;
	have.clear();
	p2[0] = 1; FORE(i, 1, max(h, w)) p2[i] = (ll)p2[i - 1] * 2 % MOD;
	REP(i, nq) {
		int x = qx[i], y = qy[i], nval = qval[i];
		pair<int, int> key = MP(x, y);
		auto it = have.find(key);
		if (it != have.end()) {
			int oval = it->second;

			if (rowcnt[x][0] >= 1 || rowcnt[x][1] >= 1) ++freerowcnt;
			if (rowcnt[x][0] >= 1 && rowcnt[x][1] >= 1) --impossiblerowcnt;
			--rowcnt[x][(y % 2) ^ oval];
			if (rowcnt[x][0] >= 1 && rowcnt[x][1] >= 1) ++impossiblerowcnt;
			if (rowcnt[x][0] >= 1 || rowcnt[x][1] >= 1) --freerowcnt;

			if (colcnt[y][0] >= 1 || colcnt[y][1] >= 1) ++freecolcnt;
			if (colcnt[y][0] >= 1 && colcnt[y][1] >= 1) --impossiblecolcnt;
			--colcnt[y][(x % 2) ^ oval];
			if (colcnt[y][0] >= 1 && colcnt[y][1] >= 1) ++impossiblecolcnt;
			if (colcnt[y][0] >= 1 || colcnt[y][1] >= 1) --freecolcnt;

			--checkercnt[(x % 2) ^ (y % 2) ^ oval];

			have.erase(it);
		}
		if (nval != -1) {
			if (rowcnt[x][0] >= 1 || rowcnt[x][1] >= 1) ++freerowcnt;
			if (rowcnt[x][0] >= 1 && rowcnt[x][1] >= 1) --impossiblerowcnt;
			++rowcnt[x][(y % 2) ^ nval];
			if (rowcnt[x][0] >= 1 && rowcnt[x][1] >= 1) ++impossiblerowcnt;
			if (rowcnt[x][0] >= 1 || rowcnt[x][1] >= 1) --freerowcnt;

			if (colcnt[y][0] >= 1 || colcnt[y][1] >= 1) ++freecolcnt;
			if (colcnt[y][0] >= 1 && colcnt[y][1] >= 1) --impossiblecolcnt;
			++colcnt[y][(x % 2) ^ nval];
			if (colcnt[y][0] >= 1 && colcnt[y][1] >= 1) ++impossiblecolcnt;
			if (colcnt[y][0] >= 1 || colcnt[y][1] >= 1) --freecolcnt;

			++checkercnt[(x % 2) ^ (y % 2) ^ nval];

			have[key] = nval;
		}

		int cur = 0;
		if (impossiblerowcnt == 0) inc(cur, p2[freerowcnt]);
		if (impossiblecolcnt == 0) inc(cur, p2[freecolcnt]);
		REP(z, 2) if (checkercnt[z] == 0) dec(cur, 1);
		qans[i] = cur;
	}
}

void run() {
	scanf("%d%d%d", &h, &w, &nq);
	REP(i, nq) scanf("%d%d%d", &qx[i], &qy[i], &qval[i]), --qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}