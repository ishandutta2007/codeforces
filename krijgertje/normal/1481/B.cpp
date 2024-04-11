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

const int MAXN = 100;
struct Z { int l, r, h; Z() {} Z(int l, int r, int h) :l(l), r(r), h(h) {} };

int n, nrocks;
int a[MAXN];



int solve() {
	int rem = nrocks;
	vector<Z> stck;
	REP(i,n) {
		while (SZ(stck) > 0 && stck.back().h <= a[i]) {
			int len = (i - 1) - stck.back().l + 1;
			int times = (SZ(stck) == 1 ? a[i] : min(a[i], stck[SZ(stck) - 2].h)) - stck.back().h;
			int full = min(times, (rem - 1) / len);
			rem -= full * len;
			times -= full;
			if (times != 0) return (i - 1) - (rem - 1);
			stck.pop_back();
		}
		int l = SZ(stck) == 0 ? 0 : stck.back().r + 1;
		stck.PB(Z(l, i, a[i]));
	}
	return -1;
}

void run() {
	scanf("%d%d", &n, &nrocks);
	REP(i, n) scanf("%d", &a[i]);
	int ans = solve();
	printf("%d\n", ans == -1 ? -1 : ans + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}