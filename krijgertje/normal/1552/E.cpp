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

const int MAXCOL = 100;
const int MAXEACH = 100;
const int MAXN = MAXCOL * MAXEACH;

int ncol, neach, n;
int a[MAXN];
pair<int, int> ans[MAXCOL];

int cnt[MAXN];
int prv[MAXCOL];
bool done[MAXCOL];

void solve() {
	int lim = (ncol + neach - 2) / (neach - 1);
	REP(i, n) cnt[i] = 0;
	REP(i, ncol) prv[i] = -1, done[i] = false;
	REP(i, n) {
		int x = a[i];
		if (prv[x] != -1 && !done[x]) {
			bool ok = true;
			FORE(j, prv[x], i) if (cnt[j] >= lim) ok = false;
			if (ok) {
				FORE(j, prv[x], i) ++cnt[j];
				ans[x] = MP(prv[x], i);
				done[x] = true;
			}
		}
		prv[x] = i;
	}
}

void run() {
	scanf("%d%d", &ncol, &neach); n = ncol * neach;
	REP(i, n) scanf("%d", &a[i]), --a[i];
	solve();
	REP(i, ncol) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	run();
	return 0;
}