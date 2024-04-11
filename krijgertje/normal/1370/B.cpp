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

const int MAXN = 1000;

int n;
int a[2 * MAXN];
int ans[MAXN - 1][2];

void solve() {
	int evn = -1, odd = -1, nans = 0;
	REP(i, 2*n) {
		if (a[i] % 2 == 0) { if (evn == -1) evn = i; else if (nans < n - 1) ans[nans][0] = evn, ans[nans][1] = i, evn = -1, ++nans; }
		if (a[i] % 2 == 1) { if (odd == -1) odd = i; else if (nans < n - 1) ans[nans][0] = odd, ans[nans][1] = i, odd = -1, ++nans; }
	}
}

void run() {
	scanf("%d", &n);
	REP(i, 2 * n) scanf("%d", &a[i]);
	solve();
	REP(i, n - 1) printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}