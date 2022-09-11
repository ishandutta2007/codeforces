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

const int MAXN = 50;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
int firstval;
int deltaval[MAXN];
ll anslen; int answays;

ll segfrom[MAXN], segto[MAXN];
vector<ll> special;

vector<int> path;
vector<vector<int>> C;
vector<int> inv;

int choose(ll n, int k) {
	int ret = 1;
	REP(i, k) ret = (ll)ret * ((n - i) % MOD) % MOD * inv[i + 1] % MOD;
	return ret;
}

int calctrans(int s, int t) {
	int npos = 0;
	FOR(i, s, t) if (path[i] == path[s] && path[i + 1] == path[t]) ++npos;
	int nneg = npos - 1;
	ll between = special[path[t]] - special[path[s]] - 1;
	int nbar = npos + nneg - 1;
	//printf("\tnpos=%d nneg=%d between=%lld\n", npos, nneg, between);
	int ret = 0;
	REPE(i, nneg) { // #times neg more than 1
		ll rem = between - 2 * i;
		if (rem < 0) continue;
		int ways = (ll)choose(rem + nbar, nbar) * C[nneg][i] % MOD;
		//printf("\t%d: %d (rem=%lld)\n", i, ways, rem);
		if (i % 2 == 0) inc(ret, ways); else inc(ret, MOD - ways);
	}
	//printf("\t->%d\n", ret);
	return ret;
}


void solve() {
	REP(i, n) {
		segfrom[i] = i == 0 ? firstval : segto[i - 1];
		segto[i] = segfrom[i] + deltaval[i];
	}
	special.clear();
	REP(i, n) special.PB(segfrom[i]), special.PB(segto[i]);
	sort(special.begin(), special.end());
	special.erase(unique(special.begin(), special.end()), special.end());
	//printf("special:"); REPSZ(i, special) printf(" %lld", special[i]); puts("");

	path.clear();
	REP(i, n) {
		int fromidx = lower_bound(special.begin(), special.end(), segfrom[i]) - special.begin();
		int toidx = lower_bound(special.begin(), special.end(), segto[i]) - special.begin();
		if (i == 0) path.PB(fromidx);
		if (fromidx < toidx) FORE(j, fromidx + 1, toidx) path.PB(j);
		if (fromidx > toidx) for (int j = fromidx - 1; j >= toidx; --j) path.PB(j);
	}
	//printf("path:"); REPSZ(i, path) printf(" %d", path[i]); puts("");
	//printf("path:"); REPSZ(i, path) printf(" %lld", special[path[i]]); puts("");

	bool desc = true;
	FORSZ(i, 1, path) if (path[i] > path[i - 1]) desc = false;
	if (desc) { anslen = 1; answays = (special[path[0]] - special[path.back()] + 1) % MOD; return; }

	anslen = 0;
	REPSZ(i, path) FORSZ(j, i + 1, path) if (path[i] < path[j]) anslen = max(anslen, special[path[j]] - special[path[i]] + 1);
	assert(anslen > 0);

	C = vector<vector<int>>(SZ(path) + 1, vector<int>(SZ(path) + 1));
	REPSZ(i, C) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; }
	inv = vector<int>(SZ(path) + 1);
	inv[1] = 1; FORSZ(i, 2, inv) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;

	answays = 0;
	vector<vector<int>> trans(SZ(path), vector<int>(SZ(path), 0));
	REPSZ(i, path) FORSZ(j, i + 1, path) if (path[j] == path[i] + 1) trans[i][j] = calctrans(i, j);
	REPSZ(i, special) {
		vector<int> dp(SZ(path), 0);
		REPSZ(j, path) if (path[j] == i) inc(dp[j], 1);
		REPSZ(j, path) FORSZ(k, j + 1, path) dp[k] = (dp[k] + (ll)dp[j] * trans[j][k]) % MOD;
		REPSZ(j, path) if (special[path[j]] - special[i] + 1 == anslen) inc(answays, dp[j]);
	}
}

void run() {
	scanf("%d", &n);
	scanf("%d", &firstval);
	REP(i, n) scanf("%d", &deltaval[i]);
	solve();
	printf("%lld %d\n", anslen, answays);
}

int main() {
	run();
	return 0;
}