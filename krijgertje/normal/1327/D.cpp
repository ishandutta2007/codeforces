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

int n;
int nxt[MAXN];
int col[MAXN];

int state[MAXN];
int b[MAXN], nb;

int val[MAXN];

bool test(int mod) {
	REP(i, mod) val[i] = -1;
	REP(i, nb) {
		int j = i % mod;
		if (val[j] == -1) val[j] = b[i];
		if (val[j] != b[i]) val[j] = -2;
	}
	REP(i, mod) { assert(val[i] != -1); if (val[i] != -2) return true; }
	return false;
}

int calc() {
	//printf("b:"); REP(i, nb) printf(" %d", b[i]); puts("");
	int ret = nb;
	for (int d = 1; d * d <= nb; ++d) if (nb % d == 0) {
		if (d < ret && test(d)) ret = min(ret, d);
		if (nb / d < ret && nb / d != d && test(nb / d)) ret = min(ret, nb / d);
	}
	return ret;
}

int solve() {
	int ret = INT_MAX;
	REP(i, n) state[i] = 0;
	REP(s, n) if (state[s] == 0) {
		int at = s; while (state[at] == 0) { state[at] = 1; at = nxt[at]; }
		if (state[at] == 1) {
			nb = 0;
			while (state[at] == 1) { state[at] = 2; b[nb++] = col[at]; at = nxt[at]; }
			ret = min(ret, calc());
		}
		at = s; while (state[at] == 1) { state[at] = 2; at = nxt[at]; }
	}
	return ret;
}


void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &nxt[i]), --nxt[i];
	REP(i, n) scanf("%d", &col[i]);
	printf("%d\n", solve());
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}