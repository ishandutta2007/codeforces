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

const int MAXN = 20000;

int n;
char s[MAXN + 1];
int ans[4];

void solve() {
	int h = n / 2;
	REP(i, h) if (s[i] == '0') { ans[0] = i, ans[1] = n - 1, ans[2] = i + 1, ans[3] = n - 1; return; }
	REP(i, h) if (s[n - i - 1] == '0') { ans[0] = 0, ans[1] = n - i - 1, ans[2] = 0, ans[3] = n - i - 2; return; }
	if (n % 2 == 0) {
		REP(i, n) assert(s[i] == '1');
		ans[0] = 0, ans[1] = h - 1, ans[2] = 1, ans[3] = h;
	} else {
		REP(i, n) if (2 * i + 1 != n) assert(s[i] == '1');
		ans[0] = 0, ans[1] = h, ans[2] = h, ans[3] = n - 1;
	}
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	solve();
	printf("%d %d %d %d\n", ans[0] + 1, ans[1] + 1, ans[2] + 1, ans[3] + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}