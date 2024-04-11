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

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	void mod(int idx, int by) { ++idx; while (idx <= n) { val[idx] += by; idx += idx & -idx; } }
	int get(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += val[idx]; idx -= idx & -idx; } return ret; }
	int get(int lidx, int ridx) { return get(ridx) - get(lidx - 1); }
};

const int MAXN = 300000;
const int MAXLG = 18;
const int MAXPATH = 300000;
struct Res { int id, x, y; Res() {} Res(int id, int x, int y) :id(id), x(x), y(y) {} };

int n, npath;
vector<int> adj[MAXN];
int path[MAXPATH][2];

int par[MAXN], dep[MAXN], up[MAXN][MAXLG + 1];
int lid[MAXN], rid[MAXN], nid;
vector<Res> who[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	lid[at] = nid++;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
	rid[at] = nid - 1;
}
int calclca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}
int calcup(int a, int steps) {
	REPE(k, MAXLG) if (steps & (1 << k)) a = up[a][k];
	return a;
}

int cnt[MAXN];
BIT bit;

ll dfscalc(int at) {
	ll ret = 0;
	int tot = bit.get(lid[at], rid[at]);
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		cnt[to] = bit.get(lid[to], rid[to]);
	}
	for (const Res& res : who[at]) {
		ll cur = tot;
		if (res.x != -1) cur -= cnt[res.x];
		if (res.y != -1) cur -= cnt[res.y];
		//printf("(%d,%d) -> %lld [%d,%d] <%d,%d>\n", path[res.id][0] + 1, path[res.id][1] + 1, cur, res.x + 1, res.y + 1, res.x != -1 ? cnt[res.x] : 0, res.y != -1 ? cnt[res.y] : 0);
		ret += cur;
	}
	for (const Res& res : who[at]) REP(j, 2) bit.mod(lid[path[res.id][j]], +1);
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		ret += dfscalc(to);
	}
	for (const Res& res : who[at]) REP(j, 2) bit.mod(lid[path[res.id][j]], -1);
	return ret;
}


ll calcpairs(int n) { return (ll)n * (n - 1) / 2; }

ll solve() {
	int root = 0; nid = 0;
	par[root] = -1;
	dfsinit(root);
	REP(i, npath) {
		int a = path[i][0], b = path[i][1], c = calclca(a, b);
		int x = a == c ? -1 : calcup(a, dep[a] - dep[c] - 1);
		int y = b == c ? -1 : calcup(b, dep[b] - dep[c] - 1);
		//printf("%d-%d -> %d\n", a + 1, b + 1, c + 1);
		who[c].PB(Res(i, min(x, y), max(x, y)));
	}

	ll ret = 0;

	// type 1
	REP(at, n) {
		for (int to : adj[at]) cnt[to] = 0;
		map<pair<int, int>, int> mp;
		//printf("%d:", at + 1); for (pair<int, int> p : who[at]) printf(" (%d,%d)", p.first + 1, p.second + 1); puts("");
		for (const Res &res : who[at]) {
			if (res.x != -1) ++cnt[res.x];
			if (res.y != -1) ++cnt[res.y];
			if (res.x != -1 && res.y != -1) mp[MP(res.x, res.y)]++;
		}
		ret += calcpairs(SZ(who[at]));
		for (int to : adj[at]) ret -= calcpairs(cnt[to]);
		for (auto kvp : mp) ret += calcpairs(kvp.second);
	}

	// type 2
	bit.init(nid);
	ret += dfscalc(root);

	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d", &npath);
	REP(i, npath) REP(j, 2) scanf("%d", &path[i][j]), --path[i][j];
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}