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

int n;
int e[MAXN - 1][2];
int ans[MAXN - 1];

vector<vector<pair<int,int>>> adj;

bool solve() {
	adj = vector<vector<pair<int, int>>>(n);
	REP(i, n - 1) { int a = e[i][0], b = e[i][1]; adj[a].PB(MP(b, i)); adj[b].PB(MP(a, i)); }
	vector<int> one;
	REP(i, n) if (SZ(adj[i]) == 1) one.PB(i);
	if (SZ(one) != 2) return false;
	int at = one[0];
	int prv = -1;
	int len = 0;
	while (true) {
		pair<int, int> e = MP(-1, -1);
		for (auto ee : adj[at]) if (ee.first != prv) { assert(e == MP(-1, -1)); e = ee; }
		if (e == MP(-1, -1)) break;
		ans[e.second] = len % 2 == 0 ? 2 : 3;
		prv = at, at = e.first, ++len;
	}
	assert(len == n - 1);
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n - 1) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}