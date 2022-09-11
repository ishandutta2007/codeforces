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

int n, k;

bool islocal = false;
vector<int> local;
int localcheat;
int nq;

int query(int at) {
	++nq;
	if (!islocal) {
		printf("? %d\n", at + 1); fflush(stdout);
		int ret; scanf("%d", &ret); return ret;
	} else {
		int ret = local[at];
		vector<int> nlocal(n, 0);
		REP(i, n) {
			int a = local[i] / 2, b = local[i] - a; if (i == localcheat) b += a, a = 0;
			nlocal[(i + n - 1) % n] += a, nlocal[(i + 1) % n] += b;
		}
		local = nlocal;
		return ret;
	}
}

int solve() {
	int step = (int)sqrt(1.0 * n) - 1;
	REP(i, step) query(0);
	int plus = -1, min = -1;
	for (int at = 0; at < n; at += step) {
		int cur = query(at);
		if (cur == k) continue;
		if (cur < k && min != -1) continue;
		if (cur > k && plus != -1) continue;
		cur = query(at);
		if (cur == k) continue;
		if (cur < k) min = at;
		if (cur > k) plus = at;
	}
	assert(plus != -1 && min != -1);
	int l = min, r = plus; if (r < l) r += n;
	while (r - l >= 2) {
		int m = l + (r - l) / 2;
		int cur = query(m % n);
		if (cur == k) return m % n;
		if (cur < k) l = m; else r = m;
	}
	assert(false); return -1;
}

void run() {
	scanf("%d%d", &n, &k);
	int ans = solve();
	printf("! %d\n", ans + 1); fflush(stdout);
}

void research() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> cur(n, k);
	map<vector<int>,int> seen;
	while (true) {
		//REP(i, n) { if (i != 0) printf(" "); printf("%2d", cur[i]); } puts("");
		REP(i, n) printf("%c", cur[i]<k ? '-' : cur[i]>k ? '+' : '='); puts("");
		if (seen[cur] >= 4) break; else ++seen[cur];
		vector<int> nxt(n, 0);
		REP(i, n) {
			int a = cur[i] / 2, b = cur[i] - a; if (i == 0) b += a, a = 0;
			nxt[(i + n - 1) % n] += a;
			nxt[(i + 1) % n] += b;
		}
		cur = nxt;
	}
}

void stress() {
	REP(rep, 10) {
		n = 100000;
		k = 2;
		islocal = true;
		localcheat = rnd() % n;
		local = vector<int>(n, k);
		nq = 0;
		int have = solve();
		int want = localcheat;
		if (have == want) { printf("%d\n", nq); continue; }
		printf("err\n");
	}
}

int main() {
	//research();
	run();
	//stress();
	return 0;
}