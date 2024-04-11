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

int n;
char a[MAXN + 1];
char b[MAXN + 1];

int cnt[2][2];

int calc() {
	int x = cnt[0][1], y = cnt[1][0];
	if (x != y) return INT_MAX;
	return x + y;
}

int solve() {
	memset(cnt, 0, sizeof(cnt));
	REP(i, n) ++cnt[a[i] - '0'][b[i] - '0'];
	int ret = calc();
	REP(i, 2) if (i == 1) REP(j, 2) if (cnt[i][j] > 0) {
		--cnt[i][j];
		REP(k, 2) swap(cnt[0][k], cnt[1][k]);
		++cnt[i][j];
		int cur = calc();
		if (cur != INT_MAX) ret = min(ret, 1 + cur);
		--cnt[i][j];
		REP(k, 2) swap(cnt[0][k], cnt[1][k]);
		++cnt[i][j];
	}
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}