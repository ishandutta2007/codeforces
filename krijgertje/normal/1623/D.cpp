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

const int MAXN = 100000;
const int MOD = 1000000007;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }
int calcinv(int x) { return pw(x, MOD - 2); }

int h, w, sx, sy, tx, ty, perc;



int solve() {
	int n = h * w;
	int pclean = (ll)perc * calcinv(100) % MOD;

	vector<int> pvisit(4 * n, -1);
	int pcur = 1;

	int x = sx, y = sy, dx = +1, dy = +1, key;
	int ret = 0;
	while (true) {
		if (x + dx < 0 || x + dx >= h) dx = -dx;
		if (y + dy < 0 || y + dy >= w) dy = -dy;
		key = 4 * (x * w + y) + (dx == -1 ? 0 : 2) + (dy == -1 ? 0 : 1);
		if (pvisit[key] != -1) break;
		pvisit[key] = pcur;
		if (x == tx || y == ty) pcur = (ll)pcur * (1 + MOD - pclean) % MOD;
		ret = (ret + pcur) % MOD;
		x += dx, y += dy;
	}
	assert(x == sx && y == sy);
	ret = (ll)ret * calcinv(1 + MOD - pcur) % MOD;
	return ret;
}

void run() {
	scanf("%d%d%d%d%d%d%d", &h, &w, &sx, &sy, &tx, &ty, &perc), --sx, --sy, --tx, --ty;
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}