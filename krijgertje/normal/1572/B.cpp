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
vector<int> ans;

int cur[MAXN];

void move(int x) {
	assert(x >= 0 && x + 2 < n);
	ans.PB(x);
	int v = cur[x] ^ cur[x + 1] ^ cur[x + 2];
	cur[x] = cur[x + 1] = cur[x + 2] = v;
}

void go(int at, int dir) {
	while (true) {
		assert(cur[at] == 0);
		int to = at + dir;
		if (to < 0 || to >= n) return;
		if (cur[to] == 0) {
			at = to;
		} else {
			int nxt = to + dir;
			assert(nxt >= 0 && nxt < n);
			if (cur[nxt] == 1) {
				move(min(nxt, at));
				at = nxt;
			} else {
				int oth = nxt + dir;
				assert(oth >= 0 && oth < n);
				if (cur[oth] == 1) {
					move(min(to, oth));
					at = oth;
				} else {
					move(min(to, oth));
					move(min(at, nxt));
					at = nxt;
				}
			}
		}
	}
}

bool solve() {
	int cnt = 0;
	REP(i, n) if (a[i] == 1) ++cnt;
	if (cnt % 2 == 1) return false;

	REP(i, n) cur[i] = a[i];
	ans.clear();

	int before = 0;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && cur[r] == cur[l]) ++r;
		int cnt = r - l;
		if (cur[l] == 0) {
			if (before % 2 == 0) {
				go(l, -1);
				go(l, +1);
				REP(i, n) assert(cur[i] == 0);
				return true;
			}
			if (cnt % 2 == 1) {
				int x = l - 1, y = r;
				assert(y < n);
				for (int z = x; z < y; z += 2) move(z);
				go(y, -1);
				go(y, +1);
				REP(i, n) assert(cur[i] == 0);
				return true;
			}
		} else {
			before += cnt;
		}
	}
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

void stress() {
	std::mt19937 rnd(12312323);
	REP(rep, 100000) {
		n = rnd() % 7	 + 1;
		if (n < 3) continue;
		REP(i, n) a[i] = rnd() % 2;
		//printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
		bool res = solve();
		if (!res) continue;
		//printf("ans=%d\n", SZ(ans)); REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
		printf(".");
		assert(SZ(ans) <= n);
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}