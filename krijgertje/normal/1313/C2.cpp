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

const int MAXN = 500000;

int n;
int lim[MAXN];
int ans[MAXN];

ll lsum[MAXN];
ll rsum[MAXN];

pair<int, int> stck[MAXN]; int nstck; ll stcksum;

void solve() {
	nstck = 0, stcksum = 0;
	REP(i, n) {
		int cnt = 1;
		while (nstck > 0 && stck[nstck - 1].second > lim[i]) stcksum -= (ll)stck[nstck - 1].first * stck[nstck - 1].second, cnt += stck[nstck - 1].first, --nstck;
		stck[nstck++] = MP(cnt, lim[i]), stcksum += (ll)cnt * lim[i];
		lsum[i] = stcksum;
	}
	nstck = 0, stcksum = 0;
	for (int i = n - 1; i >= 0; --i) {
		int cnt = 1;
		while (nstck > 0 && stck[nstck - 1].second > lim[i]) stcksum -= (ll)stck[nstck - 1].first * stck[nstck - 1].second, cnt += stck[nstck - 1].first, --nstck;
		stck[nstck++] = MP(cnt, lim[i]), stcksum += (ll)cnt * lim[i];
		rsum[i] = stcksum;
	}
	ll best = LLONG_MIN; int bestidx = -1;
	REP(i, n) {
		ll cur = lsum[i] + rsum[i] - lim[i];
		if (cur > best) best = cur, bestidx = i;
	}
	ans[bestidx] = lim[bestidx];
	for (int i = bestidx - 1; i >= 0; --i) ans[i] = min(lim[i], ans[i + 1]);
	for (int i = bestidx + 1; i < n; ++i) ans[i] = min(lim[i], ans[i - 1]);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &lim[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}