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

const int MAXN = 300000;

int n;
int a[MAXN];
bool ans[MAXN + 1];

int cnt[MAXN + 1];

void solve() {
	FORE(i, 1, n) cnt[i] = 0;
	REP(i, n) ++cnt[a[i]];
	ans[1] = true; FORE(i, 1, n) if (cnt[i] != 1) ans[1] = false;
	int l = 0, r = n - 1;
	FORE(k, 2, n) ans[k] = false;
	for (int k = n; k >= 2; --k) {
		// n-k must be on the side
		// n-k+1 must exist
		if (cnt[n - k + 1] == 0) break;
		if (k != n) {
			if (cnt[n - k] != 1) break;
			if (a[l] == n - k) ++l; else if (a[r] == n - k) --r; else break;
		}
		ans[k] = true;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	FORE(i, 1, n) printf("%d", ans[i] ? 1 : 0); puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}