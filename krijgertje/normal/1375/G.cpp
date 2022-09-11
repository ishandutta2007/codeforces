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

int n;
vector<int> adj[MAXN];

int par[MAXN];

void dfsinit(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
	}
}

pair<int, int> dfscalc(int at) { // white,black
	pair<int,int> ret = MP(0, 1);
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		pair<int, int> sub = dfscalc(to);
		ret.first += sub.second;
		ret.second += sub.first;// min(sub.first, sub.second);
	}
	return ret;
}

int solve() {
	par[0] = -1; dfsinit(0);
	pair<int, int> res = dfscalc(0);
	int ret = min(res.first, res.second) - 1;
	return max(ret, 0);
}

bool isstar(const vector<vector<int>>& adj,int lim) {
	REP(i, n) if (SZ(adj[i]) == n - 1) { return true; }
	return false;
}

int calcstupid(const vector<vector<int>>& adj,int lim) {
	if (isstar(adj,lim)) return 0;
	if (lim == 0) return lim + 1;
	int ret = lim + 1;
	//if (lim >= 3) printf("lim=%d\n", lim);
	REP(b, n) REPSZ(aa, adj[b]) REPSZ(cc, adj[b]) if (cc != aa) {
		int a = adj[b][aa], c = adj[b][cc];
		vector<vector<int>> nadj(n);
		REP(at, n) REPSZ(i, adj[at]) {
			int to = adj[at][i]; if (at > to) continue;
			if (at != a && to != a) { nadj[at].PB(to); nadj[to].PB(at); continue; }
			if (at == a) { nadj[to].PB(c); nadj[c].PB(to); }
			if (to == a) { nadj[at].PB(c); nadj[c].PB(at); }
		}
		ret = min(ret, 1 + calcstupid(nadj, lim - 1));
		if (ret == lim) { 
			//printf("%d-%d-%d\n", a + 1, b + 1, c + 1);
			return ret;
		}
	}
	return ret;
}

int solvestupid() {
	vector<vector<int>> adj(n); REP(i, n) adj[i] = ::adj[i];
	//return calcstupid(adj, (n + 1) / 2);
	for (int lim = 0;; ++lim)
		if (calcstupid(adj, lim) == lim)
			return lim;
	return -1;
}

void stress() {
	REP(rep, 1000) {
		n = rnd() % 12 + 1;
		REP(i, n) adj[i].clear();
		FOR(i, 1, n) { int j = rnd() % i; adj[i].PB(j); adj[j].PB(i); }
		int have = solve();
		int want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("%d %d\n", have, want);
		printf("%d\n", n); REP(i, n) REPSZ(j, adj[i]) { int k = adj[i][j]; if (i < k) printf("%d %d\n", i + 1, k + 1); }
		break;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	//printf("want=%d\n", solvestupid());
}


int main() {
	run();
	//stress();
	return 0;
}