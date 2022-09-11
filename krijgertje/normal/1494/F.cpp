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

const int MAXN = 3000;

int n, m;
vector<int> adj[MAXN];
vector<int> ans;

int deg[MAXN];

int id[MAXN], mnid[MAXN], nid;
map<pair<int, int>, int> comp; int ncomp;
vector<pair<int, int>> stck;

void tarjan(int at,int par,int dep=0) {
	//REP(i, dep) printf("  "); printf("tarjan(%d,%d)\n", at + 1, par + 1);
	id[at] = mnid[at] = nid++;
	for (int to : adj[at]) {
		if (to == par || comp.count(MP(at, to))) continue;
		stck.PB(MP(at, to));
		if (id[to] == -1) {
			tarjan(to, at, dep + 1);
			mnid[at] = min(mnid[at], mnid[to]);
			//printf("%d->%d: id[at]=%d mnid[to]=%d\n", at + 1, to + 1, id[at], mnid[to]);
			if (mnid[to] >= id[at]) {
				while (!comp.count(MP(at, to))) {
					int x = stck.back().first, y = stck.back().second; stck.pop_back();
					//printf("\tassigning(%d,%d)\n", x + 1, y + 1);
					comp[MP(x, y)] = comp[MP(y, x)] = ncomp;
				}
				++ncomp;
			}
		} else {
			mnid[at] = min(mnid[at], id[to]);
		}
	}
}

void removeedge(int a, int b) {
	REPSZ(i, adj[a]) if (adj[a][i] == b) { adj[a].erase(adj[a].begin() + i); --deg[a]; break; }
	REPSZ(i, adj[b]) if (adj[b][i] == a) { adj[b].erase(adj[b].begin() + i); --deg[b]; break; }
}

int pos[MAXN];
bool done[MAXN][MAXN];

void dfseuler(int at) {
	while (pos[at] < SZ(adj[at])) {
		int to = adj[at][pos[at]];
		if (done[at][to]) { ++pos[at]; continue; }
		done[at][to] = done[to][at] = true;
		dfseuler(to);
	}
	ans.PB(at);
}

void findeuler(int s, int t) {
	//printf("findeuler(%d,%d)\n", s + 1, t + 1);
	ans.clear();
	REP(i, n) pos[i] = 0;
	REP(i, n) REP(j, n) done[i][j] = false;
	dfseuler(s);
	reverse(ans.begin(), ans.end());
	//printf("ans:"); REPSZ(i, ans) printf(" %d", ans[i] + 1); puts("");
	assert(SZ(ans) >= 1 && ans[0] == s && ans[SZ(ans) - 1] == t);
	REP(at, n) for (int to : adj[at]) assert(done[at][to]);
}

bool solve() {
	nid = 0; ncomp = 0;
	REP(i, n) id[i] = -1;
	tarjan(0, -1);
	while (!stck.empty()) { int x = stck.back().first, y = stck.back().second; stck.pop_back(); comp[MP(x, y)] = comp[MP(y, x)] = ncomp; } ++ncomp;
	//for (auto kvp : comp) printf("(%d,%d)=%d\n", kvp.first.first + 1, kvp.first.second + 1, kvp.second);

	REP(i, n) deg[i] = SZ(adj[i]);
	vector<int> odd;
	REP(i, n) if (deg[i] % 2 == 1) odd.PB(i);
	if (SZ(odd) == 0) {
		findeuler(0, 0);
		return true;
	}
	if (SZ(odd) == 2) {
		findeuler(odd[0], odd[1]);
		return true;
	}
	REP(at, n) {
		int rem = SZ(odd);
		if (deg[at] % 2 == 1) --rem;
		vector<int> single;
		map<int, vector<int>> incomp;
		set<int> compok;
		for (int to : adj[at]) {
			if (deg[to] % 2 != 1) { compok.insert(comp[MP(at, to)]); continue; }
			if (deg[to] == 1) single.PB(to);
			else incomp[comp[MP(at, to)]].PB(to);
		}
		vector<int> star = single;
		for (auto kvp : incomp) { 
			if (!compok.count(kvp.first)) kvp.second.pop_back();
			for (int x : kvp.second) star.PB(x);
		}
		rem -= SZ(star);
		if (rem >= 2) continue;
		//printf("star:"); for (int x : star) printf(" %d", x + 1); puts("");
		for (int to : star) removeedge(at, to);
		odd.clear();
		REP(i, n) if (deg[i] % 2 == 1) odd.PB(i);
		assert(SZ(odd) == 0 || SZ(odd) == 2 && (odd[0] == at || odd[1] == at));
		if (SZ(odd) == 0) findeuler(at, at); else findeuler(odd[0] + odd[1] - at, at);
		ans.PB(-1);
		for (int to : star) ans.PB(to), ans.PB(at);
		return true;
	}
	return false;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	if (!solve()) { printf("0\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] == -1 ? -1 : ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}