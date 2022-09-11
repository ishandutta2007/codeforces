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

const int MAXN = 100000;
struct Item { ll want, discount; };

int n;
Item a[MAXN];

ll sumwant[MAXN + 1];

ll solve() {
	sort(a, a + n, [&](const Item& p, const Item& q) { return p.discount < q.discount; });
	sumwant[0] = 0; REP(i, n) sumwant[i + 1] = sumwant[i] + a[i].want;
	ll lim = sumwant[n];
	REP(i, n) {
		ll before = sumwant[i];
		ll after = sumwant[n] - before - 1;
		if (before + after < a[i].discount) { lim = min(lim, before); continue; }
		if (before >= a[i].discount) continue;
		ll payafter = a[i].discount - before;
		lim = min(lim, sumwant[n] - payafter);
	}
	return 2 * sumwant[n] - lim;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld%lld", &a[i].want, &a[i].discount);
	printf("%lld\n", solve());
}

ll solvestupid() {
	vector<int> p;
	REP(i, n) REP(j, a[i].want) p.PB(a[i].discount);
	sort(p.begin(), p.end());
	ll ret = 2 * SZ(p);
	do {
		ll cur = 0;
		REPSZ(i, p) cur += i >= p[i] ? 1 : 2;
		ret = min(ret, cur);
	} while (next_permutation(p.begin(), p.end()));
	return ret;
}

void stress() {
	int mxsum = 12;
	REP(rep, 1000) {
		int sum = rnd() % mxsum + 1;
		n = rnd() % sum + 1;
		REP(i, n) a[i].want = 1, a[i].discount = rnd() % sum + 1;
		REP(i, sum - n) ++a[rnd() % n].want;
		ll have = solve();
		ll want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err have=%lld want=%lld\n", have, want);
		printf("%d\n", n); REP(i, n) printf("%lld %lld\n", a[i].want, a[i].discount);
	}
}

int main() {
	run();
	//stress();
	return 0;
}