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

const int MAXN = 1 << 17;

int n;
char s[MAXN + 1];

int cnt[26][MAXN + 1];

int rec(int l, int r, int k) {
	if (r - l == 1) return 1 - (cnt[k][r] - cnt[k][l]);
	int m = l + (r - l) / 2;
	int a = (m - l) - (cnt[k][m] - cnt[k][l]) + rec(m, r, k + 1);
	int b = (r - m) - (cnt[k][r] - cnt[k][m]) + rec(l, m, k + 1);
	return min(a, b);
}

int solve() {
	REP(i, 26) { cnt[i][0] = 0; REP(j, n) cnt[i][j + 1] = cnt[i][j] + (s[j] == 'a' + i ? 1 : 0); }
	return rec(0, n, 0);
}

void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(strlen(s) == n);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}