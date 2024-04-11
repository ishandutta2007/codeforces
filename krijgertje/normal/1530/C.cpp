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

const int MAXN = 100000;

int n;
int a[MAXN];
int b[MAXN];

int solve() {
	sort(a, a + n);
	sort(b, b + n);
	ll asum = 0; REP(i, n) asum += a[i];
	ll bsum = 0; REP(i, n) bsum += b[i];
	
	int akill = n / 4, apos = 0; while (apos < akill) asum -= a[apos++];
	int bkill = n / 4, bpos = 0; while (bpos < bkill) bsum -= b[bpos++];

	for (int ret = 0;; ++ret) {
		if (asum >= bsum) return ret;
		asum += 100;
		akill = (n + ret + 1) / 4;
		bkill = (n + ret + 1) / 4 - (ret + 1);
		while (apos < akill) asum -= apos >= n ? 100 : a[apos++];
		while (bpos > 0 && bpos > bkill) bsum += b[--bpos];
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}