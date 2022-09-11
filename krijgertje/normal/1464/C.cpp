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

int n; ll want;
char s[MAXN + 1];

int bit[MAXN];

int avail[60];

bool solve() {
	REP(i, n) bit[i] = s[i] - 'a';
	if (n == 1) return (1LL << bit[0]) == want;
	ll rem = want - (1LL << bit[n - 1]) + (1LL << bit[n - 2]);
	//printf("rem=%lld\n", rem);

	REP(i, 60) avail[i] = 0;
	REP(i, n - 2) avail[bit[i]]++;
	ll lrem = rem, rrem = rem;
	REP(i, 60) {
		if (avail[i] % 2 == 0) {
			while (lrem % 2 != 0) ++lrem;
			while (rrem % 2 != 0) --rrem;
			if (lrem > rrem) return false;
			if (i + 1 >= 60) assert(avail[i] == 0); else avail[i + 1] += avail[i] / 2;
			lrem /= 2, rrem /= 2;
		} else {
			while (lrem % 2 == 0) ++lrem;
			while (rrem % 2 == 0) --rrem;
			if (lrem > rrem) return false;
			if (i + 1 >= 60) assert(avail[i] <= 1); else avail[i + 1] += avail[i] / 2;
			lrem = (lrem - 1) / 2, rrem = (rrem + 1) / 2;
		}
	}
	return lrem == 0;
}

void run() {
	scanf("%d%lld", &n, &want);
	scanf("%s", s); assert(strlen(s) == n);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}