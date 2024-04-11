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
const int MAXALPH = 200000;
const int MOD = 998244353;

int n, alph;
int s[MAXN];

int pos[MAXN + 1];
bool sep[MAXN - 1];

int inv[MAXN + MAXALPH + 1];
int fac[MAXN + MAXALPH + 1];
int ifac[MAXN + MAXALPH + 1];

int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }
int chooserep(int n, int k) { return choose(n - 1 + k, k); }

int solve() {
	inv[1] = 1; FORE(i, 2, n + alph) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n + alph) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n + alph) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	REP(i, n) pos[s[i]] = i;
	pos[n] = -1;
	REP(i, n - 1) sep[i] = pos[s[i] + 1] > pos[s[i + 1] + 1];
	//printf("sep: "); REP(i, n - 1) printf("%c", sep[i] ? '|' : '.'); puts("");

	int need = 0;
	REP(i, n - 1) if (sep[i]) ++need;
	int have = alph - 1;
	if (need > have) return 0;
	return chooserep(n + 1, have - need);
}

void run() {
	scanf("%d%d", &n, &alph);
	REP(i, n) scanf("%d", &s[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}