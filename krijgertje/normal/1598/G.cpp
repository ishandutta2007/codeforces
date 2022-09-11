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

const int MAXSLEN = 500000;
const int MAXXLEN = 200000;
const int NMOD = 5;
int pw(int x, int n, int mod) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % mod; if ((n >>= 1) == 0) return ret; x = (ll)x * x % mod; } }

char s[MAXSLEN + 1]; int slen;
char x[MAXXLEN + 1]; int xlen;
pair<int, int> ans[2];

int mod[NMOD];
int hbase[NMOD][MAXSLEN + 1];
int hinv[NMOD][MAXSLEN + 1];
int hs[NMOD][MAXSLEN + 1];
int hx[NMOD][MAXXLEN + 1];
int xwant[NMOD];

bool isprime(int x) { if (x <= 1) return false; for (int i = 2; (ll)i * i <= x; ++i) if (x % i == 0) return false; return true; }

bool check(int a, int b, int c, int d) {
	if (a< 0 || a > b || b >= c || c > d || d >= slen) return false;
	//printf("checking %d %d %d %d\n", a, b, c, d);
	REP(i, NMOD) {
		int ab = (ll)(hs[i][b + 1] + mod[i] - hs[i][a]) * hbase[i][b] % mod[i];
		int cd = (ll)(hs[i][d + 1] + mod[i] - hs[i][c]) * hbase[i][d] % mod[i];
		//printf("%d+%d vs %d\n", ab, cd, xwant[i]);
		if ((ab + cd) % mod[i] != xwant[i]) return false;
	}
	return true;
}

vector<int> calcz(string s) {
	int l = 0, r = 0;
	vector<int> z(SZ(s));
	FORSZ(i, 1, s) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < SZ(s) && s[i + z[i]] == s[z[i]]) ++z[i];
		if (i + z[i] > r) l = i, r = i + z[i];
	}
	return z;
}


void solve() {
	REP(i, NMOD) { int lo = 100000000, hi = 1000000000; int p = rnd() % (hi - lo + 1); while (!isprime(p)) ++p; mod[i] = p; }
	//printf("mod:"); REP(i, NMOD) printf(" %d", mod[i]); puts("");

	REP(i, NMOD) { hbase[i][0] = 1; REP(j, max(slen, xlen)) hbase[i][j + 1] = (ll)hbase[i][j] * 10 % mod[i]; }
	REP(i, NMOD) { int v = pw(10, mod[i] - 2, mod[i]); hinv[i][0] = 1; REP(j, max(slen, xlen)) hinv[i][j + 1] = (ll)hinv[i][j] * v % mod[i]; }
	REP(i, NMOD) { hs[i][0] = 0; REP(j, slen) hs[i][j + 1] = (hs[i][j] + (ll)hinv[i][j] * (s[j] - '0')) % mod[i]; }
	REP(i, NMOD) { hx[i][0] = 0; REP(j, xlen) hx[i][j + 1] = (hx[i][j] + (ll)hinv[i][j] * (x[j] - '0')) % mod[i]; }
	REP(i, NMOD) xwant[i] = (ll)hx[i][xlen] * hbase[i][xlen - 1] % mod[i];
	//REP(a, slen) FORE(b, a, slen) FOR(c, b + 1, slen) FOR(d, c, slen) if (check(a, b, c, d)) printf("%d %d %d %d\n", a + 1, b + 1, c + 1, d + 1);

	if (xlen >= 2) { // both have length xlen-1
		REPE(i, slen - 2 * (xlen - 1)) {
			ans[0] = MP(i, i + xlen - 2);
			ans[1] = MP(i + xlen - 1, i + xlen - 1 + xlen - 2);
			if (check(ans[0].first, ans[0].second, ans[1].first, ans[1].second)) return;
		}
	}
	vector<int> z = calcz(string(x) + "#" + string(s));
	//printf("z:"); REPSZ(i, z) printf(" %d", z[i]); puts("");
	REPE(i, slen - xlen) {
		int zz = z[xlen + 1 + i];
		int difflen = xlen - zz;
		REP(side, 2) REP(delta, 2) {
			int clen = difflen - delta;
			if (clen <= 0) continue;
			ans[0] = MP(i, i + xlen - 1);
			if (side == 0) ans[1] = MP(i - clen, i - 1), swap(ans[0], ans[1]); else ans[1] = MP(i + xlen, i + xlen + clen - 1);
			if (check(ans[0].first, ans[0].second, ans[1].first, ans[1].second)) return;
		}
	}

	printf("not found\n");
	assert(false);
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%s", x); xlen = strlen(x);
	solve();
	REP(i, 2) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	run();
	return 0;
}