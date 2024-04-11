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

struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };

int n;
int dx[2], dy[2];
vector<P> ans;

ll A[2][2];

bool solve() {
	REP(i, 2) A[0][i] = dx[i], A[1][i] = dy[i];
	while (true) {
		REP(j, 2) if (A[0][j] < 0 || A[0][j] == 0 && A[1][j] < 0) REP(i, 2) A[i][j] = -A[i][j];
		if (A[0][0] > A[0][1]) REP(i, 2) swap(A[i][0], A[i][1]);
		if (A[0][0] == 0) break;
		ll t = A[0][1] / A[0][0];
		REP(i, 2) A[i][1] -= t * A[i][0];
	}
	//printf("%lld %lld | %lld %lld\n", A[0][0], A[0][1], A[1][0], A[1][1]);
	ll xlim = A[0][1], ylim = A[1][0];
	if (xlim * ylim != n) return false;
	ans.clear();
	REP(x, xlim) REP(y, ylim) ans.PB(P(x, y));
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, 2) scanf("%d%d", &dx[i], &dy[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i, ans) printf("%d %d\n", ans[i].x, ans[i].y);
}

int main() {
	run();
	return 0;
}