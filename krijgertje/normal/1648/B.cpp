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

const int MAXN = 1000000;
const int MAXVAL = 1000000;

int n, mxval;
int a[MAXN];

bool have[MAXVAL + 1];
int havesum[MAXVAL + 1];
int b[MAXN], nb;

bool solve() {
	FORE(i, 1, mxval) have[i] = false;
	REP(i, n) have[a[i]] = true;
	nb = 0;
	FORE(i, 1, mxval) if (have[i]) b[nb++] = i;
	if (!have[1]) return false;
	havesum[0] = 0;
	FORE(i, 1, mxval) havesum[i] = havesum[i - 1] + (have[i] ? 1 : 0);
	FORE(i, 2, mxval) {
		if (have[i]) continue;
		FOR(j, 1, nb) {
			int l = min((ll)i * b[j], (ll)mxval + 1), r = min((ll)(i + 1) * b[j] - 1, (ll)mxval);
			if (l > r) break;
			//printf("i=%d b[j]=%d -> %d..%d = %lld\n", i, b[j], l, r, l <= r ? havesum[r] - havesum[l - 1] : 0LL);
			if (l <= r && havesum[r] - havesum[l - 1] != 0) return false;
		}
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &mxval);
	REP(i, n) scanf("%d", &a[i]);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}