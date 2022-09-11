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
const int MOD = 998244353;
const int MAXFLIP = 20;

int n, m;
vector<int> out[MAXN];
vector<int> revout[MAXN];

int mnflip[MAXN];
int d[MAXN][MAXFLIP + 1];

void calcmnflip() {
	REP(i, n) mnflip[i] = INT_MAX;
	deque<int> q;
	mnflip[0] = 0;
	q.push_back(0);
	while (!q.empty()) {
		int at = q.front(); q.pop_front();
		REPSZ(i, out[at]) {
			int to = out[at][i];
			int ncost = mnflip[at] + (mnflip[at] % 2 == 0 ? 0 : 1);
			if (ncost < mnflip[to]) mnflip[to] = ncost, ncost == mnflip[at] ? q.push_front(to) : q.push_back(to);
		}
		REPSZ(i, revout[at]) {
			int to = revout[at][i];
			int ncost = mnflip[at] + (mnflip[at] % 2 == 0 ? 1 : 0);
			if (ncost < mnflip[to]) mnflip[to] = ncost, ncost == mnflip[at] ? q.push_front(to) : q.push_back(to);
		}
	}
	//printf("mnflip:"); REP(i, n) printf(" %d", mnflip[i]); puts("");
}
void calcd() {
	REP(i, n) REPE(j, MAXFLIP) d[i][j] = INT_MAX;
	queue<pair<int, int>> q;
	d[0][0] = 0;
	q.push(MP(0, 0));
	while (!q.empty()) {
		int at = q.front().first, flips = q.front().second; q.pop();
		//printf("d[%d][%d]=%d\n", at, flips, d[at][flips]);
		int realflips = flips < MAXFLIP - 1 ? flips : flips % 2 == mnflip[at] % 2 ? mnflip[at] : mnflip[at] + 1;
		assert(realflips >= mnflip[at]);
		assert(flips % 2 == realflips % 2);
		REPSZ(i, out[at]) {
			int to = out[at][i];
			int nrealflips = realflips + (realflips % 2 != 0 ? 1 : 0);
			int ncost = d[at][flips] + 1;
			if (nrealflips >= MAXFLIP - 1 && nrealflips >= mnflip[to] + 2) continue;
			assert(nrealflips >= mnflip[to]);
			int nflips = nrealflips < MAXFLIP - 1 ? nrealflips : nrealflips % 2 == MAXFLIP % 2 ? MAXFLIP : MAXFLIP - 1;
			assert(nflips % 2 == nrealflips % 2);
			if (ncost < d[to][nflips]) d[to][nflips] = ncost, q.push(MP(to, nflips));
		}
		REPSZ(i, revout[at]) {
			int to = revout[at][i];
			int nrealflips = realflips + (realflips % 2 != 1 ? 1 : 0);
			int ncost = d[at][flips] + 1;
			if (nrealflips >= MAXFLIP - 1 && nrealflips >= mnflip[to] + 2) continue;
			assert(nrealflips >= mnflip[to]);
			int nflips = nrealflips < MAXFLIP - 1 ? nrealflips : nrealflips % 2 == MAXFLIP % 2 ? MAXFLIP : MAXFLIP - 1;
			assert(nflips % 2 == nrealflips % 2);
			if (ncost < d[to][nflips]) d[to][nflips] = ncost, q.push(MP(to, nflips));
		}
	}
}

int solve() {
	calcmnflip();
	calcd();
	if (mnflip[n - 1] < MAXFLIP-1) {
		int ret = INT_MAX;
		REP(i, MAXFLIP - 1) {
			int cur = d[n - 1][i];
			if (cur == INT_MAX) continue;
			cur += (1 << i) - 1;
			//printf("%d: %d\n", i, cur);
			ret = min(ret, cur);
		}
		return ret;
	} else {
		int ret = d[n - 1][MAXFLIP - (MAXFLIP % 2 == mnflip[n - 1] % 2 ? 0 : 1)];
		//printf("ret=%d+2^0+2^1+...+2^%d\n", ret, mnflip[n - 1] - 1 );
		int p2 = 1; REP(i, mnflip[n - 1]) p2 = (ll)p2 * 2 % MOD;
		ret = (ret + p2 - 1) % MOD;
		return ret;
	}
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; out[a].PB(b); revout[b].PB(a); }
	printf("%d\n", solve());
}

void path() {
	n = 50, m = n - 1;
	REP(i, m) { int a = i, b = i + 1; if (i % 2 == 0) swap(a, b); out[a].PB(b); revout[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	//path();
	run();
	return 0;
}