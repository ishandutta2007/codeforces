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

const int MAXN = 500000;

int n;

int match[2 * MAXN + 1];
int ans[2 * MAXN + 1];

void solvefirst() {
	FORE(i, 1, 2 * n) match[i] = -1;
	match[n - 1] = 2 * n - 1, match[2 * n - 1] = n - 1;
	match[n] = 2 * n, match[2 * n] = n;
	FORE(i, 1, 2 * n) if (match[i] == -1) { assert(i + 1 <= 2 * n && match[i + 1] == -1); match[i] = i + 1, match[i + 1] = i; }
	FORE(i, 1, 2 * n) ans[i] = -1;
	int nans = 0; FORE(i, 1, 2 * n) if (ans[i] == -1) { int j = match[i]; assert(ans[j] == -1); ans[i] = ans[j] = nans++; }
	FORE(i, 1, 2 * n) { if (i != 1) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

vector<int> adj[2 * MAXN + 1];
vector<vector<int>> pairs;
int col[2 * MAXN + 1];

void dfs(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (col[to] == -1) { col[to] = 1 - col[at]; dfs(to); } else assert(col[to] == 1 - col[at]);
	}
}

void solvesecond() {
	FORE(i, 1, 2 * n) adj[i].clear();
	FORE(i, 1, n) { int a = i, b = i + n; adj[a].PB(b); adj[b].PB(a); }
	pairs = vector<vector<int>>(n);
	FORE(i, 1, 2 * n) { int x; scanf("%d", &x); --x; pairs[x].PB(i); }
	REP(i, n) assert(SZ(pairs[i]) == 2);
	REP(i, n) { int a = pairs[i][0], b = pairs[i][1]; adj[a].PB(b); adj[b].PB(a); }
	FORE(i, 1, 2 * n) col[i] = -1;
	FORE(i, 1, 2 * n) assert(SZ(adj[i]) == 2);
	FORE(i, 1, 2 * n) if (col[i] == -1) { col[i] = 0; dfs(i); }
	int use = 0;
	ll sum = 0; FORE(i, 1, 2 * n) if (col[i] == use) sum += i;
	if (sum % (2 * n) != 0) use = 1;
	REP(i, n) { if (i != 0) printf(" "); int cnt = 0; REP(j, 2) { int x = pairs[i][j]; if (col[x] == use) printf("%d", x), ++cnt; } assert(cnt == 1); } puts("");
}

void solve() {
	if (n % 2 == 0) {
		printf("First\n"); fflush(stdout);
		solvefirst();
	} else {
		printf("Second\n"); fflush(stdout);
		solvesecond();
	}
}

void run() {
	scanf("%d", &n);
	solve();
}

bool calc(vector<pair<int, int>> pairs) {
	int npair = SZ(pairs);
	REP(mask, 1 << npair) {
		int have = 0; REP(i, npair) if (mask & (1 << i)) have += pairs[i].first; else have += pairs[i].second;
		if (have % (2 * npair) == 0) return false;
	}
	return true;
}
bool rec(vector<pair<int, int>> &pairs, int mask) {
	if (mask == 0) {
		return calc(pairs);
	} else {
		int x = 0; while ((mask & (1 << x)) == 0) ++x;
		for (int y = x + 1; (1 << y) <= mask; ++y) if (mask & (1 << y)) {
			pairs.PB(MP(x, y));
			bool res = rec(pairs, mask ^ (1 << x) ^ (1 << y));
			if (res) return true;
			pairs.pop_back();
		}
		return false;
	}
}

void research() {
	FORE(n, 1, 10) {
		if (n % 2 != 0) continue;
		vector<pair<int, int>> pairs;
		int mask = 0; FORE(i, 1, 2 * n) mask |= 1 << i;
		bool res = rec(pairs, mask);
		printf("%d: %s\n", n, res ? "First" : "Second");
		if (res) {
			printf("pairs:"); REPSZ(i, pairs) printf(" (%d,%d)", pairs[i].first, pairs[i].second); puts("");
		}
	}
}

int main() {
	//research();
	run();
	return 0;
}