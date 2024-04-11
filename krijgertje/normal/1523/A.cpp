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

int n, nround;
char s[MAXN + 1];
char ans[MAXN + 1];

void solve() {
	REPE(i, n) ans[i] = s[i];
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && s[r] == s[l]) ++r;
		if (s[l] == '0') {
			if (l == 0 && r == n) continue;
			if (l == 0) { int cnt = min(nround, r); REP(i, cnt) ans[r - i - 1] = '1'; continue; }
			if (r == n) { int cnt = min(nround, n - l); REP(i, cnt) ans[l + i] = '1'; continue; }
			int cnt = r - l;
			if (cnt % 2 == 1) cnt = (cnt - 1) / 2; else cnt = cnt / 2;
			cnt = min(nround, cnt);
			REP(i, cnt) ans[l + i] = ans[r - i - 1] = '1';
		}
	}
}

void run() {
	scanf("%d%d", &n, &nround);
	scanf("%s", s);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}