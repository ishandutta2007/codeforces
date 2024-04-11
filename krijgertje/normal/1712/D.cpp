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

const int MAXN = 100000;
const int MAXVAL = 1000000000;

int n, nops;
int a[MAXN];

bool small[MAXN];
bool big[MAXN];

bool can(int diam) {
	REP(i, n) small[i] = 2 * a[i] < diam;
	int need = 0;
	REP(i, n) if (small[i]) ++need;
	if (need > nops) return false;
	int rem = nops - need;
	REP(i, n) big[i] = small[i] || a[i] >= diam;
	REP(i, n - 1) if (big[i] && big[i + 1]) return true;
	if (rem >= 1) REP(i, n) if (big[i]) return true;
	if (rem >= 2) return true;
	return false;
}

int solve() {
	int lo = 1, hi = MAXVAL + 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) lo = mi; else hi = mi;
	}
	return lo;
}

void run() {
	scanf("%d%d", &n, &nops);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}