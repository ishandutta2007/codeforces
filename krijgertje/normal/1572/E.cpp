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

const int MAXN = 200;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
void inc(pair<int, ll>& a, const pair<int, ll>& b) { a.first += b.first; a.second += b.second; }
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P& a, const P& b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
ll twicearea(const P& a, const P& b, const P& c) { return abs((b - a) ^ (c - a)); }

int n, wantcut;
P p[MAXN];

pair<int, ll> dp[MAXN][MAXN]; // (# cuts,total remaining area)

ll solve() {
	ll twicetotarea = 0;
	FOR(i, 2, n) twicetotarea += twicearea(p[0], p[i - 1], p[i]);
	ll lo = 0, hi = twicetotarea / (wantcut + 1) + 1;
	while (lo + 1 < hi) {
		ll mi = lo + (hi - lo) / 2;
		FORE(len, 1, n - 1) {
			REP(i, n) {
				int j = (i + len) % n;
				if (len == 1) { dp[i][j] = MP(0, 0LL); continue; }
				dp[i][j] = MP(-1, 0LL);
				FORE(kk, 1, len - 1) {
					int k = (i + kk) % n;
					pair<int, ll> cur = MP(0, twicearea(p[i], p[k], p[j]));
					inc(cur, dp[i][k]);
					inc(cur, dp[k][j]);
					if (cur.second >= mi) ++cur.first, cur.second = 0;
					if (cur > dp[i][j]) dp[i][j] = cur; // , printf("\t%d\n", k);
				}
				//printf("%lld: %d..%d = (%d,%lld)\n", mi, i, j, dp[i][j].first, dp[i][j].second);
			}
		}
		int havecut = dp[0][n - 1].first - 1;
		if (havecut >= wantcut) lo = mi; else hi = mi;
	}
	return lo;
}

void run() {
	scanf("%d%d", &n, &wantcut);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}