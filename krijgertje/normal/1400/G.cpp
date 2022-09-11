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

const int MAXN = 300000;
const int MAXM = 20;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, m;
int mnsize[MAXN], mxsize[MAXN];
int e[MAXM][2];

vector<int> bymn[MAXN + 1];
vector<int> bymx[MAXN + 1];
bool active[MAXN]; int cntactive;
bool hasedge[MAXN];

ll mark[MAXN], curmark;
int ways[2 * MAXM + 1];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	REPE(i, n) bymn[i].clear(), bymx[i].clear();
	REP(i, n) bymn[mnsize[i]].PB(i), bymx[mxsize[i]].PB(i);
	cntactive = 0; REP(i, n) active[i] = false;
	REP(i, n) hasedge[i] = false;
	REP(i, m) REP(j, 2) hasedge[e[i][j]] = true;
	curmark = -1; REP(i, n) mark[i] = -1;
	int ret = 0;
	REP(i, 2 * m) ways[i] = 0;
	ways[0] = 1;
	FORE(sz, 1, n) {
		bool update = false;
		REPSZ(i, bymx[sz - 1]) { int id = bymx[sz - 1][i]; active[id] = false; --cntactive; if (hasedge[id]) update = true; }
		REPSZ(i, bymn[sz]) { int id = bymn[sz][i]; active[id] = true; ++cntactive; if (hasedge[id]) update = true; }
		//printf("sz=%d cntactive=%d\n", sz, cntactive);
		if (update) {
			vector<int> lst;
			REP(i, m) if (active[e[i][0]] && active[e[i][1]]) lst.PB(i);
			REPE(i, 2 * m) ways[i] = 0;
			REP(mask, 1 << SZ(lst)) {
				int cntedge = 0, cntnode = 0; ++curmark; REPSZ(i, lst) if (mask & (1 << i)) { ++cntedge; int id = lst[i]; REP(j, 2) { int x = e[id][j]; if (mark[x] != curmark) mark[x] = curmark, ++cntnode; } }
				ways[cntnode] += cntedge % 2 == 0 ? 1 : -1;
			}
			//printf("updated:"); REPE(i, 2 * m) if (ways[i] != 0) printf(" %d:%d", i, ways[i]); puts("");
		}
		int cur = 0;
		REPE(i, 2 * m) if (ways[i] != 0) {
			int mlt = ways[i]; if (mlt < 0) mlt += MOD;
			assert(i <= cntactive);
			cur = (cur + (ll)mlt * choose(cntactive - i, sz - i)) % MOD;
		}
		//printf("->%d\n", cur);
		inc(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, n) scanf("%d%d", &mnsize[i], &mxsize[i]);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}