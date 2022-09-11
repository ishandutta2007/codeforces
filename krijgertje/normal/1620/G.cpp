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

const int MAXN = 23;
const int MAXLEN = 20000;
const int MOD = 998244353;
const int ALPH = 26;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
char s[MAXN][MAXLEN + 1];

int cnt[MAXN][ALPH];
int v[1 << MAXN];
int bc[1 << MAXN];

ll solve() {
	REP(i, n) {
		REP(k, ALPH) cnt[i][k] = 0;
		int len = strlen(s[i]);
		REP(j, len) ++cnt[i][s[i][j] - 'a'];
	}
	v[0] = 0;
	FOR(mask, 1, 1 << n) {
		v[mask] = 1;
		REP(k, ALPH) {
			int lo = INT_MAX;
			REP(i, n) if (mask & (1 << i)) lo = min(lo, cnt[i][k]);
			v[mask] = (ll)v[mask] * (lo + 1) % MOD;
		}
	}
	//printf("v:"); REP(mask, 1 << n) printf(" %d", v[mask]); puts("");
	bc[0] = 0; FOR(i, 1, 1 << n) bc[i] = bc[i >> 1] + (i & 1);
	REP(mask, 1 << n) if (bc[mask] % 2 == 0) v[mask] = (MOD - v[mask]) % MOD;
	REP(bit, n) REP(mask, 1 << n) if (mask & (1 << bit)) inc(v[mask], v[mask ^ (1 << bit)]);
	//printf("v:"); REP(mask, 1 << n) printf(" %d", v[mask]); puts("");
	ll ret = 0;
	REP(mask, 1 << n) {
		int sum = 0;
		REP(i, n) if (mask & (1 << i)) sum += i + 1;
		ret ^= (ll)bc[mask] * sum * v[mask];
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%s", s[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}