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

const int MAXN = 1 << 16;

int n;
int ans[MAXN];

int val[MAXN];
int who[MAXN];

int query(char* op, int a, int b) {
	printf("%s %d %d\n", op, a + 1, b + 1); fflush(stdout);
	int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
}

void solve() {
	val[0] = 0;
	FOR(i, 1, n) val[i] = query("XOR", 0, i);

	REP(i, n) who[i] = -1;
	pair<int, int> use = MP(-1, -1);
	FOR(i, 1, n) {
		if (val[i] == 0) { use = MP(0, i); break; }
		if (who[val[i]] != -1) { use = MP(who[val[i]], i); break; }
		who[val[i]] = i;
	}
	if (use != MP(-1, -1)) {
		int a = use.first, b = use.second;
		assert(val[a] == val[b] && a != b);
		int me = query("AND", a, b);
		REP(i, n) ans[i] = me ^ val[a] ^ val[i];
	} else {
		assert(who[1] != -1 && who[2] != -1);
		int a = who[1], b = who[2];
		int me1 = query("AND", 0, a);
		int me2 = query("AND", 0, b);
		assert((me1 & (1 << 0)) == 0);
		assert((me2 & (1 << 1)) == 0);
		assert((me1 | 3) == (me2 | 3));
		int me = me1 | (me2 & 1);
		REP(i, n) ans[i] = me ^ val[i];
	}
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); REP(i, n) printf(" %d", ans[i]); puts(""); fflush(stdout);
}

int main() {
	run();
	return 0;
}