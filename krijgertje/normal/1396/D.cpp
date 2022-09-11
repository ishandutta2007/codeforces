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

const int MAXP = 2000;
const int MAXCOL = 2000;
const int MOD = 1000000007;
struct P { int x, y, col; };
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int &a, int b) { inc(a, MOD - b); }

int np, ncol, sz;
P p[MAXP];

int xx[MAXP], nxx;
int yy[MAXP], nyy;

int lwx[MAXP], rwx[MAXP];
int uwy[MAXP], dwy[MAXP];
int sumlwx[MAXP + 1], sumrwx[MAXP + 1];

map<int, int> colx[MAXCOL];

map<int, int> func;
int funcval;

int calcseg(int lo, int hi, int v) {
	return (ll)sumlwx[v + 1] * (sumrwx[hi + 1] - sumrwx[lo]) % MOD;
}

void updatefunc(int upto, int lim) {
	auto it = func.upper_bound(upto);
	int from = INT_MAX;
	while (true) {
		auto nit = it; it = it == func.begin() ? func.end() : prev(it);
		int nxt = nit == func.end() ? nxx : nit->first;
		if (nit != func.end() && nit->first <= upto) func.erase(nit);
		if (it == func.end()) break;
		if (it->second < lim) break;
		from = it->first;
		dec(funcval, calcseg(it->first, nxt - 1, it->second));
		if (upto + 1 <= nxt - 1) {
			func[upto + 1] = it->second;
			inc(funcval, calcseg(upto + 1, nxt - 1, it->second));
		}
	}
	if (from <= upto) {
		func[from] = lim;
		inc(funcval, calcseg(from, upto, lim));
	}
}

int solve() {
	nxx = 0; REP(i, np) xx[nxx++] = p[i].x; sort(xx, xx + nxx); nxx = unique(xx, xx + nxx) - xx; REP(i, np) p[i].x = lower_bound(xx, xx + nxx, p[i].x) - xx;
	nyy = 0; REP(i, np) yy[nyy++] = p[i].y; sort(yy, yy + nyy); nyy = unique(yy, yy + nyy) - yy; REP(i, np) p[i].y = lower_bound(yy, yy + nyy, p[i].y) - yy;
	REP(i, nxx) lwx[i] = i == 0 ? xx[i] + 1 : xx[i] - xx[i - 1];
	REP(i, nxx) rwx[i] = i == nxx - 1 ? sz - xx[i] : xx[i + 1] - xx[i];
	REP(i, nyy) dwy[i] = i == 0 ? yy[i] + 1 : yy[i] - yy[i - 1];
	REP(i, nyy) uwy[i] = i == nyy - 1 ? sz - yy[i] : yy[i + 1] - yy[i];
	sumlwx[0] = 0; REP(i, nxx) sumlwx[i + 1] = sumlwx[i] + lwx[i];
	sumrwx[0] = 0; REP(i, nxx) sumrwx[i + 1] = sumrwx[i] + rwx[i];

	//printf("xx:"); REP(i, nxx) printf(" %d", xx[i]); printf(" (%d)\n", sz);
	//printf("yy:"); REP(i, nyy) printf(" %d", yy[i]); printf(" (%d)\n", sz);
	//printf("p:"); REP(i, np) printf(" (%d,%d,%d)", p[i].x, p[i].y, p[i].col); puts("");

	int ret = 0;
	REP(top, nyy) {
		vector<int> xord; REP(i, np) if (p[i].y <= top) xord.PB(i); sort(xord.begin(), xord.end(), [&](const int &a, const int &b) { return p[a].x < p[b].x; });
		vector<int> colcnt(ncol, 0); int havecol = 0; int l = 0, r = 0;
		func.clear(); func[0] = -1;
		while (true) {
			while (r < SZ(xord) && (havecol < ncol || p[xord[r]].x == p[xord[r - 1]].x)) {
				int idx = xord[r++];
				if (colcnt[p[idx].col]++ == 0) ++havecol;
			}
			int rx = p[xord[r - 1]].x;
			if (havecol < ncol) break;
			while (true) {
				int idx = xord[l];
				if (colcnt[p[idx].col] == 1) break;
				--colcnt[p[idx].col]; ++l;
			}
			int lx = p[xord[l]].x;
			func[rx] = lx;
			while (l < r&&p[xord[l]].x == lx) {
				int idx = xord[l++];
				if (--colcnt[p[idx].col] == 0) --havecol;
			}
		}
		funcval = 0; for (auto it = func.begin(); it != func.end(); ++it) { auto nit = next(it); inc(funcval, calcseg(it->first, nit == func.end() ? nxx - 1 : nit->first - 1, it->second)); }
		
		//printf("top=%d\n", top);
		//printf("\tinitfunc:"); for (auto it = func.begin(); it != func.end(); ++it) printf(" %d=%d", it->first, it->second); printf(" -> %d\n", funcval);

		REP(i, ncol) colx[i].clear();
		REP(i, np) if (p[i].y <= top) ++colx[p[i].col][p[i].x];
		vector<int> remord; REP(i, np) if (p[i].y <= top) remord.PB(i); sort(remord.begin(), remord.end(), [&](const int &a, const int &b) { return p[a].y < p[b].y; });
		int atrem = 0;
		REPE(bot, top) {
			ret = (ret + (ll)funcval*dwy[bot] % MOD*uwy[top]) % MOD;
			while (atrem < SZ(remord) && p[remord[atrem]].y == bot) {
				int idx = remord[atrem++];
				map<int, int> &mp = colx[p[idx].col];
				auto it = mp.find(p[idx].x);
				assert(it != mp.end());
				if (it->second >= 2) {
					--it->second;
				} else {
					assert(it->second == 1);
					auto nit = next(it);
					int lim = it == mp.begin() ? -1 : prev(it)->first;
					int upto = nit == mp.end() ? nxx - 1 : nit->first - 1;
					updatefunc(upto, lim);
					mp.erase(it);
				}
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &np, &ncol, &sz);
	REP(i, np) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].col), --p[i].col;
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}