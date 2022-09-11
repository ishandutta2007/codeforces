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

int nshop, nfriend;
vector<vector<int>> a;

bool can(int x) {
	REP(j, nfriend) {
		bool any = false;
		REP(i, nshop) if (a[i][j] >= x) any = true;
		if (!any) return false;
	}
	bool twice = false;
	REP(i, nshop) {
		int cnt = 0;
		REP(j, nfriend) if (a[i][j] >= x) ++cnt;
		if (cnt >= 2) twice = true;
	}
	if (!twice) return false;
	return true;
}

int solve() {
	int lo = 0, hi = 0;
	REP(i, nshop) REP(j, nfriend) hi = max(hi, a[i][j] + 1);
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) lo = mi; else hi = mi;
	}
	return lo;
}

void run() {
	scanf("%d%d", &nshop, &nfriend);
	a = vector<vector<int>>(nshop, vector<int>(nfriend));
	REP(i, nshop) REP(j, nfriend) scanf("%d", &a[i][j]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}