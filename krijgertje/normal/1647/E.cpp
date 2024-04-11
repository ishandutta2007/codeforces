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

const int MAXN = 100000;
const int MAXLG = 16;

int n;
int nxt[MAXN];
int want[MAXN];
int ans[MAXN];

bool isleaf[MAXN];
vector<vector<int>> cycs;
int cycid[MAXN];
int cycidx[MAXN];
int cycdist[MAXN];

int jump[MAXN][MAXLG + 1];
int dest[MAXN];
vector<int> who[MAXN];

bool used[MAXN + 1];

void solve() {
	REP(i, n) isleaf[i] = true;
	REP(i, n) isleaf[nxt[i]] = false;
	int nleaf = 0;
	REP(i, n) if (isleaf[i]) ++nleaf;
	assert(nleaf >= 1);
	int fstleaf = -1;
	REP(i, n) if (isleaf[i]) { fstleaf = i; break; }
	assert(fstleaf != -1);
	int nstep;
	if (want[fstleaf] <= n) {
		nstep = 0;
	} else {
		int waitnr = want[fstleaf] - n - 1;
		assert(waitnr % nleaf == 0);
		nstep = waitnr / nleaf + 1;
	}
	//printf("nstep=%d\n", nstep);

	cycs.clear();
	REP(i, n) cycid[i] = -1;
	REP(i, n) if (cycid[i] == -1) {
		int at = i;
		int dist = 0;
		while (cycid[at] == -1) {
			cycid[at] = -2;
			++dist;
			at = nxt[at];
		}
		if (cycid[at] == -2) {
			vector<int> cyc;
			while (cycid[at] == -2) {
				cycid[at] = SZ(cycs);
				cycidx[at] = SZ(cyc);
				cycdist[at] = 0;
				cyc.PB(at);
				at = nxt[at];
			}
			dist -= SZ(cyc);
			cycs.PB(cyc);
		}
		dist += cycdist[at];
		int to = at;
		at = i;
		while (cycid[at] == -2) {
			cycid[at] = cycid[to];
			cycidx[at] = cycidx[to];
			cycdist[at] = dist;
			--dist;
			at = nxt[at];
		}
	}
	//REPSZ(i, cycs) { printf("cyc%d:", i); REPSZ(j, cycs[i]) printf(" %d", cycs[i][j] + 1); puts(""); }
	//REP(i, n) printf("%d: id=%d idx=%d dist=%d\n", i + 1, cycid[i], cycidx[i], cycdist[i]);

	REP(i, n) jump[i][0] = nxt[i];
	REP(k, MAXLG) REP(i, n) jump[i][k + 1] = jump[jump[i][k]][k];
	REP(i, n) who[i].clear();
	REP(i, n) {
		if (nstep >= cycdist[i]) {
			int rem = nstep - cycdist[i];
			int idx = (cycidx[i] + rem) % SZ(cycs[cycid[i]]);
			int to = cycs[cycid[i]][idx];
			dest[i] = to;
			who[to].PB(i);
		} else {
			int to = i;
			for (int k = MAXLG; k >= 0; --k) if (nstep & (1 << k)) to = jump[to][k];
			dest[i] = to;
			who[to].PB(i);
		}
	}
	//REP(i, n) if (SZ(who[i]) != 0) { printf("who%d:", i + 1); for (int x : who[i]) printf(" %d", x + 1); puts(""); }
	REP(i, n) assert((SZ(who[i]) != 0) == (want[i] <= n));

	set<int> avail;
	FORE(i, 1, n) avail.insert(i);
	REP(i, n) if (want[i] <= n) { auto it = avail.find(want[i]); assert(it != avail.end()); avail.erase(it); }
	FOR(i, 1, n) used[i] = false;
	REP(i, n) {
		int to = dest[i];
		if (!used[want[to]]) {
			ans[i] = want[to];
			used[want[to]] = true;
		} else {
			auto it = avail.upper_bound(want[to]);
			assert(it != avail.end());
			ans[i] = *it;
			used[*it] = true;
			avail.erase(it);
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &nxt[i]), --nxt[i];
	REP(i, n) scanf("%d", &want[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}