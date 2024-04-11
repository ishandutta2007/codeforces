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
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
int a[MAXN];

ll asum[MAXN + 1];
ll skipsum[MAXN];

int solve() {
	asum[0] = 0; REP(i, n) asum[i + 1] = asum[i] + a[i];
	REP(i, n) skipsum[i] = (i - 2 >= 0 ? skipsum[i - 2] : 0) + a[i];
	int ret = 0;

	// P*C*
	REPE(i, n) {
		ll psum = asum[i];
		ll csum = asum[n] - asum[i];
		if (psum > csum) inc(ret, 1);
	}
	
	// P?C+(PC)*P+C?
	REP(pfirst, 2) REP(clast, 2) {
		/*FORE(clen, 1, n - pfirst - clast) FORE(plen, 1, n - pfirst - clast - clen) {
			int mlen = n - pfirst - clast - clen - plen;
			if (mlen % 2 != 0) continue;
			int cstart = pfirst, mstart = cstart + clen, pstart = mstart + mlen;
			ll psum = (pfirst ? a[0] : 0) + (asum[pstart + plen] - asum[pstart]) + (mlen >= 2 ? skipsum[mstart + mlen - 2] - (mstart - 2 >= 0 ? skipsum[mstart - 2] : 0) : 0);
			ll csum = (clast ? a[n - 1] : 0) + (asum[cstart + clen] - asum[cstart]) + (mlen >= 2 ? skipsum[mstart + mlen - 1] - (mstart - 1 >= 0 ? skipsum[mstart - 1] : 0) : 0);
			if (psum > csum) inc(ret, 1);
		}*/
		/*FORE(clen, 1, n - pfirst - clast) {
			int plen = 1, mlen = n - pfirst - clast - clen - plen;
			if (mlen % 2 != 0) ++plen, --mlen;
			if (mlen < 0) continue;
			int cstart = pfirst, mstart = cstart + clen, pstart = mstart + mlen;
			ll psum = (pfirst ? a[0] : 0) + (asum[pstart + plen] - asum[pstart]) + (mlen >= 2 ? skipsum[mstart + mlen - 2] - (mstart - 2 >= 0 ? skipsum[mstart - 2] : 0) : 0);
			ll csum = (clast ? a[n - 1] : 0) + (asum[cstart + clen] - asum[cstart]) + (mlen >= 2 ? skipsum[mstart + mlen - 1] - (mstart - 1 >= 0 ? skipsum[mstart - 1] : 0) : 0);
			while (true) {
				if (psum > csum) inc(ret, 1);
				if (mlen == 0) break;
				plen += 2, mlen -= 2, pstart -= 2;
				psum += a[pstart + 1], csum -= a[pstart + 1];
			}
		}*/
		FORE(clen, 1, n - pfirst - clast) {
			int plen = 1, mlen = n - pfirst - clast - clen - plen;
			if (mlen % 2 != 0) ++plen, --mlen;
			if (mlen < 0) continue;
			int cstart = pfirst, mstart = cstart + clen, pstart = mstart + mlen;
			ll psum = (pfirst ? a[0] : 0) + (asum[pstart + plen] - asum[pstart]) + (mlen >= 2 ? skipsum[mstart + mlen - 2] - (mstart - 2 >= 0 ? skipsum[mstart - 2] : 0) : 0);
			ll csum = (clast ? a[n - 1] : 0) + (asum[cstart + clen] - asum[cstart]) + (mlen >= 2 ? skipsum[mstart + mlen - 1] - (mstart - 1 >= 0 ? skipsum[mstart - 1] : 0) : 0);

			// 2*(a[pstart-1]+a[pstart-3]+a[pstart-5]+...+a[pstart-1-2*k])>=csum-psum+1
			// 2*(skipsum[pstart-1]-skipsum[pstart-3-2*k])>=csum-psum+1
			int kmx = mlen / 2;
			if (psum > csum) { inc(ret, kmx + 1); continue; }
			int lo = -1, hi = kmx + 1;
			while (lo + 1 < hi) {
				int mi = lo + (hi - lo) / 2;
				if (2 * (skipsum[pstart - 1] - (pstart - 3 - 2 * mi >= 0 ? skipsum[pstart - 3 - 2 * mi] : 0)) >= csum - psum + 1) hi = mi; else lo = mi;
			}
			if (hi <= kmx) inc(ret, kmx - hi);

			/*int chk = 0;
			while (true) {
				if (psum > csum) inc(chk, 1);
				if (mlen == 0) break;
				plen += 2, mlen -= 2, pstart -= 2;
				psum += a[pstart + 1], csum -= a[pstart + 1];
			}
			printf("%d vs %d\n", (hi <= kmx ? kmx - hi : 0), chk);*/
		}
	}

	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

void research() {
	auto matches = [&](string s) -> bool {
		int cpref = 0; while (cpref < SZ(s) && s[cpref] == '.') ++cpref;
		int psuff = 0; while (psuff < SZ(s) && s[SZ(s) - psuff - 1] == '+') ++psuff;
		if (cpref + psuff == SZ(s)) return true;
		assert(SZ(s) >= 1);
		if (s[0] == '.') { s = s.substr(1); assert(SZ(s) >= 1); }
		if (s[SZ(s) - 1] == '+') { s = s.substr(0, SZ(s) - 1); assert(SZ(s) >= 1); }
		int ppref = 0; while (ppref < SZ(s) && s[ppref] == '+') ++ppref;
		int ssuff = 0; while (ssuff < SZ(s) && s[SZ(s) - ssuff - 1] == '.') ++ssuff;
		if (ppref == 0 || ssuff == 0) return false;
		s = s.substr(ppref, SZ(s) - ppref - ssuff);
		if (SZ(s) % 2 != 0) return false;
		REPSZ(i, s) if (s[i] != (i % 2 == 0 ? '.' : '+')) return false;
		return true;
	};

	FORE(n, 1, 24) {
		REP(mask, 1 << n) {
			vector<int> C, P;
			REP(i, n) if (mask & (1 << i)) C.PB(i); else P.PB(i);
			bool ok = true;
			FORSZ(i, 2, C) if (C[i - 1] - C[i - 2] < C[i] - C[i - 1]) ok = false;
			FORSZ(i, 2, P) if (P[i - 1] - P[i - 2] > P[i] - P[i - 1]) ok = false;
			string s(n, '.'); for (int i : P) s[i] = '+';
			if (ok != matches(s)) printf("%s (ok=%d matches=%d)\n", s.c_str(), ok ? 1 : 0, matches(s) ? 1 : 0);
		}
		printf("done %d\n", n);
	}
}

int main() {
	//research();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}