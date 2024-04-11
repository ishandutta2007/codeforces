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

int n, na, nb;
int a[MAXN];
int b[MAXN];

int bal[MAXN];

int solve() {
	REP(i, n) bal[i] = 0;
	REP(i, na) ++bal[a[i]];
	REP(i, nb) --bal[b[i]];
	int ret = 0;
	if (na > nb) {
		assert((na - nb) % 2 == 0);
		int rem = (na - nb) / 2;
		REP(i, n) while (rem > 0 && bal[i] >= +2) --rem, bal[i] -= 2, ++ret;
		REP(i, n) while (rem > 0 && bal[i] >= +1) --rem, bal[i] -= 2, ++ret;
		assert(rem == 0);
	} else {
		assert((nb - na) % 2 == 0);
		int rem = (nb - na) / 2;
		REP(i, n) while (rem > 0 && bal[i] <= -2) --rem, bal[i] += 2, ++ret;
		REP(i, n) while (rem > 0 && bal[i] <= -1) --rem, bal[i] += 2, ++ret;
		assert(rem == 0);
	}
	int diff = 0;
	REP(i, n) diff += abs(bal[i]);
	assert(diff % 2 == 0);
	ret += diff / 2;
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &na, &nb);
	REP(i, na) scanf("%d", &a[i]), --a[i];
	REP(i, nb) scanf("%d", &b[i]), --b[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}