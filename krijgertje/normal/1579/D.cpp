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

const int MAXN = 200000;

int n;
int a[MAXN];
vector<pair<int, int>> ans;

int ord[MAXN];
int cur[MAXN];

void solve() {
	REP(i, n) ord[i] = i;
	sort(ord, ord + n, [&](const int& i, const int& j) { return a[i] > a[j]; });
	REP(i, n) cur[i] = a[i];
	ans.clear();

	auto doit = [&](int x, int y) { --cur[x], --cur[y]; ans.PB(MP(x, y)); };
	while (true) {
		if (cur[ord[0]] == 0) break;
		int x = 0;
		while (x < n && cur[ord[x]] == cur[ord[0]]) ++x;
		if (x >= 2) {
			int cnt = x / 2, offset = x % 2;
			REP(i, cnt) doit(ord[offset + 2 * i], ord[offset + 2 * i + 1]);
		} else {
			assert(x == 1);
			if (cur[ord[1]] == 0) break;
			int y = 1;
			while (y < n && cur[ord[y]] == cur[ord[1]]) ++y;
			int lim = min(y - 1, cur[ord[0]] - cur[ord[1]]);
			REP(i, lim) doit(ord[0], ord[y - 1 - i]);
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}