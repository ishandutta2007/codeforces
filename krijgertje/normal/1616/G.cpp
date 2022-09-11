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

const int MAXN = 150000 + 2;

int n, m;
vector<int> out[MAXN];
vector<int> in[MAXN];

bool tonxt[MAXN];
int upto[MAXN];

bool canforward[MAXN][2];
bool canbackward[MAXN][2];

ll solve() {
	REP(i, n) tonxt[i] = false;
	REP(at, n) for (int to : out[at]) if (to == at + 1) tonxt[at] = true;

	for (int i = n - 1; i >= 0; --i) upto[i] = tonxt[i] ? upto[i + 1] : i;
	int x = upto[0];
	if (x == n - 1) return (ll)(n - 2)*(n - 3) / 2;

	REP(i, n) REP(k, 2) canforward[i][k] = false;
	canforward[x][0] = true;
	REP(at, n) REP(k, 2) if (canforward[at][k]) {
		for (int to : out[at]) if (to != at + 1) {
			if (upto[at + 1] < to - 1) continue;
			canforward[to - 1][1 - k] = true;
		}
	}
	REP(i, n) REP(k, 2) canbackward[i][k] = false;
	canbackward[x][0] = true;
	for (int at = n - 1; at >= 0; --at) REP(k, 2) if (canbackward[at][k]) {
		for (int to : in[at + 1]) if (to != at) {
			canbackward[to][1 - k] = true;
		}
	}

	ll ret = 0;
	// cnt all pairs
	vector<int> acnt(4, 0);
	FORE(a, 1, x + 1) { int mask = (canbackward[a - 1][0] ? 1 : 0) + (canbackward[a - 1][1] ? 2 : 0); ++acnt[mask]; }
	vector<int> bcnt(4, 0);
	FORE(b, x, n - 2) if (upto[b + 1] == n - 1) { int mask = (canforward[b][0] ? 1 : 0) + (canforward[b][1] ? 2 : 0); ++bcnt[mask]; }
	REP(amask, 4) REP(bmask, 4) {
		bool ok = false;
		REP(k, 2) if ((amask&(1 << k)) != 0 && (bmask&(1 << k)) != 0) ok = true;
		if (!ok) continue;
		ret += (ll)acnt[amask] * bcnt[bmask];
	}
	
	// subtract (x,x) (x+1,x) (x+1,x+1)
	FORE(a, x, x + 1) FORE(b, x, x + 1) if (a >= b) {
		bool ok = false;
		REP(k, 2) if (canbackward[a - 1][k] && upto[b + 1] == n - 1 && canforward[b][k]) ok = true;
		if (!ok) continue;
		--ret;
	}

	/*FORE(a, 1, x + 1) FORE(b, max(a + 1, x), n - 2) {
		bool ok = false;
		REP(k, 2) if (canbackward[a - 1][k] && upto[b + 1] == n - 1 && canforward[b][k]) ok = true;
		if (!ok) continue;
		printf("%d->%d\n", b, a);
	}*/

	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	n += 2;
	FORE(i, 1, n - 2) { out[0].PB(i); in[i].PB(0); out[i].PB(n - 1); in[n - 1].PB(i); }
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); out[a].PB(b); in[b].PB(a); }
	printf("%lld\n", solve());
	REP(i, n) out[i].clear(), in[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}