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

int n, a, b;
int ans[MAXN];

bool have[MAXN + 1];

bool solve() {
	REP(i, n) ans[i] = -1;
	FORE(i, 1, n) have[i] = false;
	if (a == b) return false;
	int l = 0, r = n - 1;
	ans[l++] = a, have[a] = true;
	ans[r--] = b, have[b] = true;
	for (int i = n; i >= a; --i) if (!have[i] && l < n / 2) ans[l++] = i, have[i] = true;
	FORE(i, 1, b) if (!have[i] && r >= n / 2) ans[r--] = i, have[i] = true;
	//printf("ans:"); REP(i, n) printf(" %d", ans[i]); puts("");
	FORE(i, 1, n) if (!have[i]) return false;
	return true;
}

void run() {
	scanf("%d%d%d", &n, &a, &b);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}