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

const int MAXN = 1000;

int n;
int a[MAXN];
int ans[2 * MAXN], nans;

int pos[MAXN + 1];
int cnt[MAXN + 1];
set<int> missing;

void makemove(int idx, int val) {
	ans[nans++] = idx;
	if (--cnt[a[idx]] == 0) missing.insert(a[idx]);
	a[idx] = val;
	if (++cnt[a[idx]] == 1) missing.erase(a[idx]);
}

void solve() {
	REPE(i, n) cnt[i] = 0;
	REP(i, n) ++cnt[a[i]];
	missing.clear(); REPE(i, n) if (cnt[i] == 0) missing.insert(i);
	nans = 0;
	while (true) {
		assert(SZ(missing) >= 1);
		int val = *missing.begin();
		if (SZ(missing) == 1 && val == 0) break;
		int to = val == 0 ? n - 1 : val - 1;
		makemove(to, val);
	}
	int ncorrect = 0; REP(i, n) if (a[i] == i + 1) ++ncorrect;
	//printf("ahalfway:"); REP(i, n) printf(" %d", a[i]); puts("");
	//printf("ncorrect=%d nmove=%d\n", ncorrect, nans);
	REPE(i, n) pos[i] = -1;
	REP(i, n) { assert(pos[a[i]] == -1); pos[a[i]] = i; }
	for (int i = n - 1; i >= 0; --i) {
		//printf("a%d:", i); REP(i, n) printf(" %d", a[i]); puts("");
		int want = i + 1;
		int have = a[i];
		if (have == want) continue;
		assert(SZ(missing) == 1);
		int val = *missing.begin();
		assert(val <= want);
		if (val == want) {
			makemove(i, want);
			pos[have] = -1, pos[want] = i;
		} else {
			assert(pos[want] != -1);
			assert(pos[want] < i);
			int idx = pos[want];
			makemove(idx, val);
			pos[want] = -1, pos[val] = idx;
			assert(SZ(missing) == 1 && *missing.begin() == want);
			makemove(i, want);
			pos[have] = -1, pos[want] = i;
		}
	}
	//printf("afin:"); REP(i, n) printf(" %d", a[i]); puts("");
	//printf("nmove=%d lim=%d\n", nans, 2 * n);
}


void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", nans);
	REP(i, nans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}