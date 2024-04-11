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

const int MAXN = 200000;
const int MAXQ = 200000;

int n, nq;
int a[MAXN];
int q[MAXQ]; ll qans[MAXQ];

ll asum[MAXN + 1];
pair<ll, int> b[MAXN + 1]; int nb;

void solve() {
	asum[0] = 0; REP(i, n) asum[i + 1] = asum[i] + a[i];
	nb = 0;
	REPE(i, n) if (nb == 0 || asum[i] > b[nb - 1].first) b[nb++] = MP(asum[i], i);
	ll mx = b[nb - 1].first;
	ll delta = asum[n];
	REP(i, nq) {
		ll rem = q[i];
		ll sofar = 0;
		if (rem > mx) {
			if (delta <= 0) { qans[i] = -1; continue; }
			ll times = (rem - mx + delta - 1) / delta;
			rem -= times * delta;
			sofar += times * n;
		}
		int lo = 0, hi = nb - 1;
		while (lo + 1 < hi) {
			int mi = lo + (hi - lo) / 2;
			if (rem <= b[mi].first) hi = mi; else lo = mi;
		}
		sofar += b[hi].second - 1;
		qans[i] = sofar;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d", &q[i]);
	solve();
	REP(i, nq) { if (i != 0) printf(" "); printf("%lld", qans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}