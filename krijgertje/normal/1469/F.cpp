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

int n, want;
int a[MAXN];

int solve() {
	vector<int> cnt = { 1,-1 }; // # on depth i is sum(j<=i,cnt[j])
	auto mod = [&](int idx, int by) { while (idx >= SZ(cnt)) cnt.PB(0); cnt[idx] += by; };
	sort(a, a + n);
	reverse(a, a + n);
	int at = 0; // for i<at: cnt[i]=0
	REP(i, n) {
		while (at < SZ(cnt) && cnt[at] == 0) ++at;
		assert(at + 1 < SZ(cnt));
		assert(cnt[at] > 0);
		if (cnt[at] >= want) return at;
		if (cnt[at] + cnt[at] + cnt[at + 1] >= want) return at + 1;
		int x = a[i];
		int y = (x - 1) / 2, z = (x - 1) - y;
		//printf("at=%d i=%d: removing %d and adding %d..%d and %d..%d (%d,%d)\n", at, i, at, at + 2, at + 1 + y, at + 2, at + 1 + z, cnt[at], cnt[at] + cnt[at + 1]);
		--cnt[at], ++cnt[at + 1];
		mod(at + 2, +1), mod(at + 2 + y, -1);
		mod(at + 2, +1), mod(at + 2 + z, -1);
	}
	int have = 0;
	while (at < SZ(cnt)) {
		have += cnt[at];
		if (have >= want) return at;
		if (at + 1 < SZ(cnt)) cnt[at + 1] += cnt[at];
		++at;
	}
	return -1;
}

void run() {
	scanf("%d%d", &n, &want);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}