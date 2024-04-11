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

const int MOD = 1000000007;
const int MAXK = 60;
const int MAXFIX = 2000;
const char COLS[6][10] = { "white","yellow","green","blue","red","orange" };
struct Fix { ll id; int col; };
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int k;
int nfix;
Fix fix[MAXFIX];

int dp[MAXK + 1];
map<pair<ll, int>, int> mem;

map<ll, int> fixmp;
map<ll, int> fixcnt;

int rec(ll at, int lvl, int col) {
	auto key = MP(at, col);
	if (mem.count(key)) return mem[key];
	if (fixmp.count(at) && fixmp[at] != col) return mem[key] = 0;
	if (!fixcnt.count(at)) return mem[key] = dp[k - lvl];

	//printf("rec(%lld,%d,%s)\n", at, lvl, COLS[col]);
	assert(lvl + 1 < k);
	int ret = 1;
	REP(ch, 2) {
		ll to = 2 * at + ch;
		int cur = 0;
		REP(ncol, 6) {
			if (ncol / 2 == col / 2) continue;
			inc(cur, rec(to, lvl + 1, ncol));
		}
		ret = (ll)ret * cur % MOD;
	}
	return mem[key] = ret;
}

int solve() {
	dp[1] = 1;
	FORE(i, 2, k) {
		dp[i] = (ll)4 * dp[i - 1] % MOD * 4 % MOD * dp[i - 1] % MOD;
	}

	fixmp.clear();
	REP(i, nfix) fixmp[fix[i].id] = fix[i].col;
	fixcnt.clear();
	REP(i, nfix) { ll id = fix[i].id / 2; while (id >= 1) { ++fixcnt[id]; id /= 2; } }

	mem.clear();
	int ret = 0;
	REP(i, 6) inc(ret, rec(1, 0, i));
	return ret;
}

void run() {
	scanf("%d", &k);
	scanf("%d", &nfix);
	REP(i, nfix) { char s[100]; scanf("%lld%s", &fix[i].id, s); fix[i].col = -1; REP(j, 6) if (strcmp(s, COLS[j]) == 0) fix[i].col = j; assert(fix[i].col != -1); }

	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}