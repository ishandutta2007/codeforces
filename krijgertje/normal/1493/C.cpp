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

int n, k;
char s[MAXN + 1];
char ans[MAXN + 1];


bool can(int preflen) {
	REP(i, n) ans[i] = '?'; ans[n] = '\0';
	vector<int> left(26, 0);
	int rem = n / k;
	REP(i, preflen) {
		int x = s[i] - 'a';
		ans[i] = 'a' + x;
		if (left[x] > 0) { --left[x]; continue; }
		if (rem == 0) return false;
		--rem;
		left[x] += k - 1;
	}
	if (preflen == n) return true;
	bool bigger = false;
	FOR(i, preflen, n) {
		int x = s[i] - 'a';
		if (!bigger) {
			if (x == 25) {
				ans[i] = 'a' + x;
				if (left[x] > 0) { --left[x]; continue; }
				if (rem == 0) return false;
				--rem;
				left[x] += k - 1;
			} else if (rem > 0) {
				ans[i] = 'a' + x + 1;
				bigger = true;
				if (left[x + 1] > 0) { --left[x + 1]; continue; }
				assert(rem != 0);
				--rem;
				left[x + 1] += k - 1;
			} else {
				++x;
				while (x < 26 && left[x] == 0) ++x;
				if (x == 26) { x = s[i] - 'a'; if (left[x] == 0) return false; }
				ans[i] = 'a' + x;
				if (x > s[i] - 'a') bigger = true;
				assert(left[x] > 0); --left[x];
			}
		} else {
			x = 0;
			if (rem > 0) {
				ans[i] = 'a' ;
				if (left[x] > 0) { --left[x]; continue; }
				assert(rem != 0);
				--rem;
				left[x] += k - 1;
			} else {
				while (x < 26 && left[x] == 0) ++x;
				assert(x < 26);
				ans[i] = 'a' + x;
				assert(left[x] > 0); --left[x];
			}
		}
	}
	return true;
}

bool solve() {
	if (n % k != 0) return false;

	int lo = 0, hi = n + 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) lo = mi; else hi = mi;
	}
	assert(can(lo));
	return true;
}

void run() {
	scanf("%d%d", &n, &k);
	scanf("%s", s); assert(strlen(s) == n);
	if (!solve()) { printf("-1\n"); return; }
	printf("%s\n", ans);

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}