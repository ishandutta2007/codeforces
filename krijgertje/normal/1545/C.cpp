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

const int MAXN = 500;
const int MOD = 998244353;

int n;
int a[2 * MAXN][MAXN];
int ans[MAXN];

bool remrow[2 * MAXN];
bool remcol[MAXN][MAXN];
int remcnt[MAXN][MAXN];

int solve() {
	REP(i, 2 * n) remrow[i] = true;
	REP(j, n) REP(k,n) remcol[j][k] = true;
	REP(j, n) REP(k, n) remcnt[j][k] = 0;
	REP(i, 2 * n) if (remrow[i]) REP(j, n) remcnt[j][a[i][j]]++;
	queue<pair<int, int>> q;
	REP(j, n) REP(k, n) if (remcol[j][k] && remcnt[j][k] <= 1) q.push(MP(j, k));
	int nans = 0;
	REP(i, n) ans[i] = -1;

	int ret = 1;
	int jnxt = 0, knxt = 0;
	while (nans<n) {
		int j, k;
		if (!q.empty()) {
			j = q.front().first, k = q.front().second; q.pop();
		} else {
			while (jnxt < n && !remcol[jnxt][knxt]) if (knxt == n - 1) ++jnxt, knxt = 0; else ++knxt;
			assert(jnxt < n);
			j = jnxt, k = knxt;
			ret = (ll)2 * ret % MOD;
		}
		if (!remcol[j][k]) continue;
		//printf("(%d,%d)\n", j + 1, k + 1);
		assert(remcnt[j][k] >= 1);
		int i = -1; REP(z, 2 * n) if (remrow[z] && a[z][j] == k) { i = z; break; } assert(i != -1);
		remrow[i] = false;
		ans[nans++] = i;
		REP(jj, n) {
			int kk = a[i][jj];
			assert(remcol[jj][kk]);
			remcol[jj][kk] = false;
			--remcnt[jj][kk];
			REP(ii, 2 * n) if (remrow[ii] && a[ii][jj] == kk) {
				remrow[ii] = false;
				REP(jjj, n) {
					int kkk = a[ii][jjj];
					if (--remcnt[jjj][kkk] == 1) q.push(MP(jjj, kkk));
				}
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, 2 * n) REP(j, n) scanf("%d", &a[i][j]), --a[i][j];
	printf("%d\n", solve());
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}