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

const int MAXN = 3000;

int n;

bool local = false;
int arr[MAXN];

int query(int a, int b, int c) {
	if (!local) {
		printf("? %d %d %d\n", a + 1, b + 1, c + 1); fflush(stdout);
		int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
	} else {
		return max({ arr[a],arr[b],arr[c] }) - min({ arr[a],arr[b],arr[c] });
	}
}

pair<int, int> solve() {
	int cand = 2, best = query(0, 1, cand); bool sure = false;
	FOR(i, 3, n) {
		int cur = query(0, 1, i);
		if (cur > best) best = cur, cand = i, sure = true;
		else if (cur < best) sure = true;
	}

	int a, b;
	if (sure) {
		a = cand, b = 0;
	} else {
		int x = query(0, 2, 3);
		int y = query(1, 2, 3);
		if (x > best || y > best) {
			return MP(2, 3);
		} else if (x < best && y < best) {
			return MP(0, 1);
		} else if (x < best) {
			// on 0 side never unique
			a = 0, b = 2;
		} else if (y < best) {
			// on 1 side never unique
			a = 1, b = 2;
		} else {
			// only unique extreme possible when 0=1 and 2=3 and 2/3 are extreme
			a = 2, b = 0;
		}
	}

	cand = -1, best = INT_MIN, sure = false;
	REP(i, n) {
		if (i == a || i == b) continue;
		int cur = query(a, b, i);
		if (cand == -1) { cand = i, best = cur, sure = false; continue; }
		if (cur > best) best = cur, cand = i, sure = true;
		else if (cur < best) sure = true;
	}
	if (sure) {
		return MP(a, cand);
	} else {
		// b may not be exteme, but in that case there are multiple equal extremes on this side
		return MP(a, b);
	}
}

void run() {
	scanf("%d", &n);
	pair<int, int> ans = solve();
	printf("! %d %d\n", ans.first + 1, ans.second + 1); fflush(stdout);
}

void stress() {
	std::mt19937 rnd(23123);
	local = true;
	int mxn = 5;
	REP(rep, 100000) {
		n = rnd() % (mxn - 4 + 1) + 4;
		int zero = rnd() % n;
		int lim = rnd() % 10 + 1;
		REP(i, n) arr[i] = i == zero ? 0 : rnd() % lim + 1;
		pair<int, int> have = solve();
		if (have == MP(-1, -1)) { printf("?"); continue; }
		bool ok = arr[have.first] == 0 || arr[have.second] == 0;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("n=%d arr=", n); REP(i, n) printf("%d ", arr[i]); printf(" ans=(%d,%d)\n", have.first, have.second);
		break;
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}