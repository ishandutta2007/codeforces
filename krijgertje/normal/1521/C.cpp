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

const int MAXN = 10000;

int n;
int ans[MAXN];

int querymaxofmins(int i, int j, int x) {
	printf("? 1 %d %d %d\n", i + 1, j + 1, x); fflush(stdout);
	int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
}
int queryminofmaxs(int i, int j, int x) {
	printf("? 2 %d %d %d\n", i + 1, j + 1, x); fflush(stdout);
	int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
}

void solve() {
	vector<int> perm(n);
	REP(i, n) perm[i] = i;
	shuffle(perm.begin(), perm.end(), rnd);
	int a = perm[0], b = perm[1];
	int mx = max(querymaxofmins(a, b, n - 1), querymaxofmins(b, a, n - 1));
	int mn = min(queryminofmaxs(a, b, 1), queryminofmaxs(b, a, 1));
	if (querymaxofmins(a, b, mx - 1) == mx) swap(a, b);
	ans[a] = mx, ans[b] = mn;

	FORSZ(i, 2, perm) {
		int at = perm[i];
		int cur = queryminofmaxs(at, a, 1);
		if (cur < ans[a]) { 
			ans[at] = cur;
		} else {
			assert(cur == ans[a]);
			ans[at] = querymaxofmins(a, at, n - 1);
			a = at;
		}
	}
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); REP(i, n) printf(" %d", ans[i]); puts(""); fflush(stdout);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}