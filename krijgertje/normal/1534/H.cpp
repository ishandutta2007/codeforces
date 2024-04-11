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

const int MAXN = 100000;

int n;
vector<int> adj[MAXN];
int root;

int par[MAXN];
int dpdown[MAXN];
int dpup[MAXN];
int act[MAXN];

void dfsinit(int at) {
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

void dfsdown(int at) {
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		dfsdown(to);
	}
	vector<pair<int,int>> lst;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		lst.PB(MP(dpdown[to], to));
	}
	sort(lst.begin(), lst.end());
	reverse(lst.begin(), lst.end());
	dpdown[at] = 1;
	REPSZ(i, lst) dpdown[at] = max(dpdown[at], lst[i].first + i);
	act[at] = SZ(lst) == 0 ? at : act[lst[0].second];
}

void dfsup(int at) {
	vector<pair<int, int>> lst;
	if (par[at] != -1) lst.PB(MP(dpup[at], par[at]));
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		lst.PB(MP(dpdown[to], to));
	}
	sort(lst.begin(), lst.end());
	reverse(lst.begin(), lst.end());
	vector<int> pref(SZ(lst) + 1);
	pref[0] = 1;
	REPSZ(i, lst) pref[i + 1] = max(pref[i], lst[i].first + i);
	vector<int> suff(SZ(lst) + 1);
	suff[SZ(lst)] = 1;
	for (int i = SZ(lst) - 1; i >= 0; --i) suff[i] = max(suff[i + 1], lst[i].first + i - 1);
	REPSZ(i, lst) if (lst[i].second != par[at]) dpup[lst[i].second] = max(pref[i], suff[i + 1]);
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		dfsup(to);
	}
}


int calcneed() {
	par[0] = -1; dfsinit(0);
	dfsdown(0);
	dpup[0] = -1; dfsup(0);
	//REP(i, n) printf("%d: up=%d dn=%d\n", i + 1, dpup[i], dpdown[i]);
	int ret = 0;
	REP(root, n) {
		vector<int> lst;
		for (int to : adj[root]) {
			if (par[to] == root) lst.PB(dpdown[to]);
			else if (par[root] == to) lst.PB(dpup[root]);
			else assert(false);
		}
		sort(lst.begin(), lst.end());
		reverse(lst.begin(), lst.end());
		//printf("root%d:", root + 1); REPSZ(i, lst) printf(" %d", lst[i]); puts("");
		if (SZ(lst) >= 1) ret = max(ret, lst[0]);
		FORSZ(i, 1, lst) ret = max(ret, lst[0] + lst[i] + i - 1);
	}
	return ret;
}

int query(int x) {
	printf("? %d\n", x + 1); fflush(stdout);
	int ret; scanf("%d", &ret); --ret; return ret;
}

int solvesubtree(int at) {
	int qlast = act[at];
	int anslast = query(qlast);
	if (anslast == root) return -1;
	while (true) {
		at = anslast;
		vector<pair<int, int>> lst;
		for (int to : adj[at]) {
			if (to == par[at]) continue;
			lst.PB(MP(dpdown[to], to));
		}
		sort(lst.begin(), lst.end());
		reverse(lst.begin(), lst.end());
		if (SZ(lst) == 0) {
			assert(qlast == at);
			return at;
		}
		assert(qlast == act[lst[0].second]);
		bool found = false;
		FORSZ(i, 1, lst) {
			qlast = act[lst[i].second];
			anslast = query(qlast);
			if (anslast == at) continue;
			found = true;
			break;
		}
		if (!found) return at;
	}
}

pair<int, int> solve() {
	par[root] = -1; dfsinit(root);
	dfsdown(root);
	vector<pair<int,int>> lst;
	for (int to : adj[root]) lst.PB(MP(dpdown[to], to));
	sort(lst.begin(), lst.end());
	reverse(lst.begin(), lst.end());
	vector<int> endpoints;
	REPSZ(i, lst) if (SZ(endpoints) < 2) {
		int cur = solvesubtree(lst[i].second);
		if (cur != -1) endpoints.PB(cur);
	}
	while (SZ(endpoints) < 2) endpoints.PB(root);
	return MP(endpoints[0], endpoints[1]);
}


void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", calcneed()); fflush(stdout);
	scanf("%d", &root); --root;
	pair<int, int> ans = solve();
	printf("! %d %d\n", ans.first + 1, ans.second + 1); fflush(stdout);
}

int main() {
	run();
	return 0;
}