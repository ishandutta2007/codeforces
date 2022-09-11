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

const int MAXN = 1000;

int n;
char s[MAXN + 1];

int solve() {
	int a = 0, b = 0, c = 0;
	for (int i = 0; i <= n - i - 1; ++i) {
		int x = s[i] - '0', y = s[n - i - 1] - '0';
		if (i == n - i - 1) { if (x == 0) ++c; continue; }
		if (x != y) ++b; else if (x == 0 && y == 0) ++a;
	}
	if (a == 0 && b == 0 && c == 0) return 0;
	if (a == 0 && b == 0) return -1;
	if (b == 0) return c == 0 ? -1 : +1;
	if (a == 0 && b == 1 && c == 1) return 0;
	return +1;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	int res = solve();
	printf("%s\n", res > 0 ? "ALICE" : res < 0 ? "BOB" : "DRAW");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}