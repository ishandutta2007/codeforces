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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN = 1000000;

char s[MAXLEN + 1]; int slen;
char ans[MAXLEN + 1];

char t[2 * MAXLEN + 1 + 1]; int tlen;
int mxodd[2 * MAXLEN + 1];

int anslen, ansl, ansr;

void upd(int l, int r) {
	//printf("update(%d,%d)\n", l, r);
	if (l + r > anslen) anslen = l + r, ansl = l, ansr = r;
}

void solve() {
	tlen = 2 * slen + 1;
	REP(i, tlen) t[i] = '*'; REP(i, slen) t[2 * i + 1] = s[i]; t[tlen] = '\0';
	//printf("%s\n", t);
	int center = 0;
	REP(i, tlen) {
		int mirror = center - (i - center);
		mxodd[i] = 0; if (i <= center + mxodd[center]) mxodd[i] = min(center + mxodd[center] - i, mxodd[mirror]);
		while (true) {
			int a = i - mxodd[i] - 1, b = i + mxodd[i] + 1;
			if (a < 0 || b >= tlen || t[a] != t[b]) break;
			++mxodd[i];
		}
		if (i + mxodd[i] > center + mxodd[center]) center = i;
	}
	//printf("mxodd:"); REP(i, tlen) printf(" %d", mxodd[i]); puts("");
	anslen = ansl = ansr = 0;
	int border = 0; while (2 * border + 2 <= slen && s[border] == s[slen - 1 - border]) ++border;
	if (border > 0) upd(border, border);
	if (2 * border + 1 == slen) upd(border + 1, border);
	//printf("border=%d\n", border);
	REP(i, tlen) {
		int l, r;
		int sz = mxodd[i];
		if (i % 2 == 1) {
			assert(sz % 2 == 1);
			--sz;
			l = (i - sz - 1) / 2, r = (i + sz - 1) / 2;
		} else {
			assert(sz % 2 == 0);
			if (sz == 0) continue;
			l = (i + 1 - sz - 1) / 2, r = (i - 1 + sz - 1) / 2;
		}
		int before = l, after = slen - r - 1;
		//if (l != r) printf("%d..%d\n", l, r);
		int plen = r - l + 1;
		if (before<=after && before <= border) {
			int overlap = border - before;
			if (2 * overlap <= plen) {
				upd(before + plen, border - overlap);
			}
		}
		if (after <= before && after <= border) {
			int overlap = border - after;
			if (2 * overlap <= plen) {
				upd(border - overlap, after + plen);
			}
		}
	}
	int at = 0; REP(i, ansl) ans[at++] = s[i]; REP(i, ansr) ans[at++] = s[slen - ansr + i]; ans[at] = '\0';

}

void run() {
	scanf("%s", s); slen = strlen(s);
	solve();
	printf("%s\n", ans);
}

int bfsolve() {
	int ret = 0;
	REPE(l, slen) REPE(r, slen - l) {
		tlen = 0; REP(i, l) t[tlen++] = s[i]; REP(i, r) t[tlen++] = s[slen - r + i]; t[tlen] = '\0';
		bool ok = true; for (int a = 0, b = tlen - 1; a <= b; ++a, --b) if (t[a] != t[b]) { ok = false; break; }
		if (ok) ret = max(ret, l + r);
	}
	return ret;
}

void stress() {
	REP(rep, 10000) {
		slen = rnd() % 100 + 1;
		REP(i, slen) s[i] = 'a' + rnd() % 26; s[slen] = '\0';
		solve();
		int have = strlen(ans);
		int want = bfsolve();
		if (have == want) { printf("."); continue; }
		printf("err: ans=%s have=%d want=%d\n", ans, have, want);
		printf("%s\n", s);
		break;
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}