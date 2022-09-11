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

struct RMQ {
	int n;
	vector<int> v;
	vector<int> lg;
	vector<vector<int>> jump;

	void init(vector<int>& _v) {
		v = _v; n = SZ(v);
		lg = vector<int>(n + 1); lg[1] = 0; FORE(i, 2, n) { lg[i] = lg[i - 1]; while ((2 << lg[i]) <= i) ++lg[i]; }
		jump = vector<vector<int>>(n, vector<int>(lg[n] + 1));
		REP(i, n) jump[i][0] = v[i];
		REP(k, lg[n]) REP(i, n) if (i + (2 << k) <= n) jump[i][k + 1] = max(jump[i][k], jump[i + (1 << k)][k]);

	}
	int query(int l, int r) {
		if (l > r) return 0;
		int k = lg[r - l + 1];
		return max(jump[l][k], jump[r - (1 << k) + 1][k]);
	}
};

const int MAXN = 300000;

int n;
int dist[MAXN];
char ans[MAXN + 1];

int l[MAXN], r[MAXN];
int a[MAXN], b[MAXN]; // a[i] and b[i]: the two nearest lanterns to the right that can illuminate i

RMQ rmq;
int dp[MAXN+1]; // dp[i]: first unilluminated lantern if we only use lanterns 0..i-1
int prv[MAXN + 1];
int act[MAXN + 1];

bool solve() {
	REP(i, n) l[i] = max(0, i - dist[i]), r[i] = min(n - 1, i + dist[i]);
	deque<int> q;
	for (int i = n - 1; i >= 0; --i) {
		while (SZ(q) > 0 && l[q.front()] > i) q.pop_front();
		a[i] = SZ(q) == 0 ? -1 : q.front();
		if (a[i] != -1) q.pop_front();
		while (SZ(q) > 0 && l[q.front()] > i) q.pop_front();
		b[i] = SZ(q) == 0 ? -1 : q.front();
		if (a[i] != -1) q.push_front(a[i]);
		q.push_front(i);
	}
	//printf("close:"); REP(i, n) printf(" %d/%d", a[i], b[i]); puts("");

	vector<int> v(n); REP(i, n) v[i] = r[i]; rmq.init(v);
	REPE(i, n) dp[i] = 0;
	auto relax = [&](int idx, int val,int p,int a) {
		//printf("\trelax(%d,%d,%d,%d)\n", idx, val, p, a);
		if (dp[idx] >= val) return;
		dp[idx] = val, prv[idx] = p, act[idx] = a;
	};
	REP(i, n) {
		//printf("%d:\n", i);
		if (dp[i] > i) {
			relax(i + 1, max(dp[i], r[i] + 1), i, -1);
		} else if (dp[i] == i || dp[i + 1] == i) {
			int from = dp[i] == i ? i : i + 1;
			if (a[i] != -1) relax(a[i] + 1, max(a[i], rmq.query(from, a[i] - 1) + 1), from, a[i]);
			if (b[i] != -1) relax(b[i] + 1, max(b[i], rmq.query(from, b[i] - 1) + 1), from, b[i]);
		}
	}
	if (dp[n] != n) return false;

	int at = n;
	REP(i, n) ans[i] = 'R'; ans[n] = '\0';
	while (at != 0) {
		if (act[at] != -1) ans[act[at]] = 'L';
		at = prv[at];
	}

	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &dist[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}