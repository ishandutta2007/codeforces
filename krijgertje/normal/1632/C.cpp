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

int sa, sb;

int solve() {
	int ret = sb - sa;
	REPE(bdelta, ret) {
		int a = sa, b = sb + bdelta;
		int cur = bdelta;
		while ((a | b) != b) {
			int idx = -1;
			for (int bit = 0; (1 << bit) <= a; ++bit) if ((a & (1 << bit)) != 0 && (b & (1 << bit)) == 0) idx = bit;
			int adelta = 0;
			if (idx != -1) {
				adelta = (1 << idx) - (a % (1 << idx));
				a += adelta, cur += adelta;
			}
		}
		if (a != b) {
			a |= b, ++cur;
		}
		assert(a == b);
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &sa, &sb);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}