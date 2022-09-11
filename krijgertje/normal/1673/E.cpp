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

const int MAXN = 1 << 20;
const int NEEDBITS = 1 << 20;

int n, needxor;
int b[MAXN];
char ans[NEEDBITS + 1];

void solve() {
	REP(i, NEEDBITS) ans[i] = '0';
	REP(i, n) {
		int x = b[i];
		FOR(j, i, n) {
			if (j != i) REP(k, b[j]) { x *= 2; if (x > NEEDBITS) break; }
			if (x >= NEEDBITS) break;
			int have = (i == 0 ? 0 : i - 1) + (j == n - 1 ? 0 : n - j - 2), need = max(0, needxor - (i == 0 ? 0 : 1) - (j == n - 1 ? 0 : 1));
			//printf("%d..%d = %d have=%d need=%d\n", i, j, x, have, need);
			if (have < need) continue;
			if (have == 0) { ans[x] ^= 1; continue; }
			if (need == 0) continue;
			int mxbit = 0;
			while ((2 << mxbit) <= have) ++mxbit;
			int cur = have;
			int bit;
			for (bit = 0; cur >= need && bit <= mxbit; ++bit) if (have & (1 << bit)) cur -= 1 << bit;
			assert(cur < need);
			bool havelast = false;
			for (--bit; bit >= 0; --bit) if (have & (1 << bit)) if (cur + (1 << bit) >= need) havelast = false; else havelast = true, cur += 1 << bit;
			if (!havelast) ans[x] ^= 1;
		}
	}

	int anslen = NEEDBITS;
	while (anslen >= 2 && ans[anslen - 1] == '0') --anslen;
	ans[anslen] = '\0';
	reverse(ans, ans + anslen);
}

void run() {
	scanf("%d%d", &n, &needxor);
	REP(i, n) scanf("%d", &b[i]);
	solve();
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}