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

const int MAXN = 500;

int n, sz;
int ans;

int dp[MAXN + 1];
int act[MAXN + 1];

int query(vector<int> lst) {
	printf("?"); REPSZ(i, lst) printf(" %d", lst[i] + 1); puts(""); fflush(stdout);
	int ret; scanf("%d", &ret); return ret;
}

bool solve() {
	REPE(i, n) dp[i] = INT_MAX, act[i] = -2;
	queue<int> q;
	auto relax = [&](int to, int cost, int by) { if (cost >= dp[to]) return; dp[to] = cost, act[to] = by; q.push(to); };
	relax(0, 0,-1);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		//printf("%d = %d\n", at, dp[at]);
		int lo = max(0, sz - n + at), hi = min(sz, at);
		FORE(ones, lo, hi) { // number of ones used
			int to = at - ones + sz - ones;
			assert(to >= 0 && to <= n);
			relax(to, dp[at] + 1, at);
		}
	}
	if (dp[n] == INT_MAX) return false;

	vector<int> seq;
	{
		int at = n;
		while (true) {
			seq.PB(at);
			if (act[at] < 0) break;
			at = act[at];
		}
		reverse(seq.begin(), seq.end());
	}
	//printf("seq:"); REPSZ(i, seq) printf(" %d", seq[i]); puts("");

	ans = 0;
	set<int> curzero;
	set<int> curone;
	REP(i, n) curzero.insert(i);
	FORSZ(i, 1, seq) {
		int to = seq[i], at = seq[i - 1];
		int x = at - to + sz;
		assert(x % 2 == 0);
		int ones = x / 2;
		int zeroes = sz - ones;
		assert(ones >= 0 && ones <= SZ(curone));
		assert(zeroes >= 0 && zeroes <= SZ(curzero));
		vector<int> myzero;
		vector<int> myone;
		REP(j, zeroes) { auto it = curzero.begin(); myzero.PB(*it); curzero.erase(it); }
		REP(j, ones) { auto it = curone.begin(); myone.PB(*it); curone.erase(it); }
		vector<int> mine;
		for (int x : myzero) curone.insert(x), mine.PB(x);
		for (int x : myone) curzero.insert(x), mine.PB(x);
		sort(mine.begin(), mine.end());
		mine.erase(unique(mine.begin(), mine.end()), mine.end());
		assert(SZ(mine) == sz);
		ans ^= query(mine);
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &sz);
	if (!solve()) { printf("-1\n"); fflush(stdout); return; }
	printf("! %d\n", ans); fflush(stdout);
}

int main() {
	run();
	return 0;
}