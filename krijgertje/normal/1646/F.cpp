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

const int MAXN = 100;

int n;
int start[MAXN][MAXN];
vector<vector<int>> ans;


int cnt[MAXN][MAXN];

void solve() {
	ans.clear();
	REP(i, n) REP(x, n) cnt[i][x] = 0;
	REP(i, n) REP(j, n) ++cnt[i][start[i][j]];
	while (true) {
		bool done = true;
		REP(i, n) REP(x, n) if (cnt[i][x] != 1) done = false;
		if (done) break;
		vector<int> cur(n, -1);
		REP(i, n) {
			REP(x, n) if (cnt[i][x] >= 2) {
				cur[i] = x;
				break;
			}
		}
		REP(i, n) if (cur[i] == -1 && i - 1 >= 0 && cur[i - 1] != -1) cur[i] = cur[i - 1];
		assert(cur[n - 1] != -1);
		REP(i, n) if (cur[i] == -1) cur[i] = cur[n - 1];
		ans.PB(cur);
		REP(i, n) { int nxt = (i + 1) % n, x = cur[i]; --cnt[i][x], ++cnt[nxt][x]; }
	}
	REP(T, n) {
		REP(t, T) {
			vector<int> cur(n);
			REP(i, n) cur[i] = (T + i + n - t) % n;
			ans.PB(cur);
			REP(i, n) { int nxt = (i + 1) % n, x = cur[i]; --cnt[i][x], ++cnt[nxt][x]; }
		}
	}
	//REP(i, n) { printf("cnt%d:", i); REP(j, n) printf(" %d", cnt[i][j]); puts(""); }
	REP(i, n) assert(cnt[i][i] == n);
}

void run() {
	scanf("%d", &n);
	REP(i, n) REP(j, n) scanf("%d", &start[i][j]), --start[i][j];
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { REPSZ(j, ans[i]) { if (j != 0) printf(" "); printf("%d", ans[i][j] + 1); } puts(""); }
}

void stress() {
	std::mt19937 rnd(123123);
	int mxn = 8;
	REP(rep, 100000) {
		//n = rnd() % mxn + 1;
		n = 10;
		//vector<int> lst(n * n);
		//REPSZ(i, lst) lst[i] = i / n;
		//shuffle(lst.begin(), lst.end(), rnd);
		//REP(i, n) REP(j, n) start[i][j] = lst[n * i + j];
		REP(i, n) REP(j, n) start[i][j] = (i + n - 1) % n;
		int swaps = rnd() % (4 * n + 1);
		REP(i, swaps) {
			int a = rnd() % n, b = rnd() % n, c = rnd() % n, d = rnd() % n;
			swap(start[a][b], start[c][d]);
		}
		::rnd = std::mt19937(rnd() % 123321313);
		//if (rep != 3) continue;
		//printf("rep=%d\n", rep);
		solve();
		//printf("!\n");
		if (rep % 1000 == 999) printf(".");
		//if (SZ(ans) > n * n - n) 
		printf("n=%d: %d vs %d\n", n, SZ(ans), n * n - n);
	}
}

int main() {
	run();
	//stress();
	return 0;
}