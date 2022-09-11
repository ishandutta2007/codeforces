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

const int MAXN = 5000000;
const int MOD = 1000000007;

int n;
int a[MAXN], t[MAXN];
int ans[MAXN];

void solve() {
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
	//printf("t:"); REP(i, n) printf(" %d", t[i]); puts("");

	vector<ll> sum(2, 0);
	REP(i, n) sum[t[i]] += a[i];
	int loser = sum[t[0]] <= sum[1 - t[0]] ? t[0] : 1 - t[0];
	int winner = 1 - loser;
	deque<pair<int, int>> q;
	REP(i, n) {
		int rem = a[i] - (i == 0 && t[i] == winner ? 1 : 0);
		while (!q.empty() && t[q.back().second] == loser && t[i] == winner && rem > 0) {
			int cur = min(rem, q.back().first);
			rem -= cur;
			q.back().first -= cur;
			if (q.back().first == 0) q.pop_back();
		}
		if (rem > 0) q.PB(MP(rem, i));
	}
	while (!q.empty() && t[q.back().second] == loser && t[q.front().second] == winner) {
		int cur = min(q.back().first, q.front().first);
		q.back().first -= cur;
		if (q.back().first == 0) q.pop_back();
		q.front().first -= cur;
		if (q.front().first == 0) q.pop_front();
	}
	REP(i, n) ans[i] = a[i];
	REPSZ(i, q) ans[q[i].second] -= q[i].first;
	//printf("ans:"); REP(i, n) printf(" %d", ans[i]); puts("");
}

void run() {
	int m;
	scanf("%d%d", &n, &m);
	vector<int> p(m), k(m), b(m), w(m);
	REP(i, m) scanf("%d%d%d%d", &p[i], &k[i], &b[i], &w[i]);
	int seed = 0, base = 0;
	auto genrnd = [&]() {
		int ret = seed;
		seed = ((ll)seed * base + 233) % 1000000007;
		return ret;
	};
	REP(i, m) {
		seed = b[i], base = w[i];
		FOR(j, i == 0 ? 0 : p[i - 1], p[i]) t[j] = (genrnd() % 2), a[j] = (genrnd() % k[i]) + 1;
	}
	solve();
	int out = 1;
	REP(i, n) out = (ll)out * (((ans[i] ^ ((ll)(i + 1) * (i + 1))) + 1) % MOD) % MOD;
	printf("%d\n", out);
}

int ansstupid[MAXN];

void solvestupid() {
	REP(i, n) ansstupid[i] = 0;
	deque<pair<int, int>> q;
	REP(i, n) q.PB(MP(a[i], i));
	int turn = t[0];
	while (!q.empty()) {
		int len = SZ(q);
		REP(i, len) if (t[q.front().second] == turn) break; else { auto p = q.front(); q.pop_front(); q.PB(p); }
		if (t[q.front().second] != turn) break;
		++ansstupid[q.front().second];
		--q.front().first;
		if (q.front().first == 0) q.pop_front();
		turn = 1 - turn;
	}
}

void stress() {
	int mxn = 100, mxa = 10;
	REP(rep, 10000) {
		n = rnd() % mxn + 1;
		int alim = rnd() % mxa + 1;
		REP(i, n) t[i] = rnd() % 2, a[i] = rnd() % alim + 1;
		solve();
		solvestupid();
		bool ok = true; REP(i, n) if (ans[i] != ansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
		printf("t:"); REP(i, n) printf(" %d", t[i]); puts("");
		printf("have:"); REP(i, n) printf(" %d", ans[i]); puts("");
		printf("want:"); REP(i, n) printf(" %d", ansstupid[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}