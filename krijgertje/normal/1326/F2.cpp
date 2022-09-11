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

const int MAXN = 18;
void inc(ll &a, ll b) { a += b; }
void dec(ll &a, ll b) { a -= b; }

int n;
char s[MAXN][MAXN + 1];

int g[MAXN][MAXN];
int bitcount[1 << MAXN];

ll dpgroup[1 << MAXN][MAXN];
ll subgroup[MAXN + 1][1 << MAXN];

ll ans[1 << (MAXN - 1)];

ll prod[MAXN + 1][1 << MAXN];
int group[MAXN], ngroup;

void rec(int rem) {
	if (rem == 0) {
		ll cur = 0; REP(mask, 1 << n) if ((n - bitcount[mask]) % 2 == 0) inc(cur, prod[ngroup][mask]); else dec(cur, prod[ngroup][mask]);
		//printf("group:"); REP(i, ngroup) printf(" %d", group[i]); printf(" -> %lld\n", cur);
		vector<int> p(ngroup); REP(i, ngroup) p[i] = group[i]; sort(p.begin(), p.end());
		do {
			int val = 0;
			REPSZ(i, p) { val = val * 2; REP(j, p[i] - 1) val = 2 * val + 1; }
			inc(ans[val], cur);
			//printf("\t%x\n", val);
		} while (next_permutation(p.begin(), p.end()));
	} else {
		int lim = rem; if (ngroup > 0) lim = min(lim, group[ngroup - 1]);
		FORE(i, 1, lim) {
			REP(mask, 1 << n) prod[ngroup + 1][mask] = prod[ngroup][mask] * subgroup[i][mask];
			group[ngroup++] = i;
			rec(rem - i);
			--ngroup;
		}
	}
}

void solve() {
	REP(i, n) REP(j, n) g[i][j] = s[i][j] == '1' ? 1 : 0;
	bitcount[0] = 0; FOR(mask, 1, 1 << n) bitcount[mask] = bitcount[mask >> 1] + (mask & 1);
	
	REP(mask, 1 << n) REP(i, n) dpgroup[mask][i] = 0;
	REP(i, n) dpgroup[1 << i][i] = 1;
	REP(mask, 1 << n) REP(i, n) if (dpgroup[mask][i] != 0) {
		REP(j, n) if ((mask&(1 << j)) == 0 && g[i][j] == 1) inc(dpgroup[mask ^ (1 << j)][j], dpgroup[mask][i]);
	}

	REPE(i, n) REP(mask, 1 << n) subgroup[i][mask] = 0;
	inc(subgroup[0][0], 1);
	REP(mask, 1 << n) REP(i, n) inc(subgroup[bitcount[mask]][mask], dpgroup[mask][i]);
	REPE(i, n) REP(bit, n) REP(mask, 1 << n) if ((mask&(1 << bit)) != 0) inc(subgroup[i][mask], subgroup[i][mask ^ (1 << bit)]);
	//REPE(i, n) REP(mask, 1 << n) if (subgroup[i][mask] != 0) printf("(%d,%x)=%lld\n", i, mask, subgroup[i][mask]);

	REP(val, 1 << (n - 1)) ans[val] = 0;
	REP(mask, 1 << n) prod[0][mask] = subgroup[0][mask];
	ngroup = 0; rec(n);

	REP(bit, n - 1) REP(val, 1 << (n - 1)) if ((val&(1 << bit)) == 0) dec(ans[val], ans[val ^ (1 << bit)]);

}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%s", &s[i]);
	solve();
	REP(i, 1 << (n - 1)) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

void stress() {
	for (n = 2; n <= MAXN; ++n) {
		REP(i, n) REP(j, n) s[i][j] = i == j ? '0' : '1'; REP(i, n) s[i][n] = '\0';
		solve();
		//REP(i, 1 << (n - 1)) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
		printf("done %d\n", n);
	}
}

int main() {
	run();
	//stress();
	return 0;
}