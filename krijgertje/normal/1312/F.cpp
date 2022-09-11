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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 300000;
const int MAXATTACK = 5;
struct Single {
	int preperiod, period;
	vector<int> gx, gy, gz;
	ll calcx(ll i) { if (i < preperiod) return gx[i]; i -= preperiod; i %= period; return gx[preperiod + i]; }
	ll calcy(ll i) { if (i < preperiod) return gy[i]; i -= preperiod; i %= period; return gy[preperiod + i]; }
	ll calcz(ll i) { if (i < preperiod) return gz[i]; i -= preperiod; i %= period; return gz[preperiod + i]; }
	void print() { printf("preperiod=%d period=%d\n", preperiod, period); printf("gx:"); REPSZ(i, gx) printf(" %d", gx[i]); puts(""); printf("gy:"); REPSZ(i, gy) printf(" %d", gy[i]); puts(""); printf("gz:"); REPSZ(i, gz) printf(" %d", gz[i]); puts(""); }
};


Single singles[MAXATTACK + 1][MAXATTACK + 1][MAXATTACK + 1];

int mex(int mask) { int ret = 0; while (mask & (1 << ret)) ++ret; return ret; }
void precalc() {
	FORE(x, 1, MAXATTACK) FORE(y, 1, MAXATTACK) FORE(z, 1, MAXATTACK) {
		vector<int> gx, gy, gz; gx.PB(0); gy.PB(0); gz.PB(0);
		map<vector<int>, int> seen;
		int len = max(x, max(y, z));
		int preperiod = -1, period = -1;
		for (int i = 1;; ++i) {
			//if (preperiod != -1 && i == preperiod + 10 * period) break;
			if (i >= len && preperiod == -1) {
				vector<int> cur; REP(j, len) cur.PB(gx[i - len + j]), cur.PB(gy[i - len + j]), cur.PB(gz[i - len + j]);
				if (seen.count(cur)) { preperiod = seen[cur]; period = i - preperiod; break; } else seen[cur] = i;
			}
			{ int mask = 0; mask |= 1 << gx[max(0, i - x)]; mask |= 1 << gy[max(0, i - y)]; mask |= 1 << gz[max(0, i - z)]; gx.PB(mex(mask)); }
			{ int mask = 0; mask |= 1 << gx[max(0, i - x)]; mask |= 1 << gz[max(0, i - z)]; gy.PB(mex(mask)); }
			{ int mask = 0; mask |= 1 << gx[max(0, i - x)]; mask |= 1 << gy[max(0, i - y)]; gz.PB(mex(mask)); }
		}
		//printf("%d %d %d: preperiod=%d period=%d\n", x, y, z, preperiod, period);
		singles[x][y][z].preperiod = preperiod, singles[x][y][z].period = period, singles[x][y][z].gx = gx, singles[x][y][z].gy = gy, singles[x][y][z].gz = gz;
		//singles[x][y][z].print();
		//REPSZ(i, gx) assert(singles[x][y][z].calcx(i) == gx[i]);
		//REPSZ(i, gy) assert(singles[x][y][z].calcy(i) == gy[i]);
		//REPSZ(i, gz) assert(singles[x][y][z].calcz(i) == gz[i]);
	}
}

int n, x, y, z;
ll a[MAXN];

int solve() {
	int sval = 0; REP(i, n) sval ^= singles[x][y][z].calcx(a[i]);
	int ret = 0;
	REP(i, n) {
		int xval = sval ^ singles[x][y][z].calcx(a[i]) ^ singles[x][y][z].calcx(max(0LL, a[i] - x)); if (xval == 0) ++ret;
		int yval = sval ^ singles[x][y][z].calcx(a[i]) ^ singles[x][y][z].calcy(max(0LL, a[i] - y)); if (yval == 0) ++ret;
		int zval = sval ^ singles[x][y][z].calcx(a[i]) ^ singles[x][y][z].calcz(max(0LL, a[i] - z)); if (zval == 0) ++ret;
		//printf("\t%d %d %d\n", xval, yval, zval);
	}
	//printf("x=%d y=%d z=%d sval=%d\n", x, y, z, sval);
	//printf("a:"); REP(i, n) printf(" %lld", a[i]); puts("");
	//singles[x][y][z].print();
	return ret;
}

void run() {
	scanf("%d%d%d%d", &n, &x, &y, &z);
	REP(i, n) scanf("%lld", &a[i]);
	printf("%d\n", solve());
}


int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}