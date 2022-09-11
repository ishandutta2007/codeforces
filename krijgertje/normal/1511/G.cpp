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

const int MAXROW = 200000;
const int MAXCOL = 200000;
const int MAXQ = 200000;

int nrow, ncol;
int chip[MAXROW];
int nq;
int ql[MAXQ], qr[MAXQ];
bool qwin[MAXQ];

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	void mod(int idx) { ++idx; while (idx <= n) { val[idx] ^= 1; idx += idx & -idx; } }
	int get(int idx) { ++idx; int ret = 0; while (idx > 0) { ret ^= val[idx]; idx -= idx & -idx; } return ret; }
	int getrange(int lidx, int ridx) { return get(ridx) ^ get(lidx - 1); }
};

BIT bit;

void solve() {
	vector<pair<int, int>> e;
	REP(i, nrow) e.PB(MP(chip[i], i));
	REP(i, nq) e.PB(MP(qr[i], nrow + 2 * i + 0));
	REP(i, nq) e.PB(MP(ql[i] - 1, nrow + 2 * i + 1));
	sort(e.begin(), e.end());

	for (int k = 0; (1 << k) <= ncol; ++k) {
		int period = 2 << k;
		bit.init(period);
		vector<int> sum(nq, 0);
		REPSZ(i, e) {
			if (e[i].second < nrow) {
				int id = e[i].second;
				bit.mod(chip[id] % period);
			} else {
				int id = (e[i].second - nrow) >> 1, by = (e[i].second - nrow) & 1 ? -1 : +1;
				int lo = (ql[id] + (1 << k)) % period;
				int hi = lo + (1 << k) - 1;
				int cur = hi < period ? bit.getrange(lo, hi) : bit.getrange(lo, period - 1) ^ bit.getrange(0, hi - period);
				sum[id] ^= cur;
			}
		}
		REP(id, nq) if (sum[id] != 0) qwin[id] = true;
	}
}

void run() {
	scanf("%d%d", &nrow, &ncol);
	REP(i, nrow) scanf("%d", &chip[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]);
	solve();
	REP(i, nq) printf("%c", qwin[i] ? 'A' : 'B'); puts("");
}

int main() {
	run();
	return 0;
}