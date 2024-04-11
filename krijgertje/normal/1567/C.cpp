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

int n;
vector<int> p10;

int solve() {
	int ndig = 1; p10 = { 1 };
	while ((ll)10 * p10.back() <= n) p10.PB(10 * p10.back()), ++ndig;
	int ret = 0;
	REP(mask, 1 << ndig) {
		int cur = 1;
		REP(i, ndig) {
			int have = (mask >> i) & 1;
			if (i < 2 && have != 0) { cur = 0; break; }
			int want = 10 * ((mask >> (i + 2)) & 1) + (n / p10[i] % 10);
			if (have > want) { cur = 0; break; }
			int need = want - have;
			int now = 0;
			FORE(a, 0, 9) { int b = need - a; if (b >= 0 && b <= 9) ++now; }
			cur *= now;
		}
		//if (cur != 0) printf("mask=%x -> %d\n", mask, cur);
		ret += cur;
	}
	return ret - 2;
}

void run() {
	scanf("%d", &n);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}