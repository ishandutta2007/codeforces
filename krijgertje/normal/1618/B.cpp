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

const int MAXN = 100;

int n;
char s[MAXN - 2][2 + 1];
char ans[MAXN + 1];

void solve() {
	REP(i, n - 3) if (s[i][1] != s[i + 1][0]) {
		int nans = 0;
		ans[nans++] = s[0][0];
		REP(j, i + 1) ans[nans++] = s[j][1];
		ans[nans++] = s[i + 1][0];
		FOR(j, i + 1, n - 2) ans[nans++] = s[j][1];
		ans[nans] = '\0';
		return;
	}
	{
		int nans = 0;
		ans[nans++] = s[0][0];
		REP(j, n - 2) ans[nans++] = s[j][1];
		ans[nans++] = 'a';
		ans[nans] = '\0';
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 2) scanf("%s", s[i]);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}