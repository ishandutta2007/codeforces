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

const int MAXN = 500000;

int n;
int a[MAXN];

int b[MAXN];
int c[MAXN];
bool been[MAXN];

bool solve() {
	REP(i, n) b[i] = i;
	sort(b, b + n, [&](int i, int j) { return a[i] < a[j]; });
	REP(i, n) c[b[i]] = i;
	REP(i, n - 1) if (a[b[i]] == a[b[i + 1]]) return true;
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
	//printf("b:"); REP(i, n) printf(" %d", b[i]); puts("");
	//printf("c:"); REP(i, n) printf(" %d", c[i]); puts("");

	REP(i, n) been[i] = false;
	int nfixed = 0, ncyc = 0;
	REP(i, n) if (c[i] == i) ++nfixed, been[i] = true;
	REP(i, n) if (!been[i]) {
		++ncyc;
		int at = i;
		while (!been[at]) { been[at] = true; at = c[at]; }
	}
	if (ncyc == 0) return true;
	return (n - nfixed - (ncyc - 1)) % 2 == 1;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%s\n", solve() ? "YES" : "NO");
}

set<vector<int>> solvestupid() {
	set<vector<int>> ret;
	vector<int> start(n);
	REP(i, n) start[i] = i;
	queue<vector<int>> q;
	auto relax = [&](const vector<int> &to) { if (ret.count(to)) return; ret.insert(to); q.push(to); };
	relax(start);
	while (!q.empty()) {
		vector<int> at = q.front(); q.pop();
		REP(i, n) REP(j, n) if (j != i) REP(k, n) if (k != i && k != j) {
			int x = at[i], y = at[j], z = at[k];
			at[i] = z, at[j] = x, at[k] = y;
			relax(at);
			at[i] = x, at[j] = y, at[k] = z;
		}
	}
	return ret;
}

void stress() {
	for (n = 1; n <= 10; ++n) {
		REP(i, n) a[i] = i;
		auto can = solvestupid();
		do {
			bool have = solve();
			bool want = can.count(vector<int>(a, a + n)) != 0;
			if (have == want) { continue; }
			printf("err\n");
			exit(0);
		} while (next_permutation(a, a + n));
		printf("done %d\n", n);
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}