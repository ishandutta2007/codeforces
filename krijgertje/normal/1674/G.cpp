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
const int MAXM = 200000;

int n, m;
int e[MAXM][2];

vector<int> out[MAXN];
vector<int> in[MAXN];
bool killed[MAXM];
bool todoout[MAXN];
bool todoin[MAXN];

int topidx[MAXN], top[MAXN], ntop;
int dp[MAXN];

void dfstop(int at) {
	for (int id : out[at]) {
		int to = e[id][1];
		if (topidx[to] == -1) dfstop(to);
	}
	topidx[at] = ntop, top[ntop] = at, ++ntop;
}

int solve() {
	REP(i, n) out[i].clear();
	REP(i, n) in[i].clear();
	REP(i, m) { int a = e[i][0], b = e[i][1]; out[a].PB(i); in[b].PB(i); }
	REP(i, m) killed[i] = false;
	REP(i, n) todoout[i] = SZ(out[i]) >= 1, todoin[i] = SZ(in[i]) >= 1;
	REP(i, n) if (SZ(out[i]) == 1) {
		int id = out[i][0];
		int a = e[id][0], b = e[id][1];
		killed[id] = true, todoout[a] = todoin[b] = false;
	}
	REP(i, n) if (SZ(in[i]) == 1) {
		int id = in[i][0];
		int a = e[id][0], b = e[id][1];
		killed[id] = true, todoout[a] = todoin[b] = false;
	}
	ntop = 0;
	REP(i, n) topidx[i] = -1;
	REP(i, n) if (topidx[i] == -1) dfstop(i);
	REP(i, n) dp[i] = -1;
	REP(i, n) {
		int at = top[i];
		assert(dp[at] == -1);
		dp[at] = 1;
		for (int id : out[at]) {
			int to = e[id][1];
			assert(dp[to] != -1);
			if (killed[id]) continue;
			dp[at] = max(dp[at], dp[to] + 1);
		}
	}
	int ret = 0;
	REP(i, n) ret = max(ret, dp[i]);
	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}