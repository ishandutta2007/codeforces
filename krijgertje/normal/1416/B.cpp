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

const int MAXN = 10000;
struct Op { int i, j, x; Op() {} Op(int i, int j, int x) :i(i), j(j), x(x) {} };

int n;
int a[MAXN];
vector<Op> ans;

int cur[MAXN];

void move(int i, int j, int x) {
	//printf("move(%d,%d,%d):", i, j, x); REP(z, n) printf(" %d", cur[z]); puts("");
	ll k = (ll)x * (i + 1);
	assert(cur[i] >= k);
	cur[i] -= k, cur[j] += k;
	ans.PB(Op(i, j, x));
}

bool solve() {
	int sum = 0; REP(i, n) sum += a[i]; if (sum % n != 0) return false;
	ans.clear(); REP(i, n) cur[i] = a[i];
	FOR(i, 1, n) {
		int step = i + 1;
		int need = (step - cur[i] % step) % step;
		assert(cur[0] >= need);
		if (need != 0) move(0, i, need);
		assert(cur[i] % step == 0);
		move(i, 0, cur[i] / step);
	}
	FOR(i, 1, n) move(0, i, sum / n);
	//printf("cur:"); REP(z, n) printf(" %d", cur[z]); puts("");
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d %d\n", ans[i].i + 1, ans[i].j + 1, ans[i].x);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}