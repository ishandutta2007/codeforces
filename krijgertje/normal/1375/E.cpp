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
int a[MAXN];
int orig[MAXN];
vector<pair<int, int>> ans;

vector<int> inv[MAXN];

void makemove(int u, int v) {
	swap(a[u], a[v]);
	ans.PB(MP(u, v));
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
}

void solve() {
	ans.clear();
	REP(i, n) orig[i] = a[i];
	REP(i, n) FOR(j, i + 1, n) if (a[i] > a[j]) inv[j].PB(i);
	for (int i = n - 1; i >= 0; --i) {
		vector<pair<int, int>> cur;
		REPSZ(j, inv[i]) { int to = inv[i][j]; cur.PB(MP(orig[to], to)); }
		sort(cur.begin(), cur.end());
		if (SZ(cur) == 0) {
			REP(j, i) assert(a[j] <= a[i]);
		} else {
			int mx = a[i]; REP(j, i) mx = max(mx, a[j]);
			assert(a[cur[SZ(cur) - 1].second] == mx);
			assert(a[cur[0].second] >= a[i]);
			REPSZ(j, cur) makemove(cur[j].second, i);
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
	run();
	return 0;
}