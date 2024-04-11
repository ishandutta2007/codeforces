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

const int MAXN = 600;

int n, m;
vector<pair<int,int>> e[MAXN];
int ans[MAXN][MAXN];

int step[MAXN][MAXN]; // transitions at time 0 (mod n). at time 1 (mod n) they are shifted by 1, at time 2 (mod n) by 2, etc.

void solve() {
	REP(i, n) REP(j, n) step[i][j] = INT_MAX;
	REP(i, n) for (auto p : e[i]) { int j = p.first, k = p.second; step[i][j] = min(step[i][j], k); }
	REP(i, n) REP(x, 2 * n) { int j = x % n, k = (j + 1) % n; if (step[i][j] != INT_MAX) step[i][k] = min(step[i][k], step[i][j] + 1); }
	//REP(i, n) { printf("step%d:", i); REP(j, n) printf(" %d", step[i][j]); puts(""); }
	REP(s, n) {
		REP(i, n) ans[s][i] = INT_MAX;
		vector<bool> done(n, false);
		ans[s][s] = 0;
		REP(t, n) {
			int at = -1;
			REP(i, n) if (!done[i] && (at == -1 || ans[s][i] < ans[s][at])) at = i;
			assert(at != -1);
			done[at] = true;
			int shift = ans[s][at] % n;
			int to = shift;
			REP(i, n) {
				ans[s][to] = min(ans[s][to], ans[s][at] + step[at][i]);
				if (++to >= n) to = 0;
			}
		}
	}
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); e[a].PB(MP(b, c)); }
	solve();
	REP(i, n) { REP(j, n) { if (j != 0) printf(" "); printf("%d", ans[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}