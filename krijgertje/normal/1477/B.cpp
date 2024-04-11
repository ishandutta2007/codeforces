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
char s[MAXN + 1];
char t[MAXN + 1];
int ql[MAXQ], qr[MAXQ];

bool solve() {
	map<int, int> intervals;
	REP(i, n) intervals[i] = t[i] - '0'; intervals[n] = -1;

	auto ensure = [&](int pos) {
		//printf("\tensuring %d\n", pos);
		auto it = intervals.lower_bound(pos);
		assert(it != intervals.end());
		if (it->first == pos) return;
		assert(it != intervals.begin());
		it = prev(it);
		int val = it->second;
		intervals[pos] = val;
	};

	for (int i = nq - 1; i >= 0; --i) {
		int l = ql[i], r = qr[i] + 1;
		ensure(l), ensure(r);
		vector<int> cnt(2, 0);
		int prevpos = l, prevval = 0;
		auto it = intervals.find(l);
		assert(it != intervals.end());
		while (true) {
			assert(it != intervals.end());
			assert(it->first >= prevpos && it->first <= r);
			cnt[prevval] += it->first - prevpos;
			if (it->first == r) break;
			prevpos = it->first, prevval = it->second;
			auto nit = next(it);
			intervals.erase(it);
			it = nit;
		}
		//printf("-> %d / %d\n", cnt[0], cnt[1]);
		if (cnt[0] == cnt[1]) return false;
		intervals[l] = cnt[0] > cnt[1] ? 0 : 1;
		//printf("intervals:"); for (auto it = intervals.begin(); it != intervals.end(); ++it) printf(" %d:%d", it->first, it->second); puts("");
	}
	REP(i, n) ensure(i);
	REP(i, n) if (intervals[i] != s[i] - '0') return false;
	return true;
}

void run() {
	scanf("%d%d", &n, &nq);
	scanf("%s", s); assert(strlen(s) == n);
	scanf("%s", t); assert(strlen(t) == n);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}