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

const int MAXN = 200000;

char s[MAXN + 1]; int n;

vector<int> zeroes;

bool can(int cntzero) {
	FOR(i, -1, SZ(zeroes)) {
		int cntone = 0;
		if (i >= 0) cntone += zeroes[i] - i;
		int j = i + cntzero + 1;
		if (j < SZ(zeroes)) cntone += n - zeroes[j] - 1 - (SZ(zeroes) - j - 1);
		//printf("can(%d) -> %d: %d (%s)\n", cntzero, i, cntone, cntone <= cntzero ? "ok" : "bad");
		if (cntone <= cntzero) return true;
	}
	return false;
}

int solve() {
	zeroes.clear();
	REP(i, n) if (s[i] == '0') zeroes.PB(i);
	int lo = -1, hi = n;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) hi = mi; else lo = mi;
	}
	return hi;
}

void run() {
	scanf("%s", s); n = strlen(s);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}