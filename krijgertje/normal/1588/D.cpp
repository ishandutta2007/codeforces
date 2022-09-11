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

const int MAXN = 10;
const int ALPH = 52;
const int MAXLEN = 2 * ALPH;

int n;
char s[MAXN][MAXLEN + 1];
char ans[MAXLEN + 1];

int dp[ALPH][1 << MAXN];
pair<int, int> prv[ALPH][1 << MAXN];

int slen[MAXN];
vector<int> pos[ALPH][MAXN];

int convert(char c) { if (islower(c)) return c - 'a'; if (isupper(c)) return 26 + c - 'A'; assert(false); return -1; }
char deconvert(int x) { if (x < 26) return 'a' + x; if (x < 52) return 'A' + x - 26; assert(false); return '?'; }

void solve() {
	memset(dp, -1, sizeof(dp));

	REP(k, ALPH) REP(i, n) pos[k][i].clear();
	REP(i, n) {
		slen[i] = strlen(s[i]);
		REP(j, slen[i]) pos[convert(s[i][j])][i].PB(j);
	}
	REP(k, ALPH) REP(i, n) assert(SZ(pos[k][i]) <= 2);

	REP(k, ALPH) {
		bool ok = true;
		REP(i, n) if (SZ(pos[k][i]) == 0) ok = false;
		if (ok) dp[k][0] = 1, prv[k][0] = MP(-1, -1);
	}
	REP(j, slen[0]) {
		int k = convert(s[0][j]);
		REP(mask, 1 << n) {
			if (dp[k][mask] == -1) continue;
			int fstidx = mask & 1;
			if (fstidx >= SZ(pos[k][0]) || pos[k][0][fstidx] != j) continue;
			//printf("dp[%c][%x]=%d\n", deconvert(k), mask, dp[k][mask]);
			REP(kk, ALPH) {
				int nmask = 0; bool ok = true;
				REP(i, n) {
					int idx = (mask >> i) & 1;
					assert(idx < SZ(pos[k][i]));
					int nidx = 0;
					while (nidx < SZ(pos[kk][i]) && pos[kk][i][nidx] <= pos[k][i][idx]) ++nidx;
					if (nidx >= SZ(pos[kk][i])) ok = false; else nmask |= nidx << i;
				}
				if (!ok) continue;
				//printf(" -> dp[%c][%x]\n", deconvert(kk), nmask);
				if (dp[k][mask] + 1 > dp[kk][nmask]) dp[kk][nmask] = dp[k][mask] + 1, prv[kk][nmask] = MP(k, mask);
			}
		}
	}
	int kbest = -1, maskbest = -1;
	REP(k, ALPH) REP(mask, 1 << n) if (dp[k][mask] != -1 && (kbest == -1 || dp[k][mask] > dp[kbest][maskbest])) kbest = k, maskbest = mask;
	if (kbest == -1) { ans[0] = '\0'; return; }
	{
		int k = kbest, mask = maskbest;
		ans[dp[k][mask]] = '\0';
		while (k != -1) {
			ans[dp[k][mask] - 1] = deconvert(k);
			tie(k, mask) = prv[k][mask];
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%s", s[i]);
	solve();
	printf("%d\n%s\n", strlen(ans), ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}