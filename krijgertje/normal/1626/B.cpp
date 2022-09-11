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

const int MAXN = 200000;

char s[MAXN + 1]; int n;
char ans[MAXN + 1];

int x[MAXN];

void solve() {
	REP(i, n) x[i] = s[i] - '0';
	for (int i = n - 1; i >= 1; --i) if (x[i - 1] + x[i] >= 10) {
		REP(j, i - 1) ans[j] = '0' + x[j];
		ans[i - 1] = '1';
		ans[i] = '0' + x[i - 1] + x[i] - 10;
		FOR(j, i + 1, n) ans[j] = '0' + x[j];
		ans[n] = '\0';
		return;
	}
	ans[0] = '0' + x[0] + x[1];
	FOR(j, 2, n) ans[j - 1] = '0' + x[j];
	ans[n - 1] = '\0';
}

void run() {
	scanf("%s", s); n = strlen(s);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}