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

const int MAXN = 200;

int na, nb, nc;
int a[MAXN], b[MAXN], c[MAXN];

ll dp[MAXN + 1][MAXN + 1][MAXN + 1];

void upd(ll& a, ll b) { a = max(a, b); }
ll solve() {
	sort(a, a + na); reverse(a, a + na);
	sort(b, b + nb); reverse(b, b + nb);
	sort(c, c + nc); reverse(c, c + nc);
	REPE(i, na) REPE(j, nb) REPE(k, nc) dp[i][j][k] = LLONG_MIN;
	dp[0][0][0] = 0;
	REPE(i, na) REPE(j, nb) REPE(k, nc) if (dp[i][j][k] != LLONG_MIN) {
		if (i < na && j < nb) upd(dp[i + 1][j + 1][k], dp[i][j][k] + (ll)a[i] * b[j]);
		if (j < nb && k < nc) upd(dp[i][j + 1][k + 1], dp[i][j][k] + (ll)b[j] * c[k]);
		if (k < nc && i < na) upd(dp[i + 1][j][k + 1], dp[i][j][k] + (ll)c[k] * a[i]);
	}
	ll ret = 0; REPE(i, na) REPE(j, nb) REPE(k, nc) upd(ret, dp[i][j][k]); return ret;
}

void run() {
	scanf("%d%d%d", &na, &nb, &nc);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	REP(i, nc) scanf("%d", &c[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}