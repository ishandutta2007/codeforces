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

const int MAXVAL = 20000000;

int pmn[MAXVAL + 1];
int pcnt[MAXVAL + 1];

void precalc() {
	memset(pmn, -1, sizeof(pmn));
	FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;
	pcnt[1] = 0; FORE(i, 2, MAXVAL) { int p = pmn[i]; int j = i / p; pcnt[i] = pcnt[j] + (pmn[i] != pmn[j] ? 1 : 0); }
}

int c, d, x;

vector<pair<int, int>> factorize(int x) {
	vector<pair<int, int>> ret;
	while (x >= 2) { int p = pmn[x]; int cnt = 0; while (x % p == 0) x /= p, ++cnt; ret.PB(MP(p, cnt)); }
	return ret;
}

vector<int> divs(int x) {
	vector<int> ret = { 1 };
	for (auto z : factorize(x)) {
		int sz = SZ(ret);
		REP(i, sz * z.second) ret.PB(ret[i] * z.first);
	}
	return ret;
}

ll calc(int prod) {
	return 1LL << pcnt[prod];
}

ll solve() {
	ll ret = 0;
	for (int g : divs(x)) {
		int num = x / g + d, den = c;
		if (num % den != 0) continue;
		int rhs = num / den;
		ret += calc(rhs);
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &c, &d, &x);
	printf("%lld\n", solve());
}


int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}