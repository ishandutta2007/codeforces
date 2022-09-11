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

const int MAXN = 18;
struct E { int from, to, w; };

int n, m;
vector<E> in[MAXN];
vector<E> out[MAXN];
int ans[MAXN];

bool seen[MAXN];
int toplst[MAXN], topidx[MAXN], ntop;
int ord[MAXN];
int invord[MAXN];

int dp[1 << MAXN]; // dp[mask] = minimum cost for assigning weights to vertexes in mask
int act[1 << MAXN];
int dp2[1 << MAXN][MAXN + 1]; // dp2[mask][at] = minimum cost for assigning weights to vertexes in mask, assuming only vertexes >= at can get mark 0, and cost for vertexes < at to vertexes with mark 0 (and lower) are already included
int act2[1 << MAXN][MAXN];

void dfstop(int at) {
	seen[at] = true;
	REPSZ(i, out[at]) {
		int to = out[at][i].to;
		if (!seen[to]) dfstop(to);
	}
	toplst[ntop] = at, topidx[at] = ntop, ++ntop;
}

void solve() {
	ntop = 0;
	REP(i, n) seen[i] = false;
	REP(i, n) if (!seen[i]) dfstop(i);
	assert(ntop == n);
	REP(i, n) ord[i] = toplst[n - i - 1];
	REP(i, n) invord[ord[i]] = i;
	//printf("ord:"); REP(i, n) printf(" %d", ord[i] + 1); puts("");

	auto upd = [&](int& a, int b, int& c, int d) { if (b < a) a = b, c = d; };
	dp[0] = 0;
	REP(mask, 1 << n) {
		act[mask] = -1;
		if (mask == 0) {
			dp[mask] = 0;
		} else {
			dp[mask] = INT_MAX;
			int sofar = 0;
			REP(idx, n) if (mask & (1 << idx)) {
				int at = ord[idx];
				int cur = dp2[mask ^ (1 << idx)][idx + 1] + sofar;
				bool ok = true;
				REPSZ(i, in[at]) {
					int from = in[at][i].from;
					if (mask & (1 << invord[from])) cur += in[at][i].w;
				}
				REPSZ(i, out[at]) {
					int to = out[at][i].to;
					if (mask & (1 << invord[to])) ok = false;
				}
				if (ok) {
					upd(dp[mask], cur, act[mask], idx);
					//printf("\tidx=%d cur=%d\n", idx, cur);
				}
				REPSZ(i, out[at]) {
					int to = out[at][i].to;
					if ((mask & (1 << invord[to])) == 0) sofar += out[at][i].w;
				}
			}
			assert(dp[mask] != INT_MAX);
		}
		dp2[mask][n] = dp[mask];
		for (int idx = n - 1; idx >= 0; --idx) {
			int at = ord[idx];
			dp2[mask][idx] = INT_MAX;
			act2[mask][idx] = -1;
			if ((mask & (1 << idx)) == 0) { upd(dp2[mask][idx], dp2[mask][idx + 1], act2[mask][idx], 0); continue; }
			int insum = 0; REPSZ(i, in[at]) { int from = in[at][i].from; if (mask & (1 << invord[from])) insum += in[at][i].w; }
			bool ok = true; int outsum = 0; REPSZ(i, out[at]) { int to = out[at][i].to; if ((mask & (1 << invord[to])) == 0) outsum += out[at][i].w; else ok = false; }
			//printf("mask=%x idx=%d at=%d ok=%s outsum=%d insum=%d\n", mask, idx, at, ok ? "YES" : "NO", outsum, insum);
			upd(dp2[mask][idx], dp2[mask][idx + 1] + outsum, act2[mask][idx], 0);
			if (ok) upd(dp2[mask][idx], dp2[mask ^ (1 << idx)][idx + 1] + insum, act2[mask][idx], 1);
		}
		//printf("dp[%x]=%d\n", mask, dp[mask]);
	}
	//printf("min cost = %d\n", dp[(1 << n) - 1]);
	{
		int mask = (1 << n) - 1, idx = -1, val = 0;
		REP(i, n) ans[i] = -1;
		while (mask != 0) {
			if (idx == -1) {
				idx = act[mask];
				ans[ord[idx]] = val;
				mask ^= 1 << idx, ++idx;
			} else if(idx==n) {
				++val;
				idx = -1;
			} else if (act2[mask][idx]) {
				ans[ord[idx]] = val;
				mask ^= 1 << idx, ++idx;
			} else {
				++idx;
			}
		}
	}
}


void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; E e; e.from = a, e.to = b, e.w = c; in[b].PB(e); out[a].PB(e); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}