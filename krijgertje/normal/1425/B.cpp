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

const int MAXN = 2000;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, m;
vector<int> adj[MAXN];

vector<int> cyc;
vector<int> todo[MAXN];

int solve() {
	assert(SZ(adj[0]) % 2 == 0); FOR(i, 1, n) assert(SZ(adj[i]) == 2);
	REP(i, n) todo[i] = adj[i];
	cyc.clear();
	while (SZ(todo[0]) > 0) {
		int prv = 0, at = todo[0].back(); todo[0].pop_back(); int len = 1;
		while (true) {
			auto it = find(todo[at].begin(), todo[at].end(), prv);
			assert(it != todo[at].end());
			todo[at].erase(it);
			if (at == 0) break;
			int to = todo[at].back(); todo[at].pop_back(); ++len;
			prv = at, at = to;
		}
		cyc.PB(len);
	}
	REP(i, n) assert(SZ(todo[i]) == 0);
	int sum = 0; REPSZ(i, cyc) sum += cyc[i]; assert(sum == m);
	//printf("cyc:"); REPSZ(i, cyc) printf(" %d", cyc[i]); puts("");
	vector<vector<int>> dp(4, vector<int>(2 * sum + 1, 0)); // 0=noskip, 1=skip, 2=meet middle, 3=meet end
	inc(dp[0][sum + 0], 1);
	REPSZ(i, cyc) {
		int len = cyc[i];
		vector<vector<int>> ndp(4, vector<int>(2 * sum + 1, 0));
		REP(state, 4) FORE(bal, -sum, +sum) {
			int ways = dp[state][sum + bal]; if (ways == 0) continue;
			inc(ndp[state][sum + bal + len], ways);
			inc(ndp[state][sum + bal - len], ways);
			if (state != 3) inc(ndp[state == 0 ? 1 : state][sum + bal], ways);
			if (state < 2) FORE(i, 1, len - 1) inc(ndp[2][sum + bal + i - (len - i)], (ll)2 * ways % MOD);
			if (state < 2) FORE(i, 1, len - 2) inc(ndp[2][sum + bal + i - (len - i - 1)], (ll)2 * ways % MOD);
			if (state == 0) for (int i : {0, len - 1}) inc(ndp[3][sum + bal + i - (len - i - 1)], (ll)2 * ways % MOD);

		}
		//REP(state, 3) FORE(bal, -sum, +sum) if (ndp[state][sum + bal] != 0) printf("after %d: (%d,%+d)=%d\n", i, state, bal, ndp[state][sum + bal]);
		swap(dp, ndp);
	}
	int ret = 0;
	inc(ret, dp[0][sum + 0]);
	inc(ret, dp[2][sum + 0]);
	inc(ret, dp[3][sum + 0]);
	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}