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

const int MAXSTAT = 100000;
const int MAXTRAIN = 100000;
const int MAXS = 4 * MAXSTAT;
struct Z { ll l, r; Z() {} Z(ll l, ll r) :l(l), r(r) {} };
bool operator<(const Z& a, const Z& b) { return a.l < b.l; }

int nstat, ntrain;
vector<int> ch[MAXSTAT];
int par[MAXSTAT], parlen[MAXSTAT];
int initswitch[MAXSTAT];
int tdest[MAXTRAIN], tstart[MAXTRAIN];
ll breakat; int nswitch;

int dep[MAXSTAT], sz[MAXSTAT], heavy[MAXSTAT]; ll dist[MAXSTAT];
int hroot[MAXSTAT], hidx[MAXSTAT], hwho[MAXSTAT], nh;

int curswitch[MAXSTAT];

vector<Z> z;

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1; sz[at] = 1; heavy[at] = -1; dist[at] = par[at] == -1 ? 0 : dist[par[at]] + parlen[at];
	REPSZ(i, ch[at]) {
		int to = ch[at][i];
		dfsinit(to);
		sz[at] += sz[to];
		if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
	}
}

int sfstmarked[MAXS];
int sval[MAXS];

void sapply(int x, int val) {
	sval[x] = val;
}
void spush(int x) {
	if (sval[x] != INT_MIN) sapply(2 * x + 1, sval[x]), sapply(2 * x + 2, sval[x]), sval[x] = INT_MIN;
}
void spull(int x) {
	sfstmarked[x] = sfstmarked[2 * x + 1];
	if (sfstmarked[x] == -1) sfstmarked[x] = sfstmarked[2 * x + 2];
}
void sinit(int x, int l, int r) {
	sval[x] = INT_MIN;
	if (l == r) {
		int at = hwho[l];
		sfstmarked[x] = par[at] != -1 && curswitch[par[at]] != at ? l : -1;
		//if (sfstmarked[x] != -1) printf("marked: %d at %d\n", at + 1, l);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
int sgetmarked(int x, int l, int r, int L, int R) {
	//if (x == 0) printf("\tgetting marked in %d..%d\n", L, R);
	if (L <= l && r <= R) {
		return sfstmarked[x];
	} else {
		int m = l + (r - l) / 2; spush(x); int ret = -1;
		if (ret == -1 && L <= m) ret = sgetmarked(2 * x + 1, l, m, L, R);
		if (ret == -1 && m + 1 <= R) ret = sgetmarked(2 * x + 2, m + 1, r, L, R);
		spull(x);
		return ret;
	}
}
void smark(int x, int l, int r, int IDX) {
	//if (x == 0) printf("\tmarking %d\n", IDX);
	if (l == r) {
		sfstmarked[x] = l;
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) smark(2 * x + 1, l, m, IDX); else smark(2 * x + 2, m + 1, r, IDX);
		spull(x);
	}
}
void sunmark(int x, int l, int r, int IDX) {
	//if (x == 0) printf("\tunmarking %d\n", IDX);
	if (l == r) {
		sfstmarked[x] = -1;
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) sunmark(2 * x + 1, l, m, IDX); else sunmark(2 * x + 2, m + 1, r, IDX);
		spull(x);
	}
}
void sset(int x, int l, int r, int L, int R, int VAL) {
	if (L <= l && r <= R) {
		sapply(x, VAL);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) sset(2 * x + 1, l, m, L, R, VAL);
		if (m + 1 <= R) sset(2 * x + 2, m + 1, r, L, R, VAL);
		spull(x);
	}
}
int sget(int x, int l, int r, int IDX) {
	if (l == r) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; spush(x); int ret;
		if (IDX <= m) ret = sget(2 * x + 1, l, m, IDX); else ret = sget(2 * x + 2, m + 1, r, IDX);
		spull(x);
		return ret;
	}
}

void solve() {
	dfsinit(0);
	nh = 0; REP(i, nstat) if (par[i] == -1 || heavy[par[i]] != i) for (int at = i; at != -1; at = heavy[at]) hroot[at] = i, hidx[at] = nh, hwho[nh] = at, ++nh; assert(nh == nstat);
	//REP(i, nstat) printf("%d: hidx=%d\n", i + 1, hidx[i]);

	z.clear();
	REP(i, nstat) curswitch[i] = initswitch[i];
	sinit(0, 0, nh - 1);
	REP(i, ntrain) {
		//printf("processing train%d\n", i);
		int at = tdest[i];
		while (at != -1) {
			int l = hidx[hroot[at]], r = hidx[at];
			while (true) {
				int curidx = sgetmarked(0, 0, nh - 1, l, r);
				if (curidx == -1) break;
				int cur = hwho[curidx];
				int tlastatroot = sget(0, 0, nh - 1, hidx[par[cur]]);
				ll tfrom = tlastatroot == INT_MIN ? 1 : tlastatroot + 1 + dist[par[cur]], tto = tstart[i] + dist[par[cur]]; assert(tfrom <= tto);
				//printf("train%d: cur=%d (idx=%d) tlastatroot=%d -> %lld..%lld\n", i, cur + 1, curidx, tlastatroot, tfrom, tto);
				z.PB(Z(tfrom, tto));
				assert(par[cur] != -1 && curswitch[par[cur]] != cur);
				smark(0, 0, nh - 1, hidx[curswitch[par[cur]]]);
				curswitch[par[cur]] = cur;
				sunmark(0, 0, nh - 1, hidx[cur]);
			}
			int rr = at == tdest[i] ? r - 1 : r;
			if (l <= rr) sset(0, 0, nh - 1, l, rr, tstart[i]);
			at = par[hroot[at]];
		}
	}
	//REPSZ(i, z) printf("[%lld..%lld]\n", z[i].l, z[i].r);

	sort(z.begin(), z.end());
	breakat = LLONG_MAX;
	{
		int zpos = 0; ll t = 1; priority_queue<ll> pq;
		while (true) {
			if (pq.empty()) { if (zpos >= SZ(z)) break; t = z[zpos].l; }
			while (zpos < SZ(z) && t >= z[zpos].l) pq.push(-z[zpos++].r);
			while (!pq.empty()) {
				ll lim = -pq.top(); pq.pop();
				if (lim < t) { breakat = min(breakat, lim); continue; } else break;
			}
			++t;
		}
	}
	nswitch = 0;
	REPSZ(i, z) if (z[i].r < breakat) ++nswitch;
	if (breakat == LLONG_MAX) breakat = -1;
}

void run() {
	scanf("%d%d", &nstat, &ntrain);
	REP(i, nstat) par[i] = -1, parlen[i] = 0, ch[i].clear(), initswitch[i] = -1;
	REP(i, nstat - 1) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; ch[a].PB(b); par[b] = a; parlen[b] = c; initswitch[a] = b; }
	REP(i, ntrain) scanf("%d%d", &tdest[i], &tstart[i]), --tdest[i];
	solve();
	printf("%lld %d\n", breakat, nswitch);
}

int main() {
	run();
	return 0;
}