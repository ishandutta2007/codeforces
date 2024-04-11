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

const int MAXN = 200000;
const int MAXZONE = 26;
const int MAXQ = 200000;

int n;
vector<pair<int, int>> adj[MAXN];
int nzone;
char zonestr[MAXN + 1];
int zone[MAXN];
int scost[MAXZONE];
int sfine[MAXZONE];
int period;
int nq;
int qkind[MAXQ], qzone[MAXQ], qval[MAXQ], qnode[MAXQ];
ll qans[MAXQ];

int par[MAXN], parlen[MAXN]; ll dep[MAXN];

int zoneroot[MAXN];
ll fixedscan[MAXN];
pair<int, int> extrascan[MAXN];

int mp[1 << MAXZONE];
vector<int> opt[MAXN];
ll subtree[MAXN];

int ccost[MAXZONE];
int cfine[MAXZONE];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + parlen[at];
	for (auto e : adj[at]) {
		int to = e.first, len = e.second;
		if (to == par[at]) continue;
		par[to] = at;
		parlen[to] = len;
		dfsinit(to);
	}
}
void dfsscan(int at) {
	zoneroot[at] = par[at] == -1 || zone[par[at]] != zone[at] ? at : zoneroot[par[at]];
	ll l = par[zoneroot[at]] == -1 ? 1 : dep[par[zoneroot[at]]] + 1, r = dep[at];
	fixedscan[at] = (r - l + 1) / period;
	extrascan[at] = (r - l + 1) % period == 0 ? MP(-1, -1) : MP((int)(l % period), (int)(r % period));

	for (auto e : adj[at]) {
		int to = e.first, len = e.second;
		if (to == par[at]) continue;
		dfsscan(to);
	}
}
void dfszone(int at) {
	int mask = 0;
	auto inrange = [&](int v, pair<int, int> range) { if (range == MP(-1, -1)) return false; if (range.first <= range.second) return range.first <= v && v <= range.second; else return v >= range.first || v <= range.second; };
	for (int x = par[zoneroot[at]]; x != -1; x = par[zoneroot[x]]) if (inrange((int)(dep[at] % period), extrascan[x])) mask |= 1 << zone[x];
	if (mp[mask] == -1) {
		mp[mask] = SZ(opt[zoneroot[at]]);
		opt[zoneroot[at]].PB(mask);
		assert(SZ(opt[zoneroot[at]]) <= 2 * nzone);
	}
	subtree[at] = 1LL << mp[mask];
	for (auto e : adj[at]) {
		int to = e.first, len = e.second;
		if (to == par[at]) continue;
		if (zone[to] != zone[at]) continue;
		dfszone(to);
		subtree[at] |= subtree[to];
	}
}

void solve() {
	par[0] = -1, parlen[0] = 0;
	dfsinit(0);

	dfsscan(0);

	REP(mask, 1 << nzone) mp[mask] = -1;
	REP(i, n) if (i == zoneroot[i]) {
		opt[i].clear();
		dfszone(i);
		for (int mask : opt[i]) mp[mask] = -1;
	}

	REP(i, nzone) ccost[i] = scost[i], cfine[i] = sfine[i];
	REP(i, nq) {
		if (qkind[i] == 1) ccost[qzone[i]] = qval[i];
		if (qkind[i] == 2) cfine[qzone[i]] = qval[i];
		if (qkind[i] == 3) {
			int at = qnode[i];
			int root = zoneroot[at];
			//printf("at=%d root=%d:", at + 1, root + 1); for (int x = par[zoneroot[at]]; x != -1; x = par[zoneroot[x]]) printf(" %c=%lld+[%d..%d]", 'A' + zone[x], fixedscan[x], extrascan[x].first, extrascan[x].second); puts("");
			qans[i] = LLONG_MAX;
			REPSZ(j, opt[root]) {
				if ((subtree[at] & (1LL << j)) == 0) continue;
				int mask = opt[root][j];
				ll cur = 0;
				for (int x = par[zoneroot[at]]; x != -1; x = par[zoneroot[x]]) {
					ll cnt = fixedscan[x] + ((mask & (1 << zone[x])) != 0 ? 1 : 0);
					ll totfine = cnt == 0 ? 0 : cfine[zone[x]] > LLONG_MAX / cnt ? LLONG_MAX : cnt * cfine[zone[x]];
					cur += min((ll)ccost[zone[x]], totfine);
				}
				qans[i] = min(qans[i], cur);
			}
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	scanf("%d", &nzone);
	scanf("%s", zonestr); REP(i, n) zone[i] = zonestr[i] - 'A';
	REP(i, nzone) scanf("%d", &scost[i]);
	REP(i, nzone) scanf("%d", &sfine[i]);
	scanf("%d", &period);
	scanf("%d", &nq);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1 || qkind[i] == 2) { char c; scanf(" %c%d", &c, &qval[i]); qzone[i] = c - 'A'; }
		if (qkind[i] == 3) scanf("%d", &qnode[i]), --qnode[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 3) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}