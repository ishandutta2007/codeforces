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

const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXLG = 17;

int n, nq;
int perm[MAXN];
int acost[MAXN];
int bcost[MAXN];
int q[MAXQ]; ll qans[MAXQ];

int par[MAXN];
vector<int> ch[MAXN];
int dep[MAXN], sz[MAXN], heavy[MAXN], hroot[MAXN];
vector<int> hlst[MAXN];
//int up[MAXN][MAXLG + 1];

bool mustvisit[MAXN];
int markcnt[MAXN];
multiset<int> markedset[MAXN]; // for each heavy path, the depth of the marked nodes

ll dpmarked[MAXN];
ll dpunmarked[MAXN];
ll pathdelta[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	sz[at] = 1;
	heavy[at] = -1;
	//up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	for (int to : ch[at]) {
		dfsinit(to);
		sz[at] += sz[to];
		if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
	}
}

int updpath(int at, int by) {
	int ret = -1;
	while (at != -1) {
		int root = hroot[at];
		if (by == -1) markedset[root].erase(markedset[root].find(dep[at]-dep[root]));
		if (ret == -1 && !markedset[root].empty()) ret = hlst[root][min(*markedset[root].rbegin(), dep[at] - dep[root])];
		if (by == +1) markedset[root].insert(dep[at]-dep[root]);
		at = par[root];
	}
	return ret;
}

ll calc(int z, int y) {
	//printf("calc(%d,%d)\n", z, y);
	ll ret = pathdelta[y];
	if (z != -1) ret -= pathdelta[z];
	return ret;
}


int stck[MAXN], nstck;

void solve() {
	nstck = 0;
	REP(i, n) {
		while (nstck > 0 && perm[i] > perm[stck[nstck - 1]]) --nstck;
		par[i] = nstck == 0 ? -1 : stck[nstck - 1];
		stck[nstck++] = i;
	}

	REP(i, n) ch[i].clear(), hlst[i].clear();
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	REP(i, n) if (par[i] == -1) dfsinit(i);
	REP(i, n) if (par[i] == -1 || i != heavy[par[i]]) for (int x = i; x != -1; x = heavy[x]) hroot[x] = i, hlst[i].PB(x);
	
	for (int i = n - 1; i >= 0; --i) {
		ll atot = acost[i]; for (int j : ch[i]) atot += dpunmarked[j];
		ll btot = bcost[i];
		dpmarked[i] = atot;
		dpunmarked[i] = min(atot, btot);
	}
	REP(i, n) pathdelta[i] = (par[i] == -1 ? 0 : pathdelta[par[i]]) + (dpmarked[i] - dpunmarked[i]);

	ll startcost = 0;
	REP(i, n) if (par[i] == -1) startcost += dpunmarked[i];
	REP(i, n) mustvisit[i] = false;
	REP(i, n) markcnt[i] = 0;
	REP(i, n) markedset[i].clear();

	ll curcost = startcost;
	REP(i, nq) {
		int x = q[i];
		if (!mustvisit[x]) {
			mustvisit[x] = true;
			int y = par[x];
			if (y != -1) {
				int z = updpath(y, +1);
				//printf("x=%d y=%d z=%d\n", x + 1, y + 1, z + 1);
				if (z == -1 || dep[z] < dep[y]) curcost += calc(z, y);
			}
		} else {
			mustvisit[x] = false;
			int y = par[x];
			if (y != -1) {
				int z = updpath(y, -1);
				if (z == -1 || dep[z] < dep[y]) curcost -= calc(z, y);
			}
		}
		qans[i] = curcost;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &perm[i]);
	REP(i, n) scanf("%d", &acost[i]);
	REP(i, n) scanf("%d", &bcost[i]);
	REP(i, nq) scanf("%d", &q[i]), --q[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

ll qansstupid[MAXQ];

void solvestupid() {
	REP(i, n) mustvisit[i] = false;
	REP(i, nq) {
		int x = q[i];
		mustvisit[x] = !mustvisit[x];
		vector<ll> dp(n + 1, LLONG_MAX);
		dp[0] = 0;
		REP(j, n) {
			dp[j + 1] = min(dp[j + 1], dp[j] + acost[j]);
			int k = j + 1; bool ok = true; while (k < n && perm[k] < perm[j]) { if (mustvisit[k]) { ok = false; break; } ++k; }
			if (ok) dp[k] = min(dp[k], dp[j] + bcost[j]);
		}
		qansstupid[i] = dp[n];
	}
}

void stress() {
	int mxn = 10, mxq = 10;
	REP(i, 10000) {
		n = rnd() % mxn + 1, nq = rnd() % mxq + 1;
		REP(i, n) { perm[i] = i; int idx = rnd() % (i + 1); swap(perm[i], perm[idx]); }
		REP(i, n) acost[i] = rnd() % 10 + 1;
		REP(i, n) bcost[i] = rnd() % 10 + 1;
		REP(i, nq) q[i] = rnd() % n;
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("%d %d\n", n, nq);
		REP(i, n) { if (i != 0) printf(" "); printf("%d", perm[i] + 1); } puts("");
		REP(i, n) { if (i != 0) printf(" "); printf("%d", acost[i]); } puts("");
		REP(i, n) { if (i != 0) printf(" "); printf("%d", bcost[i]); } puts("");
		REP(i, nq) { if (i != 0) printf(" "); printf("%d", q[i] + 1); } puts("");
		printf("have:"); REP(i, nq) printf(" %lld", qans[i]); puts("");
		printf("want:"); REP(i, nq) printf(" %lld", qansstupid[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}