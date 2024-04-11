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

const int MAXN = 14;
struct Res { vector<vector<int>> ways; };



int n;
char g[MAXN][MAXN + 1];;
ll ans[1 << MAXN - 1];

int v[MAXN][MAXN];

int bitcount[1 << MAXN];
int rev[1 << MAXN];

Res calc(vector<int> lst, bool dorev) {
	int m = SZ(lst);
	Res ret; ret.ways = vector<vector<int>>(m, vector<int>(1 << (m - 1), 0));
	vector<int> p(m); REP(i, m) p[i] = i;
	do {
		int val = 0;
		REP(i, m - 1) {
			int a = lst[p[i]], b = lst[p[i + 1]];
			val += v[a][b] << i;
		}
		if (dorev) val = rev[val];
		++ret.ways[p[m - 1]][val];
	} while (next_permutation(p.begin(), p.end()));
	//printf("lst:"); REPSZ(i, lst) printf(" %d", lst[i]); printf(":"); REP(i, m) REP(j, 1 << (m - 1)) if (ret.ways[i][j] != 0) printf(" (%d,%d)=%d", i, j, ret.ways[i][j]); puts("");
	return ret;
}




void solve() {
	REP(i, n) REP(j, n) v[i][j] = g[i][j] == '1';
	bitcount[0] = 0; FOR(i, 1, 1 << n) bitcount[i] = bitcount[i >> 1] + (i & 1);
	int n1 = (n + 1) / 2, n2 = n - n1;
	REP(i, 1 << (n - 1)) ans[i] = 0;
	REP(mask, 1 << (n2 - 1)) { rev[mask] = 0; REP(i, (n2 - 1)) if (mask & (1 << i)) rev[mask] |= 1 << (n2 - 1 - i - 1); }
	REP(mask, 1 << n) if (bitcount[mask] == n1) {
		vector<int> alst, blst; REP(i, n) if (mask & (1 << i)) alst.PB(i); else blst.PB(i);
		Res a = calc(alst, false);
		Res b = calc(blst, true);
		REPSZ(i, alst) REPSZ(j, blst) REP(aval, 1 << (n1 - 1)) REP(bval, 1 << (n2 - 1)) {
			int val = aval + (v[alst[i]][blst[j]] << (n1 - 1)) + (bval << n1);
			ll cur = (ll)a.ways[i][aval] * b.ways[j][bval];
			//if (cur != 0) printf("ans[%d]+=%lld (%d %d %d)\n", val, cur, aval, v[alst[i]][blst[j]], bval);
			ans[val] += cur;
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%s", &g[i]);
	solve();
	REP(i, 1 << (n - 1)) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

void stress() {
	for (n = MAXN; n <= MAXN; ++n) {
		REP(i, n) REP(j, n) g[i][j] = i == j ? '0' : '1'; REP(i, n) g[i][n] = '\0';
		solve();
		printf("done %d\n", n);
	}
}

int main() {
	run();
	//stress();
	return 0;
}