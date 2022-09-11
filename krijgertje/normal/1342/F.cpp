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

const int MAXN = 15;

int n;
int a[MAXN];
vector<pair<int, int>> ans;

int fstbit[1 << MAXN];
int sum[1 << MAXN];
int dp[1 << MAXN][MAXN + 1][MAXN+1]; // dp[mask][i][j] = the sum of last submask over all partitionings of mask into a valid sequence of submasks of length i with the active bit of last submask being i (or INT_MAX if no valid partitioning)
int pmask[1 << MAXN][MAXN + 1][MAXN + 1];
int pj[1 << MAXN][MAXN + 1][MAXN + 1];
bool alive[MAXN];

void upd(int mask,int i,int j,int val,int pmask,int pj) {
	if (val >= dp[mask][i][j]) return;
	dp[mask][i][j] = val;
	::pmask[mask][i][j] = pmask;
	::pj[mask][i][j] = pj;
}
int getid(int x) { assert(alive[x]); int ret = 0; REP(i, x) if (alive[i]) ++ret; return ret; }

void solve() {
	FOR(mask, 1, 1 << n) { int i = 0; while (i < n && (mask & (1 << i)) == 0) ++i; assert(i < n); fstbit[mask] = i; }
	REP(mask, 1 << n) { sum[mask] = 0; REP(i, n) if (mask & (1 << i)) sum[mask] += a[i]; }
	REP(mask, 1 << n) REPE(i, n) REP(j, n) dp[mask][i][j] = INT_MAX;
	FOR(mask, 1, 1 << n) upd(mask, 1, fstbit[mask], sum[mask], 0, -1);
	REP(mask, 1 << n) REPE(i, n) {
		REP(j, n) if (dp[mask][i][j] != INT_MAX) {
			int rem = (1 << n) - mask - 1;
			for (int nxt = 0;; nxt = (nxt + mask + 1) & rem) {
				if (nxt != 0 && sum[nxt] > dp[mask][i][j]) {
					int activeopt = (nxt >> j) << j;
					if (activeopt != 0) {
						int ni = i + 1, nj = fstbit[activeopt];
						//printf("%x/%d/%d -> %x/%d/%d (%d)\n", mask, i, j, mask | nxt, ni, nj, sum[nxt]);
						upd(mask | nxt, ni, nj, sum[nxt], mask, j);
					}
				}
				if (nxt == rem) break;
			}
		}
	}
	int cmask = (1 << n) - 1, ci = -1, cj = -1;
	REPE(i, n) REP(j, n) if (dp[cmask][i][j] != INT_MAX && (ci == -1 || i > ci)) ci = i, cj = j;
	//printf("bi=%d bj=%d\n", ci, cj);
	vector<pair<int, int>> orig;
	while (cmask != 0) {
		int pmask = ::pmask[cmask][ci][cj], pi = ci - 1, pj = ::pj[cmask][ci][cj];
		int now = cmask ^ pmask;
		REP(k, n) if ((now & (1 << k)) != 0 && k != cj) orig.PB(MP(k, cj));
		cmask = pmask, ci = pi, cj = pj;
	}
	ans.clear();
	REP(i, n) alive[i] = true;
	REPSZ(i, orig) {
		int a = orig[i].first, b = orig[i].second;
		ans.PB(MP(getid(a), getid(b)));
		alive[a] = false;
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