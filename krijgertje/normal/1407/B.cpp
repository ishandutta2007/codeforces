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
int a[MAXN];
int b[MAXN];

bool used[MAXN];

void solve() {
	int mx = a[0]; FOR(i, 1, n) mx = max(mx, a[i]);
	REP(i, n) used[i] = false;
	int nb = 0;
	REP(i, n) if (a[i] == mx) used[i] = true, b[nb++] = a[i];
	int g = mx;
	while (nb < n) {
		int best = -1; REP(i, n) if (!used[i]) { int cur = gcd(g, a[i]); if (best == -1 || cur > best) best = cur; } assert(best != -1);
		REP(i, n) if (!used[i] && gcd(g, a[i]) == best) used[i] = true, b[nb++] = a[i];
		g = best;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", b[i]); } puts("");

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}