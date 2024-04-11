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

const int MAXLEN = 200000;
const int ALPH = 26;

char s[MAXLEN + 1]; int slen;
vector<pair<int, int>> ans;

int same[MAXLEN], nsame;
int samecnt[ALPH], samefreq[MAXLEN + 1];
int stck[MAXLEN], nstck;
vector<pair<int, int>> orig;

int bit[MAXLEN + 1];
void bmod(int idx, int by) { ++idx; while (idx <= slen) { bit[idx] += by; idx += idx & -idx; } }
int bget(int idx) { ++idx; int ret = 0; while (idx >= 1) { ret += bit[idx]; idx -= idx & -idx; } return ret; }

void solve() {
	nsame = 0; REP(i, ALPH) samecnt[i] = 0; REP(i, slen - 1) if (s[i] == s[i + 1]) { same[nsame++] = i; ++samecnt[s[i] - 'a']; }
	orig.clear();
	nstck = 0;
	REPE(i, slen) samefreq[i] = 0; REP(i, ALPH) ++samefreq[samecnt[i]];
	int mxcnt = 0; REP(i, ALPH) mxcnt = max(mxcnt, samecnt[i]);
	int sumcnt = nsame;
	REP(i, nsame) {
		if (nstck >= 1) {
			int a = stck[nstck - 1], b = same[i];
			if (s[a] != s[b]) {
				int aa = s[a] - 'a', bb = s[b] - 'a';
				int nsumcnt = sumcnt - 2;
				int nmxcnt = (samecnt[aa] == mxcnt || samecnt[bb] == mxcnt) && samefreq[mxcnt] == 1 || samecnt[aa] == mxcnt && samecnt[bb] == mxcnt && samefreq[mxcnt] == 2 ? mxcnt - 1 : mxcnt;
				//printf("\t(%d,%d)->(%d,%d)\n", mxcnt, sumcnt, nmxcnt, nsumcnt);
				if (1 + max(nmxcnt, (nsumcnt + 1) / 2) <= max(mxcnt, (sumcnt + 1) / 2)) {
					orig.PB(MP(a + 1, b));
					--nstck;
					--samefreq[samecnt[aa]], --samecnt[aa], ++samefreq[samecnt[aa]];
					--samefreq[samecnt[bb]], --samecnt[bb], ++samefreq[samecnt[bb]];
					sumcnt -= 2; while (samefreq[mxcnt] == 0) --mxcnt;
					continue;
				}
			}
		}
		stck[nstck++] = same[i];
	}
	assert(mxcnt == sumcnt);
	while (nstck >= 1) {
		int a = stck[nstck - 1];
		int aa = s[a] - 'a';
		int nsumcnt = sumcnt - 1;
		int nmxcnt = samecnt[aa] == mxcnt && samefreq[mxcnt] == 1 ? mxcnt - 1 : mxcnt;
		if (1 + max(nmxcnt, (nsumcnt + 1) / 2) <= max(mxcnt, (sumcnt + 1) / 2)) {
			orig.PB(MP(a + 1, a + 1));
			--nstck;
			--samefreq[samecnt[aa]], --samecnt[aa], ++samefreq[samecnt[aa]];
			--sumcnt; while (samefreq[mxcnt] == 0) --mxcnt;
			continue;
		}
		assert(false);
	}
	assert(mxcnt == 0 && sumcnt == 0 && nstck == 0);
	orig.PB(MP(0, slen - 1));
	//printf("orig:"); REPSZ(i, orig) printf(" %d..%d", orig[i].first, orig[i].second); puts("");

	ans.clear();
	REPE(i, slen) bit[i] = 0;
	REPSZ(i, orig) {
		int a = orig[i].first, b = orig[i].second;
		int aa = bget(a - 1), bb = bget(b);
		int x = a - aa, y = (b - a + 1) - (bb - aa);
		ans.PB(MP(x, x + y - 1));
		bmod(a, y);
	}
}

void run() {
	scanf("%s", s); slen = strlen(s);
	solve();
	printf("%d\n", SZ(ans)); REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}