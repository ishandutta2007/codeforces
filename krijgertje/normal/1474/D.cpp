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

const int MAXN = 200000;

int n;
int a[MAXN];

int pref[MAXN], suff[MAXN];

bool solve() {
	pref[0] = 0;
	FOR(i, 1, n) {
		if (pref[i - 1] == -1) { pref[i] = -1; continue; }
		int rem = a[i - 1] - pref[i - 1];
		if (rem < 0) { pref[i] = -1; continue; }
		pref[i] = rem;
	}
	suff[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		if (suff[i + 1] == -1) { suff[i] = -1; continue; }
		int rem = a[i + 1] - suff[i + 1];
		if (rem < 0) { suff[i] = -1; continue; }
		suff[i] = rem;
	}
	if (pref[n - 1] == a[n - 1]) return true;
	REP(i, n - 1) {
		int x = pref[i], y = suff[i + 1];
		if (x == -1 || y == -1) continue;
		if (x > a[i + 1] || y > a[i]) continue;
		if (a[i + 1] - x == a[i] - y) return true;
	}
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}