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

const int MAXELF = 1000000;
const int MAXSPOT = 20;

int nelf, lim, nspot;
char s[MAXSPOT + 1];
char t[MAXSPOT + 1];
int op[MAXELF][2];
int anscommon, ansl, ansr;

int lmask[MAXELF + 1];
int rmask[MAXELF + 1];

int dp[1 << MAXSPOT];
int act[1 << MAXSPOT];

void update(int smask, int a) {
	int bits = 0; REP(i, nspot) if (smask & (1 << i)) ++bits;
	if (bits <= dp[smask]) return;
	dp[smask] = bits, act[smask] = a;
	queue<int> q;
	q.push(smask);
	while (!q.empty()) {
		int mask = q.front(); q.pop();
		//printf("%x = %d (%d)\n", mask, dp[mask], act[mask]);
		REP(i, nspot) {
			int nmask = mask ^ (1 << i);
			int nval = dp[mask] - ((smask & mask & (1 << i)) != 0 ? 1 : 0);
			if (nval > dp[nmask]) dp[nmask] = nval, act[nmask] = a, q.push(nmask);
		}
	}
}

void solve() {
	vector<int> perm(nspot);
	auto eval = [&](char *z) { int ret = 0; REP(i, nspot) if (z[i] == '1') ret |= 1 << perm[i]; return ret; };
	REP(i, nspot) perm[i] = i;
	lmask[nelf] = eval(s);
	for (int i = nelf - 1; i >= 0; --i) {
		int a = op[i][0], b = op[i][1];
		swap(perm[a], perm[b]);
		lmask[i] = eval(s);
	}
	REP(i, nspot) perm[i] = i;
	rmask[nelf] = eval(t);
	for (int i = nelf - 1; i >= 0; --i) {
		int a = op[i][0], b = op[i][1];
		swap(perm[a], perm[b]);
		rmask[i] = eval(t);
	}
	//REPE(i, nelf) { printf("l: "); REP(j, nspot) printf("%d", (lmask[i] >> j) & 1); printf(" r: "); REP(j, nspot) printf("%d", (rmask[i] >> j) & 1); puts(""); }

	REP(mask, 1 << nspot) dp[mask] = -1;
	anscommon = -1, ansl = -1, ansr = -1;
	for (int i = nelf; i >= 0; --i) {
		if (i + lim <= nelf) update(rmask[i + lim], i + lim - 1);
		if (dp[lmask[i]] > anscommon) anscommon = dp[lmask[i]], ansl = i, ansr = act[lmask[i]];
	}
	int sone = 0; REP(i, nspot) if (s[i] == '1') ++sone;
	int tone = 0; REP(i, nspot) if (t[i] == '1') ++tone;
	anscommon = anscommon + (nspot - anscommon - (sone - anscommon) - (tone - anscommon));
}

void run() {
	scanf("%d%d%d", &nelf, &lim, &nspot);
	scanf("%s", s);
	scanf("%s", t);
	REP(i, nelf) REP(j, 2) scanf("%d", &op[i][j]), --op[i][j];
	solve();
	printf("%d\n%d %d\n", anscommon, ansl + 1, ansr + 1);
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i,1,ncase)
	run();
	return 0;
}