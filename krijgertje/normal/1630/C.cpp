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

const int MAXN = 200000;

int n;
int a[MAXN];

int last[MAXN];
int first[MAXN];

int calc(int l, int r) {
	int cnt = r - l + 1;
	if (cnt == 1) return 0;

	int keep = 2;
	int at = l;
	int lim = last[a[at]];
	while (lim != r) {
		int nlim = lim;
		while (at <= lim) nlim = max(nlim, last[a[at]]), ++at;
		assert(nlim > lim);
		++keep;
		lim = nlim;
	}
	return cnt - keep;
}

int solve() {
	REP(i, n) last[i] = first[i] = -1;
	REP(i, n) { if (first[a[i]] == -1) first[a[i]] = i; last[a[i]] = i; }
	int ret = 0;
	for (int l = 0, r = l; l < n; l = r) {
		int lim = l + 1;
		while (r < lim) {
			lim = max(lim, last[a[r]] + 1);
			++r;
		}
		int cnt = r - l;
		ret += calc(l, r - 1);
	}
	return ret;
}


int solvestupid() {
	vector<bool> been(1 << n, false);
	queue<int> q;
	auto relax = [&](int mask) { if (been[mask]) return; been[mask] = true; q.push(mask); };
	relax(0);
	int ret = 0;
	while (!q.empty()) {
		int mask = q.front(); q.pop();
		int cnt = 0; REP(i, n) if (mask & (1 << i)) ++cnt;
		ret = max(ret, cnt);
		REP(i, n) if ((mask & (1 << i)) == 0) FOR(j, i + 1, n) if ((mask & (1 << j)) == 0) FOR(k, j + 1, n) if ((mask & (1 << k)) == 0 && a[i] == a[k]) relax(mask | (1 << j));
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
	//printf("%d\n", solvestupid());
}


void stress() {
	int mxn = 15;
	REP(rep, 100000) {
		n = rnd() % mxn + 1;
		REP(i, n) a[i] = rnd() % n;
		int have = solve();
		int want = solvestupid();
		if (have == want) { if (rep % 1000 == 999) printf("."); continue; }
		printf("err have=%d want=%d rep=%d\n", have, want, rep);
		printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i] + 1); } puts("");
		mxn = n - 1;
	}
}

int main() {
	run();
	//stress();
	return 0;
}