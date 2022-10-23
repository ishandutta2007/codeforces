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

int n;
int a[MAXN];
int b[MAXN];

int f(int x) { assert(x >= 1); int ret = 0; while (x > 0) x /= 10, ++ret; return ret; }

int solve() {
	vector<int> asmall(10, 0);
	vector<int> bsmall(10, 0);
	multiset<int> abig;
	int ret = 0;
	REP(i, n) if (a[i] < 10) ++asmall[a[i]]; else abig.insert(a[i]);
	REP(i, n) if (b[i] < 10) ++bsmall[b[i]]; else {
		auto it = abig.find(b[i]);
		if (it != abig.end()) {
			abig.erase(it);
		} else {
			++bsmall[f(b[i])];
			++ret;
		}
	}
	for (int x : abig) ++asmall[f(x)], ++ret;
	for (int x = 9; x >= 1; --x) {
		int common = min(asmall[x], bsmall[x]);
		asmall[x] -= common, bsmall[x] -= common;
		ret += asmall[x] + bsmall[x];
		if (x == 1) assert(asmall[x] == 0 && bsmall[x] == 0); else asmall[1] += asmall[x], bsmall[1] += bsmall[x], asmall[x] = bsmall[x] = 0;
	}
	return ret;
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