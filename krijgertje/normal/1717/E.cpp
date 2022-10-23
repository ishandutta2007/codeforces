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
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

const int MAXN = 100000;
const int MOD = 1000000007;

int n;

int pmn[MAXN + 1];
int phi[MAXN + 1];

int solve() {
	memset(pmn, -1, sizeof(pmn));
	FORE(i, 2, n) if (pmn[i] == -1) for (int j = i; j <= n; j += i) if (pmn[j] == -1) pmn[j] = i;
	phi[1] = 1; FORE(i, 2, n) phi[i] = phi[i / pmn[i]] * (pmn[i / pmn[i]] == pmn[i] ? pmn[i] : pmn[i] - 1);
	//printf("phi:"); FORE(i, 1, n) printf(" %d", phi[i]); puts("");

	int ret = 0;
	FORE(d, 1, n) for (int ab = 2 * d; ab < n; ab += d) { int c = n - ab; int cnt = phi[ab / d]; ret = (ret + (ll)cnt * lcm(c, d)) % MOD; }
	return ret;
}

void run() {
	scanf("%d", &n);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}