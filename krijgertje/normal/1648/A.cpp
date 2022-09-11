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

int h, w;
vector<vector<int>> a;

void rot() {
	vector<vector<int>> b(w, vector<int>(h));
	REP(x, h) REP(y, w) b[y][x] = a[x][y];
	swap(h, w), a = b;
}

ll calcvert() {
	int ncol = 0;
	REP(x, h) REP(y, w) ncol = max(ncol, a[x][y] + 1);
	vector<vector<int>> bycol(ncol);
	REP(x, h) REP(y, w) bycol[a[x][y]].PB(x);
	ll ret = 0;
	REP(c, ncol) {
		const vector<int> &b = bycol[c];
		for (int l = 0, r = l; l < SZ(b); l = r) {
			int before = l, after = SZ(b) - l;
			if (before != 0) ret += (ll)(b[l] - b[l - 1]) * before * after;
			while (r < SZ(b) && b[r] == b[l]) ++r;
		}
	}
	return ret;
}

ll solve() {
	ll ret = 0;
	REP(i, 2) {
		ret += calcvert();
		rot();
	}
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	a = vector<vector<int>>(h, vector<int>(w));
	REP(x, h) REP(y, w) scanf("%d", &a[x][y]), --a[x][y];
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}