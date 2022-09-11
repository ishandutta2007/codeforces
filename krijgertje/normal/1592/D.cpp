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

const int MAXN = 1000;

int n;
vector<int> adj[MAXN];

int par[MAXN], dep[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

int query(const vector<pair<int, int>>& e) {
	if (SZ(e) == 0) return INT_MIN;
	vector<int> lst;
	REPSZ(i, e) lst.PB(e[i].first), lst.PB(e[i].second);
	sort(lst.begin(), lst.end());
	lst.erase(unique(lst.begin(), lst.end()), lst.end());
	printf("? %d", SZ(lst)); REPSZ(i, lst) printf(" %d", lst[i] + 1); puts(""); fflush(stdout);
	int ret; scanf("%d", &ret); return ret;
}

pair<int, int> solve() {
	par[0] = -1;
	dfsinit(0);
	vector<pair<int, int>> all;
	vector<vector<pair<int, int>>> e(3);

	REP(i, n) if (par[i] != -1) all.PB(MP(par[i], i)), e[dep[par[i]] % 3].PB(MP(par[i], i));
	vector<int> ord(3); REP(i, 3) ord[i] = i; sort(ord.begin(), ord.end(), [&](int a, int b) { return SZ(e[a]) > SZ(e[b]); });

	int mxval = query(all);
	vector<pair<int, int>> rem;
	for (int i : ord) {
		int cur = i == ord.back() ? mxval : query(e[i]);
		if (cur == mxval) { rem = e[i]; break; }
	}
	assert(SZ(rem) >= 1);
	while (SZ(rem) >= 2) {
		int cnt = SZ(rem) / 2;
		vector<pair<int, int>> cur(rem.begin(), rem.begin() + cnt);
		if (query(cur) == mxval) rem = cur; else rem = vector<pair<int, int>>(rem.begin() + cnt, rem.end());
	}
	assert(SZ(rem) == 1);
	return rem[0];
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	pair<int, int> ans = solve();
	printf("! %d %d\n", ans.first + 1, ans.second + 1); fflush(stdout);

}

int main() {
	run();
	return 0;
}