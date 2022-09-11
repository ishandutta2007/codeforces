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
struct Seg { int l, r, id; };

int n;
Seg seg[MAXN];

Seg byl[MAXN];
Seg byr[MAXN];

int cnt[MAXN];

int solve() {
	REP(i, n) byl[i] = seg[i], byr[i] = seg[i];
	sort(byl, byl + n, [&](const Seg& a, const Seg& b) { return a.l < b.l; });
	sort(byr, byr + n, [&](const Seg& a, const Seg& b) { return a.r < b.r; });

	REP(i, n) cnt[i] = 0;
	{
		int at = 0;
		REP(i, n) {
			while (at < n && byr[at].r < byl[i].l) ++at;
			cnt[byl[i].id] += at;
		}
	}
	{
		int at = n - 1;
		for (int i = n - 1; i >= 0; --i) {
			while (at >= 0 && byl[at].l > byr[i].r) --at;
			cnt[byr[i].id] += n - at - 1;
		}
	}

	int ret = INT_MAX;
	REP(i, n) ret = min(ret, cnt[i]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &seg[i].l, &seg[i].r), seg[i].id = i;
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}