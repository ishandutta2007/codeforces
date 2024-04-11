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

const int MAXN = 18;
const int MOD = 998244353;

int n;
char s[(1 << MAXN) - 1 + 1];

char a[(1 << MAXN) - 1 + 1]; int alen;
char b[(1 << MAXN) - 1 + 1]; int blen;
bool inv[(1 << MAXN) - 1];

void gen(int idx, char *t, int &tlen) {
	if (idx >= (1 << n) - 1) return;
	t[tlen++] = s[idx];
	int l = 2 * idx + 1, r = 2 * idx + 2;
	if (inv[idx]) swap(l, r);
	gen(l, t, tlen);
	gen(r, t, tlen);
}


int solve() {
	int ret = 1;
	REP(i, (1 << n) - 1) inv[i] = false;
	REP(bit, n - 1) {
		int base = (1 << (n - 2 - bit)) - 1;

		REP(i, (1 << (n - 2 - bit))) {
			int me = base + i;
			int l = 2 * me + 1, r = 2 * me + 2;
			alen = 0; gen(l, a, alen); a[alen] = '\0';
			blen = 0; gen(r, b, blen); b[alen] = '\0';
			//printf("%s vs %s\n", a, b);
			int cmp = 0;
			assert(alen == blen);
			REP(j, alen) if (a[j] != b[j]) { cmp = a[j] < b[j] ? -1 : +1; break; }
			if (cmp != 0) ret = (ll)2 * ret % MOD;
			if (cmp == +1) inv[me] = true;
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}