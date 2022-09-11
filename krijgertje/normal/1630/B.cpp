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

int n, k;
int a[MAXN];
int ansl, ansr;
vector<pair<int, int>> ans;

int b[MAXN];

void solve() {
	REP(i, n) b[i] = a[i];
	sort(b, b + n);
	int need = (n + k + 1) / 2;
	ansl = b[0], ansr = b[n - 1];
	REPE(i, n - need) {
		int curl = b[i], curr = b[i + need - 1];
		if (curr - curl < ansr - ansl) ansl = curl, ansr = curr;
	}
	ans.clear();
	int at = 0;
	while (at < n) {
		int to = at, bal = 0;
		while (to < n && (bal <= 0 || SZ(ans) + 1 == k)) {
			if (a[to] >= ansl && a[to] <= ansr) ++bal; else --bal;
			++to;
		}
		assert(bal > 0);
		ans.PB(MP(at, to - 1));
		at = to;
	}
	assert(SZ(ans) == k);
}

void run() {
	scanf("%d%d", &n, &k);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d %d\n", ansl, ansr);
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}